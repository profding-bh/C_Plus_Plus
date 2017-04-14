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
	
	
	cout<<"请输入成绩(-1,表示):";
	for(num=0; num<MAX; ++num){
		cin>>score[num];
		if(score[num] == -1) break;
	}
	
	return 0;
}


