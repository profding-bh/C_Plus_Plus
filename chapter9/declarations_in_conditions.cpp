#include<iostream>
using namespace std;


/*

To avoid accidental misuse of a variable,it is usually a good idea to 
introduce the variable into the smallest scope possible.

In particular,it is usually best to delay the definition of a local variable
until one can give it an initial value.

One of the most elegnant applications of  these two principles is to declare
a variable in a condition. Consider:


if(double d = prim(true)){
	left /= d;
	break;
}

The scope of d extends from its point of declaration to the end of the statement

that the condition controls.For example,Had there been an else-branch to the if-statement,
d would be in scope on both branches.

如下：
*/

int 
main()
{
	if(int a = 0){
		cout<<a<<endl;
	}else
		{
		cout<<a<<endl;
	}
	return 0;
}
