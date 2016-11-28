#include<iostream>
using namespace std;


void
f4()
{

	int a = 1;
	const int c = 2;
	const int* p1 = &c; // ok
	const int* p2 = &a; // ok
	
	int* p3 = &c;//error: initialization of int* with const int*
	*p3 = 7;// try to change the value of c
}

int
main()
{
	
	f4();
	return 0;
}
