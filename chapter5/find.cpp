#include<iostream>
using namespace std;


int
main()
{
	int k,x;

	int array[] = {1,2,3,4,5,6,7,8,9,0};

	cout<<"请输入要查找的数据：";
	cin>>x;

	for(k = 0; k<10;++k)
		if(x == array[k]) break;
	
	if(k == 10) cout<<"没有找到";
	else cout<<"find"<<k<<endl;
	return 0;
}


