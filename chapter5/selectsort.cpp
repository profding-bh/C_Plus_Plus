#include<iostream>
using namespace std;

// 直接选择排序
int
main()
{
	int lh,rh,k,tmp;
	
	int array[] = {2,5,1,9,10,0,4,8,7,6};
	
	
	for(lh=0;lh<sizeof(array)/sizeof(array[0])-1;++lh)//n-1遍
	{
		rh = lh; //rh剩余元素的最小下标
		for(k=lh+1;k<sizeof(array)/sizeof(array[0]);++k)
		{
			if(array[k] < array[rh]) rh = k;
		}
		tmp = array[lh];
		array[lh] = array[rh];
		array[rh]=tmp;
	}
	
	for(lh=0;lh<sizeof(array)/sizeof(array[0]);++lh)
		printf("%d\t",array[lh]);
	return 0;
}


