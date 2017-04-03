#include<iostream>
#include<cmath>
/*

greedy:

贪婪法，也叫 贪心法。（greedy）

1.目的：
用于求 问题的最优解。

2.
适合情况：

而此问题的解决 是由一系列阶段组成的。


3.
基本思想：
在求解过程的每一个阶段都选取一个局部最优的策略，把问题规模缩小，最后把每一步的结果合并 起来
形成一个全局解。


贪心法，并不是对所有问题 都能 得到最优解。






*/

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
