#include<iostream>
using namespace std;
#include"createanddestroy.h"

createanddestroy::createanddestroy(int n)
{
objectid= n;
cout<<"构造对象 "<<objectid<<endl;
}
createanddestroy::~createanddestroy()
{
cout<<"析构对象 "<<objectid<<endl;
}





