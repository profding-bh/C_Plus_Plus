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
}//如果有else分支的话,else分支同样适用于d.其实向这样的做法,你以前从来没有试过吧了.

The scope of d extends from its point of declaration to the end of the statement

that the condition controls.For example,Had there been an else-branch to the if-statement,
d would be in scope on both branches.



The  obvious and traditional alternatives is to declare d before the condition,
However,this opens the scope(literally) for the use of d before its initialization 
or after its intended useful life:

double d;
//...
d2 = d; // oops!

//...
if(double d = prim(true)){
	left /= d;
	break;
}
//...
d = 2.0f;// two unrelated uses of d

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

	int a = 12;
    if(int b = a){
		cout<<b<<endl;
	}else
		{
		cout<<b<<endl;
	}
	return 0;
}

/*
In addition to the logical benefits of declaring variables in conditions,doing 
so also yields the most compact source code.

A declaration in a condition must declare and initialize a single variable or const.

*/

/*

if something can be stated in the language itself, if should be,and not just 
mentioned in a comment.

once something has been stated in the language itself,it should not be mentioned

in a comment.

a = b +c;//a becomes b+c
count++;//increment the counter


a well-chosen and well-written set of comments is  an essential part of 
a good program.

writing good comments can be as difficult as writing the program itself.

it is an art well worth cultivating.

1)don't declare a variable until you have a value to initialize it with.
2)perfer a switch-statement to an if-statement when there is a choice.
3)perfer a range-for-statement to a for-statment wheen there is a choice.
4)perfer a for-statement to a while-statement  when there is an obvious loop variable.
5)perfer a while-statement to a for-statement when there is no obvious loop variable.
6) avoid do-statement.
7)avoid goto(not yet)
8)keep comments crisp
9)don't say in comments what can be clearly stated in code.
10）state intent in comments
11)maintain a consistent indentation style.

*/



