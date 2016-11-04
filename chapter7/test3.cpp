#include<iostream>

#include<string.h> // is not equal to #include<string>

using namespace std;

void
f();

int
main()
{
	string a = u8"The official vowels in Danish are:a,e,i,o,u,\u00E6,\u00F8,\u00E5 and y.";
	cout<<a<<endl;
// The official vowels in Danish are:a,e,i,o,u,æ,ø,å and y.

// The hexadecimal number after the \u is a Unicode code point
// The order of us and Rs and their cases are significant:RU and Ur are not 
// valid string prefixes.

// 有顺序


#if 0
string b = UR"(folder\\file)";//error!
cout<<b<<endl;
#endif


	f();

// 神了！
char c[]="Texas";
cout<< 3["Texas"] <<endl;
cout<< "Texas"[3] <<endl;
cout<< 'a' <<endl;


	return 0;
}




void
f()
{
	char v[] = "Annemarie";
	char* p = v;// implicit conversion of char[] to char*
	cout<<strlen(p)<<endl;//9
	cout<<strlen(v)<<endl;// 9 implicit conversion of char[] to char*

	//v = p;// error:cannot assign to array
}

