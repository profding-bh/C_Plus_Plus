#include<iostream>
using namespace std;

class A{
public:
 A(){}
 void destroy(){delete this;}
 void hello(){cout<<"hello"<<endl; } 
private:
 ~A();
};




int
main()
{
//	A a;	
	A* ptr = new A;
	ptr->hello();
//	(*ptr).destroy();
	
	return 0;
}
