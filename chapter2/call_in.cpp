#include<iostream>
using namespace std;


double
square(double x)
{
	return x*x;
}

void 
printf_square(double x)
{
	cout<<"the square of "<< x << " is "<< square(x)<<"\n";
}



int
main()
{
	printf_square(1.1);
	return 0;
}
