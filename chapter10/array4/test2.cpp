#include<iostream>
#include"createanddestroy.h"
using namespace std;

// 跟声明顺序有关
static createanddestroy global2(100);

createanddestroy global(0);



void f1()
{
	cout<<"func f1"<<endl;
	static createanddestroy obj1(1);
	createanddestroy obj(2);
}

int
main()
{
	createanddestroy obj4(4);
	f1();
	f1();
	return 0;
}

