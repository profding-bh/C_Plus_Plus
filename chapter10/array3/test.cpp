#include<iostream>
#include"doubleArray.h"
using namespace std;


int
main()
{
	doubleArray array;
	double value;
	int low,high,i;

	cout<<"Please input array subscripts range:";
	cin>>low>>high;


	if(!array.initialize(low,high)) cout<<"Array memoroy failure"<<endl;
	for(i = low;i<=high;++i)	{
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
	array.cleanup();
	return 0;
}

