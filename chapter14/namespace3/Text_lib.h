// Text_lib:--defined in a header  Text_lib.h

namespace Text_lib  {
class Glyph { /* ...*/ };
class Word { /* ...*/ }; // sequence of Glyphs
class Line { /* ...*/ }; 	// sequence of Words
class Text { /* ...*/ }; // sequence of Lines


File* open(const char* ); // open text file

Word operator+(const Line&, const Line&);// concatenate
}

using namespace Graph_lib;
using namespace Text_lib;


Glyph gl; // Text_lib::Glyph
vector<Shape*> vs;// Graph_lib::Shape


Text txt;// error: ambiguous
File* fp= open("my_precious_data");//error: ambiguous
// In particular, don't place a using-directive in the 
// global scope in a header file except in very specialized 
// circumstances.

// Argument-Dependent Lookup

/*
a function taking an argument of user-defined type X is more often
than not defined in the same namespace as X. Consequently, if a function
isn't found in the context of its use,we look in the namespace of its arguments.

*/

namespace Chrono{
 class Date {/* ... */ }
 bool operator==(const Date&, const std::string&);

	std::string format(const Date&);// make string representation
	//...
}


void
f(Chrono::Date d,int i)
{
	std::string s = format(d);// Chrono::format()
	std::string t = format(i);// error: no format() in scope
}
// This lookup rule(called Argument-Dependent Lookup or simple ADL)

// Note that the namespace itself needs to be in scope 

// Naturally,a function can take arguments from more than one  namespace.


void
f(Chrono::Date d,std::string s) // f属于一个namespace
{
	if(d == s){
		//....
	}else if(d == "August 4,1914"){
			//..
	}
}


namespace N{
	struct S {int i;}
	void f(S);
	void g(S);
	void h(int);
}

struct Base{
	void f(N::S);
};

struct D:Base{// see,struct也可以继承!!!
	void mf();
	
	void g(N::S x){
		f(x);// call Base::f()
		mf(x);// call D::mf()
		h(1);//error:no h(int) available
	}
};


/*
In the standard, the rules for argument-dependent lookup are phrased in 
terms of associated namespaces.Basically:

If an argument is a class member,the associated namespaces are the class
itself(including its base classes) and  the class's enclosing namespaces.

If an argument is a member of a namespace,the associated namespaces are the 
enclosing namespaces.

If an argument is a build-in type,there are no associated namespaces.

*/




namespace N{
	template<class T>
		void f(T,int);//N::f()
	class X {};
}

namespace N2{
	N::X x;

	void f(N::X,unsigned);
	
	void g(){	
		f(x,1);// calls N:f(X,int),not f(N::X,unsigned)
	}
}



/*
namespaces are open


*/

namespace A{
	int f(); // now A has member f()
}

namespace A{
	int g(); // now A has two members f() and g()
}


//my header:
void mf();// my function
void yf();// your function
void mg();// my function



// my header:
namespace Mine{
	void mf();//  my function
}


void  yf();// your function


namespace Mine{
	void mg();// my function
}


namespace Parser{
	double expr(bool);
	double prim(bool get) {/* ... */ }
	double term(bool get) {/* ... */ }
	double expr(bool get) {/* ... */ }
}

namespace Lexer{
	enum class Kind:char{/* ... */}
	class Token 	{/* ... */}
	class Token_stream {/* ... */}

	Token_stream ts;
}

namespace Table{
	map<string,double>table;
}
namespace Driver{
	void calculate() {/* ... */}
}

int main()  {/* ... */}


namespace Error{
	int no_of_error;
	double  error(const string& s) {/* ... */}
}


// a module can provide different interfaces to different
//users, and often an interface is designed long  before the implementation
// details are made concrete.


namespace Parser{
	double prim(bool ); 
	double term(bool ); 
	double expr(bool ); 
}


double 
Parser::prim(bool get) 
{ /*... */ 

}
 
double 
Parser::term(bool get) 
{ /*... */ 

}
double 
Parser::expr(bool get) 
{ /*... */ 

}


double Parser::prim(bool get)
{
	if(get)  Lexer::ts.get();

	switch(Lexer::ts.current().kind){
		case Lexer::Kind::number: 
		{
			double v = Lexer::ts.current().number_value;
			Lexer::ts.get();
			return v;
		}
		case Lexer::Kind::name: 
		{
			double&  v = Table::table[Lexer::ts.current().string_value];
			if(Lexer::ts.get().kind ==  Lexer::Kind::assign) v = expr(true);
			// '=' seen: assignment
			return v;
		}
		case Lexer::Kind::minus://unary minus
			return -prim(true);
		case Lexer::Kind::lp: 
		{
			double  e = expr(true);
			if(Lexer::ts.current().kind !=  Lexer::Kind::rp) 
				return Error::error("')' expected");
			Lexer::ts.get();//eat ')'
			return e;
		}
		default:
			return Error::error("primary expected");
	}
}


using  Lexer::ts;// saves eight occurences of "Lexer::"
using  Lexer::Kind; // saves six occurences of "Lexer::"
using  Error::error;//  saves two occurences of "Error::"
using  Table::table; //  saves one occurence of "Table::"


double prim(bool get)//handle primaries
{
	if(get)  ts.get();

	switch(ts.current().kind){
		case Kind::number: 
		{
			double v = ts.current().number_value;
			ts.get();
			return v;
		}
		case Kind::name: 
		{
			double&  v = table[ts.current().string_value];
			if(ts.get().kind ==  Kind::assign) v = expr(true);
			// '=' seen: assignment
			return v;
		}
		case Kind::minus://unary minus
			return -prim(true);
		case Kind::lp: 
		{
			double  e = expr(true);
			if(ts.current().kind !=  Kind::rp) 
				return error("')' expected");
			ts.get();//eat ')'
			return e;
		}
		default:
			return error("primary expected");
	}
}


/*
if we use using-directives,we get:


*/
using namespace Lexer; // saves fourteen occurences of "Lexer::"
using namespace Error; // saves two occurences of "Error::"
using namespace Table; //  saves one occurence of "Table::"

double prim(bool get)//handle primaries
{
	// as before
}














