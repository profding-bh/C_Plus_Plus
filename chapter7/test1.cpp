#include<iostream>
using namespace std;

const char* p = "Heraclitus";
const char* q = "Heraclitus";

void
g()
{
	if(p == q) 
		cout<<"one!\n";// the result is implementation-defined
    else  
		cout<<"two!\n";
}
/*

Note that == compares addresses(pointer values)when applied to pointers,
and not the values pointed to.

The empty string is written as a pair of adjacent double quotes,"",and
has the type const char[1]. The one character of the empty string is the
termination '\0';


*/

int
main()
{
	g();
	return 0;
}
