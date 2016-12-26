apologies

r = 2.5
enum class Kind:char{
	name,number,end,
	plus='+',minus='-',div='/',print=';',assign='=',lp='(',rp=')'
};



struct Token{
	Kind kind;
	string sting_value;
	double number_value;
};


class Token_stream{

public:
	Token get();//read and return next token
	const Token& current();// most recently read token
};


double expr(bool get)// add and subtract
{
	double left = term(get);

	for(;;){
		switch(ts.current().kind){
			case Kind::plus:  left += term(true); break;
			case Kind::minus: left -= term(true); break;
			default: return left;
		}
	}
}


/*
The curious notation for(;;) is a way to specify an infinite loop.
you could pronounce it "forever"

*/

double term(bool get) //multiply and divide
{
	double left = prim(get);

	for(;;){
		switch(ts.current().kind){
			case Kind::mul:  left *= prim(true); break;
			case Kind::div: 
				if(auto d = prim(true) ){
					left /= d; break;
				}
				return error("divide by 0");
			default: return left;
		}
	}
}


double prim(bool get) // handle primaries
{
	if(get) ts.get(); ///read next token

	switch(ts.current().kind){
	case Kind::number:  //floating-point constant
		{
			double v = ts.current().number_value; 
			ts.get();
			return v;
		}
	case Kind::name:  
		{
			double& v = table[ts.current().string_value]; // find the corresponding
			if(ts.get().kind == Kind::assign) //'=' seen: assignment
				v = expr(true);
			return v;
		}
	case Kind::minus:  // unary minus
		{
			return -prim(true);
		}
	case Kind::lp: 
	  {
			auto e = expr(true);	
			if(ts.current().kind != Kind::rp)
			    return error("')' expected");
			ts.get();// eat ')'
			return e;
		} 
	default:
			return error("primary expected ");
	}
}



class Token_stream{

public:
 	Token_stream(istream& s):ip(&s),owns{false}{}
	Token_stream(istream* s):ip(p),owns{true}{}

	Token_stream(){close();}

	Token get(); // read and return next token
	Token& current();//most recently read token
	

	void set_input(istream& s){close(); ip= &s,owns=false;}
	void set_input(istream* s){close(); ip= s,owns=true;}

private:
	void close(){if(owns) delete ip;}

	istream* ip; // pointer to an input stream
	bool owns;//does the Token_stream own the istream?
	Token ct {Kind::end};//current token

};

Token Token_stream::get()
{
	char ch= 0;
	*ip >> ch;
	switch(ch){

	case 0: return ct = {Kind::end};//assign and return 
}

ct.kind = Kind:end; // assign
return ct;

case ';':// end of expression:print
case '*':
case '/':
case '+':
case '-':
case '(':
case ')':
case '=':
	return ct= {static_cast<Kind>(ch)};


case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9'
case '.':
	ip->putback(ch);// put the first digit (or .)back into the input stream
	*ip>>ct.number_value;//read the number into ct
	ct.kind=Kind::number;
	return ct;



default:
	// name ,name =,or error
	if(isalpha(ch)){
		ip->putback(ch);// put the first character back into the input stream
		*ip>>ct.sting_value;//read the string into ct
		ct.kind=Kind::name;
		return ct;
	}
/*

whim


deceptively 
*/


error("bad token");
return ct = {Kind::print};

Token Token_stream::get()
{
	char ch= 0;
	*ip >> ch;
	switch(ch){

	case 0: return ct = {Kind::end};//assign and return 
	
	case ';':// end of expression:print
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
	return ct= {static_cast<Kind>(ch)};
	
	case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case  '8':case '9'
    case '.':
	ip->putback(ch);// put the first digit (or .)back into the input stream
	*ip>>ct.number_value;//read the number into ct
	ct.kind=Kind::number;
	return ct;

	default:
	// name ,name =,or error
	if(isalpha(ch)){
		ip->putback(ch);// put the first character back into the input stream
		*ip>>ct.sting_value;//read the string into ct
		ct.kind=Kind::name;
		return ct;
	}
	error("bad token");
	return ct = {Kind::print};
	}	
}




Token Token_stream::get()
{
	char ch= 0;
	do{
			// skip whitespace except '\n'
		if(!ip->get(ch))return ct={Kind::end};
	}while(ch !='\n'&& isspace(ch));
	switch(ch){
	case ':':
	case '\n':return ct = {Kind::print};
	}
}


default:
	// name ,name =,or error
	if(isalpha(ch)){
		string_value = ch;
		while(ip->get(ch)&&isalnum(ch))
			string_value += ch; //append ch to end of string_value
		ip->putback(ch);
		return ct={Kind::name};
	}


int no_of_errors;
double error(const string& s){

	no_of_errors++;
	cerr<<"error:"<<s<<endl;
	return 1;
}

/*
	The stream cerr is an unbuffered output stream usually used to report errors.

stylized
*/

Token_stream ts {cin}; //use input from cin

void calculate()
{
	for(;;){//forever
		ts.get();
		if(ts.current().kind == Kind::end) break;	
		if(ts.current().kind == Kind::print) continue;	
		cout<<expr(false)<<endl;
	}
}

int main()
{
	table["pi"] = 3.1415926535;//insert predefined names
	table["e"] = 2.718281;

	calculate();
	return no_of_errors;
}



/*

Headers:
#include<iosteam>//I/O 
#include<string>// strings
#include<map>//map
#include<cctype>//isalpha(),etc.


a stream  that reads from a string is unsurprising called an istringstream.

so to calculate expressions presented on the command line.we simply have to 
get our  Token_stream to read from an appropriate istringstream.
*/


Token_stream ts {cin}; //use input from cin



int main(int argc,char* argv[])
{
	switch(argc){
		case 1:break;
		case 2:ts.set_input(new istringstream{argv[1]}) break;
		default: error("too many arguments");return 1;
	}

	table["pi"] = 3.1415926535;//insert predefined names
	table["e"] = 2.718281;

	calculate();
	return no_of_errors;
}


vector<string> arguments(int argc,char* argv[])
{
	vector<string> res;
	for(int i = 0; i!=argc;++i)
		res.push_back(argv[i]);
	return res;
}

/*

scarcity

parenthesized expression (expr)
Lambda  [capture-list] lambda-declarator {stmt-list}
scope resolution class-name::member
scope resolution namespace-name::member
global            ::name

value construction type {expr-list}

and &
and_eq &=
bitand &
bitor |
compl ~
not !
not_eq !=
or | // || ?
or_eq |=
 xor ^
xor ^=


Max Munch rule

abrupt 

underflow
overflow


in particular ,you can not assume that the expression is evaluated left-to-right.


*/

int x = f(2)+g(3);// undefined whether f() or g() is called first.
int i = 1;
v[i] = i++;//undefined result


void f(int x,int y)
{
	int j = x = y;
	int* p = &++x;
	int* q = &(x++);
	int* p2 = &(x>y?x:y);
	int& r = (x<y)?x:1;
}

f1(v[i],i++);//two arguments
f2((v[i],i++));//one argument


/*
mathematician.

*/



void f(string& s1,string& s2, string& s3)
{
	const char* cs = (s1+s2).c_str();
	cout<<cs;
	if(strlen(cs=(s2+s3).c_str())<8 && cs[0]=='a'){
		//cs used here
	}
}


void f(string& s1,string& s2, string& s3)
{
	
	cout<<s1+s2;
	string s = s2+s3;
	if(s.length()<8 && s[0]=='a'){
		// use s here
	}
}

void g(const string &,const string &);


void h( string & s1, string& s2)
{
	const string& s= s1+s2;
	string ss = s1+s2;
	g(s,ss);//
}



void f(Shape& s,int n,char ch)
{
	s.move(string{n,ch});//construct a string with n copies of ch to pass to Shape::move()
}

int x1 = 7;
constexpr int x2 = 7;
constexpr int x3 = x1;// error:initializer is not a constant expression
constexpr int x4 = x2;//ok

void f()
{
constexpr int y3 = x1;// error:initializer is not a constant expression

constexpr int y4 = x2;//ok
}

constexpr int isqrt_helper(int sq,int d,int a)
{
	return sq<=a?isqrt_helper(sq+d,d+2,a):d;
}


constexpr int isqrt(int x)
{
	return isqrt_helper(1,3,x)/2-1;
}



constexpr int s1 = isqrt(9);//s1 becomes 3
constexpr int s2 = isqrt(1234);


const int x = 7;
const string s = "asdf";
const int y = sqrt(x);

constexpr int xx = x; //ok
constexpr string ss = s;// error: s is not a constant expression

constexpr int yy = y; //  sqrt(x)is not  a constant expression

/*
usually, constexpr is a better choice than const  for defining simple constants,
but constexpr is new in c++11.


*/


struct Point{
	int x,y,z;
	constexpr Point up(int d){return {x,y,z+d};}
	constexpr Point move(int dx,int dy){return {x+dx,y+dy};}
};

//origo
constexpr Point origo {0,0};
constexpr int z = origo.x;

constexpr Point a[] = {
	origo,Point{1,1},Point{2,2},Point.move(3,3)
};
constexpr int x = a[1].x;//



constexpr Point  xy{0,sqrt(2)};//error:sqrt(2)is not  a constant expression


constexpr int square(int x)
{
	return x*x;
}
constexpr int radial_distance(Point p)
{
	return isqrt(square(p.x)+square(p.y)+square(p.z));
}

constexpr Point p1 {10,20,30};//the default constructor is constexpr
constexpr p2{p1.up(20)};//Point::up() is  constexpr

constexpr int dist = radial_distance( p2);


constexpr Point move(int dx,int dy) const {return {x+dx,y+dy};}


template<>
class complex<double>{

public:
	constexpr complex(double re = 0.0,double im = 0.0);
	constexpr complex(const　complex<float>& );
	explicit  constexpr complex(const complex<long double>&);

	constexpr double real();	//read the real part
	void real(double);// set the real part
	
	constexpr double imag();// read the imaginary part
	void imag(double);// set the imaginary part
	
	complex<double>& operator=(double);
	complex<double>& operator+=(double);
};


constexpr complex<float> z1 {1,2};//note:<float>not<double>
constexpr double re = z1.real();
constexpr double im = z1.imag();


constexpr complex<double>　z2 {re,im}; // z2 becomes a copy of z1
constexpr complex<double>　z3 {z1};// z3 becomes a copy of z1




/*
impoverished

the implicit conversions that preverse values are commonly referred to as promotions.

bewildering

*/

constexpr const char* p1 = "asdf";
constexpr const char* p2 = p1;//ok
constexpr const char* p2 = p1+2;//error: the compiler does not  know the value of p1
constexpr  char c = p1[2];//ok c=='d', the compiler    knows the value pointed to by p1



//

void f(double d)
{
	char  c = d;// beware: double-precison floating-point to char conversion
}
void f(double d)
{
	char  c { d};// error: double-precison floating-point to char conversion
}


/* congrument */

unsigned char uc = 1023; // binary 11111111, uc becomes binary 11111111:that is 255


signed char sc =  1023;// implementation -defined


float f = FLT_MAX; // largest  float value
double d = f;//ok d ==f

// FLT_MAX, DBL_MAX int  <climits>

double d2 = DBL_MAX;	// largest  double value
float f2 = d2;// undefined: if FLT_MAX <  DBL_MAX



long double ld = d2 // ok ld == d2

// numeric_limits in <limits>

long double ld2 = numeric_limits<long double>::max();

double  d3 = ld2;//undefined: if  sizeof(long double) > sizeof( double)
 
/*

	any pointer to an object type can be implicitly converted to a void*
	a pointer (reference)to a derived class can be  implicitly  converted to a pointer
(reference) to an  accessible  and unambiguous base.

*/

int* p= (1+2)*(2*(1-1));//ok but weird

void f(int* p,int i)
{
	bool is_not_zero = p;// true if p != 0
	bool b2 = i; // true if i != 0
	
}

void fi(int);
void fb(bool);

void ff(int* p,int* q )
{
	if(p) do_something(*p);//ok
	if(q != nullptr) do_something(*q);//ok but verbose

	fi(p);// error:no pointer to int conversion
	fb(p);// ok :pointer to bool conversion(surprise???)
}


int i = 2.7;// i is 2
char b = 2000.7 // undefined for 8-bit chars:

char checked_cast(int i)
{
	char c = i;// warning: not portable
	if( i != c) throw std::runtime_error{"int-to-char check failed"};
 return c;
}


void my_code(int i)
{
	char c = checked_cast( i);
}


/*
in initializations, truncation can be avoided by using  the {}-initializer notation.

1)prefer the standard library to  other libraries and to "handcrafted code"
2)use character-level input only when you have to 
3)perfer suitable  abstractions(classes ,algorithms.etc) to direct use of  language features.
4) when reading ,always consider ill-format input
5) avoid complicated expressions
6) if in doubt about operator precedence ,parenthesize
7) avoid expressions with undefined order of  evaluation;
8) avoid narrowing conversions
9) Define symbolic constants to avoid  "magic constants"

*/


