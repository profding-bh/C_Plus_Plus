#include<iostream>
using namespace std;

class A  
{  
private:  
    void* operator new(size_t t){}     // 注意函数的第一个参数和返回值都是固定的  
    void operator delete(void* ptr){} // 重载了new就需要重载delete  
public:  
    A(){}  
    ~A(){}  
	void hello() {cout<<"hello"<<endl;}
};



int
main()
{
//	A* ptr = new A;
	
	A a;
	a.hello();
	
	return 0;
}
