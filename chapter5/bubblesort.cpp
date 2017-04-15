#include<iostream>
using namespace std;

// 冒泡排序
int
main()
{
	int i,j,tmp;
	int a[] = {0,3,5,1,8,7,9,4,2,10,6};
	bool flag = false;
	
	for(i=0;i<sizeof(a)/sizeof(a[0])-1;++i)
	{
		flag = false;
		for(j=0;j< sizeof(a)/sizeof(a[0])-1-i ;++j)
		{
			if(a[j]> a[j+1]) {tmp = a[j];a[j] = a[j+1];a[j+1] = tmp;flag = true;}
		}
		if(!flag) break; // 没有发生交换,提前结束
	}
	for(i=0;i<sizeof(a)/sizeof(a[0]);++i)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}


