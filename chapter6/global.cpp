#include<iostream>
#include<vector> // 数组
using namespace std;

void f();





int
main()
{

extern int x;
	f();
	
	cout<<"in main():x = "<<x<<endl;
	return 0;
}

int x;

void f()
{
	cout<<"in f():x = "<<x<<endl;
}




