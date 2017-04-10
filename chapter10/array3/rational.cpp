#include"rational.h"


void Rational::reduct()
{
// 找出num & den的最大公约数，然后除以最大公约数
	int min = (num > den?den:num);
	
	for(;min >= 1;--min)
	{
		if(num%min == 0 && den % min == 0)
		{
			num /= min;
			den /= min;
			break;
		}
	}
}// 化简

void Rational::add(const Rational& r1, const Rational &r2)
{
	num = r1.num * r2.den + r1.den * r2.num;
	den = r1.den * r2.den;
	reduct();
}// r1+r2,结果存在当前对象中


// 成员函数可以访问本类的私有成员。
void Rational::multi(const Rational& r1, const Rational &r2)
{
	num = r1.num*r2.num;
	den = r1.den*r2.den;
	reduct();
} // r1*r2,结果存在当前对象中






