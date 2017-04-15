#include<iostream>
using namespace std;

// 求解3元一次方程组
int
main()
{
	double a[3][3],b[3],result[3],detA,detB,tmp[3];
	
	
	int i,j;
	
	for(i=0;i<3;++i){
		cout<<"请输入第"<<i+1<<"个方程的3个系数和常数项：";
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>b[i];
	}
	
	detA=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]
	-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2]-a[0][2]*a[1][1]*a[2][0];
	
	
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			tmp[j] = a[j][i];
			a[j][i] = b[j]; // 替换列
		}
		
			
	   detB=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]
	-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2]-a[0][2]*a[1][1]*a[2][0];
	
	 // 还原,因为下次循环，还得用原来的系数矩阵
	 for(j=0;j<3;++j)
	    a[j][i] = tmp[j];
	   
	   result[i] = detB/detA; 
		
	}
	
	cout<<"x = "<<result[0] <<",y = " <<result[1]<<",z = " <<result[2]<<endl;
	return 0;
}


