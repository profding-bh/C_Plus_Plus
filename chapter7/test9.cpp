#include<iostream>
#include<vector>
using namespace std;


template<class K,class V>
class Map{ // a simple map class
	public:
	V& operator[](const K& v);// return  the vlaue corresponding to the key v
	
	pair<K,V>* begin() {return &elem[0];}
	pair<K,V>* end() {return &elem[0]+elem.size();}// ??会不会相差一? 验证一下.
private:	
	vector<pair<K,V>> elem;//{key,value} pairs
};


/*
The standard-library map is typically implemented as a red-black tree.
*/

template<class K,class V>
V& Map<K,V>::operator[](const K& k)
{
	for(auto& x:elem)
		if(k == x.first)
			return x.second;
// V{}获取的是??vlaue,调用的方法??
	elem.push_back({k,V{}});// add pair at end
	return elem.back().second;//return the (default) value of the new element
}
int
main()
{
	Map<string,int> buf;
	for(string s;cin>>s;) ++buf[s];

	for(const auto& x:buf)
		cout<<x.first<<":"<<x.second<<"\n";
	return 0;
}


/*
	An rvalue reference can  bind to an rvalue,but not to an lvalue.

	In that ,an rvalue reference is  exactly opposite to an lvalue reference.
	
*/
