#include<iostream>
using namespace std;


class A
{
public:
	int b;
};


int x;

int 
main()
{
// How to reference to A ?
//1)plus scope resolution operator ::
	::A a;// 说明默认全局作用域可以这样引用。
	a.b = 3;
	cout<<a.b<<endl;


//2)
	A b;
	b.b = 45;
	cout<<b.b<<endl;

int x;
	::x = 3;
	x = 1;
{
	int x = 2;
	cout<<x<<endl;// There is no way to use a hidden local name ,e.g.:x
}
	cout<<x<<' ' << ::x<<endl;

	return 0;


	
}
