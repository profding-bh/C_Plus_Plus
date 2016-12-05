
enum class (a scoped enumeration)is an enum where the enumerators are within the 
scope of the enumeration and  no implicit conversions to other types are provided.

an array of an aggregate of elements of the same type.


struct Address {
	const char* name; // "Jim Dandy"
	int number;//61
	const char* street; // "South St"
	const char* town;// "New Providence"
	char state[2]; // 'N' 'J'
	const char* zip;// "07974"
};


void
f()
{
	Address jd;
	jd.name = "Jim Dandy";
	jd.number = 61;
}

Address jd = {
	"Jim Dandy"
	61,"South St",
	"New Providence",
	{'N','J'},
	"07974"
};


void print_addr(Address* p)
{
	cout<<p->name<<"\n"
		<<p->number<<' '<<p->street<<"\n"
		<<p->town<<"\n"
		<<p->state[0]<<p->state[1]<<' '<<p->zip<<"\n";
}


void print_addr2(const Address& r)
{
	cout<<r.name<<"\n"
		<<r.number<<' '<<r.street<<"\n"
		<<r.town<<"\n"
		<<r.state[0]<<r.state[1]<<' '<<r.zip<<"\n";
}



Address current;
Address set_current(Address next)
{
	Address prev = current;
	current = next;
	return prev;
}

//struct Layout

struct Readout{
	char hour; //[0:23]
	int value;
	char seq;// sequence mark ['a':'z']
};
// 所以,安排成员时,应该从小到大.
// members are allocated in memory in declaration order.


struct Readout{
	int value;
	char hour; //[0:23]	
	char seq;// sequence mark ['a':'z']
};


// struct Names
struct Link{
	Link* previous;
	Link* successor;
};


struct No_good{
	No_good member;// error:recursive definition
};

struct List;

struct Link{
	Link* pre;
	Link* suc;
	List* member_of;
	int data;
};

struct List{
	Link* head;
};


struct S; // S is the name of some type

extern S a;
S f();
void g(S);
S* h(S*);

void 
k(S* p)
{
	S a;// error: S not defined;size needed to allocate

	f();// error: S not defined;size needed to return value
	g(a);// error: S not defined;size needed to pass argument 
	p->m = 7;// error: S not defined;member name not known
	
	S* q = h(p);	// ok:pointers can be allocated and passed
	q->m = 7;//error: S not  defined;member name not known
}



struct stat {/*...*/ };
int stat(char*name ,struct stat* buf);

// A struct is simply a class where  the members are public  by default. So,a 
// struct can have member functions. In particular, a struct can have constructors.

struct Points{
	vector<Point>elem; // must contain at least one Point
	Points(Point p0){ elem.push_back(p0); }
	Points(Point p0,Point p1){elem.push_back(p0); elem.push_back(p1); }
	//...
};

Points x0;//error: no default constructor
Points x1 {{100,200}};// one point
Points x1 {{100,200},{300,400}};// two points

struct Point{
	int x,y;
};
Point p0;// danger; uninitialized if in local scope
Point p1 {};//default construction: {{},{}} ; that is {0.0}
Point p2 {1};// the second member is default  constructed:{1,{}};that is {1,0}
Point p3 {1,2}; //{1,2}


struct Address{
	string name; // "Jim Dandy"
	int number;//61
	string street;// "South St"
	string town;// "New Providence"
	char state[2];// 'N','J'
	char zip[5];// 07974
	
	Address(const string n,int nu,const string& const string& t,const string& st,int z);
};


Address jd = {
	"Jim Dandy",
	61,
	"South St",
	"New Providence",
	"NJ",
	7974 // 07974 would be octal
};

Address::Address(const string n,int nu,const string& s const string& t,const string& st,int z)
// validate postal code
:name(n),number(nu),street(s),town(t)
{
	if(st.size() != 2)
		error("State abbreviation should be two characters")
	state = {st[0],st[1]};// store postal code
	ostringstream ost;// an output string stream:
	ost<<z;
	string zi {ost.str()};
	switch(zi.size()){
		case 5:
		zip={zi[0],zi[1],zi[2],zi[3],zi[4]};
		break;
		case 4:
		zip={zi[0],zi[1],zi[2],zi[3]};
		break;
		default:
			error("unexpected ZIP code format");
	}
	// ...check that the code makes sense...
}


//Naturally,we can have arrays of structs and structs containing arrays.

struct Point{
	int x,y;
};
Point points[3] {{1,2},{3,4},{5,6}};// array of structs 

int x2 = points[2].x;

struct Array{
	Point elem[3];// struct containing array.
};
Array  points2 {{1,2},{3,4},{5,6}};
int y2 = points2.elem[2].y;


Array shift(Array a, Point p)
{
	for(int i=0; i!=3;++i){
		a.elem[i].x +=  p.x;
		a.elem[i].y +=  p.y;
	}
	return a;	
}


Array ax = shift(points2,{10,20});

template<typename T, size_t N>
struct array{
	T elem[N];
	T* begin() noexcept {return elem;}
	const T* begin() const noexcept {return elem;}
	T* end() noexcept {return elem+N;}
	const T* end() const noexcept {return elem+N;}
	

	constexpr size_t size() noexcept;
	T&  operator[](size_t n) {return elem[n];}
	const T&  operator[](size_t n) const  {return elem[n];}

	T* data() noexcept {return elem;}
	const T* data() const noexcept {return elem;}

	//...
};
	
struct Point{
	int x,y;
};

using Array = array<Point,3>; // array of 3 Points

Array  points {{1,2},{3,4},{5,6}};

int x2 = points[2].x;
int y2 = points[2].y;



Array shift(Array a, Point p)
{

	for(int i=0; i!=a.size();++i){
		a[i].x +=  p.x;// 直接a[i], not a.elem[i]
		a[i].y +=  p.y;
	}
	return a;	
}
Array ax = shift(points,{10,20});

ostream& operator<<(ostream& os, Point p)
{
	cout<<'{'<<p[i].x<<','<<p[i].y<<'}';
}

void print(Point a[],int s) // must specify number of elements
{
	for(int i = 0;i !=s;++i)
		cout<<a[i]<<'\n';
}


template<typename T,int N>
void print(array<T,N>& a)
{
	for(int i=0; i!=a.size;++i)
		cout<<a[i]<<'\n';
}

Point point1[] = {{1,2},{3,4},{5,6}};// 3 elements
array<Points,3> point2 = {{1,2},{3,4},{5,6}};// 3 elements


void f()
{
	print(point1,4);	// 4 is a bad error
	print(point2);
}


Point point1[] = {{1,2},{3,4},{5,6}};
array<Points,3> point2 = {{1,2},{3,4},{5,6}};// 3 elements
array<Point> point3 = {{1,2},{3,4},{5,6}};//error:number of elements not given


struct S1 {int a;};
struct S2 {int a;};

// Two structs are different types even when they have the same members.

S1 x;
S2 y = x;// error:type mismatch

S1 x;
int i = x;// error:type mismatch


// POD: Plain Old Data 
// POD is an object that can be manipulated as "just data" without worrying
// about  complications of class  layouts or user-defined semantics for construction,copy,and 
// move.
struct S0 {}; // a POD
struct S1 {int a;}; // a POD
struct S2 {int a;S2(int aa):a(aa){} }; // not a POD(no default constructor)
struct S3 {int a;S3(int aa):a(aa){} S3(){} }; //  a POD(user-defined default constructor)
struct S4 {int a;S4(int aa):a(aa){} S4()=default; }; //  a POD
struct S5 {virtual void f();/*..*/}// not a POD(has a virtual function)

struct S6:S1{}; //a POD
struct S7:S0{ int b;}; //a POD
struct S8:S1{ int b;}; // not a POD (data in both S1 and S8)
struct S9:S0,S1{}; //a POD


// for us to manipulate an object  as "just data"(as a POD),the object must
1)not have a complicated layout(e.g.:with a vptr;)
2)not have nonstandard(user-defined)copy semantics,and
3)have a trivial default constructor

template<typename T>
	void mycopy(T* to,constT* from,int count);

template<typename T>
void mycopy(T* to,constT* from,int count)
{
	if(is_pod<T>::value)
		memcpy(to,from,count*sizeof(T));
	else
		for(int i=0;i!=count;++i)
			to[i] = from[i];
}



// It seems extravagant to use a whole byte(a char or a bool) to represent a binary
// variable-for example ,an on/off switch --but a char is the smallest object that can 
// be independently allocated and addressed in C++.

//  A field  is often called a bit-field.


struct PPN{// R6000 Physical Page Number
	unsigned int PFN:22;// Page Frame Number
	int :3;//unused
	unsigned int  CCA:3; //Cache Coherency Algorithm
	bool nonreachable:1;
	bool dirty:1;
	bool valid:1;
	bool global:1;
};
//  A field must be of an integral or enumeration type.


// Note that a bool field really can be represented by a single bit.



void part_of_VM_system(PPN* p)
{
	//..
	if(p->dirty){ // contents changed
		// copy to disk
		p->dirty = 0;
	}
}


// A union is a struct in which all members are allocated at the same address that the union
// occupies only as much space as its largest member.

enum Type{ str,num};

struct Entry{
	char* name;
	Type t;
	char* s; // use s if t == str
	int i; // use i if t == num
};



void f(Entry* p)
{
	if(p->t == str)
		cout<<p->s;
	//..
}



union Value{
	char* s; 
	int i;
};

struct Entry{
	char* name;
	Type t;
	Value v;// use v.s if t == str ; use v.i if t == num
};


void f(Entry* p)
{
	if(p->t == str)
		cout<<p->v.s;
	//..
}


union Fudge{
	int i;
	int* p;
};

int*
cheat
(int i)
{
	Fudge a;
	a.i = i;
	return a.p; //bad use
}


int*
cheat2
(int i)
{
	return reinterpret_cast<int*>(i); //obviously ugly and dangerous
}

/*
many of the facilities provided for classes are not relevant for unions,so some
restrictions are imposed on unions:

1)a union cannot have virtual functions.
2)  a union cannot have members of reference type.
3)  a union cannot have base classes.//union is a final class
4)  If a union has  a member with a user-defined constructor, a copy operation,a move operation,
or a destructor,then that special function is deleted for that union;
5) at most one member of a union can have an in-class initializer.
6) a union cannot be used as a base class

*/

void f(Entry a)
{
	Entry b = a;
}


union U{
	int m1;
	complex<double>m2;// complex has a constructor
	string m3;// string has a constructor(maintaining a serious invariant )
};


void f2(U x)
{
	U u; // error: which default  constructor?
	U u2 = x;// error: which copy  constructor?
	u.m1 = 1;// assign to int member
	string s = u.m3;//disaster, read from string member
	return ;//error:which destructors are called for x,u,and u2?
}


union U2{
	int a;
	const char* p{""};
};

U2 x1;// default initialized to x1.p == ""
U2 x2 {7};// x2.a == 7


class Entry2{ // two alternative representations represented as a union
	private:
	enum class Tag {number,text};
	Tag type;// discriminant	

	union{ // representation
		int i;
		string s;// string has default  constructor,copy operation and destructor.
	};
	public:
	struct Bad_entry{};// used for exceptions

	string name;
	~Entry2();
	Entry2& operator=(const Entry2&);// necessary because of the string variant
	Entry2(const Entry2&);
	//..
	int number() const;
	string text()const;

	void set_number(int n);
	void set_text(const string&);
	//..
};



int  Entry2::number() const
{
	if(type != Tag::number) throw  Bad_entry{};
	return i; // 这也能访问到??需要确认一下!见后面560行
}


string  Entry2::text() const
{
	if(type != Tag::text) throw  Bad_entry{};
	return s;// 这也能访问到??需要确认一下!  见后面560行
}



void  Entry2::set_number(int n)
{
	if(type == Tag::text){
		s.~string();// explicitly destroy string
		type = Tag::number;
	}	
	i = n;
}

void  Entry2::set_text(int n)
{
	if(type == Tag::text){
		s = ss; 
	else{
		new(&s) string{ss}; // placement new:explicitly construct string
		type = Tag::text;
	}	
}



//Note that the union in the declaration of Entry2 is not named.That makes it an
// anonymous union. An anonymous union is an object,not a type,and its members can 
// be accessed without mentioning an object name.That means that we can use members of an
// anonymous union exactly as we use other members of a class---as  long as we remember
// that union members really can be used only one at a time.


 
Entry2& Entry2::operator=(const Entry2& e)// necessary because of the string variant
{
	if(type == Tag::text && e.type == Tag::text ){
		s = e.s; // usual string assignment
		return *this;
	}


	if(type == Tag::text) s.~string(); // explicitly destroy 
	
	switch(e.type){
		case Tag::number:
			i = e.i;
			break;
		case Tag::text:
			new(&s)(e.s);	// placement new:explicitly construct 
			type = e.type;
	}
	return *this;
}


Entry2::~Entry2()
{
	if(type == Tag::text) s.~string(); // explicitly destroy 
}



/*

Enumerations:

	enum class Color {red,green,blue};

// This defines  an enumeration called Color with the enumerators red,
green,and blue.

// colloquially adv. 口语地；用通俗语
	"an enumeration" is colloquially shortened to "an enum"

two kinds of enumerations:
1) enum classes,  for which the enumerator names(e.g.:red) are local to the enum and
their values do not implicitly convert to other types.

2) "Plain enums" for which  the enumerator names  are in the same scope  as the enum and
their values  implicitly convert to integers.

prefer the enum classes, because they cause fewer surprises.



An enum class is a scoped and strongly typed enumeration.



*/
enum class Traffic_light {red,yellow,green};
enum class Warning  {green,yellow,orange,red};// fire alert levels

// Note that the enumerators present in both enums do not clash because each is in
// the scope of its own enum class 

Warning a1 = 7;// error: no int->Warning conversion
int a2 = green; // error:green not in scope
int a3 = Warning::green;// // error: no Warning->int conversion
Warning a4 = Warning::green;//ok


void 
f(Traffic_light x)
{
	if(x == 9) {/*...*/}   //error: 9 is not a Traffic_light
	if(x == red) {/*...*/}  // error: no red in scope
	if(x == Warning::red){/*...*/} //  error: x is not a Warning
	if(x == Traffic_light::red){/*...*/}//ok
}


// An enumeration  is represented by some integer type and each enumerators by
// some  integer value. we call the type used to represent an enumeration its
// underlying type. The underlying type must be one of the signed or unsigned 
// integer types ;the default is int.

// we could be explicit about that:
enum class Warning:int{green,yellow,orange,red}; // sizeof(Warning) == sizeof(int)


/*

if we considered that too wasteful of space,we could instead use a char.
*/

enum class Warning:char{green,yellow,orange,red};// sizeof(Warning) == 1

// by default, enumerator values are assigned increasing from 0.

static_cast<int>(Warning::green) == 0
static_cast<int>(Warning::yellow) == 1
static_cast<int>(Warning::orange) == 2
static_cast<int>(Warning::red) == 3



void
f(Warning key)
{
	switch(key){
		case Warning::green: // do something 
		break;
		// case Warning::yellow: // do something 
		// break;
		case Warning::orange: // do something 
		break;
		case Warning::red: // do something 
		break;
	}
}


enum class Printer_flags{
	acknowledge = 1;
	paper_empty = 2;
	busy = 4;
	out_of_black= 8;
	out_of_color = 16;
};


// bitwise or
constexpr  Printer_flags operator|(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a) | static_cast<int>(b));
}

// bitwise and
constexpr  Printer_flags operator&(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a) & static_cast<int>(b));
}


void try_to_print(Printer_flags x)
{
	if(x & Printer_flags::acknowledge){
		//...
	}else if(x & Printer_flags::busy){
		//...
	}else if(x & (Printer_flags::out_of_black | Printer_flags::out_of_color) ){
			// either we are out of  black or we are out of color
			//...
	}
	//...
}
void g(Printer_flags x)
{

	switch(x){
		case Printer_flags::acknowledge:
		//...
		break;
		case Printer_flags::busy:
		//...
		break;
		case Printer_flags::out_of_black:
		//...
		break;
		case Printer_flags::out_of_color:
		//...
		break;
		case Printer_flags::out_of_black & Printer_flags::out_of_color:
		// we are out of black *and* out of color
		//...
		break;
	}

	//...
}

enum class Color_code:char; // declaration
void foobar( Color_code* p);// use of declaration
//...
enum class Color_code:char { // definition
	red,yellow,green,blue
};


enum class Flag:char{x = 1,y = 2,z = 4,e = 8};

Flag f0 {}; //f0 gets the default value 0
Flag f1 = 5; // type error: 5 is not of type Flag
Flag f2 = Flag{5}; // error:no narrowing conversion to an enum class 
Flag f3 = static_cast<Flag>(5); // brute force
Flag f4 = static_cast<Flag>(999);// error: 999 is not a char value(maybe not caught)


int  i = static_cast<int>(Flag::y);//i becomes 2
char c = static_cast<char>(Flag::e);//c becomes 8


enum  Traffic_light {red,yellow,green};
enum  Warning  {green,yellow,orange,red};// fire alert levels

// error: two definitions of yellow (to the same value)
// error: two definitions of red (to different valuse)


Warning a1 = 7;// error: no int->Warning conversion

int a2 = green;// ok, green is in scope and converts to int

int a3 = Warning::green;//ok: Warning->int conversion
Warning a4 = Warning::green;// ok

void f(Traffic_light x)
{
	if(x == 9) {/*...*/}   //ok but  Traffic_light doesn't have a 9
	if(x == red) {/*...*/}  // error: two reds in scope
	if(x == Warning::red){/*...*/} // ok ouch!
	if(x == Traffic_light::red){/*...*/}//ok
}

enum  Traffic_light {tl_red,tl_yellow,tl_green};
enum  Warning  {green,yellow,orange,red};// fire alert levels


void f(Traffic_light x)
{
	if(x == red) {/*...*/}  // ok ouch!
	if(x == Warning::red){/*...*/} // ok ouch!
	if(x == Traffic_light::red){/*...*/}//error: red is not a Traffic_light value
}
enum Traffic_light:char { tl_red,tl_yellow,tl_green }; // underlying type is char

enum Color_code:char; // declaration
void foobar(Color_code* p); // use of  declaration
enum Color_code:char { // definition
	red,yellow,green,blue
};

enum E1 {dark,light};// range 0:1
enum E2 {a=3,b=9};// range 0:15
enum E3 {min=-10,max=1000000};// range:-1048576:1048575


enum  Flag {x=1,y=2,z=4,e=8};//range 0:15

/*

If you don't  specify the underlying type, you can't declare the enum without defining
it.and its underlying type  id determined  by a relatively complicated algorithm:
when all enumerators are no-negative,the range of the enumeration is [0:pow(2,k)-1] where
pow(2,k) is the smallest power of  2 for which all enumerators are within the range.
If there are negative enumerators,the range is [-pow(2,k):pow(2,k)-1].
This defines the smallest bit-field capable of holding the enumerator values using the 
conventional two's complement representation.

*/


Flag f0{}; // f0 gets the default value 0 
Flag f1 = 5; // type error: 5 is not of type Flag
Flag f2 = Flag{5};//  error; no explicit conversion from int to Flag
Flag f2 = static_cast<Flag>(5); // ok: 5 is within the range of Flag
Flag f3 = static_cast<Flag>(z | e); // ok: 12 is within the range of Flag
Flag f4 = static_cast<Flag>(99);// undefined: 99 is not within the range of Flag

// unnamed enums
/*
a plain enum can be  unnamed.

	
*/
enum {arrow_up = 1,arrow_down,arrow_sideways };

/* we use that when all we need is a set of  integer constants ,rather than a type to
use for variables */

/*
1) when compactness of data is important,lay out stucture data members with larger members
before smaller ones.//成员安排:空间由大 到 小!!!
2) use bit-fields to represent  hardware-imposed data layouts.
3) Don't natively try to optimize memory consumption by packing several values into a single 
byte.

4) Use unions to save space(represent alternatives) and never for type conversion.
5) Use enumerations to represent sets of named constants.
6) Prefer class enums over "plain" enums to minimize surprises.
7) define operations on enumerations for  safe and simple use.

*/




