#include<iostream>
using namespace std;

void printInt( int);

// 打印2进制，8进制，10进制,16进制
void printIntBase( int,int );

int
main()
{


#if 0
	int  num;
	cout<<"Please input a interger:"<<endl;
	cin>>num;

	printInt(num);
	cout<<endl;
	
	#endif
	
	int  num,base;
	cout<<"Please input a interger:"<<endl;
	cin>>num;

   cout<<"Please input base:"<<endl;
	cin>>base;
	
	printIntBase(num,base);
	cout<<endl;
	return 0;
}


// printInt(1234)
void printInt( int n)
{
 if(n<10)  cout<< static_cast<char>(n+'0');
 else {
 printInt(n/10);
 cout<< static_cast<char>(n%10+'0');
}
}
// printIntBase(1234,8)
void printIntBase( int num,int base )
{
static char DIGIT[17] = "0123456789abcdef";

if(num < base) cout<< DIGIT[num];
else {
 printIntBase(num/base,base);
 cout<<DIGIT[num%base];
}
}


