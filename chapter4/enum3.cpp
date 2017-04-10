#include<iostream>
using namespace std;

// 在设计一个算法时，要时刻记住提高它的效率
int 
main()
{
	int i,j,k;

#if 0
	for(i=1;i<=15;++i) // 西瓜
	{
		for(j=1;j<=50;++j)// 苹果
		{
			for(k=1;k<=150;++k) // 橘子
			{
				if(10*i+3*j+k == 150 && (i+j+k) == 100)
				{
					printf("西瓜：%d  苹果：%d  橘子:%d\n",i,j,k);
				}
			}
		}
	}

#endif

	for(i=1;i<=14;++i) // 西瓜
	{
		for(j=1;j<=(150-10*i)/3 ;++j)// 苹果
		{
				k = 150-10*i-3*j;// 剩下买橘子的钱
				if( i+j+k == 100)
				{
					printf("西瓜：%d  苹果：%d  橘子:%d\n",i,j,k);
				}
		}
	}
	return 0;
}
