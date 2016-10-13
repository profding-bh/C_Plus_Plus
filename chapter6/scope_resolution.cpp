#include<iostream>
using namespace std;


class A
{
public:
	int b;
};

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
	return 0;
}
