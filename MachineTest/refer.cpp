#include<iostream>
using namespace std;


/*
 引用就是给变量起一个别名，使一块内存空间可以通过几个变量名来访问。

 type &varName;

一旦将 一个变量定义为 一个变量的别名，就不可以使其作为 另一个变量的别名。

这是指针和 引用主要的区别。


引用 和 被引用的变量之间的 绑定是 永久的。而指针可以通过赋值指向另一个变量。

int i,k,*p = &k;

int &j = i;



*/
int
main()
{
    int i = 1;
    int &j = i;
    cout<<j<<endl;

    int &jj = j;
        cout<<jj<<endl;

     //   const int &a = 100; ok!
/*
引用类型的变量一般是一个同类型的变量，或 你能隐式转换成该类型
的变量。但如果声明的引用类型是常量，它的初值也可以是常数。
*/

      //     int &a = 100; error!
        // cout<<a<<endl;

        #if 0
        int a = 12;
        const int &b = a;

        cout<<a<<endl;
        cout<<b<<endl;
        a = 14;
        cout<<a<<endl;
        cout<<b<<endl;
        #endif // 0

        int a = 12;
        const int &b = a;

        cout<<a<<endl;
        cout<<b<<endl;
        b = 14; // assignment of read-only reference
        cout<<a<<endl;
        cout<<b<<endl;


    return 0;
}
