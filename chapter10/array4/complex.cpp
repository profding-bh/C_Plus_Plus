#include<iostream>
#include"complex.h"

using namespace std;



int
main()
{
	Complex c1(2,2),c2(1,3),c3;
	
	
	c1.display();
	c2.display();
	
	c3.add(c1,c2);
	c3.display();
	
	
	c3.sub(c1,c2);
	c3.display();
	
	
	c3.multi(c1,c2);
	c3.display();
	
	return 0;
}
