
#include "ash_bitmap.h"
#include "mseasyncshared.h"

#include <mutex>
#include <future>
#include <list>
#include <random>

#include <iostream>
#include <ratio>
#include <chrono>
#include <string>

namespace ash {

	class CImage : public CBitmap {
	public:
		using CBitmap::CBitmap;

		CImage& operator=(const CBitmap &x) {
			CBitmap::operator=(x);
			on_potential_modification();
			return (*this);
		}

		void clear_and_set_dimensions(CBMCoordinates dimensions) {
			CBitmap::clear_and_set_dimensions(dimensions);
			on_potential_modification();
		}

		void set_to_hs_color_map_image() {
			for (size_t y = 0; y < (*this).dimensions().y(); y += 1) {
				for (size_t x = 0; x < (*this).dimensions().x(); x += 1) {
					auto pixel1 = hsv2pixel(x / (double)(*this).dimensions().x(), y / (double)(*this).dimensions().y(), 0.5);
					(*this).pixel_ref(CBMCoordinates(x, y)) = pixel1;
				}
			}
			on_potential_modification();
		}
		void set_to_default_image() { set_to_hs_color_map_image(); }

		double mean_brightness_of_subrectangle(CBMCoordinates lower_coordinates, CBMCoordinates dimensions) const {
			const auto subrectangle_bitmap = (*this).subrectangle(lower_coordinates, dimensions);
			double total_brightness = 0.0;
			for (const auto& pixel_cref : subrectangle_bitmap.pixels()) {
				total_brightness += pixel_cref.brightness();
			}
			double mean_brightness = 0.0;
			if ((0 != dimensions.y()) && (0 != dimensions.x())) {
				mean_brightness = total_brightness / ((double)dimensions.y()) / ((double)dimensions.x());
			}
			return mean_brightness;
		}

		void convert_to_grayscale() {
			for (auto& pixel_ref : (*this).pixels_ref()) {
				pixel_ref.convert_to_grayscale();
			}
			on_potential_modification();
		}

	protected:
		/* A function meant to be called whenever an operation that could potentially modify the image occurs. */
		virtual void on_potential_modification() {}

		CPixel& pixel_ref(CBMCoordinates coordinates) {
			return CBitmap::pixel_ref(coordinates);
		}
		std::vector<CPixel>& pixels_ref() { return CBitmap::pixels_ref(); }
	};

	class CImageWithProtectedCache : public CImage {
	public:
		using CImage::CImage;

		double mean_brightness_of_subrectangle(CBMCoordinates lower_coordinates, CBMCoordinates dimensions) const {
			/* By default, this "lock guard" protects the (mutable) cache from being accessed simultaneously from
			multiple threads. This functionality can be disabled in derived classes. */
			CObjLockGuard lock_guard1(*this);

			/* Check if the result is in the cache. */
			for (const auto& cached_mean_brightness_of_subrectangle_cref : m_cached_mean_brightness_of_subrectangles) {
				if ((cached_mean_brightness_of_subrectangle_cref.m_lower_coordinates == lower_coordinates) && (cached_mean_brightness_of_subrectangle_cref.m_dimensions == dimensions)) {
					return cached_mean_brightness_of_subrectangle_cref.m_mean_brightness;
				}
			}

			/* It wasn't in the cache, so we'll evaluate the result and add the new result to the cache. */
			CCachedMeanBrightnessOfSubrectangle cache_item;
			cache_item.m_lower_coordinates = lower_coordinates;
			cache_item.m_dimensions = dimensions;
			cache_item.m_mean_brightness = CImage::mean_brightness_of_subrectangle(lower_coordinates, dimensions);
			m_cached_mean_brightness_of_subrectangles.insert(m_cached_mean_brightness_of_subrectangles.cbegin(), cache_item);
			if (m_cached_mean_brightness_of_subrectangles.size() > 10/*max cache size*/) {
				m_cached_mean_brightness_of_subrectangles.pop_back();
			}

			return cache_item.m_mean_brightness;
		}

	private:

		class CCachedMeanBrightnessOfSubrectangle {
		public:
			CBMCoordinates m_lower_coordinates;
			CBMCoordinates m_dimensions;
			double m_mean_brightness = 0.0;
		};

		virtual void lock_obj_mutex() const { m_obj_mutex.lock(); }
		virtual void unlock_obj_mutex() const { m_obj_mutex.unlock(); }
		class CObjLockGuard {
		public:
			CObjLockGuard(const CImageWithProtectedCache& parent_cref) : parent_cptr(&parent_cref) {
				parent_cptr->lock_obj_mutex();
			}
			~CObjLockGuard() {
				parent_cptr->unlock_obj_mutex();
			}
			const CImageWithProtectedCache* parent_cptr;
		};

		void on_potential_modification() override {
			/* Clear the cache whenever the image is modified. */
			m_cached_mean_brightness_of_subrectangles.clear();
		}

		mutable std::vector<CCachedMeanBrightnessOfSubrectangle> m_cached_mean_brightness_of_subrectangles;
		mutable std::mutex m_obj_mutex;

		friend class CObjLockGuard;
	};

	class CImageWithUnprotectedCache : public CImageWithProtectedCache {
	public:
		using CImageWithProtectedCache::CImageWithProtectedCache;

		/* Here we override some virtual functions to disable the thread safety mechanism, thereby saving
		(a bit of) performance cost. */
		void lock_obj_mutex() const override {}
		void unlock_obj_mutex() const override {}
	};
}

int main()
{
	{
		std::default_random_engine rand_generator1;
		std::uniform_int_distribution<int> udist_0_9(0, 9);
		const size_t num_tasks = 10;
		const size_t num_digits_per_task = 10000;
		const size_t num_digits = num_tasks * num_digits_per_task;

		{
			/* This block contains a simple example demonstrating the use of mse::TAsyncSharedReadWriteAccessRequester
			to safely share an object between threads. */

			class CObj1WithUnprotectedMutable {
			public:
				std::string text() const {
					m_last_access_time = std::chrono::system_clock::now();
					return m_text1;
				}
				void set_text(const std::string& text) {
					m_last_access_time = std::chrono::system_clock::now();
					m_text1 = text;
				}
				std::chrono::system_clock::time_point last_access_time() {
					return m_last_access_time;
				}
			private:
				std::string m_text1 = "initial text";
				/* Note that mutable members can affect the safety of object sharing. */
				mutable std::chrono::system_clock::time_point m_last_access_time;
			};
			class B {
			public:
				static size_t num_occurrences(mse::TAsyncSharedReadWriteAccessRequester<CObj1WithUnprotectedMutable> obj1_access_requester,
					const char ch, size_t start_pos, size_t length) {

					/* Here we're counting the number of occurrences of the given character in the specified section
					of the (shared) object's string of digits. */
					auto obj1_readlock_ptr = obj1_access_requester.readlock_ptr();
					auto end_pos = start_pos + length;
					assert(end_pos <= obj1_readlock_ptr->text().length());
					size_t num_occurrences = 0;
					for (size_t i = start_pos; i < end_pos; i += 1) {
						if (obj1_readlock_ptr->text().at(i) == ch) {
							num_occurrences += 1;
						}
					}
					return num_occurrences;

					/* At the end of the scope, obj1_readlock_ptr will be destroyed and its lock on the shared object
					will be released. */
				}
			};

			/* mse::make_asyncsharedreadwrite<>, like std::make_shared<>, actually allocates the target object. */
			auto obj1_access_requester = mse::make_asyncsharedreadwrite<CObj1WithUnprotectedMutable>();

			std::string rand_digits_string;
			for (size_t i = 0; i < num_digits; i += 1) {
				/* Just generating a random string of digits. */
				rand_digits_string += std::to_string(udist_0_9(rand_generator1));
			}
			/* In the next line we temporarily grab a pointer to the object with a "write lock" so we can (safely) call a
			non-const member function. */
			obj1_access_requester.writelock_ptr()->set_text(rand_digits_string);

			std::list<std::future<size_t>> futures;
			for (size_t i = 0; i < num_tasks; i += 1) {
				/* Here we're dividing the (shared) object's string of digits into sections and setting up
				some (potentially) asynchronous tasks to count the number of occurrences of the character
				'5' in each section. */
				futures.emplace_back(std::async(B::num_occurrences, obj1_access_requester, '5', i*num_digits_per_task, num_digits_per_task));
			}

			size_t total_num_occurrences = 0;
			for (auto it = futures.begin(); futures.end() != it; it++) {
				total_num_occurrences += (*it).get();
			}
		}
		{
			/* This block is essentially the same as the previous block except that instead of sharing a CObj1WithUnprotectedMutable
			we're sharing a CObj1WithNoMutables. Because it doesn't have any unprotected mutable members, it's safe to
			permit simultaneous read access, so instead of TAsyncSharedReadWriteAccessRequester<>, we can use
			TAsyncSharedObjectThatYouAreSureHasNoUnprotectedMutablesReadWriteAccessRequester<>. */

			class CObj1WithNoMutables {
			public:
				std::string text() const {
					return m_text1;
				}
				void set_text(const std::string& text) {
					m_text1 = text;
				}
			private:
				std::string m_text1 = "initial text";
			};
			class B {
			public:
				static size_t num_occurrences(mse::TAsyncSharedObjectThatYouAreSureHasNoUnprotectedMutablesReadWriteAccessRequester<CObj1WithNoMutables> obj1_access_requester,
					const char ch, size_t start_pos, size_t length) {

					auto obj1_readlock_ptr = obj1_access_requester.readlock_ptr();
					auto end_pos = start_pos + length;
					assert(end_pos <= obj1_readlock_ptr->text().length());
					size_t num_occurrences = 0;
					for (size_t i = start_pos; i < end_pos; i += 1) {
						if (obj1_readlock_ptr->text().at(i) == ch) {
							num_occurrences += 1;
						}
					}
					return num_occurrences;
				}
			};

			auto obj1_access_requester = mse::make_asyncsharedobjectthatyouaresurehasnounprotectedmutablesreadwrite<CObj1WithNoMutables>();

			std::string rand_digits_string;
			for (size_t i = 0; i < num_digits; i += 1) {
				rand_digits_string += std::to_string(udist_0_9(rand_generator1));
			}
			obj1_access_requester.writelock_ptr()->set_text(rand_digits_string);

			std::list<std::future<size_t>> futures;
			for (size_t i = 0; i < num_tasks; i += 1) {
				futures.emplace_back(std::async(B::num_occurrences, obj1_access_requester, '5', i*num_digits_per_task, num_digits_per_task));
			}

			size_t total_num_occurrences = 0;
			for (auto it = futures.begin(); futures.end() != it; it++) {
				total_num_occurrences += (*it).get();
			}
		}
		{
			/* This block contains an example demonstrating the use of mse::TReadOnlyStdSharedFixedConstPointer
			to share an object between threads in simple read only situations. */

			class CObj1WithNoMutables {
			public:
				CObj1WithNoMutables(const std::string& text) : m_text1(text) {}
				std::string text() const {
					return m_text1;
				}
				void set_text(const std::string& text) {
					m_text1 = text;
				}
			private:
				std::string m_text1 = "initial text";
			};
			class B {
			public:
				static size_t num_occurrences(const std::shared_ptr<const CObj1WithNoMutables> obj1_shptr,
					const char ch, size_t start_pos, size_t length) {

					auto end_pos = start_pos + length;
					assert(end_pos <= obj1_shptr->text().length());
					size_t num_occurrences = 0;
					for (size_t i = start_pos; i < end_pos; i += 1) {
						if (obj1_shptr->text().at(i) == ch) {
							num_occurrences += 1;
						}
					}
					return num_occurrences;
				}
			};

			std::string rand_digits_string;
			for (size_t i = 0; i < num_digits; i += 1) {
				rand_digits_string += std::to_string(udist_0_9(rand_generator1));
			}

			/* mse::make_readonlystdshared<> returns an mse::TReadOnlyStdSharedFixedConstPointer which is compatible
			with the corresponding std::shared_ptr. Aside from enforcing constness, the main reason for using
			mse::make_readonlystdshared<> over std::make_shared<> is to make clear the intended purpose of the
			pointer. Namely, to share an object between threads with the intent that the object not be modified. */
			auto obj1_roshfcptr = mse::make_readonlystdshared<CObj1WithNoMutables>(rand_digits_string);

			std::list<std::future<size_t>> futures;
			for (size_t i = 0; i < num_tasks; i += 1) {
				futures.emplace_back(std::async(B::num_occurrences, obj1_roshfcptr, '5', i*num_digits_per_task, num_digits_per_task));
			}

			size_t total_num_occurrences = 0;
			for (auto it = futures.begin(); futures.end() != it; it++) {
				total_num_occurrences += (*it).get();
			}
		}
	}

	{
		class CObjWithIndirectMember {
		public:
			CObjWithIndirectMember() : m_string1(*(new std::string("initial text"))) {}
			~CObjWithIndirectMember() {
				delete (&m_string1);
			}
			void set_string2(const std::string& string_cref) const {
				/* We know the "mutable" keyword can be used to subvert "const"ness. */
				m_string2 = string_cref;
			}
			void set_string1(const std::string& string_cref) const {
				/* As with members declared with the "mutable" keyword qualifier, "const"ness does not
				propagate to "indirect" members. */
				m_string1 = string_cref;
			}

			mutable std::string m_string2 = "initial text";
			std::string& m_string1;
		};

		const CObjWithIndirectMember const_obj_with_indirect_member;

		/* "const" objects aren't necessarily unmodifiable if they have members declared "mutable". */
		const_obj_with_indirect_member.m_string2 = "new text";

		/* Or if they have "indirect" members. That is, members that are actually references to other objects. */
		const_obj_with_indirect_member.m_string1 = "new text";

		/* So declaring an object "const" doesn't necessarily make it safe to share without access controls. */
	}

	{
		/* This is an example of "atomic" transactions when performing operations on multiple interdependent
		shared objects. In this case, funds transfers between accounts. */

		class CAccount {
		public:
			void add_to_balance(double amount) {
				m_balance += amount;
				m_last_transaction_time = std::chrono::system_clock::now();
			}
			double balance() const {
				return m_balance;
			}
		private:
			double m_balance = 0.0;
			std::chrono::system_clock::time_point m_last_transaction_time;
		};
		class B {
		public:
			static bool nonatomic_funds_transfer(mse::TAsyncSharedReadWriteAccessRequester<CAccount> source_ar,
				mse::TAsyncSharedReadWriteAccessRequester<CAccount> destination_ar, const double amount) {
				/* Non-atomic transactions between shared objects like this can be bad. They can result in
				"race condition" bugs. */

				if (source_ar.readlock_ptr()->balance() >= amount) {
					source_ar.writelock_ptr()->add_to_balance(-amount);

					destination_ar.writelock_ptr()->add_to_balance(amount);
					return true;
				}
				else {
					return false;
				}
			}

			static bool atomic_funds_transfer(mse::TAsyncSharedReadWriteAccessRequester<CAccount> source_ar,
				mse::TAsyncSharedReadWriteAccessRequester<CAccount> destination_ar, const double amount) {
				/* You want your transactions between shared objects to be atomic like this one to avoid
				"race condition" bugs. */

				/* To make your transaction atomic, first obtain a lock on all the parties in the transaction. */
				auto source_writelock_ptr = source_ar.writelock_ptr();
				auto destination_writelock_ptr = destination_ar.writelock_ptr();

				if (source_writelock_ptr->balance() >= amount) {
					source_writelock_ptr->add_to_balance(-amount);
					destination_writelock_ptr->add_to_balance(amount);
					return true;
				}
				else {
					return false;
				}
			}
		};

		/* create the accounts */
		auto bobs_account_access_requester = mse::make_asyncsharedreadwrite<CAccount>();
		auto bills_account_access_requester = mse::make_asyncsharedreadwrite<CAccount>();
		auto barrys_account_access_requester = mse::make_asyncsharedreadwrite<CAccount>();

		/* set initial balances */
		bobs_account_access_requester.writelock_ptr()->add_to_balance(100.0);
		bills_account_access_requester.writelock_ptr()->add_to_balance(200.0);
		barrys_account_access_requester.writelock_ptr()->add_to_balance(300.0);

		/* do some concurrent fund transfers */
		std::future<bool> bob_to_bill_res = std::async(B::atomic_funds_transfer, bobs_account_access_requester,
			bills_account_access_requester, 10.0);

		std::future<bool> bill_to_barry_res = std::async(B::atomic_funds_transfer, bills_account_access_requester,
			barrys_account_access_requester, 20.0);

		std::future<bool> barry_to_bob_res = std::async(B::atomic_funds_transfer, barrys_account_access_requester,
			bobs_account_access_requester, 30.0);

		bool all_transfers_were_executed = (bob_to_bill_res.get() && bill_to_barry_res.get() && barry_to_bob_res.get());
	}

	{
		auto access_requester = mse::make_asyncsharedreadwrite<std::string>("some text");
		auto writelock_ptr1 = access_requester.try_writelock_ptr();
		if (writelock_ptr1) {
			// lock request succeeded
			int q = 5;
		}
		auto readlock_ptr2 = access_requester.try_readlock_ptr_for(std::chrono::seconds(10));
		auto writelock_ptr3 = access_requester.try_writelock_ptr_until(std::chrono::steady_clock::now() + std::chrono::seconds(10));
	}

	{
		/* Here are a couple of examples that are similar to the first ones with the random string of digits,
		but instead use, as the shared object, image classes with a built-in (result) cache. These image classes
		are intended as an example of when a class might have mutable members that need to be considered when
		sharing an object between threads. */

		std::default_random_engine rand_generator2;
		std::uniform_real_distribution<double> udist_0_1(0.0, 1.0);
		const size_t image_dimension1 = 256;
		const size_t num_samples = 10;
		const size_t sample_dimension1 = 10;

		{
			/* In this example, the shared image object has an "unprotected" cache, and therefore unprotected
			mutable members. So it is not safe to allow simultaneous (read) access. */

			class B {
			public:
				static double mean_brightness_of_subrectangle(mse::TAsyncSharedReadWriteAccessRequester<ash::CImageWithUnprotectedCache> image_access_requester, ash::CBMCoordinates lower_coordinates, ash::CBMCoordinates dimensions) {
					auto image_readlock_ptr = image_access_requester.readlock_ptr();
					return image_readlock_ptr->mean_brightness_of_subrectangle(lower_coordinates, dimensions);
				}
			};

			auto image1_access_requester = mse::make_asyncsharedreadwrite<ash::CImageWithUnprotectedCache>(ash::CBMDimensions(image_dimension1, image_dimension1));

			image1_access_requester.writelock_ptr()->set_to_default_image();

			std::list<std::future<double>> futures;
			for (size_t i = 0; i < num_samples; i += 1) {
				/* Here we're randomly choosing some subrectangles in the image and setting up some (potentially)
				asynchronous tasks to calculate the "mean brightness" of each subrectangle. */
				auto x_coord = size_t(udist_0_1(rand_generator2) * (image_dimension1 - sample_dimension1 - 1));
				auto y_coord = size_t(udist_0_1(rand_generator2) * (image_dimension1 - sample_dimension1 - 1));
				futures.emplace_back(std::async(B::mean_brightness_of_subrectangle, image1_access_requester, ash::CBMCoordinates(x_coord, y_coord), ash::CBMDimensions(sample_dimension1, sample_dimension1)));
			}

			{
				/* Some of those tasks we just setup could still be concurrently accessing the shared object, so our
				request for a writelock_ptr() could block for a while. */
				auto image1_writelock_ptr = image1_access_requester.writelock_ptr();

				/* While converting to grayscale does modify the image, it does so in a way that does not affect
				"brightness", so it won't mess up the "mean brightness" calculations being done by the tasks we set
				up.*/
				image1_writelock_ptr->convert_to_grayscale();
			}

			double total_brightness = 0.0;
			for (auto it = futures.begin(); futures.end() != it; it++) {
				total_brightness += (*it).get();
			}
			double mean_brightness_estimate = total_brightness / double(num_samples);
		}

		{
			/* This block is essentially the same as the previous block except that instead of sharing a CImageWithUnprotectedCache
			we're sharing a CImageWithProtectedCache. Because its mutable members are "protected" (i.e. thread safe) it's safe to
			permit simultaneous read access, so instead of TAsyncSharedReadWriteAccessRequester<>, we can use
			TAsyncSharedObjectThatYouAreSureHasNoUnprotectedMutablesReadWriteAccessRequester<>. */

			class B {
			public:
				static double mean_brightness_of_subrectangle(
					mse::TAsyncSharedObjectThatYouAreSureHasNoUnprotectedMutablesReadWriteAccessRequester<ash::CImageWithProtectedCache> image_access_requester,
					ash::CBMCoordinates lower_coordinates, ash::CBMCoordinates dimensions) {
					auto image_readlock_ptr = image_access_requester.readlock_ptr();
					return image_readlock_ptr->mean_brightness_of_subrectangle(lower_coordinates, dimensions);
				}
			};

			auto image1_access_requester = mse::make_asyncsharedobjectthatyouaresurehasnounprotectedmutablesreadwrite<ash::CImageWithProtectedCache>(ash::CBMDimensions(image_dimension1, image_dimension1));

			image1_access_requester.writelock_ptr()->set_to_default_image();

			std::list<std::future<double>> futures;
			for (size_t i = 0; i < num_samples; i += 1) {
				auto x_coord = size_t(udist_0_1(rand_generator2) * (image_dimension1 - sample_dimension1 - 1));
				auto y_coord = size_t(udist_0_1(rand_generator2) * (image_dimension1 - sample_dimension1 - 1));
				futures.emplace_back(std::async(B::mean_brightness_of_subrectangle, image1_access_requester, ash::CBMCoordinates(x_coord, y_coord), ash::CBMDimensions(sample_dimension1, sample_dimension1)));
			}

			{
				auto image1_writelock_ptr = image1_access_requester.writelock_ptr();
				image1_writelock_ptr->convert_to_grayscale();
			}

			double total_brightness = 0.0;
			for (auto it = futures.begin(); futures.end() != it; it++) {
				total_brightness += (*it).get();
			}
			double mean_brightness_estimate = total_brightness / double(num_samples);
		}
	}

	return 0;
}

