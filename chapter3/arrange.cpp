#include<iostream>
using namespace std;



/*

基于哨兵的循环：

根据某个条件成立与否，来决定是否继续的循环称为，

基于哨兵的循环。

一个特定的标记,即为哨兵。

break:中止最内层循环

当一个循环中，有些操作必须在条件测试之前执行时，称为 循环中途退出问题。

*/
/**
输出A B C 的全排列：不能重复

*/
int
main()
{
	char a,b,c;
	for(a = 'A';a  <= 'C';++a)
	{
		for(b='A';b<='C';++b)
		{
			if(a == b) continue;
			else{
				for(c = 'A';c<='C';++c)
				{
					if(c == a || c == b) continue;
					else
					 cout<<a<<' '<<b<<' '<<c<<endl;	
				}
			}
		}
	}	
	return 0;
}
