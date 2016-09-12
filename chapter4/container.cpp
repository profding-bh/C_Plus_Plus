#include<string>
#include<list>


std::string s{"Four legs Good,two legs badddd"};
std::list<std::string> slogans {"war is peace","Freedom is ", "ignorance is"};


#include<string>
using namespace std;

string s {"xxx"}; // Ok:string is std::string


// 类也是在命名空间中的


string compose(const string& name, const string& domain)
{
	return name +'@' +domain;
}


auto addr = compose("dmr","bell-labs.com");


void m2(string& s1,string& s2)
{
	s1 = s1 + '\n';
	s2 += '\n';// a better way
}



string name = "Niels Stroustrup";

void m3()
{
	string s = name.substr(6,10);
	name.replace(0,5,"nicholas");
	name[0]=toupper(name[0]);
}




string incantation; //咒语

void respond(const string& answer)
{
	if(answer == incantation ){
			// perform  magic
	}else if(answer == "yes"){
			// ...
	}
	// ..
}

void f()
{
	cout<<10;
}

void g()
{
	int i {10};//C++11
	cout<<i;
}


void h(int i)
{
	cout<<"the value of i is ";
	cout<<i;
	cout<<'\n';
}

void h2(int i)
{
	cout<<"the value of i is "<< i <<'\n';
}




void k()
{
	int b = 'b';// note:char implicitly converted to int
	char c = 'c';
	cout <<'a'<<b<<c;
}


void f(int i)
{
	int i;
	cin>>i;

	double d;
	cin>>d;
}




void hello(int i)
{
	cout<<"Please enter your name\n";
	string str;
	cin>>str;
	cout<<"Hello,"<<str <<"!\n";
}


void hello_line(int i)
{
	cout<<"Please enter your name\n";
	string str;
	getline(cin,str);// a whole line
	cout<<"Hello,"<<str <<"!\n";
}


struct Entry{
	string name;
	int number;
};

ostream& operator<<(ostream& os,const Entry& e)
{
	return os<<"{\""<<e.name<<"\","<<e.number<<"}";
}


istream& operator>>(istream& is,Entry& e)
// read{"name",number}pair.Note: formatted with {"",and}
{
	char c,c2;
	if(is>>c&&c=='{' && is>>c2&&c2=='"'){	// start with a { "
		string name;// the default value of string is the empty string.""
		while(is.get(c)&& c!='"')// anything before is a " is part of the name
			name+=c;
		
		if(is>>c&& c==','){
			int number = 0;
			if(is>>number>>c && c == '}'){// read the number and a }
				e={name,number};// assign to the entry.
				return is;
			}
		}
	}
	is.setf(ios_base::failbit);// register the failure in the stream
	return is;
}



{"Hon Mow Clld",11111}

for(Entry ee;cin>>ee;)
	cout<<ee<<'\n';


{"Hon Mow Clld",11111}

vector<Entry> phone_book={

	{"David",123},
	{"Davidssss",356},
	{"Ejkafj",789}
};


void print_book(const vector<Entry>& book)
{
	for(const auto& x:book)
		cout<<x<<'\n';
}

vector<int> v1 = {1,2,3,4}; // size is 4
vector<string> v2; //size is 0
vector<Shape*> v3(23);// size is 23,initial element value:nullptr

vector<double> v4(32,9.9); // size is 32,initial element value:9.9



void input()
{
	for(Entry e;cin>>e;)
		phone_book.push_back(e);
}


void silly(vector<Entry>& book)
{
	int i = book[ph.size()].number; // book.size() is out of range
		//
}


template<typename T>
class Vec:public std::vector<T> { //??
	
public:
	using vector<T>::vector;// use the constructors from vector(under the name Vec)	
	
	T& operator[](int i) // range check
	{ return vector<T>::at(i); }
	
	const T& operator[](int i) const // range check const objects
	{ return vector<T>::at(i); }
};



void checked(Vec<Entry>& book)
{

	try{
		book[book.size()] = {"Hoe",999999};// will throw an exception
		//....
	}
	catch(out_of_range){
		cout<<"range error\n";
	}
}



int main()
{
	try{
		// your code
		//....
	}
	catch(out_of_range){
		cout<<"range error\n";
	}
	catch(...){
		cerr<<"unknown exception thrown\n";
	}
}


list<Entry> phone_book = {

	{"David",123},
	{"Davidssss",356}	
};

int get_number(const string& s)
{
	for(const auto& x: phone_book)
		if(x.name == s)
			return x.number;
	return 0;// use 0 to represent "number not found"
}




 

int get_number(const string& s)
{
	for( auto p = phone_book.begin(); p!= phone_book.end();++p)
		if(p->name == s)
			return p->number;
	return 0;// use 0 to represent "number not found"
}


void f(const Entry& ee,list<Entry>::iterator p,list<Entry>::iterator q)
{
	phone_book.insert(p,ee); // add ee before the element referred to by p
	phone_book.erase(q);  // remove the element referred to by q
}


map<string,int> phone_book {

	{"David",123},
	{"Davidssss",356}
};


int get_number(const string& s)
{	
	return phone_book[s];
}



unordered_map<string,int> phone_book {

	{"David",123},
	{"Davidssss",356}
};
int get_number(const string& s)
{	
	return phone_book[s];
}


bool operator<(const Entry& x,const Entry& y)//less than
{
	return x.name<y.name;// order Entry by their names
}


void f(vector<Entry>& vec,list<Entry>& lst)
{
	sort(vec.begin(),vec.end());// use < for order
	unique_copy(vec.begin(),vec.end(),lst.begin());// don't copy adjacent equal elements
}




list<Entry> f(vector<Entry>& vec)
{
	list<Entry> res;
	sort(vec.begin(),vec.end());
	unique_copy(vec.begin(),vec.end(),back_inserter(res));//append to res
	return res;
}



bool has_c(const string &s,char c)// does s contain the character c?
{
	auto p = find(s.begin(),s.end(),c);
	
	if(p != s.end())
		return true;
	else
		return false;
}


bool has_c(const string &s,char c)// does s contain the character c?
{	
	return  find(s.begin(),s.end(),c) != s.end();
}




vector<string::iterator> find_all(string& s,char c)
{
	vector<string::iterator> res;
	for(auto p = s.begin();p != s.end();++p)
		if(*p == c)
			res.push_back(p);
	return res;
}


void test()
{
	string m {"Mary had a little lamb"};//lamb:小羊

	for(auto p:find_all(m,'a'))
		if(*p != 'a')
			cerr<<"a bug!\n";
}



template<typename C,typename V>
vector<typename C::iterator> find_all(C& c,V v)
{
	vector<typename C::iterator> res;

	for(auto p = c.begin(); p != c.end();++p)
		if(*p == v)
			res.push_back(p);
	return res;
}



template<typename T>
using Iterator<T> = typename T::iterator;

template<typename C,typename V>
vector<Iterator<C>> find_all(C& c,V v) // find all occurences of v in c
{
	vector<Iterator<C>> res;

	for(auto p = c.begin(); p != c.end();++p)
		if(*p == v)
			res.push_back(p);
	return res;
}


void test()
{
	string m {"Mary had a little lamb"};
	for(auto p:find_all(m,'a'))
		if(*p != 'a')
			cerr<<"string bug!\n";
	
	
	list<double> ld {1.1,2.2,3.3,1.1};
	for(auto p:find_all(ld,1.1))
		if(*p != 1.1)
			cerr<<"list bug!\n";


		
	vector<string> vs {"red","blue","green","green","orange","green"};
	for(auto p:find_all(vs,"green"))
		if(*p != "green")
			cerr<<"vector bug!\n";


	for(auto p:find_all(vs,"green"))
		 *p = "vert";
}



ostream_iterator<string> oo {cout}; // write stings to cout

int main()
{
	*oo = "Hello,";// meaning cout <<"Hello,"
	++oo;
	*oo="world\n";// meaning cout <<"world\n"
}


istream_iterator<string> ii {cin};
istream_iterator<string> eos {};

int main()
{
	string from,to;
	
	cin>>from>>to; // get source and target file names

	
	ifstream is {from}; // input stream for file "from"
	istream_iterator<string> ii {is}; // input  iterator for stream
	istream_iterator<string> eos {};// input sentinel: 哨兵

	
	ofstream os {to}; // output stream for file "to"
	
	ostream_iterator<string>  oo {os,"\n"};// output iterator for stream

	vector<string>  b {ii,eos};// b is a vector initialized from input [ii:eos)
	
	sort(b.begin(),b.end());// sort the buffer
	
	
	unique_copy(b.begin(),b.end(),oo);// copy buffer to output,discard replicated values

	return !is.eof() || !os; // return error state
}

set<string>  b {ii,eos};// collect strings from input
copy(b.begin(),b.end(),oo);// copy buffer to output


int main()
{
	string from,to;
	cin>>from>>to;// get source and target file names

		
	ifstream is {from}; // input stream for file "from"
	ofstream os {to}; // output stream for file "to"
		

	set<string> b {istream_iterator<string>{is},istream_iterator<string>{}};//read input

	copy(b.begin(),b.end(),ostream_iterator<string>{os,"\n"});// copy to output

	return !is.eof() || !os;// return error state
}




void f(map<sting,int>& m)
{
	auto p = find_if(m.begin(),m.end(),Greater_than{43});
	//...
}


struct Greater_than{

	int val;
	Greater_than(int v):val{v}{}

	bool operator()(const pair<string,int>& r){return r.second>val;}

};


namespace Estd{

	using namespace std;


 	template<class C>
	void sort(C& c)
	{
		sort(c.begin(),c.end());
	}

	template<class C,class Pred>
	void sort(C& c,Pred p)
	{
		sort(c.begin(),c.end(),p);
	}
//...

}





 






















