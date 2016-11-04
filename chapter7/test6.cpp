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


int
main()
{
	
	int a[][3]={1,2,3,4,5,6,7};
	cout<<sizeof(int)<<endl;// 4
	cout<<sizeof(a)<<endl;// 36 = 4 * 9 
	print_mij(a[0],3,3);


	
	return 0;
}
