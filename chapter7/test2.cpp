#include<iostream>
using namespace std;


char alpha[]="abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";


char b[]="Jens\000Munk";


int
main()
{
	cout<<alpha<<endl;
	cout<<b<<endl;//Jens

	string s ="\\w\\\\w";//  \w\\w
	cout<<s<<endl;

	/*
	the fact that a backslash(\) is an escape character becomes
	notable souce of errors.
	to prevent the frustration literal and errors caused by this clash of
	of conventions, C++ provides raw character strings

	
	*/

	cout<<"\\"<<endl;//   backslash(\)
	cout<<"\""<<endl;// "

	string s2 = R"(\w\\w)";//  \w\\w 
	cout << s2 <<endl;

	string s3 = R"(\w\\w)";// I'm pretty sure I got that right
	cout << s3 <<endl;

	
	string s4 = R"("\w\\w")";// I'm pretty sure I got that right
	cout << s4 <<endl;

	string s5 = R"("quoted string")";// I'm pretty sure I got that right
	cout << s5 <<endl;

	string s6 = R"("quoted string")";// I'm pretty sure I got that right
	cout << s6 <<endl;

	string s7 = R"***("quoted () string containing the usual terminator("))")***"; // I'm pretty sure I got that right
	cout << s7 <<endl;

	string s8 = R"*("quoted () string containing the usual terminator("))")*"; // I'm pretty sure I got that right
	cout << s8 <<endl;



	//string s9 = "('(?:[^\\\\']|\\\\.)*'|\"(?:[^\\\\\"]|\\\\.)*")|"; 
	// cout << s9 <<endl;
 string  counts {R"(1
22
333
)"};// a raw string literals can contain a newline.
	cout<<counts;

	string s10 {"1\n22\n333"};// I'm pretty sure I got that right
	cout << s10 <<endl;
	return 0;
}

/*
raw character strings:  R"()", not r"()" , not R""

一定要有圆括号。但是圆括号，作为语法格式一部分，本身并不是string的字符。


但如何要包含)?


"( & )" is the only default delimiter pair. We can add 

delimiters before the ( and after the ) in "(...)".for example:

R"***("quoted string containing the usual terminator("))")***"

delimiters:前后一样，对称。不唯一，可以自己指定。

This way we can cope with(almost) arbitrarily complicated patterns.





A raw character strings is string literal where a backslash is just a
backslash  (and a double quote is just a double quote)

raw  string literals use the R"(ccc)" notation for sequence of characters ccc.





\\
\"

*/
