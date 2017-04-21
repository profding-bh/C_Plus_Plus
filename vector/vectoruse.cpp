#include<iostream>
#include<vector>
using namespace std;

int
main()
{
#if 0
	vector<int*> a;
	int b = 4;
	a.push_back(&b);
	cout<<a[0]<<endl;
	
#endif
	
	
#if 0
	
	vector<int> a;
	int b = 4;
	a.push_back(b);
	cout<<a[0]<<endl;

#endif	
	
#if 1
   vector< vector<int> >  array2(3);
  //  array2[1][3] = 9; segment fault,原因就是没有指定向量大小。
   array2[1].push_back(9);
   cout<<array2[1][0]<<endl;
   
   int i,j;
   for(i = 0;i<3;++i)
      array2[i].resize(3); // 设置数组大小为3*3
    
    //setter
    int count = 1;
    for(i=0;i<3;++i)
    {
         for(j=0;j<3;++j)
   		{
			array2[i][j] = count++;      
   		}
    }
    
    
    //getter
     for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
   		{
			cout<<array2[i][j]<<"\t";      
   		}
   		cout<<"\n";
    }


// 重新改变数组大小。
    array2.resize(5);
    array2[3].resize(3);
    array2[4].resize(3);// now is 5*3
    
    
    count=1;
     for(i=0;i<5;++i)
    {
         for(j=0;j<3;++j)
   		{
			array2[i][j] = count++;      
   		}
    }
    
    
    //getter
     for(i=0;i<5;++i)
    {
        for(j=0;j<3;++j)
   		{
			cout<<array2[i][j]<<"\t";      
   		}
   		cout<<"\n";
    }
    
    cout<< array2[4].at(0)<<endl;
    

#endif
	
	return 0;
} 
