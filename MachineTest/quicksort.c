#include<stdio.h>


void quick_s(int a[],int s,int e)
{
	int i = s,j = e;
	int key = a[s];
	int temp;

	if( s > e || !a ) return;

	while(i<j)
	{
		while(a[j] >= key && i < j) //从 右往 左 找 比key小的数,同时j还不能比i小
		   j--;
		while(a[i] <= key && i < j) //从 左  往 右  找 比key 大的数,同时i还不能比j大
		   i++;
		// swap
		temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}
	a[s] = a[i]; // or a[j]
	a[i] = key;
	
	quick_s(a,s,i-1);
	quick_s(a,j+1,e);
}


int  fabonacci(int n)
{
 	int i,f0,f1,fn; 
	switch(n)
 	{
  	 case 0: return 0;
   	 case 1: return 1;
  	 default:
	{
		f0 = 0;
		f1 = 1;
        for(i=2;i<=n;++i)
 		{ 
			fn = f0 + f1;
		//	printf("f%d is %d\n",i,fn);
			f0 = f1;
			f1 = fn;
      	 }
		return fn;
	 } 
 	}
}



int  fabonacci_rec(int n)
{
 	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return fabonacci_rec(n-1)+fabonacci_rec(n-2);
}






void print(int a[],int n)
{
	for(int i = 0;i < n;++i)
		printf("%d\t",a[i]);
	printf("\n");
}


int 
main()
{
	int a[]={6,1,2,7,9,3,4,5,10,8};

	quick_s(a,0,sizeof(a)/sizeof(a[0])-1);
// quick_s(a,0,0);
 	print(a,sizeof(a)/sizeof(a[0]));

  printf("f1 is %d\n",fabonacci(1));  ;

 printf("f5 is %d\n",fabonacci_rec(5));  ;
	return 0;
}
