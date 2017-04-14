#include<iostream>
using namespace std;


int
main()
{
	int k,x;

	int array[] = {0,1,2,3,4,5,6,7,8,9};

	cout<<"请输入要查找的数据：";
	cin>>x;

  	int low = 0,high = sizeof(array)/sizeof(array[0]);
	int mid = 0;
	while(low <= high){
	mid = (low+high)/2;
	if(a[mid] == x) break;
	if(x > a[mid]) low= mid+1; else high = mid -1;
}
	
	if(low > high) cout<<"没有找到";
	else cout<<"find"<<mid<<endl;
	return 0;
}


