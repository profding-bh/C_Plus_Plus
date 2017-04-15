#include<iostream>
using namespace std;


#define MAX_SIZE 10

int
main()
{
//a*b=c
	int a[MAX_SIZE][MAX_SIZE],b[MAX_SIZE][MAX_SIZE],c[MAX_SIZE][MAX_SIZE];
	
	int i,j,k,numofrowa,numofcola,numofcolb;
	
	cout<<"Please input numofrowa,numofcola,numofcolb";
	cin>>numofrowa>>numofcola>>numofcolb;
	
	
	cout<<"input a:\n";
	
	for(i=0;i<numofrowa;++i)//a的行数
	{
		for(j=0;j<numofcola;++j)//a的列数
		{
			cout<<"a["<<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
		}
	}
	
	cout<<"input b:\n";
	
	for(i=0;i<numofcola;++i)//b的行数
	{
		for(j=0;j<numofcolb;++j)// b的列数
		{
			cout<<"b["<<i<<"]["<<j<<"] = ";
			cin>>b[i][j];
		}
	}
	
	
	
	for(i=0;i<numofcola;++i) //a的行数
	{
		for(j=0;j<numofcolb;++j)// b的列数
		{
			c[i][j] = 0;
			for(k=0;k<numofcola;++k) //a的列数
			{
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	
	
	cout<<"output c:\n";
	for(i=0;i<numofcola;++i)
	{
		for(j=0;j<numofcolb;++j)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	return 0;
}


