#include<iostream>
#include<vector> // 数组

using namespace std;


int  p(int  n)
{
	int a = 1;
	if(n<0) return 0;
	for(int i = 1;i<=n;++i) a *= i;
	
		return a;
}




int getInput()
{
int num;
while(true){
cin>>num;
if(num >=1 && num<=10) return num; 
}



}

void printstarN(int N)
{	
	int i,j,k;
	for(i=1;i<=N;++i)
	{
		for(j=1;j<=N-i;++j)
		{
			cout<<" ";//N-i
		}
		
		for(k=1;k<=2*i-1;++k)
		{
			cout<<"*";
		}
		cout<<endl;
	}
}



int
main()
{
	//printstarN(6);
	// cout<<getInput();
	return 0;
}
