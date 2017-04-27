#include<stdio.h>

#define SQR(X) X * X

int 
main()
{
	int a = 10,k = 2,m=1;
	a /= SQR( k+m )/ SQR( k+m );
 	printf("%d\n",a);
	return 0;
}
