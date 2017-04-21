#pragma once
#ifndef ASH_BITMAP_H_
#define ASH_BITMAP_H_

#include <vector>
#include <tuple>

namespace ash {
	typedef unsigned char byte_t;
	class CPixelComponent {
	public:
		CPixelComponent() {}
		CPixelComponent(const CPixelComponent&) = default;
		CPixelComponent(byte_t byte) : m_byte(byte) {}
		byte_t byte() const { return m_byte; }
		byte_t& byte_ref() { return m_byte; }
		void apply_brightness_factor(double bf) {
			double new_val = bf * m_byte;
			if (0.0 > new_val) { m_byte = 0; return; }
			if (255.0 <= new_val) { m_byte = 255; return; }
			m_byte = (byte_t)new_val;
		}

	private:
		byte_t m_byte = 0;
	};

	class CPixel {
	public:
		CPixel() {}
		CPixel(const CPixel&) = default;
		CPixel(CPixelComponent r, CPixelComponent g, CPixelComponent b) : m_r(r), m_g(g), m_b(b) {}
		const CPixelComponent& r() const { return m_r; }
		const CPixelComponent& g() const { return m_g; }
		const CPixelComponent& b() const { return m_b; }
		CPixelComponent& r_ref() { return m_r; }
		CPixelComponent& g_ref() { return m_g; }
		CPixelComponent& b_ref() { return m_b; }
		double brightness() const { return (((double)m_r.byte()) + ((double)m_g.byte()) + ((double)m_b.byte())) / 255.0 / 3.0; }
		void apply_brightness_factor(double bf) {
			m_r.apply_brightness_factor(bf);
			m_g.apply_brightness_factor(bf);
			m_b.apply_brightness_factor(bf);
		}
		void convert_to_grayscale() {
			byte_t brightness_byte = (byte_t)((*this).brightness() * 255.0);
			m_r.byte_ref() = brightness_byte;
			m_g.byte_ref() = brightness_byte;
			m_b.byte_ref() = brightness_byte;
		}

	private:
		CPixelComponent m_r;
		CPixelComponent m_g;
		CPixelComponent m_b;
	};

	typedef std::tuple<size_t, size_t> C2DTuple;
	class CBMCoordinates : public C2DTuple {
	public:
		CBMCoordinates() : C2DTuple(0, 0) {}
		CBMCoordinates(const CBMCoordinates&) = default;
		CBMCoordinates(size_t x, size_t y) : C2DTuple(x, y) {}
		size_t x() const { return std::get<0>(*this); }
		size_t y() const { return std::get<1>(*this); }
		size_t& x_ref() { return std::get<0>(*this); }
		size_t& y_ref() { return std::get<1>(*this); }
		bool operator==(const CBMCoordinates &rhs) const { return (((*this).x() == rhs.x()) && ((*this).y() == rhs.y())); }
	};

	class CBMDimensions : public CBMCoordinates {
	public:
		CBMDimensions() {}
		CBMDimensions(const CBMDimensions&) = default;
		CBMDimensions(size_t x, size_t y) : CBMCoordinates(x, y) {}
		CBMDimensions(CBMCoordinates coordinates) : CBMCoordinates(coordinates) {}
		bool contains(CBMCoordinates rhs) const {
			if ((rhs.x() <= (*this).x()) && (rhs.y() <= (*this).y())) {
				return true;
			}
			else {
				return false;
			}
		}
		CBMDimensions& operator+=(const CBMCoordinates& rhs) { (*this).x_ref() += rhs.x(); (*this).y_ref() += rhs.y(); return (*this); }
		CBMDimensions operator+(const CBMCoordinates& rhs) const { CBMDimensions retval(*this); retval += rhs; return retval; }
	};

	inline CBMCoordinates& operator+=(CBMCoordinates& lhs, const CBMDimensions &rhs) {
		lhs.x_ref() += rhs.x(); lhs.y_ref() += rhs.y(); return lhs;
	}
	inline CBMCoordinates operator+(const CBMCoordinates& lhs, const CBMDimensions &rhs) { CBMCoordinates retval(lhs); retval += rhs; return retval; }

	class CBitmap {
	public:
		CBitmap() {}
		CBitmap(const CBitmap&) = default;
		CBitmap(CBMDimensions dimensions) : m_dimensions(dimensions) { m_pixels.resize(dimensions.x() * dimensions.y()); }
		void clear_and_set_dimensions(CBMCoordinates dimensions) {
			m_pixels.clear();
			m_pixels.resize(dimensions.x() * dimensions.y());
		}
		const CPixel& pixel(CBMCoordinates coordinates) const {
			if (!m_dimensions.contains(coordinates)) { throw(std::out_of_range("out of range coordinate - pixel() - CBitmap")); }
			return m_pixels[coordinates.y()*m_dimensions.x() + coordinates.x()];
		}
		CPixel& pixel_ref(CBMCoordinates coordinates) {
			if (!m_dimensions.contains(coordinates)) { throw(std::out_of_range("out of range coordinate - pixel_ref() - CBitmap")); }
			return m_pixels[coordinates.y()*m_dimensions.x() + coordinates.x()];
		}
		CBitmap subrectangle(CBMCoordinates lower_coordinates, CBMCoordinates dimensions) const {
			if (!m_dimensions.contains(lower_coordinates + dimensions)) { throw(std::out_of_range("out of range coordinate - subbitmap() - CBitmap")); }
			CBitmap retval(dimensions);
			for (size_t y = 0; y < dimensions.y(); y += 1) {
				for (size_t x = 0; x < dimensions.x(); x += 1) {
					retval.pixel_ref(CBMCoordinates(x, y)) = (*this).pixel(CBMCoordinates(lower_coordinates.x() + x, lower_coordinates.y() + y));
				}
			}
			return retval;
		}
		const CBMDimensions& dimensions() const {
			return m_dimensions;
		}
		const std::vector<CPixel>& pixels() const { return m_pixels; }
		std::vector<CPixel>& pixels_ref() { return m_pixels; }

	private:
		CBMDimensions m_dimensions;
		std::vector<CPixel> m_pixels;
	};

	CPixel hsv2pixel(double h, double s, double v) {
		if (h < 0.0) { h = 0.0; }
		if (s < 0.0) { s = 0.0; }
		if (v < 0.0) { v = 0.0; }
		if (h >= 1.0) { h = 1.0; }
		if (s > 1.0) { s = 1.0; }
		if (v > 1.0) { v = 1.0; }
		auto K1 = v * s;
		int section = (int)(h * 6.0);
		auto K2 = K1 * (1 - abs(section % 2 - 1));
		double r = 0.0;
		double g = 0.0;
		double b = 0.0;
		switch (section) {
		case 0:
			r = K1;
			g = K2;
			break;
		case 1:
			r = K2;
			g = K1;
			break;
		case 2:
			g = K1;
			b = K2;
			break;
		case 3:
			g = K2;
			b = K1;
			break;
		case 4:
			r = K2;
			b = K1;
			break;
		default:
			r = K1;
			b = K2;
		}
		auto K3 = v - K1;
		r += K3;
		g += K3;
		b += K3;
		CPixel retval((byte_t)(r * 255), (byte_t)(g * 255), (byte_t)(b * 255));
		return retval;
	}

}

#endif // ASH_BITMAP_H_
