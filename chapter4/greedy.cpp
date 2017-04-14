#include<iostream>
#include<cstdlib>
using namespace std;



#define ONEFEN 1
#define TWOFEN 2
#define FIVEFEN 5
#define ONEJIAO 10


//用greedy解决硬币找零问题


int compare(const void *a, const void *b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    cout<<(*pb )- (*pa)<<endl;
   // return 1;
    return (*pb )- (*pa);  //从大到小排序
}



int compare2(const void *a, const void *b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    cout<<(*pa )- (*pb)<<endl;
    return (*pa )- (*pb);  //从小到大排序
}


int
main()
{

#if 0
	int r;
	cout<<"Please input remainder:以分为单位";
	cin>>r;
	
	
	cout<<"一共找零：";
	while(r>0){
		if(r>=ONEJIAO) 
		{	r = r-ONEJIAO; cout<<"1角"<<endl;}
		else if(r >= FIVEFEN)
		{   r = r-FIVEFEN;  cout<<"5分"<<endl;}
			else if (r >=TWOFEN)
		{			r = r-TWOFEN;cout<<"2分"<<endl;}
				else if(r >= ONEFEN)
			{	   r = r-ONEFEN; cout<<"1分"<<endl;}
	}
	
	#endif
	
	
	#if 0
	int money;
	// onejiao:1角的个数，...
	int onefen = 0,twofen = 0,fivefen= 0,onejiao=0;
	
	
	cout<<"输入要找零的钱（以分为单位）：";cin>>money;
	
	
	if(money >=ONEJIAO ) {onejiao = money/ONEJIAO;money %= ONEJIAO;}
	if(money >=FIVEFEN ) {fivefen = 1;money -= FIVEFEN;}
	if(money >=TWOFEN ) {twofen = money/TWOFEN;money %= TWOFEN;}
	if(money >=ONEFEN ) {onefen = 1;}
	
	
	cout<<"1角硬币数:"<<onejiao<<endl;
	cout<<"5分硬币数:"<<fivefen<<endl;
	cout<<"2分硬币数:"<<twofen<<endl;
	cout<<"1分硬币数:"<<onefen<<endl;
	#endif
	
	
	#if 1
	#define N 10
	cout<<N<<endl;
	
	
	int a;
	cout<<"Please the number of integer:";
	cin >>a;
	
	int i,b[N]={0};
	for(i=0;i<a;++i)
		cin>>b[i];
		
//	for(i=0;i<a;++i)
	//	cout<<b[i]<<endl;
	
	qsort(b,a,sizeof(int),compare);
	
//	for(i=0;i<a;++i)
	//	cout<<b[i]<<endl;
		
	cout<< 100 * b[0]+10*b[1]+b[2]<<endl; 
	#endif
	
	#if 0
	int num = 0,max = 10,current;
	
	for(int digit = 100;digit > 0; digit /=10){
		current = 0;
		for(int n:{5,6,2,4,9,1})
			if(n>current &&  n < max) current = n;
		num += digit*current;
		max = current; // 上一次找到的最大数字
		}
		
		cout<<num<<endl;
		#endif
	return 0;
}
