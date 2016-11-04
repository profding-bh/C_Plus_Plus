#include<iostream>
using namespace std;


template<typename T>
int byte_diff(T* p,T*q)
{
	// reinterpret_cast:把指针转化为整数。
	return reinterpret_cast<char*>(q)-reinterpret_cast<char*>(p);
}


void
diff_test()
{
	int vi[10];
	short vs[10];// &vi[1]-&vi[0] 地址相减，得到相差元素的个数
	cout<< vi <<' '<<&vi[1]<<' '<<&vi[1]-&vi[0]<<' '<<byte_diff(&vi[0],&vi[1])<<endl;
	cout<< vs <<' '<<&vs[1]<<' '<<&vs[1]-&vs[0]<<' '<<byte_diff(&vs[0],&vs[1])<<endl;
}
/*
0xbfb2ef08 0xbfb2ef0c 1 4
0xbfb2eef4 0xbfb2eef6 1 2


substraction of pointers is defined only when both pointers point to elements of
the same array(although the language has not fast way of ensuring that is the case).

*/



void
f()
{
 	int v1[10]= {-1,-1,-1,-1,2,3,4,5,6,7};
	int v2[10]= {1,2,3};//v2 地址大于v1

	int i1 = &v1[5] - &v1[3];// i1 = 2
	int i2 = &v1[5] - &v2[3];//result undefined

	cout<< i1 <<endl;
	cout<< i2 <<endl;
	
	int* p1 = v2+2;// p1 = &v2[2];
	int* p2 = v2-2;// *p2 undefined

	cout<< *p1 <<endl;
	cout<< *p2 <<endl;
}

void 
fp(char v[],int size)
{
	for(int i = 0; i != size;++i)
		//use(v[i]);// hope that v has at least size elements
		cout<<v[i]<<' ';
cout<<endl;
	//for(int x:v) // error:range-for does not work for pointers,v is pointer
	// ;//	use(x);


	const int N = 7;
	char v2[N]="aaaaaa";
	for(int i = 0; i != N;++i)
		//use(v2[i]);
		cout<<v2[i]<<' ';
	cout<<endl;
	for(char x:v2) // range-for workes for array of known size
		//use(x);
		cout<<x<<' ';
	cout<<endl;
}

int
main()
{
	char v1[10]= "helloworl";
	diff_test();
	f();
	fp(v1,10);
	return 0;
}
