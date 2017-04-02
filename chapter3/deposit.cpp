#include<iostream>
#include<cmath>


using namespace std;

int
main()
{
	const double oneYearRate = 0.025,twoYearRate = 0.028;
	double balance,interest;

	int type,startDate,endDate;

	cout<<"请输入存款类型：（1：一年期 2：二年期）"	;
	cin>>type;

	cout<<"请输入存款金额：";
	cin>>balance;

	cout<<"请输入起始日期：";
	cin>>startDate;	
	
	cout<<"请输入终止日期：";
	cin>>endDate;	

	if(type == 1)
		interest = pow(1+oneYearRate,endDate-startDate)*balance-balance;
	else
		interest = pow(1+twoYearRate,endDate-startDate)*balance-balance;

	cout<<balance<<"元存"<<endDate-startDate<<"天共的利息"<<interest<<"元"<<endl;
	return 0;
}
