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





































