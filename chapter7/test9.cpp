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

1) A non-const lvalue reference refers to an object, to which the user of
the reference can write.

2) A const lvalue reference refers to a constant,which is immutable from
the point of view of the user of the reference.

3) An  rvalue reference refers to a temporary object,which the user of 
the  reference can (and typically will) modify,assuming that the object will
never be used again.





	An rvalue reference can  bind to an rvalue,but not to an lvalue.

	In that ,an rvalue reference is  exactly opposite to an lvalue reference.
	
*/


string var {"Cambridge"};
string f();
string& r1 {var}; //  lvalue reference,bind r1 to var(an lvalue)
string& r2 {f()}; // lvalue reference,error:f() is an rvalue
string& r3 {"Princeton"}; // lvalue reference,error:cannot bind to temporary

string&& rr1 {f()}; // rvalue reference,fine: bind rr1 to  rvalue(a temporary)
string&& rr2 {var}; //  rvalue reference,error: var is an lvalue.
string&& rr3 {"Oxford"}; // rr3 refers to a temporary holding "Oxford"


const string cr1& {"Harvard"}; // ok: make temporary and bind to cr1

The && declarator operator means "rvalue reference" 


// Both a const lvalue reference and an rvalue reference can bind to an rvalue.
string 
f(string&& s)
{
	if(s.size())
	 s[0] = toupper(s[0]);
	return s;
}


template<class T>
swap(T& a,T& b)// "old-style swap"
{
	T tmp {a};// now we have two copies of a
	a = b; // now we have two copies of b
	b = tmp;//now we have two copies of tmp(aka a)
}






