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















