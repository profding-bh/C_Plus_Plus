#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double s[100];

int i,n;

int cmp( const void *a , const void *b )
{
printf("%f\n",*(double *)a - *(double *)b);
//return *(double *)a - *(double *)b;

return *(double *)a > *(double *)b ? 1 : -1;
//返回值的问题，显然cmp返回的是一个整型，所以避免double返回小数而被丢失，用一个判断返回值。
}

// 2.1 2.3

int main()
{

// 输入想要输入的数的个数
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%lf",&s[i]);
qsort(s,n,sizeof(s[0]),cmp);

for(i=0;i<n;i++)
printf("%lf\t",s[i]);

printf("\n");
return(0);
}
