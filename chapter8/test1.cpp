#include<iostream>
using namespace std;



enum class Warning:char{green,yellow,orange,red};// sizeof(Warning) == 1

void
f(Warning key)
{
	switch(key){
		case Warning::green: // do something 
		break;
		// case Warning::yellow: // do something 
		// break;
		case Warning::orange: // do something 
		break;
		case Warning::red: // do something 
		break;
	}
}



//enum  Traffic_light {red,yellow,green};
enum  Warning2  {green,yellow,orange,red};// fire alert levels

 // error: redeclaration of ‘green’
//  error: redeclaration of ‘yellow’
//  error: redeclaration of ‘red’
int
main()
{
	Warning key = Warning::green;
	f(key);


	Warning2 a1 = 7;// error: invalid conversion from ‘int’ to ‘Warning2’
	return 0;
}
