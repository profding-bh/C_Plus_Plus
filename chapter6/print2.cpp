#include<iostream>
#include"print2.h"
using namespace std;

int a[30];

void print(int value,int base=2)
{
    int i=0,c=0;   
    while(value!=0)  
    {  
        i=value%base;  
        a[c++]=i;   
        value=value/base;  
    }  
    c--;//因为c代表存入数据的长度而下表范围是0~c-1  
    for(;c>=0;c--)//倒序输出即为这个数字对应的二进制  
    {  
        cout<<a[c];    
    }  
	cout<<endl; 
}
