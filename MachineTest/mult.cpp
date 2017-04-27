#if 0
#include<iostream>
using namespace std;

int
main()
{
    int n,m,k,a[1000][1000];
    cin>>n>>m>>k;


    int i,j;
    for(i = 1;i<= n;++i)
    {
        for(j = 1;j<= m; ++j)
        {
            a[i][j] = i * j;
        }
    }


     for(i = 1;i<= n;++i)
    {
        for( j = 1;j<= m; ++j)
        {
           cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;

}

#endif // 0


//别人的AC的答案
#include <iostream>
#include <cmath>
using namespace std;
typedef long long int64;  // int64(LL): 64位整型数, 即long long的别称

int64 m, n, k;

int64 cal(int64 x)  // 计算比x小的数的个数
{
	int64 sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int64 temp = ( x / i>=m) ? m : (x / i);//temp每一行中比x小的数的个数(若i*m<=x,则会有m个数满足要求，否则会有x/i个数满足)
		sum += temp;
	}
	return sum;
}


int64 cal2(int64 x)
{

    int64 sum = 0;
    for(int i = 1;i <= n;++i)
    {

        int64 temp = (x/i >= m)?m:(x/i);
        sum += temp;
    }
    return sum;
}




int64 binarySearch(int64 leftVal, int64 rightVal, int64 kth)
{
	int64 midVal;
	while (leftVal <=rightVal)
	{
		midVal = (leftVal + rightVal) / 2;
		int64 calvalue = cal2(midVal);//求乘法表中所有的小于等于midval的数的个数
		if (calvalue < kth)
		{
			leftVal = midVal + 1;// 要找的数在后面，区间下限继续增大
		}
		else
		{
			rightVal = midVal - 1;  // 要找的数在前面，区间上限继续减小
		}
	}
	return leftVal;
}

int main()
{
	cin >> n;
	cin >> m;
	cin >> k;
	if (n<1 || n>500000 || m<1 || m>500000 || k<1 || k>n*m)
	{
		return 0;
	}
	cout << binarySearch(1, n*m, k);

	return 0;
}


