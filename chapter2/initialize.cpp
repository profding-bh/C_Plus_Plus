#include<iostream>
#include<complex>
#include<vector>
#include<cmath>

using namespace std;


double d1 = 2.3;

//  这种初始化方式第一次见.
double d2 {2.3}; // a univeral form based on curly-brace-delimited

// initialize.cpp:10:11: warning: extended initializer lists only
//  available with -std=c++11 or -std=gnu++11
//  double d2 {2.3}; // a univeral form based on curly-brace-delimited

// $(CC) initialize.cpp  -std=c++11 -o initialize

// $(CC) initialize.cpp  -std=gnu++11 -o initialize


//curly brace  花括号，大括号

// must #include<complex>
complex<double> z=1;
//complex<double> a = {1,2}; // the = is optional with {...}
complex<double> a1 {d1,d2};


// must #include<vector>
vector<int> v {1,2,3,4,5,6}; // a vector of ints


int i1 = 7.2; // i1 becomes 7
//int i2 {7.2}; //
//int i3 =  {7.2};// the = is redundant

/*

1) A constant cannot be left uninitialized and a variable should noly be
left uninitialized extremely rare circumstances.

2) Don't introduce a name until you have a suitable value for it.

3)  When defining a variable, you don't actually need to state its type
explicitly when it can be deduced from the initializer:

auto b = true; // a bool
auto ch = 'x'; // a char
auto i = 123; // an int
auto d = 1.2; // a double
auto z = sqrt(y);// z has the type of whatever sqrt(y) returns

With auto,we use the = syntax because there is no type conversion
involved  that might cause problems.




C++ supports two notions of immutability:

<1>const: meaning roughly "I promise not to change this value".
This is used primarily to specify interfaces,so that data can be passed to
functions without fear of it being modified.


<2>constexpr: meaning roughly "to be evaluated at compile time".This is
used primarily to specify constants, to allow placement of data in memory
where it is unlikely to be corrupted, for performance.


e.g.:
*/

#if 0
const int dmv = 17;
int var = 12;


constexpr double square(double x) { return x*x; }

// To be constexpr, a function must be rather simple: just a return-statement
// a value.



constexpr double max1 = 1.4 * square(dmv);

// error: the value of ‘var’ is not usable in a constant expression
// constexpr double max2 = 1.4 * square(var);

const double max3 = 1.4 * square(var);

// undefined reference to `sum(std::vector<double, std::allocator<double> > const&)'
// error: ld returned 1 exit status,链接出错！
// 相信你知道原因。
double sum(const vector<double>& );

vector<double> v1 {1.1,2.2,3.3,4.4,5.5,6.6};

const double s1 = sum(v1);

//error: call to non-constexpr function ‘double sum(const std::vector<double>&)’
//constexpr double s2 = sum(v1);



#endif

#if 1

/*
bool accept(){

	cout<< "Do you want to proceed(y or n)?\n";

	char answer = 0;
	cin>>answer;

	if(answer == 'y') return true;
	return false;
}

bool accept2(){

	cout<< "Do you want to proceed(y or n)?\n";
	char answer = 0;
	cin>>answer;
	switch(answer){
		case 'y':
		return true;
		case 'n':
		return false;
		default: // 非法字符也是false
		 	cout<<"I'll take that for a no.\n";
			return false;
	}
}
*/

bool accept3(){

	int tries = 1;
	while(tries < 4){
		cout<< "Do you want to proceed(y or n)?\n";
		char answer = 0;
		cin>>answer;
		switch(answer){
			case 'y':
			return true;
			case 'n':
			return false;
			default: // 非法字符继续
		 		cout<<"Sorry,I don't understand that.\n";
				++tries;
		}
	}
	// 用户输入错误，超过3次(含3次)，直接返回。
	cout<<"I'll take that for a no.\n";
	return false;
}

int count_x(char *p,char x)
{
	if(p==nullptr) return 0;
	int count = 0;
/*
Q:难道*p != 0 可以自动将整数0，转换成，空字符 ，然后进行比较？？？？
	for(; *p != 0; ++p){ // *p!='\0';
		if(*p == x){
			++count;
		}
	}
*/
	// my method
	for(; *p!='\0'; ++p){ // *p!='\0';
		if(*p == x){
			++count;
		}
	}
	return count;
}


void print()
{
	int v[] = {0,1,2,3,4,5,6,7,8,9};

	// "for every element of v,from the first to the last,place
	//a copy in x and print it ."
	for(auto x:v){
		cout << x <<endl;
	}

	for(auto x:{10,22,33}){
		cout<<x<<endl;
	}
}

void increment()
{
	int v[] = {0,1,2,3,4,5,6,7,8,9};

	// not copy the values from v into variable x,but rather just have x
	// refer to an element.
	for(auto& x:v){
		++x;
	}

	for(auto x:v){
		cout << x <<endl;
	}
}

/*


In a declaration,the unary suffix & means "reference to".

A reference is similar to a pointer,except that you don't need to use a
prefix * to access the value referred to by the reference.

Also, a reference cannot be made to refer to a different object after its

initialization. when used in declarations,operators,such as (&,*,[]),
are called declarator
operators.



T a[n]; // T[n] :array of n Ts,?a[n]

T* p; // T*: pointer to T
T& r: // T&: reference to T.


In older code,0 or NULL is typically used instead of nullptr.

However,using nullptr eliminates potential confusion between integers(
such as 0 or NULL) and pointers.



*/
#endif

int
main()
{
#if 0
	char ch[]="ax_x";
	cout<< count_x(ch,'x') <<endl;
#endif
//	accept3();


//	print();
	increment();
	return 0;
}
