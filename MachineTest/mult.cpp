#include<iostream>
using namespace std;

int
main()
{
    int n,m,k,a[1000][1000];
    cin>>n>>m>>k;

    for(int i = 1;i<= n;++i)
    {
        for(int j = 1;j<= m; ++j)
        {
            a[i][j] = i * j;
        }
    }


     for(int i = 1;i<= n;++i)
    {
        for(int j = 1;j<= m; ++j)
        {
           cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;

}

