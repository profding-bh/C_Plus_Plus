char c = 'a';
char* p = &c;//  p hold the address of c; & is the address-of operator



char c = 'a';
char* p = &c;//  p hold the address of c; & is the address-of operator
char c2 = *p;// c2 == 'a', * is the dereference operator



int* pi; // pointer to int 

char** ppc; // pointer to pointer to char
int* ap[15]; // array of 15 pointers to ints
int (*fp)(char*);// pointer to function taking a char* argument; returns an int

int* f(char* );// function taking a char* argument;returns a pointer to int



void
f(int* pi)
{
	void* pv = pi;// ok: implicit conversion of int* to void*
	*pv; // error:can't dereference void*

	++pv;// error:can't increment void*(the size of the object pointed to is unknown)


	int* pi2 = static_cast<int*>(pv); // explicit conversion back to int*

	double* pd1 = pv; // error
	double* pd2 = pi; //error
	double* pd3 = static_cast<double*>(pv); // unsafe
}



void* my_alloc(size_t n);// allocate n bytes from my special heap


int* pi = nullptr;
double* pd = nullptr;
int i = nullptr; // error:i is not a pointer


int* x = 0; // x gets the value nullptr

int* p = NULL; // using the macro NULL

// However, there are differences in the definition of NULL in different 
// implementations;for example,NULL might be 0 or 0L. In C, NULL is typically
// (void*)0,which makes it illegal in C++.


int* p = NULL;// error:can't not assign a void* to an int*

// For a type T,T[size] is the type "array of size elements of type T."

float v[3]; // an array of three floats:v[0],v[1],v[2]
char* a[32]; // an array of 32 pointers to char:a[0],...,a[31]



void
f()
{
	int aa[10];
	aa[6] = 9;// assign to aa's 7th element
	int x = aa[99];// undefined behavior
	
}
// access out of the range of an array is undefined and usually disastrous.
// In particular,run-time range checking  is neither guaranteed nor common


void
f(int n)
{
	int v1[n];// error: array size not a constant expression
	vector<int> v2(n);// ok:vector with n int elements
}

//an array can be allocated statically, on the stack, and on the free store.
int a1[10]; // 10 ints in static storage


void
f()
{
	int a2[20]; // 20 ints on the stack
	int* p = new int[40]; // 40 ints on the free store
}

// There is no array assignment 

int v1[] = {1,2,3,4};
char v2[] = {'a','b','c',0};


char v3[2] = {'a','b',0}; // error:too many initializers
char v4[3] = {'a','b',0}; // ok



int v5[8] = {1,2,3,4};
<==>
int v5[] =  {1,2,3,4,0,0,0,0};


// There is no built-in copy operation for arrays. You cannot 
// initialize one array with another (not even of exactly the same type),
// and there is no array assignment:
int v6[8] = v5;//error; can't copy an array(cannot assign an int* to an array)
(vector可以)


v6= v5;// error: no array assignment


"this is a string"

sizeof("Bohr") == 5


void
f()
{
	char* p= "Plato";// error: but accepted in pre-C++-standard code
	p[4] = 'e'; // error: assignment to const
}

void
f()
{

	char p[] = "Zeno"; // p is an array of 5 char
	p[0] = 'R';// OK
}


const char* error_message(int i)
{
	//...
	return "range error";
}


const char* p = "Heraclitus";
const char* q = "Heraclitus";

void
g()
{
	if(p == q) cout<<"one!\n";// the result is implementation-defined
//..
}


cout<<"beep at end of message\a\n";




"this is not a string"
"but a syntax error"



char alpha[]="abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";//ok!
//the compiler will concatenate adjacent strings.so alpha
/*
could  equivalently have been initialized by the single string.

"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

*/


/*
Larger  Character sets

A string with the prefix L, such as L"angst",is 

a string of wide  characters. Its type is 
const wchar_t[];


similarity, a string with the prefix LR,such as LR"(ANGST)",
is a raw string of wide characters of type const wchar_t[].
such a string is terminated by a L"\0" character.


6种
UTF-8,UTF-16,UTF-32.

Essentially all Internet applications(e.g.: browsers & email)
rely on one or more of these encodings.

UTF-8: is a variable-width encoding: common characters fit into 
1 byte, less frequently used characters into 2 bytes,
and rarer   characters into 3 or 4 bytes.

In particular,the ASCII characters fit into 1 byte with the same 

encodings(integer values) in UTF-8 as in ASCII

a UTF-8  string is terminated by '\0', a UTF-16 string by 
u'\0', and a UTF-32 string by U'\0'.


"folder\\file" // implementation character set string
R"(folder\\file)"  // implementation character set raw string


u8"folder\\file" // UTF-8  string

u8R"(folder\\file)" // UTF-8  raw string

u"folder\\file" // UTF-16 string
uR"(folder\\file)" // UTF-16 raw string



U"folder\\file" // UTF-32 string
UR"(folder\\file)" // UTF-32 raw string


u8"The official vowels in Danish are:a,e,i,o,u,\u00E6,\u00F8,\u00E5 and y."


*/


/*
Pointers into Arrays:

int v[] = {1,2,3,4 };

int* p1 = v;// pointer to initial element(implicit conversion)
int* p2 = &v[0];//  pointer to initial element

int* p3 = v+4; // pointer to one-beyond-last element,最后一个元素的后面一个元素。

The result of taking the address of the element before the
initial element or beyond  one-past-the-last element is undefined.

and should be avoided.

for example:

int* p4 = v - 1;// before the beginning, undefined: don't do it.
int* p5 = v + 7; //beyond the end,undefined: don't do it.



extern "C" int strlen(const char* ) ;// from<string.h>


void
f()
{
	char v[] = "Annemarie";
	char* p = v;// implicit conversion of char[] to char*
	strlen(p);
	strlen(v);// implicit conversion of char[] to char*

	v = p;// error:cannot assign to array
}

There is no implicit or explicit conversion from  a pointer to an array.

The implicit conversion of the array argument to a pointer means that the 
size of the array is lost to the called function.




*/


/*

Navigating Arrays:


*/
void
fi(char v[])
{
	for(int i = 0;v[i] != 0; ++i)
		use(v[i]);
}


void
fp(char v[])
{
	for(char* p = v;*p != 0; ++p)
		use(*p);
}


//对于一维数组a[]

a[j] == *(&a[0]+j) == *(a+j) == *(j+a) == j[a]



// It usually surprises people to find that a[j] == j[a]

template<typename T>
int byte_diff(T* p,T*q)
{
	// reinterpret_cast:把指针转化为整数。
	return reinterpret_cast<char*>(q)-reinterpret_cast<char*>(p);
}


void
diff_test()
{
	int vi[10];
	short vs[10];
	cout<< vi <<' '<<&vi[1]<<' '<<&vi[1]-&vi[0]<<' '<<byte_diff(&vi[0],&vi[1])<<endl;
	cout<< vs <<' '<<&vs[1]<<' '<<&vs[1]-&vs[0]<<' '<<byte_diff(&vs[0],&vs[1])<<endl;
}


void
f()
{
 	int v1[10];
	int v2[10];

	int i1 = &v1[5] - &v1[3];// i1 = 2
	int i2 = &v1[5] - &v2[3];//result undefined


	int* p1 = v2+2;// p1 = &v2[2];
	int* p2 = v2-2;// *p2 undefined
}





/*
Multidimensional Arrays:



*/


int ma[3][5]; // 3 arrays with 5 ints each

void
init_ma()
{
	for(int i = 0;i != 3;++i)
		for(int j = 0;j != 5;++j)
			ma[i][j] = 10 *i+j;
}

void
print_ma()
{
	for(int i = 0;i != 3;++i){
		for(int j = 0;j != 5;++j)
			cout<<ma[i][j] <<'\t';
		cout<<'\n';
	}
}


int bads[3,5];// error:comma not allowed in constant expression



/*

C++ offers two related meanings of "constant";
1) constexpr: Evaluate at compile time;
2) const: Do not modify in this scope.

constexpr's role is to enable and ensure compile-time evaluation,

whereas const's primary role is to specify immutability in interfaces.

Many objects don't have their values changed after initialization:

1)symbolic constants lead to more maintainable code than using literals directly in code.
2)Many pointers are often read through but never written through.
3) Most function parameters are read but not written to.


*/
const int model = 90; // model is a const
const int v[] ={1,2,3,4};// v[i] is a const
const int x; // error: no initializer
// Because an object declared cannot be assigned to,it must be initialized.


void
f()
{
	model = 200;//error
	v[2] = 3;//error
}


void
g(const X* p)// p是可变的,*p不可以变
{
	// can't modify *p here
}


void
h()
{
	X val; // val can be modified here.
	g(&val);
//..
}


/*
When using a pointer, two objects are  involved:the pointer itself and
the object pointed to.


"Prefixing" a declaration of a pointer with const makes the object,but not the pointer,a constant.
e.g.:
const X* p;// *p is a constant


To declare a pointer itself,rather than the object pointed to,to be a constant,
we use the declarator operator *const instead of plain *.
e.g.:
X *const p; // p is a constant

*/


void
f1(char* p)
{
	char s[] = "Gorm";
	
	const char* pc = s; // pointer to constant
	pc[3] = 'g';// error: pc pointers to constant
	pc = p;//ok

	char *const cp = s; //constant pointer
	cp[3] = 'a'; //ok
	cp = p;//error:cp is constant


	const char *const cpc = s;// constant pointer to const
	cpc[3] = 'a'; //error: cpc  points to constant
	cpc = p;// error:cpc is constant
}

/*
the declarator operator that makes a pointer constant is *const.

There is no const* declarator operator, so a const  appearing before the *
is taken to be part of the base type.

char *const cp; // const pointer to char
char const* pc; // pointer to const char
const char* pc2 // pointer to const char
*/

const char* strchr(const char*p, char c); // find first occurrence of c in p
char* strchr(char* p, char c); 		//	find first occurrence of c in p

void
f4()
{

	int a = 1;
	const int c = 2;
	const int* p1 = &c; // ok
	const int* p2 = &a; // ok
	
	int* p3 = &c;//error: initialization of int* with const int*
	*p3 = 7;// try to change the value of c
}


/*
Pointers and Ownership:
*/
/*
It is usually a good idea  to immediately place a pointer that represents ownership in 
a resource handle class,such as vector,string,and unique_ptr.That way,
we can assume that every pointer that is not within a resource handle is not an owner 
and must not be deleted.
*/

void 
confused(int* p)
{
//	delete p??
}

int global {7};

 
void
f()
{
	X* pn = new int{7};
	int i {7};
	
	int q = &i;
	confused(pn);
	confused(q);
	confused(&global);
}

//Like a pointer, a reference is an alias for an object.

template<class T>
class vector{
	T* elem;
	//...
	public:
	T& operator[](int i){return elem[i];} // return reference to element
	const T& operator[](int i) const {return elem[i];}  // return reference to const element 

	void push_back(const T& a);// pass element to be added by reference
//...
};


void
f(const vector<double>& v)
{
	double d1 = v[1]; // copy the value of the double referred to by v.operator[](1) into d1
	v[2] = 7;// place 7 in the double  referred to by the result of v.operator[](2) ???

	v.push_back(d1);// give push_back()	 a reference to d1 to work with
}

/*

to reflect the lvalue/rvalue and const/non-const distinctions, there are three kinds of references:

<1> lvalue references: to  refer to objects whose vlaue we want to  change
<2> const references:  to  refer to objects whose vlaue we do not want to  change(e.g.: a constant)
<3> rvalue references: to  refer to objects whose vlaue we do not need to perserve after we have used it(e.g.:a temporary)


collectively, they are  called references. The first two are both called  lvalue references.
*/


/*

In  a type name,the notation X&  means"reference to X"


*/

void
f()
{
	int var = 1;
	int& r {var}; // r and var now refer to the same int
	int x = r; // x becomes 1

	r = 2;// var becomes 2
}


int var = 1;
int& r1 {var};//ok:r1 intialized
int& r2;// error:initializer missing
extern int& r3;// ok:r3 initialized elsewhere


void
g()
{
	int var = 0;
	int& rr {var};
	++rr;// var is incremented to 1
	int* pp = &rr;//pp points to var
}

/* 
to get a pointer to the object denoted by a reference rr,
we can write &rr

we cannot define an array of references.In that sense, a reference is not an object.


*/


double& dr = 1;//error:lvalue needed ???

const double& cdr {1};//ok

double temp = double{1}; // first create a temporary with the right vlaue
const double& cdr {temp};// then use the temporary as the initializer for cdr


void
increment(int& aa)
{
	++aa;
}

void
f()
{
	int x = 1;
	increment(x);// x = 2
}



int next(int p){return p+1;}

void
g()
{
	int x = 1;
	increment(x);// x = 2
	x = next(x); // x= 3
}
template<class K,class V>
class Map{ // a simple map class
	public:
	V& operator[](const K& v);// return  the vlaue corresponding to the key v
	
	pair<K,V>* begin() {return &elem[0];}
	pair<K,V>* end() {return &elem[0]+elem.size();}// ??会不会相差一? 验证一下.
private:	
	vector<pair<K,V>> elem;//{key,value} pairs
}


/*
The standard-library map is typically implemented as a red-black tree.
*/

template<class K,class V>
V& Map<K,V>::operator[](const K& k)
{
	for(auto& x:elem)
		if(k == x.first)
			return x.second;
	elem.push_back({k,V{}});// add pair at end
	return elem.back().second;//return the (default) value of the new element
}


int 
main()
{
	Map<string,int> buf;
	
 
}




/*

1) A non-const lvalue reference refers to an object, to which the user of
the reference can write.

2) A const lvalue reference refers to a constant,which is immutable from
the point of view of the user of the reference.

3) An  rvalue reference refers to a temporary object,which the user of 
the  reference can (and typically will) modify,assuming that the object will
never be used again.





	An rvalue reference can  bind to an rvalue,but not to an lvalue.

	In that ,an rvalue reference is  exactly opposite to an lvalue reference.
	
*/


string var {"Cambridge"};
string f();
string& r1 {var}; //  lvalue reference,bind r1 to var(an lvalue)
string& r2 {f()}; // lvalue reference,error:f() is an rvalue
string& r3 {"Princeton"}; // lvalue reference,error:cannot bind to temporary

string&& rr1 {f()}; // rvalue reference,fine: bind rr1 to  rvalue(a temporary)
string&& rr2 {var}; //  rvalue reference,error: var is an lvalue.
string&& rr3 {"Oxford"}; // rr3 refers to a temporary holding "Oxford"


const string cr1& {"Harvard"}; // ok: make temporary and bind to cr1

The && declarator operator means "rvalue reference" 


// Both a const lvalue reference and an rvalue reference can bind to an rvalue.
string 
f(string&& s)
{
	if(s.size())
	 s[0] = toupper(s[0]);
	return s;
}


template<class T>
swap(T& a,T& b)// "old-style swap"
{
	T tmp {a};// now we have two copies of a
	a = b; // now we have two copies of b
	b = tmp;//now we have two copies of tmp(aka a)
}

template<class T>
void swap(T& a,T& b)// "perfect swap"(almost)
{
	T tmp {static_cast<T&&>(a)}; // the initialization may write to a
	a = static_cast<T&&>(b); // the assignment may  write to b
	b = static_cast<T&&>(tmp);// the assignment may  write to tmp
}

// the result value of static_cast<T&&>(x) is an rvalue of type T&& for x.



template<class T> class vector {
	//...
	vector(const vector& r);//copy constructor(copy r's representation)

	vector(vector&& r);// move constructor("steal"  representation from r)

};
vector<string> s;
vector<string> s2 {s}; // s is an lvalue,so use copy constructor
vector<string> s3 {s+"tail"};// s+"tail" is an rvalue so pick move constructor

// the standard library provides a move()function:
// move(x) means static_cast<X&&>(x) where X is the type of x.

template<class T>
void swap(T& a,T& b)// "perfect swap"(almost)
{
	T tmp {move(a)}; // move from a
	a = move(b); // move from b
	b = move(tmp);// move from tmp
}

void
f(vector<int>& v)
{
	swap(v,vector<int>{1,2,3});//repalace v's element with 1,2,3
}

template<class T> void swap(T&&a,T& b);
template<class T> void swap(T&a,T&& b);


void
f(string& s,vector<int>& v)
{
	s.shrink_to_fit();// make s.capacity() == s.size()
	swap(s,string{s}); // make s.capacity() == s.size()
 	v.clear(); // make v empty
	swap(v.vector<int>{}); // make v empty
	v={};//  // make v empty
}

// References to References
using rr_i = int&&;
using lr_i = int&;
using rr_rr_i = rr_i&&;// "int && &&" is an int&&
using lr_rr_i = rr_i&; // "int && &" is an int&
using rr_lr_i = lr_i&&;// "int & &&" is an int&
using lr_lr_i = lr_i&; // "int & &" is an int&

// lvalue reference always wins.
// reference collapse

// the syntax does not allow:
int&& & r = i;

void
fp(char* p)
{
	while(*p)
		cout<<++*p;
}

void
fr(char& r)
{
	while(r)
		cout<<++r;// oops:increments the char referred to,not the reference
// near-infinite loop!
}

void
fr2(char& r)
{
 char* p = &r;//get a pointer to the object referred to
 while(*p)
	cout<<++*p;
}

template<class T> class Proxy{
	T& m;
public:
	Proxy(T& mm):m{mm}{ }
	//...
};



template<class T> class Handle{ // Handle refers to its current object
	T* m;
public:
	Handle(T* mm):m{mm}{ }
	void rebind(T* mm){m = mm;}
	//...
};

Matrix operator+(const Matrix&,const Matrix&); // ok
Matrix operator-(const Matrix*,const Matrix*); // error: no user-defined type argument


Matrix y,z;
//...
Matrix x = y + z; // ok
Matrix x2 = &y - &z;// error and ugly

int x,y;
string& a1[] = {x,y};// error: array of references
string* a2[] = {&x,&y};//ok
vector<string&> s1 = {x,y};// error: vector of references
vector<string*> s2 = {&x,&y};// ok


void
fp(X* p)
{
	if(p == nullptr){
		// no value
	}else {
		// use *p
	}
}


void 
fr(X& r) // common style
{
	//assume  that r is valid and use it
}


void 
fr2(X& r) 
{

	if(&r == &nullX){
		// no value
	} else {
		// use r
	}
}

char* ident(char* p) {return p;}
char& r{*ident(nullptr)}; //invalid code









