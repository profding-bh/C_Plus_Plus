struct In
{
double data;
int other;
}s[100];
 // 对结构体一级排序
//按照data的值从小到大将结构体排序,关于结构体内的排序关键数据data的类型可以很多种，
 
int cmp( const void *a ,const void *b)
{
return (*(struct In *)a).data > (*(struct In *)b).data ? 1 : -1;
//注意，这条语句在VC6.0环境下运行可能会出错，但是并不是语句错了，而是你要先 Build ，或者全部重建。总之语句是对的。
//或者你可以将这上面1条语句改成下面这3条语句
//struct In *aa = (In *)a;
//struct In *bb = (In *)b;
//return aa->data > bb->data ? 1 : -1;
}



//五、对结构体二级排序
struct In2
{
int x;   //你可以比喻成：失败次数
int y;   //你可以比喻成：成功次数
}s2[100];
 
//按照x从小到大排序，当x相等时按照y从大到小排序。 你可以想象成：失败是主要因素的一个问题，先比较 失败次数少，失败次数相同 再看 成功次数多。
 
int cmp2( const void *a , const void *b )
{
struct In2 *c = (struct In2 *)a;
struct In2 *d = (struct In2 *)b;
// 出现多个排序指标时
if(c->x != d->x) return c->x - d->x; // x从小到大排序
else return d->y - c->y; //  x相等时按照y从大到小排序
}


int n,i;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{

#if 0
// 输入想要输入的数的个数
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%lf%d",&s[i].data,&s[i].other);

}

//for(i=0;i<n;i++)
//{
 //printf("%lf\t%d\n",s[i].data,s[i].other);
//}

qsort(s,n,sizeof(s[0]),cmp);

for(i=0;i<n;i++)
{
 printf("%lf\t%d\n",s[i].data,s[i].other);
}

printf("\n");

#endif

// 输入想要输入的数的个数
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%d%d",&s2[i].x,&s2[i].y);
}

 qsort(s2,n,sizeof(s2[0]),cmp2);

for(i=0;i<n;i++)
{
 printf("%d\t%d\n",s2[i].x,s2[i].y);
}

printf("\n");



return(0);
}
