#include<iostream>
#include<algorithm>
using namespace std;
 
 #define N 5
 
 int cmp(int a,int b)
{
  if(a > b)
  return 1; //a< b 升序排列，如果改为 a > b，则为降序,要注意sort()中cmp()的返值只有1和0，不像qsort中存在-1！！！！
  else
  return 0;
}

 // 默认sort排序后是升序，如果想让他降序排列，可以使用自己编的cmp函数
int main()
{
      int a[N];
      for(int i=0;i<N;++i)
          cin>>a[i];
     // sort(a,a+N);             //范围，很明显这里是a+N 注意，这是必要的，如果是a+4
     // sort是变参函数
     sort(a,a+N,cmp);
      for(int i=0;i<N;i++)        //最后一个值a[4]就不会参与排序。
              cout<<a[i]<<endl;
       return 0;
}
