// namespace 可以匿名的。
unsigned char c1 = 64;// well defined: 
//a char has at least 8 bits and can always hold 64
unsigned char c2 = 1264;// implementation-defined: truncation
//  if a char has only 8 bits.


static_assert(4<=sizeof(int),"sizeof(int) too small");


const int size = 4 * 1024;
char page[size];


void f()
{
	page[size+size] = 7; // undefined
}

x = y + f(2);

float x; // x is a floating-point variable
int y = 7;// y is an integer variable with the initial value 7
float f(int); // f is a function taking an argument of type int and
// returning a floating-point number

void f(int a, int b)
{
	bool b1 {a == b};
	// ...
}


bool is_open(File *);

bool greater(int a, int b) {return a > b;}


bool b1 = 7;// 7 != 0, so b becomes true
bool b2 {7};// error: narrowing

int i1 = true; // i1 becomes 1
int i2 {true}; // i2 becomes 1

void f(int i)
{
	bool b { i != 0 };
	//...
}


bool a = true;
bool b = true;

bool x = a + b; // a + b is 2,so x becomes true
bool y = a || b;// a || b is 1,so y becomes true("||" means "or")

bool z = a - b;// a-b is 0,so z becomses false

void g(int* p)
{
	bool b = p; // narrows to true  or false
	bool b2 { p != nullptr};// explicit test against nullptr

	if(p){ // equivalent to p != nullptr
	 //...
	}
}


char ch = 'a';


void 
intval()
{
	for(char c;cin>>c;){
		cout<<"the value of '"<<c<<"'is ""<< int {c}<<'\n'; 
	}
}


void
digits()
{
	for(int i=0;i != 10;++i)
		cout<<static_cast<char>('0'+i);
}



char c = 255; // 255 is "all ones",hexadecimal oxFF

int i =c;

void
f(char c,signed char sc,unsigned char uc)
{
	char* pc = &uc; // error:no pointer conversion
	signed char* psc = pc;//error:no pointer conversion
	unsigned char* puc = pc;//error:no pointer conversion
	psc = puc;// error:no pointer conversion
	
}


void
g(char c,signed char sc,unsigned char uc)
{
	c = 255;// implementation-defined if plain chars are signed and have 8 bits
	c = sc;// ok
	c = uc;//implementation-defined if plain chars are signed and if uc's value is too large

	uc = sc;// ok,conversion to unsigned

	sc = c;// implementation-defined if plain chars are unsigned and if c's value is too large
	uc = c;// ok,conversion to unsigned
}



// assume that a char is 8 bits
signed char sc = -160;

unsigned char uc = sc; // uc == 116(because 256 -160 == 116)
cout<<uc;// print 't'

char count[256];// assume 8-bit chars
++count[sc];//likely disaster:out-of-range access

++count[uc];// ok


char v1[] = "a\xah\129";// 6 chars: 'a' '\xa' 'h' '\12' '9' '\0'
char v2[] = "a\xah\127";// 5 chars: 'a' '\xa' 'h' '\127' '\0'
char v3[] = "a\xad\127";// 4 chars: 'a' '\xad'  '\127'  '\0'
char v4[] = "a\xad\0127";// 5 chars: 'a' '\xad'  '\012' '7' '\0'


U'\UFADEBEEF'

u'\uDEAD'
u'\xDEAD'


cout<<0xF0UL<<' '<<0LU<<'\n';

 

1.23 .23 0.23 1. 1.0 1.2e10 1.23e-15

65.43e-21

3.1415926f 2.0f 2.99F 2.9e-3f

3.14L  2.0L 2.99L 2.9e-3L

1LU // unsigned long
2UL // unsigned long
3ULL // unsigned long long
4LLU // unsigned long long
5LUL // ERROR

1L // LONG INT
1.0L //long double

"foo bar"s // a literal of type std::string 
123_km // a literal of Distance


void x;// error: there are no void objects
void& r;// error: there are no reference to void
void f();// function:f does not return a value
void* pv;//pointer to object of unknown type

1 == sizeof(char) <= sizeof(short)<= sizeof(int)<= sizeof(long)<= sizeof(long long)
1 <= sizeof(bool) <= sizeof(long)

sizeof(float)<=sizeof(double)<=sizeof(long double)

sizeof(N) == sizeof(signed N) == sizeof(unsigned N) //N can be char ,short ,int, long, or long long.



#include<limits>
#include<iostream>

int
main()
{
	cout<<"size of long" << sizeof(1L)<<'\n';
	cout<<"size of long long" << sizeof(1LL)<<'\n';

	cout<<"largest float == "<<std::numeric_limits<float>::max()<<'\n';
	
cout<<"char is signed == "<<std::numeric_limits<char>::is_signed()<<'\n';

	
}


int16_t  x {0xaabb};// 2 bytes
int64_t xxxx {0xaaaabbbbccccdddd};//8 bytes
int_least16_t y;// at least 2 bytes(just like int)
int_least32_t yy;// at least 4 bytes(just like long)
int_fast32_t z;// the fastest int type with at least 4 bytes


void* allocate(size_t n);// get n bytes

auto ac = alignof('c'); // the alignment of a char
auto ai = alignof(1); //  the alignment of an int
auto ad = alignof(2.0); // the alignment of a double


int a[20];
auto aa = alignof(a);// the alignment of an int



void
user(const vector<X>&  vx)
{

	constexpr int bufmax = 1024;
	alignas(X) buffer[bufmax];// uninitialized

	const int max = min(vx.size(),bufmax/sizeof(X));

	uninitialized_copy(vx.begin(),vx.begin()+max,buffer);
	//..
}



char ch;
string s;
auto count = 1;
const double pi {3.14};
extern int error_number;


const char*  name = "Njal";
const char* season[] = {"spring","summer","fall","winter"};

vector<string>  people {name,"SPppppp","Gunar"};

struct Date {int d,m,y;};
int day(Date* p) {return p->d;}


double sqrt(double);

template<class T> 
T abs(T a) 
{
	return a < 0?-a:a;
}



constexpr int 
fac(int n) 
{
	return (n<2)?1:n*fac(n-1);
}// possible compile-time evaluation



constexpr double zz { ii*fac(7) };// compile-time initialization

using Cmplx = std::complex<double>;// type alias
struct User;// type name
enum class Beer {Car,Tru,THor};

namespace NS
{
	int a;	
}



// assume that these declarations are in the global scope,we have
char ch; // set aside memory for a char and initialize it to 0

auto count = 1;// set aside memory for an int and initialize it to 1
const char* name = "Njal";// set aside memory for a pointer to char

// set aside memory for a string literal "Njal"
// initialize the pointer with the address of that string literal

struct Date {int d,m,y;}; // Date is a struct with three members
const double pi {3.1415};

int
day(Date* p)
{
	return p->d; 
}

using Point= std::complex<short>;// Point is a name for std::complex<short>


double sqrt(double) ;//function declaration
extern int error_number;// variable  declaration
struct User; //	type name declaration



double sqrt(double d) { /*...*/ }

 int error_number = 1;
struct User {/*...*/ }; 


int count;
int count;// error:redefinition

extern int error_number;
extern short error_number;//error:type mismatch


extern int error_number;
extern int error_number;//ok:redeclaration


void 
f()
{
	int count {1}; // initialize count to 1
	const char* name {"bjir"};// name is a variable that points to a constant

	count = 2;// assign 2 to count
	name = "Marian";
	

}


// of the definitions, only two do not specific values.

char ch;
string s;


const char* kings[] = {"Antigonus","Swel","Ptolme"};

const c = 7;//error:no type

gt(int a ,int b)//error:no return type
{
	return (a>b)?a:b;
}


unsigned ui;//ok
long li;// ok

int x,y//int x,int y;

int*p ,y;// int *p,int y;not int* y;

int x ,*q;// int x,int *q;

int v[10],*pv;// int v[10], int *pv;


int x;//global x
void
f()
{
	int x;// local x hides global x 
	x = 1;// assign to local x
	{
		int x;// hides first local x
		x = 2;// assign to second local x

	}
	x = 3;// assign to first local x
}


int* p = &x;// take address of global x











int x;
void f2()
{
	int x = 1;// hide global x
	::x = 2;// assign to global x
	x = 2;// assign to local x
}


int x = 97;
void
f3()
{
	int x = x;// perverse:initialize x with it own(uninitialize )value	
}



int x = 11;
void
f4()
{
	int y = x; // use global x: y = 11
	int x = 22;
	y = x;//use local x:y = 22
}// such subtleties are best avoided




void
f5(int x)
{
	int x; //error
}// The names of function arguments are considered declared in the outermost block of
	// a function.


void
f(vector<string>& v,list<int>& lst)
{
	for(const auto& x:v) cout<<x<<endl;
	for(auto x:lst) cout<<x<<endl;
	for(int i = 0; i != v.size();++i) cout<< v[i]<<endl;
	for(auto i:{1,2,3,4}) cout<<i<<endl;
}




X a1 {v};
X a2 =  {v};
X a3  = v;
X a4(v);
// of these,only the first can be used in every context.
// Old habits die hard. so I sometimes use = when initializing a simple 
// variable with a simple value.

int x1 = 0;
char c1 = 'z';

//Initialization using {}, list initialization, does not allow narrowing.
// That is:
//1) An integer  cannot be converted to another integer that cannot hold 
// its value.For example,char to int is allowed,but not int to char.
//2) A floating-point value cannot be  converted to another floating-point type
// that cannot hold its value.For example, float to double is allowed,but not
// double to float
// 3)An integer vlaue cannot be converted to a  floating-point type.


void
f(double val,int val2)
{
	int x2 = val; // if val == 7.9,x2 becomes 7

	char c2 = val2;// if val2 == 1025,c2 becomes 1
	
	int x3 {val};// error:possible truncation
	char c3 {val2};// error:possible narrowing

	char c4 {24};// OK: 24 can be represented exactly as a char
	char c5 {264};// error(assumeing 8-bit chars):cannot be represented as a char
	
	int x4 {2.0};// error:no double to int value conversion

	//...
} 

auto z1 {99};// z1 is an initializer_list<int>
auto z2 = 99;// z2 is an int
//看到差别了吧!
// so prefer = when using auto


vector<int> v1 {99};// v1 is a vector of 1 element with the value 99
vector<int> v2(99);// v2 is a vector of 99 elements each with the default value 0

vector<string> v1{"hello!"};// v1 is a vector of 1 element with the value "hello!"
vector<string> v2("hello!");// error:no vector constructor takes a string literal

// the empty initializer list,{},is used to indicate that a default vlaue is desired.
//
int x4 {};// x4 becomes 0
double d4 {};// d4 becomes 0.0
char* p {};// p becomes nullptr
vector<int> v4{};//v4 becomes the empty vector
string s4{};// s4 becomes ""


if no initializer is specified, a global,namespace,local static,or static 
member(collectively called static objects) is initialized to {} of the
appropriate type.


int a;// means "int a{};"so that a becomes 0

double d;// means "double d{};",so that d becomes 0.0


free store: 堆区

void
f()
{
	int x;// x does not have a well-defined value
	char buf[1024];// buf[i] does not have a well-defined value


	int* p{new int};// *p does not have a well-defined value
	char* q {new char[1024]};//q[i]does not have a well-defined value
	
	string s; // s == "" because of string's default constructor
	vector<char> v; // v == {} because of vector's default constructor


	string* ps {new string}; //*ps is "" because of string's default constructor

	//看到没有 可以 *string对象


 	

}
// if you want initialization of local variable of bulit-in type or objects of 
// built-in type created with new,use{}.

void
ff()
{
	int x {};// x becomes 0
	char buf[1024]{};  //buf[i] becomes 0 for all i


	int * p {new int{10}};// *p becomes 10
	char* q {new char[1024]{}};// q[i] becomes 0 for all i
	
}


//in some cases, function-style argument lists can be used 

// for example:
complex<double> z(0,pi);// use constructor
vector<double> v(10,3,3);// use constructor:v gets 10 element initialized to 3.3



complex<double> z1(1,2);//function-style initializer(initialization by construcor)
complex<double>  f1();// function declaration


complex<double> z2 {1,2};// initialization by constructor to {1,2}

complex<double> f2 {};// initialization by constructor to the default value {0,0}



auto x1 {1,2,3,4};// x1 is an initializer_list<int>
auto x2 {1.0,2.25,3.5};// x2 is an initializer_list of<double>


auto x3 {1.0,2};// error:cannot deduce the type of {1.0,2}


int a1= 123;
char a2 = 123;
auto a3 = 123;// the type of a3 is "int"

template<class T> 
void f1(vector<T>& arg)
{
	for(vector<T>::iterator p = arg.begin();p != arg.end;++p)
		*p = 7;

	for(auto p = arg.begin();p != arg.end();++p)
		*p = 7;
}

// The loop using auto is the more convenient to write and the easier to read.


void
f(double d)
{
	constexpr auto max = d+7;
	int a[max];// error: array bound not an integer
	//
}

void 
f(vector<int>& v)
{
	for(const auto& x:v){ // x is a const int&
		///..
	}
}
// Note that the type of an expression is never a reference because references
// are implicitly dereferenced in expressions.

void
g(int& v)
{
	auto x = v;// x is an int(not an int&)
	auto& y = v; // y is an int&
}



char v1 = 123456;// 123456 is an int
int v2 = 'c';// 'c' is a char

T v3 = f();

char v1 {12345};// error:narrowing
int v2 {'c'};//fine:implicit char ->int conversion
T v3 {f()}; // works iff the type of f() can be implicitly converted to a T


auto v1 = 12345;// v1 is an int
auto v2 = 'c';// v2 is a char
auto v3  = f();// v3  is of some appropriate type

auto v1 {12345};// v1 is a list of int
auto v2 {'c'}; // v2 is a list of char
auto v3 {f()};// v3 is a list of  some appropriate type



auto x0 {};// error:cannot deduce a type
auto x1 {1};// list of int with one element
auto x2 {1,2};//  list of int with two elements
auto x3 {1,2,3}; // list of int with three elements


//the type of a homogeneous list of elements of type T is taken to be of type 
// initializer_list<T>


template<class T, class U>
auto operator+(const Matrix<T>& a,const Matrix<U>& b)->Matrix<decltype(T{}+U{})>;





template<class T, class U>
auto operator+(const Matrix<T>& a,const Matrix<U>& b)->Matrix<decltype(T{}+U{})>
{
	Matrix<decltype(T{}+U{})> res;
	for(int i = 0; i != a.rows();++i)
		for(int j = 0;j != a.cols();++j)
			res(i,j) += a(i,j)+b(i,j);
	return res;
}




// an object is contiguous region of storage.

//lvalue can refer to a constant

// using "m" for movable,and "i" for has identity



prvalue "pure rvalue"
glvalue "generalized lvalue"

xvalue "x" for "extraordinary" or "expert only"


void
f(vector<string>& vs)
{
	vector<string>& v2 = std::move(vs);//move vs to v2
}



// Type aliases
using Pchar = char*;// Pointer to character
using PF= int(*)(double); // pointer to function taking a double and returning an int


// similar types can define the same name as a member alias:

template<class T>
class vector{
	using value_type = T;// every container has a value_type
	//...
};



template<class T>
class list{
	using value_type = T;// every container has a value_type
	//...
};

Pchar p1 = nullptr;// p1 is a char*
char* p3 = p1;// fine





typedef int int32_t; // equivalent to "using  int32_t = int;"

typedef short int16_t;// // equivalent to "using  int16_t = short;"

typedef void (*PtoF)(int);// equivalent to "using  PtoF = void (*)(int);"




using int32_t = long;

// The "_t" suffix is conventional for aliases("typedefs")


template<typename T>
	using Vector = std::vector<T,My_allocator<T>>;

// we cannot apply type specifiers,such as unsigned , to an alias.
using Char = char;
using Uchar = unsigned Char;// error
using Uchar = unsigned char;// ok






















