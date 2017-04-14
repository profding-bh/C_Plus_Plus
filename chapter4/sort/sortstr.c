// 注意：qsort 中的  cmp 得自己写 。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct In
{
int data;
char str[100];
}s[100];


int n,i;


//按照结构体中字符串str的字典顺序排序
int cmp( const void *a , const void *b )
{
return strcmp((*(struct In *)a).str , (*(struct In *)b).str );
}



int main()
{
// 输入想要输入的数的个数
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%d %s",&s[i].data,s[i].str);
}

 qsort(s,n,sizeof(s[0]),cmp);

for(i=0;i<n;i++)
{
 printf("%d\t%s\n",s[i].data,s[i].str);
}

printf("\n");



return(0);
}
