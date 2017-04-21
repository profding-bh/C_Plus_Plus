#include<iostream>
#include<vector> // 数组
using namespace std;


#define MAX 10 

int average(int array[5]);



int ReadIntegerArray(int array[],int max,int flag);
void ReverseIntegerArray(int array[],int size);
void PrintIntegerArray(int array[],int size);



int
main()
{

#if 0
	int i,score[5];
	cout<<"请输入5个成绩："<<endl;
	
	for(i=0;i<5;i++) cin>>score[i];
	
	
	cout<<"平均成绩:"<<average(score)<<endl;
	
	#endif
	
	
	int IntegerArray[MAX],flag,Currentsize;
	
	cout<<"结束标记:";cin>> flag;
	
	Currentsize = ReadIntegerArray(IntegerArray,MAX,flag);
	ReverseIntegerArray(IntegerArray,Currentsize);
	PrintIntegerArray(IntegerArray,Currentsize);
	

	return 0;
}

int average(int array[5])
{
int i,sum =0;
for(i=0;i<5;++i)
sum += array[i];
return sum / 5;
}


int ReadIntegerArray(int array[],int max,int flag)
{
	int size =0;
	cout<<"input elements ,terminate"<<flag<<endl;

	while(size < max){
		cin>>array[size];
		if(flag ==  array[size]) break; else ++size;
	}
	return size;
}

void ReverseIntegerArray(int array[],int size)
{
 int i,tmp;
 for(i=0;i<size/2;++i) // 
 {
   tmp = array[i];
   array[i] = array[size-1-i];
   array[size-1-i]= tmp;
 }
}
void PrintIntegerArray(int array[],int size)
{
 int i;
 if(size == 0 )return;
 for(i=0;i<size;++i) cout<<array[i]<<'\t';
 cout<<endl;

}








