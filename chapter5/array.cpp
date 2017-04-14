//#define 
constexpr int len=10;


#include<iostream>
#include<cmath>
using namespace std;


int
main()
{
	const int MAX = 100;
	int score[MAX],num = 0;
	double  average = 0, variance = 0;
	
	
	cout<<"请输入成绩(-1,表示结束):";
	for(num=0; num<MAX; ++num){
		cin>>score[num];
		if(score[num] == -1) break;
		average += score[num];
	}

average =average/num;

cout<<num<<endl;

	for(int i =0; i< num ; ++i){
		variance += (average - score[i]) * (average - score[i]);
	
	}
variance = sqrt(variance/(num-1));

	cout<<"average:"<<average<<endl;
cout<<"variance:"<<variance<<endl;
	
	return 0;
}


