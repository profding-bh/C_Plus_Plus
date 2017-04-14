#include<iostream>
using namespace std;

const double PI = 3.14;
const Rational r1(1,2);


class Test{
private:
	//const int size = 2;
	const int size ;
	public:
	Test(int s):size(s){
	//	size = s;
	}
	
	void display(){
	cout<<size<<endl;
	}
};



int
main()
{
	Test t(1);
	t.display();
	return 0;
}

