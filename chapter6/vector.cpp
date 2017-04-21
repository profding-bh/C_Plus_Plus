#include<iostream>
#include<vector>

using namespace std;




#if 1

int
main(void)
{

	vector<double> v(10,3.3);// use constructor:v gets 10 element initialized to 3.3
	for(auto x: v)
		cout<<x<<endl;
	return 0;
}
#endif

