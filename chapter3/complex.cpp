
class complex{
	double re,im;
public:
	complex(double r,double i):re{r},im{i}{}
	complex(double r):re{r},im{0}{}
	complex():re{0},im{0}{}


	double real()const {return re;}
	void real(double d) {re = d;}
	double imag()const {return im;}
	void imag(double d) {im = d;}

	complex& operator+=(complex z){re += z.re,im += z.im;return *this;}
	complex& operator+-(complex z){re -= z.re,im -= z.im;return *this;}

	complex& operator*=(complex );// defined out-of-class somewhere
	complex& operator/=(complex );// defined out-of-class somewhere
};


complex& operator+(complex a,complex b){ return a+=b;}
complex& operator-(complex a,complex b){ return a-=b;}

complex& operator-(complex a){ return {-a.real(),-a.imag()}}// unary minus

complex& operator*(complex a,complex b ){return a *=b;}
complex& operator/(complex a,complex b ){return a /=b;}


bool operator==(complex a,complex b)
{
	return a.real()== b.real() && a.imag() == b.image();
}


bool operator!=(complex a,complex b)
{
	return !(a == b);
}


void f(complex z)
{
	complex a {2.3};
	complex b {1/a};
	complex c {a+z*complex{1,2.3}};
//...
	if(c != b)
		c = -(b/a)+2*b;
}


class Vector{
private:
	double *elem;
	int sz;
public:
	
	Vector(int s):elem{new double[s]},sz{s}
	{	
		for(int i = 0;i !=s; ++i) elem[i] = 0;
	}

	~Vector(){delete[] elem;}

	double& operator[](int i);
	int size() const;
};


void fct(int n)
{
	Vector v(n);
	
	//...use v...

	{
		Vector v2(2*n);
		
		//...use v2 and v...
		
	} // v2 is destroyed here

	//...use v...
}


class Vector{
public:
	
	Vector(std::initializer_list<double>);
	
//....
  void push_back(double);
	
};



Vector read(istream& is)
{
	Vector v;
	for(double d;is>>d;)
		v.push_back(d);
	return v;
}



Vector v1 = {1,2,3,4,5};


Vector::Vector(std::initializer_list<double> lst):
	elem{new double[lst.size()]},sz{lst.size()}
{
	copy(lst.begin(),lst.end(),elem);// copy from lst into elem
}



class Container{

public:
	virtual double& operator[](int) =0; // pure virtual function
	virtual int size() const =0;	// const member function
	virtual ~Container(){}
};



void use(Container& c)
{
	const int sz=c.size();

	for(int i=0;i != sz;++i)
		cout<<c[i]<<'\n';
}




class Vector_container:public Container{

	Vector v;
public:
	Vector_container(int s):v(s){}
	~Vector_container()[]

	
	 double& operator[](int i){return v[i];} 
	 int size() const {return v.size();}	
};


void g()
{
	Vector_container vc {1,2,3};
	use(vc);
}



class List_container:public Container{

	std::list<double> ld;
public:
	List_container(){} // empty List
	List_container(initializer_list<double> il):ld{il} {}
	~List_container()[]

	 double& operator[](int i); 
	 int size() const {return ld.size();}	
};



double& List_container::operator[](int i)
{
	for(auto& x:ld){
		if(0 == i) return x;
		--i;
	}
	throw_out_of_range("List container");
}


void h()
{
	List_container lc = {1,2,3,4};
	use(lc);
}


class Shape{
public:
	virtual Point center() const =0;
	virtual void move(Point to) =0;

	virtual void draw() const =0;
	virtual void rotate(int angle) =0;
	
	virtual ~Shape(){}
	
};


void rotate_all(vector<Shape*>& v,int angle)
{
	for(auto p:v)
		p->rotate(angle);
}


class Circle:public Shape {
public:

	 Circle(Point p,int rr);


	 Point center() const {return x;}
	 void move(Point to) {x=to};

	 void draw() const;
	 void rotate(int) {};
	
private:
	Point x;// center
	int r;// radius
};


class Smiley:public Circle {
public:

	Smiley(Point p,int r):Circle{p,r},mouth{nullptr}{}

	~Smiley()
	{
		delete mouth;
		for(auto p:eyes) delete p; // delete[] eyes?? 不行吗
	}
	 
	
	 void move(Point to);

	 void draw() const;
	 void rotate(int);

	void add_eye(Shape* s){eyes.push_back(s);}
	void set_mouth(Shape*);
	
	virtual void wink(int i);// 眨眼
	
private:
	Vector<Shape*> eyes;
	Shape* mouth;
};


void Smiley::draw()
{
	Circle::draw(); // 先划圈
	for(auto p:eyes)
		p->draw();// 2只眼睛
	mouth->draw();// 嘴
}


enum class Kind{circle,triangle,smiley};


Shape* read_shape(istream& is)// read shape descriptions from input steam is
{
	// ..read shape header from is and find its Kind k...
	switch(k){

	case Kind::circle:
		return new Circle{p,r}; // 创建无名对象，直接上类名，加参数。
	case Kind::triangle:
		return new Triangle{p1,p2,p3};
	case Kind::smiley:
		Smiley* ps = new Smiley{p,r};
		ps->add_eye(e1);
		ps->add_eye(e2);
		ps->set_mouth(m);
		return ps;
	}
}


void user()
{
	std::vector<Shape*> v;
	while(cin)
		v.push_back(read_shape(cin));
	draw_all(v);
	rotate_all(v,45);
	for(auto p:v) delete p;
}



unique_ptr<Shape> read_shape(istream& is)
{
	switch(k){

	case Kind::circle:
		return unique_ptr<Shape>{new Circle{p,r}}; // 创建无名对象，直接上类名，加参数。
	...
	}
}


void user()
{
	vector<unique_ptr<Shape>> v;
		
	while(cin)
		v.push_back(read_shape(cin));
	draw_all(v);
	rotate_all(v,45);
}



void test(complex z1)
{
	complex z2 {z1}; // copy initialization
	complex z3;
	z3 = z2; // copy assignment 

	// the diff between  copy initialization &  copy assignment ?
}

//浅拷贝
void bad_copy(Vector v1)
{
	Vector v2=v1;// copy v1's representation into v2
	v1[0] = 2;// now v2[0] is also 2!
	v2[1] = 3;// now v1[1] is also 3!
}


class Vector{
	
private:
	double* elem;
	int sz;
public:
	Vector(int s);
	~Vector(){delete[] elem;}

	Vector(const Vector& a);
	Vector& operator=(const Vector& a);

	double& operator[](int i);
	const double& operator[](int i) const;

	int size() const;
};


// 谁先初始化？sz有可能为0
Vector::Vector(const Vector& a)
	:elem{new double[sz]},sz{a.sz}
{
	for(int i = 0; i!=sz;++i)
		elem[i] = a.elem[i];
}


Vector& Vector::operator=(const Vector& a)
{
	double* p = new double[a.sz];
	for(int i = 0; i!=sz;++i)
		p[i] = a.elem[i];
	delete[] elem; // delete  old elements
	elem = p;
	sz = a.sz;
	return *this;
}


Vector operator+(const Vector& a,const Vector& b)
{
	if(a.size() != b.size())
		throw Vector_size_mismatch{};

	Vector res(a.size());
	for(int i = 0;i != a.size[];++i)
		res[i] = a[i] + b[i];
	return res;
}



void f(const Vector& x,const Vector& y, const Vector& z)
{
	Vector r;
	//...
	r = x + y + z;
	//...
}

class Vector
{
	Vector(const Vector& a); // copy constructor
	Vector& operator=(const Vector& a);// copy assignment 

	Vector(Vector&& a);// move constructor
	Vector& operator=(Vector&& a);// move assignment
};





Vector::Vector(Vector&& a)
	:elem{a.elem}, // "grab the elements" from a
	sz{a.sz}
{
	a.elem = nullptr; // now a has no elements
	a.sz = 0;
}

Vector f()
{
	Vector x(100);
	Vector y(100);
	Vector z(100);

	z = x; // get a copy
	y = std::move(x);	// get a move

	return z;// get a move
}


std::vector<thread> my_threads;


Vector init(int n)
{
	thread t {heartbeat};// run heartbeat concurrently on its own thread

	my_threads.push_back(move(t));// move t into my_threads

	
	Vector vec(n);
	for(int i = 0; i< vec.size();++i) vec[i] = 99;
	return vec;
}


auto v=init();




// suppress operations:废止
class Shape{

	public:
	 Shape(const Shape&) =delete; // no copy operations
	Shape& operator=(const Shape&)=delete;

	Shape(Shape&&) =delete;// no move operations
	Shape& operator=(Shape&&)=delete;

	～Shape();
	
};


template<typename T>
class Vector{

private:
	T *elem;
	int sz;
	
public:
	Vector(int s);
	~Vector(){delete[] elem;}

	T& operator[](int i);
	const T& operator[](int i) const;
	int size() const {return sz;}
}

template<typename T>
Vector<T>::Vector(int s)
{
	if(s<0) throw Negative_size{};
	elem = new T[s];
	sz = s;
}



template<typename T>
const T& Vector<T>::operator[](int i)const 
{
	if(i < 0 || size() <= i) throw out_of_range{"Vector::operator[]"};
	return elem[i];
}



Vector<char> vc(200); // vector of 200 characters
Vector<string> vs(17);// vector of 17 strings.
Vector<list<int>> vli(45);// vector of 45 lists of integers



void write(const Vector<string>& vs)
{
	for(int i = 0;i != vs.size();++i)
		cout<<vs[i]<<'\n';
}



template<typename T>
T* begin(Vector<T>& x)
{
	return &x[0];
}


template<typename T>
T* end(Vector<T>& x)
{
	//return &x[x.size()-1];应该也可以	
	return x.begin() + x.size(); // pointer to one-past-last element
}


void f2(const Vector<string>& vs )
{
	for(auto& s:vs)
		cout<<s<<'\n';
}


template<typename Container,typename Value>
Value sum(const Container& c,  Value v)
{
	for(auto x:c)
		v+=x;
	return v;
}


void user(Vector<int>& vi,
	std::list<double>& ld,
	std::vector<complex<double>>& vc)
{
	int x = sum(vi,0);
	double = d = sum(vi,0.0);
	double dd = sum(ld,0.0);
	auto z = sum(vc,complex<double>{});
}


template<typename T>
class Less_than{
	const T val;
public:
	Less_than(const T& v):val(v){}
	bool operator()(const T& x)const {return x < val;}// call operator
};

Less_than<int> Iti {42};
Less_than<string> Its {"Backus"};


void fct(int n,const string& s )
{
	bool b1 = Iti(n); // true if n < 42
	bool b2 = Its(s); // true if s < "Backus"

}






template<typename C,typename P>
int count(const C& c,P pred)
{
	int cnt = 0;
	for(const auto& x:c)
		if(pred(x))
			++cnt;
	return cnt;
}

void f( const Vector<int>& vec,
		const list<string>& lst,
		int x,const string& s)
{
	cout<<"number of values less than"<<x
		<<":"<<count(vec,Less_than<int>{x})
		<<"\n";
	cout<<"number of values less than"<<s
		<<":"<<count(lst,Less_than<string>{s})
		<<"\n";
}

void f1( const Vector<int>& vec,
		const list<string>& lst,
		int x,
		const string& s)
{
	cout<<"number of values less than"<<x
		<<":"<<count(vec,[&](int a){return a < x;})
		<<"\n";
	cout<<"number of values less than"<<s
		<<":"<<count(lst,[&](const string& a){return a < s;})
		<<"\n";
}


template<class C,class Oper>
void for_all(C& c ,Oper op)// assume that C is a container of pointers
{
	for(auto& x:c)
		op(*x);// pass op() a reference to each element pointed to
}


void user()
{
	vector<unique_ptr<Shape>> v;
	while(cin)
		v.push_back(read_shape(cin));
	for_all(v,[](Shape& s){s.draw();});
	for_all(v,[](Shape& s){s.rotate(45);});
}


template<typename T,typename... Tail>
void f(T head, Tail... tail)
{
	g(head);// do something to head
	f(tail...);// try again with tail
}


void f(){}

int main()
{
	cout<<"first:";
	f(1,2.2,"hello");

	cout<<"\nsecond:";
	f(0.2,'c',"yuck!",0,1,2);
	cout<<"\n";
}


template<typename T>
void g(T x)
{
	cout<<x<<"";
}

using size_t = unsigned int;

template<typename T>
class Vector{

public:
	using value_type = T;
	//.....
};


template<typename C>
using Element_type= typename C::value_type;

template<typename Container>
void algo(Container& c)
{	
	Vector<Element_type<Container>> vec;
	//
}


template<typename Key,typename Value>
class Map{
	//
};
template<typename Value>
using String_map = Map<string,Value>;

String_map<int> m;// m is a Map<string,int>


































































