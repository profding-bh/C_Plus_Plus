// a  programmer is a machine for turning caffeine into code.

/*
note that a declaration is a statement and that an expression 
becomes a statement when you add a semicolon at its end.

Unlike an expression, a statement does not have a value.

Instead,statements are used to specify the order of execution.

a = b+c;// expression statement
if(a == 7)// if-statement
	b =  9;//execute if and only if a == 7

Logically, a = b+c is executed before the if,as everyone would expect.

A compiler may reorder code to improve performance as long as the 
result is identical to that of the simple order of execution.


Statement Summary:

statement:
	declaration
	expression[opt];
	{statement-list[opt]}
	try {statement-list[opt]} handler-list
	

	case constant-expression:statement
	default:statement
	break;
	continue;

	return expression[opt];
	
	goto identifier;
	identifier:statement

	selection-statement
	iteration-statement

selection-statement:
	if(condition) statement
	if(condition) statement else statement
	switch(condition) statement

iteration-statement:
	while(condition) statement
	do{statement} while(expression);

	for(fot-init-statement;condition[opt];expression[opt]) statement
	for(for-init-declaration:expression) statement
	

statement-list:
	statement  statement-list[opt]

condition:
	expression
	type-specifier declarator = expression
	type-specifier declarator { expression }

handler-list:
	handler handler-list[opt]
handler:
	catch( exception-declaration ) { statement-list[opt] }

	*/

/*
a declaration is  a statement. unless  a variable is declared static.

*/


void f(vector<string>& v,int i, const char* p)
{
	if(p==nullptr) return ;
	if(i<0 || v.size()<=i) error("bad index");
	string s = v[i];
	if(s == p){
		//...
	}
	//...
}

void use()
{
	string s1; 
	s1 = "The best is the enemy of the good.";
	//...
}


string s2 {"Voltaire"};

void input()
{
	int buf[max];
	int count = 0;
	for(int i;cin>>i;){
		if(i<0) error("unexpected negative value");
		if(count == max) error("buffer overflow");
		buf[count++] = i;
	}
	//...
}

// a condition is either an expression or a declaration

if(x) //...
//means if(x != 0) //...

if(p)//...

if(p != nullptr) //...

enum E1 {a,b};
enum class E2 {a,b};

void
f(E1 x, E2 y)
{
	if(x) //... ok
	if(y) //... error: no conversion to bool
	
	if(y == E2::a) //ok
		//...

	//
}

if(p && 1< p->count) //...


int 
max(int a,int b)
{
	return (a>b)?a:b; // return  the larger of a and b 
}


void f2(int i)
{
	if(i){
		int x = i+2;
		++x;
		//...
	}else{
		++x;//error: x is not in scope
	}
	++x;// error: x is not in scope
}


void f1(int i)
{
	if(i)	
		int x = i+2; // error: declaration of if-statement branch 
}




// a switch-statement selects  among a set of  alternatives(case-labels)
 

void f(int i)
{
	switch(i){
		case 2.7: //error:floating  point uses for case
		//...
		case 2:
		//...
		case 4-2: //error:2 used twice in case labels
		//...
	}
}


switch(val){
case 1:
	f();
	break;
case 2:
	g();
	break;
default:
	h();
	break;

}

if(val == 1)
	f();
else if (val == 2)
		g();
else
	h();

switch(val){
case 1:
	cout<<"case 1\n";
case 2:
	cout<<"case 2\n";
default:
	cout<<"default: case not found\n";
}


/*
It is a good idea to comment the rare cases in which a fall-through is
intentional so that an uncommented fall-through can be assumed 
to be an error.


 */


switch(action){
case do_and_print:
	act(value);
	// no break;fall through to print
case print:
	printf(value);
	break;
//...
}

// a break  is the  most common way of  terminating a case,but 
// a return is often useful.



enum class Vessel {cup,glass,goblet,chalice};


void problematic(Vessel v)
{
	switch(v){
		case Vessel::cup: /* ...*/ break;
		case Vessel::glass: /* ...*/ break;
		case Vessel::goblet: /* ...*/ break;
		case Vessel::chalice: /* ...*/ break;
	}
}

void f(int i)
{
	switch(i){
	case 0:
		int x;//uninitialized.
		int y = 3;// error:declaration can be bypassed(explicitly initialized)
		string s;//  error:declaration can be bypassed(implicitly initialized)
	case 1:
		++x;// error:use of uninitialized object
		++y;
		s = "nasty!"
	}
}

/*

To avoid accidential misuse of a variable, it is usually  a good idea to
introduce the variable into the smallest scope possible.
In particular, it is usually best to delay the definition of a local variable
until one can give it an initial value.

One of the most elegant applications of these two principles is to 
declare a variable in a condition.

*/


/*

The　simplest loop is a range-for-statement,it simply gives the programmer
access to  each  element of a range.
*/

int sum(vector<int>& v)
{
	int s = 0;
	for(int x:v) // range-for-statement,the expression after the colon must denote a sequence(a range)
		s += x;
	return s;
}



int sum2(vector<int>& v)
{
	int s = 0;
	for(auto p = begin(v); p != end(v);++p) // range-for-statement,the expression after the colon must denote a sequence(a range)
		s += *p;// p is pointer
	return s;
} 

void incr(vector<int>& v)
{
	for(int& x:v)
		++x;
}

template<class T>
T accum(vector<T>& v)
{
	T sum = 0;
	for(const T& x:v)
		sum += x;
	return sum;
}
//Note that   a range-for  loop is a deliberately simple construct.
// For example,using it you can't touch two elements at the same time and 
// can't effectively traverse two ranges simultaneously.


void f(int v[],int max)
{
	for(int i= 0;i != max; ++i)
		v[i] = i*i;
}



void f(int v[],int max)
{
	int i= 0;//introduce loop variable
	while(i != max){ // test termination condition
		v[i] = i*i;// execute the loop body
		++i;// increment loop variable
	}
}



for(auto p=begin(v); c!=end(v);++p){
	//...use iterator p for elements in container

}

for(string s;cin>>s;)
	v.push_back(s);

for(;;){ //"forever"
	//..
}

while(true){ //"forever"
	//..
}



template<class Iter,class Value>
Iter find(Iter first,Iter last, Value val)
{
	while(first != last && *first != val)
		++first;
	return first;
}





void print_backwards(char a[],int i)//i must be positive
{
	cout<<'{';
	do{
		cout<<a[--i];
	}while(i);
	cout<<'}';
}

// I recommend avoiding do-statements

void f(vector<string>& v, string terminator)
{
	char c;
	string s;
	while(cin>>c){
		///
		if(c=='\n') break;		
		///	
	}
}
// sometimes,we don't want to exit the loop completely,we just want to get to the end of
// the loop body. A  continue skips the rest of the body of an iteration-statement.

void find_prime(vector<string>& v)
{
	for(int i = 0; i != v.size();++i){
		if(!prime(v[i])) continue;
		return v[i];
	}
}

void find_prime(vector<string>& v)
{
	for(int i = 0; i != v.size();++i){
		if(prime(v[i])){
   			return v[i]; // 
		}
	} 
}

// The scope of a label is the function it is in.
// This implies that  you can use goto to jump both into and out of blocks.
// The only restriction is that you cannot jump past an initializer or into an
// exception handler.


void do_something(int i,int j)
{
	for(i=0;i!=n;++i)
		for(j=0;j!=m;++j)
			if(nm[i][j] == a)
				goto found;
	//not found
found:
	//nm[i][j] == a
}



















