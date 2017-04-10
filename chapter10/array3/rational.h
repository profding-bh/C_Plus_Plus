#ifndef _RATIONAL_H_
#define _RATIONAL_H_


#include<iostream>
using namespace std;

class Rational{
private:
int num;// 分子
int den;// 分母
void reduct(); // 化简


public:

void create(int n,int d)
{
	num = n; // this->num = n;
	den = d; // this->den = d;
	reduct();// this->reduct();
}//inline


void display()
{
	cout<<num<<"/"<<den<<endl;
}//inline




void add(const Rational& r1, const Rational &r2);// r1+r2,结果存在当前对象中
void multi(const Rational& r1, const Rational &r2); // r1*r2,结果存在当前对象中


};



#endif
