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


	if(!initialize(array,low,high)) cout<<"Array memoroy failure"<<endl;
	for(i = low;i<=high;++i)	{
		cout<<"Please input "<<i<<"th element:";
		cin>>value;
		insert(array,i,value);
	}

// for(;;); the simple forever loop
	for(;;){
		cout<<"Please input the index you want (0 is terminate!)";
		cin>>i;
		if(0 == i) break;
		value = 0;
		if(fatch(array,i,value)) cout<<value<<endl;
		else cout<<"out of boundary\n";
	}
	cleanup(array);
	return 0;
}

