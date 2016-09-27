mutex m; // used to protect access to shared data


//....


void f()
{
	unique_lock<mutex>  lck {m}; // acquire the mutex m

	//...manipulate shared data...

	
}


void f(int i,int j) // X* vs. unique_ptr<X>
{
	X* p = new X; // allocate a new X;

	unique_ptr<X> sp {new X};// allocate a new X and give its pointer to  unique_ptr


	//...


	if(i < 99)  throw Z{};// may throw an exception

	if(j < 77) return ; // may return "early"

	p->do_something();// may throw an exception

	sp->do_something();// may throw an exception


	//...
	delete p; // destroy *p
}



void f(int i, int j) // use a local variable
{
	X x;
//....
}

unique_ptr<X>  make_X(int i)
// make an X and immediately give it to a unique_ptr
{
	//...check i,etc...
	return unique_ptr<X>  {new X{i}};
}


void f(shared_ptr<fstream>);
void g(shared_ptr<fstream>);

void user(const string& name,ios_base::openmode mode)
{
	shared_ptr<fstream> fp {new fsteam(name,mode)};
	if(!*fp) throw No_file{};// make sure the file was properly opened

	f(fp);
	g(fp);
//...
}



void f(); //function

struct F{ // function object
	void operator()();// F's call operator
};


void user()
{
	thread t1 {f}; // f() executes in separate thread
	thread t2 {F()};// F()() executes in separate thread

	t1.join(); // wait for t1
	t2.join(); // wait for t2
}


void f() {cout<<"Hello";}


struct F{
	void operator()() {cout << "Parallel World!\n"; }
};

// PaHerallllel o World!


void f(vector<double>& v)
{
	vector<double> v;
	F(vector<double>& vv):v{vv}{}
	void operator()();
}


int 
main()
{
	vector<double>  some_vec {1,2,3,4};
	vector<double>  vec2 {10,11,12};


	thread t1 {f,some_vec}; // f(some_vec) executes in separate thread
	thread t2 {F(vec2)};// F(vec2)() executes in separate thread

	t1.join(); // wait for t1
	t2.join(); // wait for t2
}


void f(const vector<double>& v, double *res); // take input from v; place result in *res


class F{

public:
	F(const vector<double>& vv, double *p):v{vv},res{p}{}
	void operator()();// place result in *res
private:
	const vector<double>& v;// source of input
	double *res;// target for output
};



int 
main()
{
	vector<double> some_vec;
	vector<double> vec2;

	//...


	double res1;
	double res2;


	thread t1 {f,some_vec,&res1}; // f(some_vec,&res1) executes in separate thread
	thread t2 {F(vec2,&res2)};// F(vec2,&res2)() executes in separate thread

	t1.join(); // wait for t1
	t2.join(); // wait for t2

	cout<< res1 << ' '<<res2<<'\n';
}


mutex m;// controlling mutex
int sh;  // shared data

void f()
{
	unique_lock<mutex> lck {m}; // acquire mutex;
	sh += 7; // manipulate shared data	
}// release mutex implicitly

class Record{
	public:
	mutex m;
	//...
};


void f()
{
	//...
	unique_lock<mutex> lck1 {m1,defer_lock};//defer_lock:don't yet try to  acquire the mutex
	unique_lock<mutex> lck2 {m2,defer_lock};
	unique_lock<mutex> lck3 {m3,defer_lock};
	
	lock(lck1,lck2,lck3); // acquire all three locks


	//... manipulate shared data...
}// implicity release all mutexes


using namespace std::chrono; 

auto t0 = high_resoltution_clock::now();
this_thread::sleep_for(milliseconds{20});
auto t1 = high_resoltution_clock::now();

cout<< duration_cast<nanoseconds>(t1-t0).count()<<"nanoseconds passed\n";


class Message{ // object to be communicated
	//...
};

queue<Message> mqueue;// the queue of messages

condition_variable mcond;// the variable communicating events

mutex mmutex;// the locking mechanism

void consumer()
{

	while(true){
		unique_lock<mutex> lck {mmutex}; // acquire mmutex
		while(mcond.wait(lck)) ;// do nothing // release lck and wait;
		// re-acquire lck upon wakeup
		auto m = mqueue.front(); // get the  message
		mqueue.pop();
		
		lck.unlock(); // release lck
		//...process m...
	}
}


void  producer()
{
	while(true){
		Message m;
		// ..fill the message...
		unique_lock<mutex> lck {mmutex};// protect operations
		mqueue.push(m);
		mcond.notify_one();	// notify 其实就是:pthread_cond_broadcast
/*
// Wake up all threads waiting for condition variables COND. 
extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __THROWNL __nonnull ((1));
*/
	} // release lock at end of scope
}




X v =fx.get();// 


void f(promise<X>& px)
{
	 //...

	try{
		X res;
		// .. compute a value for res...
		px.set_value(res);
	}
	catch(...){// oops:couldn't compute res
	// pass the exception to the future's thread.
	px.set_exception(current_exception());
		
	}
} 



void g(future<X>& fx)// a task: get the result from fx
{
	// ...
	try{
		X v = fx.get();// if necessary,wait for the value to get computed
		// ..usv v....
	}
	catch(...){ // oops: someone couldn't compute v
		// ... handle error....
	}
	// ...
}



double asscu(double* beg,double* end,double init)
// compute the sum of [beg:end) starting with the initial value init
{
	return accumulate(beg,end,init);
}



double comp2(vector<double>& v)
{
	using Task_type = double(double*,double*,double);// type of task


	packaged_task<Task_type>  pt0 {assum};// package the task(i.e.,accum)

	packaged_task<Task_type>  pt1 {assum};


	future<double> f0 {pt0.get_future()};// get hold of pt0's future
	
	future<double> f1 {pt1.get_future()};// get hold of pt1's future


	double* first = &v[0];

	thread t1 {move(pt0),first,first+v.size()/2,0}; // start a thread for pt0
	
	thread t2 {move(pt1),first+v.size()/2,first+v.size(),0}; // start a thread for pt1
	
	
	//...

	return f0.get() + f1.get();// get the results
}



double comp4(vector<double>& v)
// spawn many tasks if v is large enough
{
	if(v.size()<10000)  return accum(v.begin(),v.end(),0.0);	

	auto v0 = &v[0];
	auto sz = v.size();

	auto f0 = async(assum,v0,v0+sz/4,0.0);// first quarter
	auto f1 = async(assum,v0+sz/4,v0+sz/2,0.0);// second quarter
	auto f2 = async(assum,v0+sz/2,v0+3*sz/4,0.0);//third quarter
	auto f3 = async(assum,v0+3*sz/4,v0+sz,0.0);// fourth quarter

	return f0.get()+f1.get()+f2.get()+f3.get();// collect and combine the results
}


using namespace std::chrono;


auto t0 = high_resolution_clock:now();
do_work();
auto t1 = high_resolution_clock:now();
cout<< duration_cast<milliseconds>(t1-t0).count()<<"msec\n";


constexpr float min = numeric_limits<float>::min();// smallest positive float


constexpr int szi = sizeof(int);// the  number of bytes in an int



void test(vector<string>& v,forward_list<int>& lst)
{
	sort(v);// sort the vector
	sort(lst);// sort the singly-linked list
}


template<typename Ran> // for random-access interators
void sort_helper(Ran beg, Ran end, random_access_iterator_tag)// we can subscript into [beg:end)
{
	sort(beg,end); // just sort it
}


template<typename For> // for random-access interators
void sort(C& c)// we can subscript into [beg:end)
{
	using Iter = Iterator_type<C>;
	sort_helper(c.begin(),c.end(),Iterator_category<Iter>{});
}


template<typename C>
	using Iterator_type = typename::Iterator;// C's interator type



template<typename Iter>
	using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;// Iter's category


bool b1 = Is_arithmetic<int>();// yes,int is an arithmetic type
bool b2 = Is_arithmetic<string>();// no,std::string is not an arithmetic type

template<typename Scalar>
class complex{
	Scalar re,im;
public:
	static_assert(Is_arithmetic<Scalar>(),"Sorry I only support complex  of arithmetic types");
	
	//...
};





template<typename T>
constexpr bool Is_arithmetic()
{
	renturn std::is_arithmetic<T>::value;
}


template<typename Forward_iterator,typename T,typename Compare>
		pair<Forward_iterator,Forward_iterator>
		equal_range(Forward_iterator first,Forward_iterator last, const T&val, Compare cmp);

// compare names
auto  rec_eq=[](const Record& r1,const Record& r2) { return r1.name < r2.name;}

void f(const vector<Record>& v)// assume that v is sorted on its "name" field
{
	auto er = equal_range(v.begin(),v.end(),Record{"Reg"},rec_eq);

	// print all equal records
	for(auto p = er.first; p != er.second;++p)
		cout<<*p;// assume that << is difined for Record
}

void f(vector<string>& v)
{
	auto pp = make_pair(v.begin(),2); //  pp is a pair<vector<string>::iterator,int>
	// ...
}


tuple<string,int,double> t2("Sild",123,3.14); // the type is explicitly specified

auto t = make_tuple(string("Herring"),10,1.23); // the type id deduced 
// t is a tuple<string,int,double>

string  s = get<0>(t); // get first element of tuple

int x = get<1>(t);

double d = get<2>(t);



regex pat (R"(\w{2}\s*\d{5}(-\d{4})?)");// ZIP code pattern:XXdddd-dddd and variants

cout << "Pattern:"<<pat<<'\n';

int lineno = 0;
for(string line;getline(cin,line);){
	++lineno;
	smatch matches;	
	if(regex_search(line,matches.pat))
		cout<<lineno<<":"<<matches[0]<<'\n';
}


void f()
{
	list<double> lst {1,2,3,4,5,9999.99999};
	auto s = accumulate(lst.begin(),lst.end(),0.0);// calculate the sum
	
	cout<<s<<'\n';// print 10014.9999
}


template<typename Scalar>
class complex{
public:
	complex(const Scalar& re = {}, const Scalar& im={});

	// ...
};




void f(complex<float> fl, complex<double> db)
{
	complex<long double> ld {fl+sqrt(db)};
	
	db += fl * 3;

	fl = pow(1/fl,2);

	// ...
}



using  my_engine = default_random_engine; // type of engine

using  my_distribution = uniform_int_distribution<>;// type of distribution


my_engine  re {};//the default  engine

my_distribution one_to_six {1,6};// distribution that maps to the ints 1..6


auto die = bind(one_to_six,re);// make a generator


int  x = die();// roll the die: x becomes a value in [1:6]


Rand_int rnd {1,10}; // make a random number generator for [1:10]

int x = rnd();// x is a number in [1:10]


class Rand_int {

	public:
	Rand_int(int low,int high):dist{low,high}{}
	int operator()() { return dist(re);} // draw an int


	private:
	default_random_engine re;
	uniform_int_distribution<> dist;
};


int 
main()
{
	Rand_int rnd {0,4};
	
	vector<int> histogram(5);
	for(int i = 0;i != 200;++i)
		++histogram[rnd()];

	
	for(int i = 0;i != mn.size();++i){
		cout<<i<<'\t';
		for(int j = 0;j != mn[i];++j) cout<<'*';
			cout<<endl;
	}
}



template<typename T>
class valarray{

	//...
};


void f(valarray<double>& a1, valarray<double>& a2)
{
	valarray<double> a = a1 * 3.14 + a2 /a1;// numeric array operators,*,+,/ ,and =

	a2 += a1 * 3.14;

	a = abs(a);

	double d = a2[7];
	//...
}

static_assert(numeric_limits<char>::is_signed,"unsigned characters!");
static_assert(100000 < numeric_limits<int>::max(),"small ints!");








































