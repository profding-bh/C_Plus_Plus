// Graph_lib:--defined in a header  Graph_lib.h

class Shape {/* ... */ };

class Line:public Shape {/* ... */ };
class Poly_Line:public Shape {/* ... */ };// connected sequence of lines
class Text:public Shape {/* ... */ };// text label



Shape operator+(const Shape&, const Shape&);// compose


Graph_reader open(const char*);// open files of Shapes



// Text_lib:--defined in a header  Text_lib.h
class Glyph { /* ...*/ };
class Word { /* ...*/ }; // sequence of Glyphs
class Line { /* ...*/ }; 	// sequence of Words
class Text { /* ...*/ }; // sequence of Lines


File* open(const char* ); // open text file

Word operator+(const Line&, const Line&);// concatenate


#include"Text_lib.h"
#include"Graph_lib.h" //


//namespace-name::member-name notation.



// Explicit Qualification:

namespace namespace-name{

// declaration & definitions

}


namespace Parser{
	double expr(bool);// declaration
	double term(bool);
	double prim(bool);
}



double varl = Parser::expr();//use


double Parser::expr(bool b) // definition
{

}

// we cannot declare a new member of a namespace outside a namespace definition
//using the qualifier syntax.

void Parser::logical(bool);// error:no logical() in Parser
double Parser::trem(bool);//error:no trem() in Parser(misspelling)

double Parser::prim(int);//error:Parser::prim() takes a bool argument(wrong type)


// a namespace is a scope.
// the global scope is a namespace and can be explicitly referred to using ::.
// classes are namespaces.


using-Declarations

#include<string>
#include<vector>
#include<sstream>


std::vector<std::string> split(const std::string& s)
{
	std::vector<std::string> res;
	std::istringstream iss(s);

	for(std::string buf;iss>>buf;)
		res.push_back(buf);

	return res;
}


// to alleviate that we can use a using-declaration to say that
// in this code string means std::string

using std::string; // use "string" to mean "std::string"

std::vector<string> split(const string& s)
// split s into its whitespace-separated substrings
{
	std::vector<string> res;
	std::istringstream iss(s);

	for(string buf;iss>>buf;)
		res.push_back(buf);

	return res;
}


namespace N{

	void f(int);
	void f(string);
}


void
g()
{
	using N::f;
	f(789); // N::f(int)
	f("Bruce");//N::f(string)
}



 using-Directive
// we can use a using-directive to request that every name from a namespace
// be accessible in our scope without qualification.

using  namespace std;// make every name from std accessible

vector<string> split(const string& s)
// split s into its whitespace-separated substrings
{
	vector<string> res;
	istringstream iss(s);

	for(string buf;iss>>buf;)
		res.push_back(buf);

	return res;
}
 
/*

so, the trade-off among explicit qualification,using-declaration,and using-directives
must be made on a case-by-case basis. The rules of thumb are:

1) If some qualification is really common for several names,use a using-directive for that
namespace

2) If some qualification is  common for a particular name from a namespace, use a using-declaration
for that name.

3) If a qualification for a name is uncommon, use explicit qualification to make it clear
from where the name comes.

4) Don't use explicit qualification for names in the same namespace as the user.


*/


namespace Parser{//user interface
 	double expr(bool);
}


namespace Parser{ //implementer  interface
	double prim(bool ); 
	double term(bool ); 
	double expr(bool ); 

	using namespace Lexer;// use all facilities offered by lexer
	using Error::error;
	using Table::table;
	
}



namespace Parser{//user interface
 	double expr(bool);
}


namespace Parser_impl{ //implementer  interface
	using namespace Parser;

	double prim(bool ); 
	double term(bool ); 
	double expr(bool ); 

	using namespace Lexer;// use all facilities offered by lexer
	using Error::error;
	using Table::table;
	
}

// composition using namespace
namespace X{
	int i,j,k;
}

int k;

void 
f1()
{
	int i = 0;
	using namespace X;// make  names from X accessible
	i++; //local i
	j++; // X::j
	k++;// error: X's k or the global k?
	::k++;// the global k
	X::k++;// X's k 
	
}

void 
f2()
{
	int i = 0;
	using X::i;// error:i declared twice in f2()
	using X::j;
using X::k; // hides global k


	i++;
	j++;// X::j
	k++;// X::k
}




// namespace aliases
namespace A{ //short name,will clash(eventually)
//...
}

A::String s1 = "Grieg";
A::String s2 = "Nielsen";

namespace American_Telephone_and_Telegraph{// too long
//..
}

American_Telephone_and_Telegraph::string s3 = "Grieg";
American_Telephone_and_Telegraph::string s4 = "Nielsen";

// use namespace alias to shorten names.

namespace ATT = American_Telephone_and_Telegraph;
ATT::string s3 = "Grieg";
ATT::string s4 = "Nielsen";

// namespace aliases also allow a user to refer to "the library"

namespace Lib = Foundation_library_v2r11;

// ...

Lib::set s;
Lib::String s5 = "Sibelius";


// namespace composition:


namespace His_string{
	class  String { /* ....*/ };
	String operator+(const String&,const String& );
	String operator+(const String&,const char* );
	
	void fill(char);
//..
}

namespace Her_vector{
	template<class T>
		class Vector { /* ....*/  };
	//..
}


namespace My_lib{
	using  namespace His_string;
	using  namespace Her_vector;
	
	void my_fct(String &);
}

void f()
{
	 My_lib::String s = "Byron";// finds My_lib::His_string::String
	//..
	
}
using  namespace My_lib;


void g(Vector<String>& vs)
{
	//..
	my_fct(vs[5]);
	//..
}


void My_lib::fill(char c) // error: no fill() declared in My_lib
{
	//..
}


void His_string::fill(char c) // ok:  fill() declared in His_string
{
	//..
}

void My_lib::my_fct(String& v)//ok:String is My_lib::String,meaning His_string:: String
{
	//...
}
/*

ideally, a namespace should 
1) express a logically coherent set of features,
2) not give users access to unrelated features,and,
3) not impose a significant notational burden on users.

*/

namespace His_lib{
	class  String { /* ....*/ };
	template<class T>
		class Vector { /* ....*/ };
	//...
}

namespace Her_lib{
	
	template<class T>
		class Vector { /* ....*/ };
	class  String { /* ....*/ };
	//...
}


namespace My_lib{
	using namespace Her_lib;// everything from Her_lib
	using namespace His_lib;// everything from His_lib
	
	
	using  His_lib::String; // resolve potential clash in favor of His_lib
	using  Her_lib::Vector; // resolve potential clash in favor of Her_lib
	
	template<class T>
		class List { /* ....*/ };// additional stuff
	//...
}



namespace Lib2{
	using namespace Her_lib;// everything from Her_lib
	using namespace His_lib;// everything from His_lib
	
	
	using  His_lib::String; // resolve potential clash in favor of His_lib
	using  Her_lib::Vector; // resolve potential clash in favor of Her_lib
	
	using  Her_String = Her_lib::String;// rename

	
	
	
	template<class T>
		using His_vec  = His_lib::Vector<T>;//rename

	template<class T>
		class List { /* ....*/ };// additional stuff
	//...
}




/*
namespaces and overloading

*/
//old A.h
void f(int);
//..


//old B.h
void f(char);
//..


//old user.c
#include"A.h"
#include"B.h"

void 
g()
{
	f('a');// calls the f() from B.h
}


//new A.h
namespace A{
	void f(int);
//..
}


//new B.h
namespace B{
void f(char);
//..

}


//new user.c
#include"A.h"
#include"B.h"

//using-directives:
using namespace A;
using namespace B;

void 
g()
{
	f('a');// calls the f() from B.h
}
// it is usually best to avoid using-directives in header files.
// because, putting them there greatly increases the chances of name clashes.


sort(v.begin(),v.end());

sort(v)

#include<algorithm>

namespace Estd{
	using  namespace std;
	template<class C>
		void sort(C& c){ std::sort(c.begin(),c.end()); }
	template<class C,class P>
		void sort(C&c, P p){ std::sort(c.begin(),c.end(),p);}
}

using namespace Estd;

template<class T>
void print(const vector<T>& v)
{
	for(auto& x:v)
		cout<<v<<' ';
cout<<"\n";
}


void f()
{
	std::vector<int> v {7,3,9,4,0,1};
	
	sort(v);
	print(v);
	sort(v,  [](int x,int y){ return x >y; }  );
	print(v);

	
sort(v.begin(),v.end());
	print(v);
	sort(v.begin(),v.end(), [](int x,int y){ return x >y; } );
	print(v);
}

namespace Popular{
 	inline  namespace V3_2{// V3_2 provides the default meaning of Popular
			double f(double);
			int f(int);
			template<class T>
				class C { /* ....*/ }
	}
	 namespace V3_0{
		//...
		
	}
	
	namespace V2_4_2{//...
			double f(double);
			template<class T>
				class C { /* ....*/ }
	}
}


using namespace Popular;

void f()
{
	f(1);// Popular::V3_2::f(int)
	V3_0::f(1);// Popular::V3_0::f(double)
	V2_4_2::f(1);// Popular::V2_4_2::f(double)
}
template<class T>
Popular::C<T*> 
{ /* ....*/ }

// file V3_common:
	//...lots of delcarations..
// file V3_2


namespace V3_2{// V3_2 provides the default meaning of Popular
	double f(double);
	int f(int);
	template<class T>
		class C { /* ....*/ }
	#include"V3_common"
}


// file V3_0.h

namespace V3_0{
	#include"V3_common"
}

//file Popular.h:

namespace Popular{
	inline
	#include"V3_2.h"
	#include"V3_0.h"
	#include"V2_4_2.h"
}


//nested namespaces
namespace X{
// ..all my declarations...
}

void h();
namespace X {
	void g();
	//...
	namespace Y {
	void f();
	void ff();
	//...
	
	}
}



void X::Y::ff()//猜测是 ,X::Y::已经说明了在哪个namespace?
{	
	f();//我的 X::Y::f();
	g();//我的 X::g();
	h();
}


void X::g()
{
	f();// error: no f() in X
	Y::f();//ok
}




void h()
{
	f();// error:no global f()
	Y::f();// error:no global Y
	X::f();// error:no global in X
	X::Y::f();//ok
}





//unnamed namespaces
// the aim is to preserve locality of code rather than to present an interface
// to users.

#include"header.h"

namespace Mine{
	int a;
	void f(){ /* */ }
	int g(){ /* */ }
}

#include"header.h"

namespace {
	int a;
	void f(){ /* */ }
	int g(){ /* */ }
}

// clearly,there has to be some way of accessing members of an unnamed namespace
// from outside the unnamed namespace.Consequently, an unnamed namespace has an
// implied using-directive.
// the previous declaration is equivalent to:
#include"header.h"

namespace $$${
	int a;
	void f(){ /* */ }
	int g(){ /* */ }
}


//cstdio:
namespace std{
	int printf("const char*"...);
}



//stdio.h
#include<cstdio>
using namespace std;



#include<vector>// carefully avoids polluting the global namespace
vector v1;// error:no "vector" in global scope.
#include<stdio.h>// contains a "using namespace std;"
vector v2;// oops:this now works



//stdio.h
#include<cstdio>
using  std::printf;
//...





















 


