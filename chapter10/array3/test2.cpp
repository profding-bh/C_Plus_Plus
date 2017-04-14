#include<iostream>
#include"rational.h"
using namespace std;


// 当把一个对象赋值给另一个对象时，所有的 数据成员都会 逐位复制。


/*
成员函数操作的数据成员是：本对象的数据成员。

由于所有该类对象中的成员函数代码是完全相同的，c++采用了
一个优化的手段。不管创建了多少个该类的对象，成员函数在内存中，只有一个副本。
所有对象共享这个副本。


定义一个对象时，系统只为 数据成员分配空间。


c++为每个成员函数设置了：一个隐藏的指向本类型的形参指针this.

this指针。


成员函数中，对  成员对象短访问是  通过this指针。

当通过，对象调用成员函数时，编译器会把 相应对象的地址传给形参this.


通常，在写成员函数时，可以省略this, 编译器会自动加上。

但是，如果在 成员函数中，要把对象作为整体，来访问时，必须显式调用this
aka:*this.

这种情况在，函数中 返回一个对调用函数的对象的引用时经常出现。


初始化，

类名(const 类名 &)s

*/


int
main()
{
	Rational r1,r2,r3;
	
	
	int n,d;
	cout<<"please input first rational number[num ,den]:";
	cin>>n>>d; 
	r1.create(n,d);
	r1.display();
	
	
	cout<<"please input second rational number[num ,den]:";
	cin>>n>>d;
	r2.create(n,d);
	r2.display();
	
	
	r3.add(r1,r2);
	r3.display();
	
	
	r3.multi(r1,r2);
	r3.display();
	
	return 0;
}

