#include<iostream>
using namespace std;

inline int square(int x) {return x*x;}
inline int cube(int x) {return x*x*x;} // inline跟register类型一样。是建议的。


#if 0
int max(int a1,int a2);
int max(int a1,int a2,int a3);
int max(int a1,int a2,int a3,int a4);
int max(int a1,int a2,int a3,int a4,int a5);
#endif



template<class T>
T max(T a,T b)
{
	return a>b?a:b;
}


/*

if(递归终止的条件测试) return {不需要递归计算的简单解决方案}
else return (包括调用同一函数的递归解决方案);


*/
int
main()
{

#if 0
	cout<<"x"<<'\t'<<"x*x"<<"\t"<<"x*x*x"<<endl;
	for(int i = 1;i<=1000;++i)
	 	cout<<i<<"\t"<<square(i)<<"\t"<<cube(i)<<endl;
#endif

#if 0
cout<< "max(3,5)" << max(3,5)<<endl;
cout<< "max(3,5,4)" << max(3,5,4)<<endl;
cout<< "max(3,5,7,9)" << max(3,5,7,9)<<endl;
cout<< "max(3,5,2,4,6)" << max(3,5,2,4,6)<<endl;
#endif

cout<< "max(3,5)" << ::max(3,5) <<endl;
cout<< "max(3.2,3.4)" << ::max(3.2,3.4) <<endl;
cout<< "max('d','r')" << ::max('d','r') <<endl;


cout<< "max(3,5)" << std::max(3,5) <<endl;
cout<< "max(3.2,3.4)" << std::max(3.2,3.4) <<endl;
cout<< "max('d','r')" << std::max('d','r') <<endl;


	return 0;
}

#if 0
int max(int a1,int a2)
{
 return a1>a2?a1:a2;
}


int max(int a1,int a2,int a3)
{
 int tmp = max(a1,a2);
 return max(tmp,a3);
}

int max(int a1,int a2,int a3,int a4)
{
 int tmp=max(a1,a2,a3);
 return max(tmp,a4);
}
int max(int a1,int a2,int a3,int a4,int a5)
{
int tmp=max(a1,a2,a3,a4);
 return max(tmp,a5);
}
#endif










