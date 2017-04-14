#include<iostream>
using namespace std;

class Complex{

private:
	double real; //
	double imag;
	
public:
// Complex(double r = ,double i = 0 ){
 Complex(double r  ,double i  ){
 	real = r; 
 	imag = i;
 }
 
 /*


C++11的扩展：
1.
 
 

*/
  Complex()=default; 
  
 void add(const Complex &c1, const Complex &c2)
 {
 	real = c1.real+c2.real;
 	imag = c1.imag+c2.imag;
 }
 
  void sub(const Complex &c1, const Complex &c2)
 {
 	real = c1.real-c2.real;
 	imag = c1.imag-c2.imag;
 }
 
  void multi(const Complex &c1, const Complex &c2)
 {
 	real = c1.real*c2.real - c1.imag*c2.imag;
 	imag = c1.imag*c2.real + c1.real*c2.imag;
 }
 
 void display()
 {
 	if(imag > 0) cout<<real <<'+'<<imag<<'i'<<endl;
 	else cout<<real <<'-'<<-imag<<'i'<<endl;
 }
 
 
 
 
 
 

 
 
 
 
 
 
 
};
