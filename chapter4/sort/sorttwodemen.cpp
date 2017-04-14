// 对二维数组的排序：
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;


// 二维数组的排序
bool cmp(int *p,int *q)
{
	cout<<*p <<"\t" <<*q<<endl;
    if(p[0]==q[0])
    {
        if(p[1]==q[1])
        {
            return p[2]<q[2];
        }
        else 
        	return p[1]<q[1];
    }
    else
      return p[0]< q[0];
}

constexpr int N = 10;

int main()
{
    srand(time(0));
    int i;
    int **a= new int* [N];
    for(i=0;i< N ;++i)
    {
        a[i]=new int[3];
        // assign data
        a[i][0]=rand()% N ;
        a[i][1]=rand()% N ;
        a[i][2]=rand()% N ;
        printf("%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2]);
    }
    sort(a,a+N ,cmp);
    
    cout<<"After sort"<<endl;
    for(i=0;i< N ;++i)
    {
        printf("%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2]);
    }
    return 0;
}
