#include<iostream>
using namespace std;


// ABCD*E=DCBA
// 约束条件：A B C D E 代表不同的数字
int 
main()
{


	int i,j,k,m,n;


#if 0
	for(i=1;i<=9;++i) // A ,A != 0
	{

		for(j=0;j<=9;++j) //B 
		{
			if(i == j) 
				continue;
			for(k=0;k<=9;++k) // C
			{
				if(j == k) 
					continue;		
				for(m=0;m<=9;++m) // D
				{
					if(k == m) 
					   continue;
					for(n=1;n<=9;++n)// E != 0
					{
						if(m == n) 
							continue;
						if((1000*i+100*j+10*k+m)*n == 1000*m+100*k+10*j+i)
						{	
							printf("the number is %d\n",(1000*i+100*j+10*k+m)*n);
							goto end;
						}
					}	
					
				}	
			}	
		}
	}	
#endif

	for(i=1;i<=9;++i) // A ,A != 0
	{

		for(j=0;j<=9;++j) //B 
		{
			if(j == i) 
				continue;
			for(k=0;k<=9;++k) // C
			{
				if(k == i || k == j) 
					continue;		
				for(m=0;m<=9;++m) // D
				{
					if(m == i || m == j || m == k) 
					   continue;
					for(n=1;n<=9;++n)// E != 0
					{
						if(n == i || n == j || n == k || n == m) 
							continue;
						if((1000*i+100*j+10*k+m)*n == 1000*m+100*k+10*j+i)
						{	
							printf("the number is %d\n",(1000*i+100*j+10*k+m)*n);
							goto end;
						}
					}	
					
				}	
			}	
		}
	}	
end:
	printf("A is %d\n",i);
	printf("B is %d\n",j);
	printf("C is %d\n",k);
	printf("D is %d\n",m);
	printf("E is %d\n",n);
	return 0;
}
