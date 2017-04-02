#include<iostream>
#include<cstdlib>

/*

rand()--->cstdlib
生成0-9 之间 的随机数,有2种方法：
1)rand()%10;
2)rand()*10/(RAND_MAX+1);
*/
using namespace std;

int
main()
{
	int n1,n2,op,r1,r2;

	n1 = rand()%10;	
	n2 = rand()%10;	
	cout<<"RAND_MAX is "<<RAND_MAX<<endl;
//	op = rand()*4/(RAND_MAX+1); 这样会overflow的，
// 还是采用第一种方法.

	op = rand()%4;
/* 0-->+
   1-->-
   2-->*
   3-->/
*/
	switch(op){
	case 0: cout<<n1<<"+"<<n2<<"=";cin>>r1;
			if(n1+n2 == r1) cout<<"Right\n";
			else cout<<"Wrong\n";
			break;
	case 1: cout<<n1<<"-"<<n2<<"=";cin>>r1;
			if(n1-n2 == r1) cout<<"Right\n";
			else cout<<"Wrong\n";
			break;
	case 2: cout<<n1<<"*"<<n2<<"=";cin>>r1;
			if(n1*n2 == r1) cout<<"Right\n";
			else cout<<"Wrong\n";
			break;
	case 3: cout<<n1<<"/"<<n2<<"=";cin>>r1;cout<<"余数：";cin>>r2;
			if(n1/n2 == r1 && n1%n2 == r2) cout<<"Right\n";
			else cout<<"Wrong\n";
			break;
	}
	return 0;
}
