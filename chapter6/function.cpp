#include<iostream>
#include<vector> // 数组
using namespace std;

int p(int);
int max(int a ,int b);



const double PI = 3.1415926;


// 静态局部变量
int f(int a);




int
main()
{
	int x,y;
//	cin>>x>>y;
	
	//cout<<max(x,y);
	
	/*
	const float PI = static_cast<float>(::PI);
	cout<< "Local float value of PI = "<<PI;
	cout<< "\n Global double  value of PI = "<<::PI;
	*/
	
	
	
	int a = 2;
	for(int i = 0;i<3;++i) 
		{ cout<<f(a); cout<<"\n";}
	
	

	return 0;
}

int f(int a)
{
 int b = 0;
 static int c = 3;
 b=b+1;//1 
 c = c+1;
 return (a+b+c);
} // 2+1+4 == 7 ,2+1+5 == 8 ,2+1+6 == 9



int p(int n)
{
    int a = 1;
	if(n<0) return 0;
	for(int i = 1;i<=n;++i) a *= i;
	
		return a;
}
int max(int a ,int b)
{
 int n1,n2;
 n1 = p(a);
 n2 = p(b);
 return (n1>n2?n1:n2);
}



