#include<iostream>
using namespace std;


void 
print_mij(int* m,int dim1,int dim2)
{
	for(int i = 0;i != dim1;++i){
		for(int j = 0;j != dim2;++j)
			cout<<m[i*dim2+j]<<'\t';// obscure
		cout<<'\n';
	}
}

void
print_m35(int m[3][5])
{
	cout<<m<<'\t'<<&m[0][0]<<endl;
	for(int i = 0;i != 3;++i){
		for(int j = 0;j != 5;++j)
			cout<<m[i][j]<<'\t';
		cout<<'\n';
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

int
main()
{
	int v[3][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	print_m35(v);
cout<<'\n';
	print_mi5(v,3);
cout<<'\n';
	print_mij(&v[0][0],3,5);
cout<<'\n';
	print_mij(v[0],3,5);// ok
cout<<'\n';
	print_mij(v,3,5);// type error:
	return 0;
}
