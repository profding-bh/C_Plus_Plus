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











