#include<iostream>
#include"construct.h"
using namespace std;


int
main()
{
	doubleArray array(20,30);
	double value;
	int i;

	for(i = 20;i<= 30;++i)	{
		cout<<"Please input "<<i<<"th element:";
		cin>>value;  
		array.insert(i,value);
	}

// for(;;); the simple forever loop

	for(;;){
		cout<<"Please input the index you want (0 is terminate!)";
		cin>>i;
		if(0 == i) break;
		value = 0;
		if(array.fatch(i,value)) cout<<value<<endl;
		else cout<<"out of boundary\n";
	}

	return 0;
}

