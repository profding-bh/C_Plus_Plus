#include<iostream>
#include<cmath>


using namespace std;

int
main()
{
	double a,b,c,x1,x2,dlt;

	cout<<"请输入方程的3个系数："<<endl;
	cin>>a>>b>>c;


	dlt = b*b-4*a*c;
	x1 = (-b+sqrt(dlt))/(2*a);
	x2 = (-b-sqrt(dlt))/(2*a);


	cout<<"x1= "<<x1<<" x2= "<<x2<<endl;
	return 0;
}
