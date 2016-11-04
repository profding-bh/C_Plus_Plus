#include<iostream>
using namespace std;


void 
comp(double arg[10]);// arg is a double*;

void 
comp2(double* arg);

void
f();

void
f2();


void
print_m35(int m[3][5]);


void
print_m123(int m[1][2][3]);


void 
print_mi5(int m[][5],int dim1);

//void 
// print_mij(int m[][],int dim1,int dim2);// // the argument declaration m[][], is illegal.



void 
print_mij(int* m,int dim1,int dim2);


void 
print_mijk(int* m,int dim1,int dim2,int dim3);


void 
print_mijkp(int* m,int dim1,int dim2,int dim3,int dim4);

int
main()
{
	
	//int bads[3,5];// error:comma not allowed in constant expression
	int good[3][5]; //3 arrays with 5 ints each
	//int ouch = good[1,4];//error:int  initialized by int*(good[1,4] means good[4],which
//	is an int*)

	int nice = good[1][4];
	
//	f();


//	f2();

	//int a[3][5] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	//print_m35(a);

//	int a[1][2][3] {1,2,3,4,5,6};
//	 print_m123(a);
//	print_m123(a[1][2][3]);//error!

	//int a[3][5] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//	print_mi5(a,3);


	//int a[3][5] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	//print_mij(a[0],3,5);
	//print_mij(&a[0][0],3,5);

	//int a[2][2][3] {1,2,3,4,5,6,7,8,9,10,11,12};
 //   print_mijk(&a[0][0][0],2,2,3);


	int a[2][2][2][2] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    print_mijkp(&a[0][0][0][0],2,2,2,2);
	return 0;
}

/*

Passing Arrays:

Array cannot directly by passed by value. Instead, an array is passed 

as  a pointer to its first element.(任意维数的数组都是如此！！！)


*/

void 
comp(double arg[10])// arg is a double*
{
	for(int i = 0; i != 10; ++i) {//10
		arg[i] += 99;
		cout<<arg[i]<<" "<<&arg[i]<<" ";
	}
	cout<<'\n';
}



/*
99 99 99 99 99 99 99 99 99 99 
99 99 99 99 99 198 198 198 198 198 
99 99 99 99 99 99 99 99 99 99
*/



void 
comp2(double* arg)// 
{
	for(int i = 0; i != 10; ++i) {//10
		arg[i] += 99;
		cout<<arg[i]<<" ";//<<&arg[i]<<" ";
	}
	cout<<'\n';
}


void
f()
{
	double a1[10];
	double a2[5];
	double a3[100];

// 栈里面的顺序：
// a2-->a1--->a3(很奇怪啊！！！)
	comp(a1);
	comp(a2);//disaster!
	comp(a3);//uses only the first 10 elements
}

void
f2()
{
	double a1[10];
	double a2[5];
	double a3[100];

// 栈里面的顺序：
// a2-->a1--->a3(很奇怪啊！！！)
	comp2(a1);
	comp2(a2);//disaster!
	comp2(a3);//uses only the first 10 elements
}


/* 
Passing Two dimensions array:

*/

void
print_m35(int m[3][5])
{
// 0xbf854274	0xbf854274

	cout<<m<<'\t'<<&m[0][0]<<endl;
	for(int i = 0;i != 3;++i){
		for(int j = 0;j != 5;++j)
			cout<<m[i][j]<<'\t';
		cout<<'\n';
	}
}

/* 
Passing three dimensions array:

*/
void
print_m123(int m[1][2][3])
{
//0xbf894bcc	0xbf894bcc

	cout<<m<<'\t'<<&m[0][0][0]<<endl;
	for(int i = 0;i != 1;++i){
		for(int j = 0;j != 2;++j){
			for(int k = 0;k != 3;++k)
			 cout<<m[i][j][k]<<'\t';
		cout<<'\n';
		}	
	}
}


void 
print_mi5(int m[][5],int dim1)
{
	for(int i = 0;i != dim1;++i){
		for(int j = 0;j != 5;++j)
			cout<<m[i][j]<<'\t';
		cout<<'\n';
	}
}

/*

void 
print_mij(int m[][],int dim1,int dim2)
{
// declaration of ‘m’ as multidimensional array must have bounds for all dimensions except the first: 也就是说，对于多维数组，除了第一维可以为空以外，其他维必须显式给出。
// does't behave as most people would think


// the argument declaration m[][], is illegal.because the second dimension of 
// a multimensional array must be known in order to find the location of an 
// element.
	for(int i = 0;i != dim1;++i){
		for(int j = 0;j != dim2;++j)
			cout<<m[i][j]<<'\t';
		cout<<'\n';
	}
}
*/

// a correct solution:
void 
print_mij(int* m,int dim1,int dim2)
{
	for(int i = 0;i != dim1;++i){
		for(int j = 0;j != dim2;++j)
			cout<<m[i*dim2+j]<<'\t';// obscure
		cout<<'\n';
	}
}
// m[i][j] is correctly interpreted as *(*(m+i)+j).



void 
print_mijk(int* m,int dim1,int dim2,int dim3)
{
	for(int i = 0;i != dim1;++i){
		for(int j = 0;j != dim2;++j){
			for(int k = 0;k != dim3;++k)
			 	cout<<m[i*(dim2*dim3)+j*dim3+k]<<'\t';// 
			cout<<'\n';	
		}
	}
}

void 
print_mijkp(int* m,int dim1,int dim2,int dim3,int dim4)
{
	for(int i = 0;i != dim1;++i){
		for(int j = 0;j != dim2;++j){
			for(int k = 0;k != dim3;++k){
				for(int p = 0;p != dim4;++p)
			 	   cout<<m[i*(dim2*dim3*dim4)+j*(dim3*dim4)+k*dim4+p]<<'\t'<<&m[i*(dim2*dim3*dim4)+j*(dim3*dim4)+k*dim4+p]<<'\t';// 
			    cout<<'\n';	
			}
		}
	}
}
/*
任意多维数组处理：


void 
print_m123...n(int* m,int dim1,int dim2,int dim3,...int dimn)
{
	for(int i = 0;i != dim1;++i){
		for(int j = 0;j != dim2;++j){
			....
			for(int n = 0;n != dimn;++n)
	任何一个元素可以通过如下方式访问：
	任何一个元素的地址：&m[i*(dim2*dim3*...*dimn)+j*(dim3*dim4*...*dimn)+k*...+ (n-1)*dimn+n]。
			 	cout<<m[i*(dim2*dim3*...*dimn)+j*(dim3*dim4*...*dimn)+k*...+ (n-1)*dimn+n]<<'\t';// 
			cout<<'\n';	
		}
	}
}
*/



