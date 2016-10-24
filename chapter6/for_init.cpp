#include<iostream>
#include<vector>

using namespace std;

int
main()
{
	vector<string>& v = {"a","bb"};

	for(int i = 0; i != v.size();++i) cout<< v[i]<<endl;
	return 0;
}
