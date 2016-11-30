#include<iostream>
using namespace std;


template<class T>
void swap_me(T& a,T& b)// "perfect swap"(almost)
{
	T tmp {static_cast<T&&>(a)}; // the initialization may write to a
	a = static_cast<T&&>(b); // the assignment may  write to b
	b = static_cast<T&&>(tmp);// the assignment may  write to tmp
}
// the result value of static_cast<T&&>(x) is an rvalue of type T&& for x.


int
main()
{
#if 0
	int a = 1,b = 2;
	cout<<a<<" "<<b<<endl;
	swap_me(a,b);
	cout<<a<<" "<<b<<endl;

#endif
	double a = 3.0,b = 2.0;
	cout<<a<<" "<<b<<endl;
	swap_me(a,b);
	cout<<a<<" "<<b<<endl;
	return 0;
}
