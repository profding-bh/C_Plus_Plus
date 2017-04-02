#include<iostream>
#include<cmath>

using namespace std;

/*


for(int i: {1,9,6,8,3})
 	cout <<i<<endl;
*/



/*

求一个整数n的最大因子，不包括他本身。

分析：
既然不包括他本身的话，那么，最小的因数应该从2开始计算，
最大的因数就不应该超过n/2,而不用从n-1开始算。

*/
int
main()
{
	int i;
	cout<<"input a integer:";
	cin>>i;	

	int j;
	for( j = i/2; j >= 2; --j)
	{
		if( i%j == 0 ) 
		{
			break;
		}
    } 	
	cout<<j<<endl;
	cout<<"xxxxxxxxxxx"<<endl;
	for(int ii: {1,9,6,8,3})
	 	cout<<ii<<endl;
	return 0;
}
