#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s[10000],n,i;

int cmp(const void *a,const void *b)
{
return(*(int *)b-*(int *)a);  //实现的是降序排序
}


int main()
{
// 输入想要输入的数的个数
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&s[i]);
qsort(s,n,sizeof(s[0]),cmp);
for(i=0;i<n;i++)
printf("%d ",s[i]);
printf("\n");
return(0);
}
