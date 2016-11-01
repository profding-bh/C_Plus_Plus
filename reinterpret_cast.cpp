#include<iostream>
#include<stdio.h>
using namespace std;


//namespace Mine{

class A{
public:
int m_a;
};
class B{
public:
int m_b;
};

class C: public A,public B{
};


//}

//using my = Mine;

int 
main()
{
C c;
printf("%p %p %p\n",&c,reinterpret_cast<B*>(&c),static_cast<B*>(&c));
printf("%p %p \n",(&c.m_a),(&c.m_b));
printf("%p %p %p\n",A,B,C);
return 0;
}



