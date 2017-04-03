#include<iostream>
#include<cstring>

using namespace std;


/*

在C++中，静态成员 是 属于整个类，而不是某个 对象。

静态成员变量（数据成员 & 成员函数） 只存储 一份，供所有对象 共用。

所以，在所有对象中都可以访问它。

使用静态 成员变量 可以实现 多个对象 之间的数据共享。（通过静态数据成员不就可以了吗！）

但又不破坏 隐藏的原则。保证了安全性，还可以节省内存。

静态成员的定义或声明，要加上 static。静态成员可以通过 域作用符::来访问。

静态数据成员的正确初始化方法--> 放在类外面初始化。

2.
原来引用的初始化和const常量 一样只能在构造函数的初始化列表里初始。

*/

#if 0
class Point{
	public:
	void init(){ cout<<"init"<<endl; }
	static void output(){cout<<"output"<<endl;} // static member function
	// static int a = 3;
	 static int a;
};


// //静态成员的正确初始化方法,因为这个家伙在 全局区，他虽然定义在类里面，但其实已经脱离了
// Point类的管理。

// int Point::a = 2;


#endif


#if 0
class Point{
	public:
	void init(){ cout<<"init"<<endl; }
	static void output(){cout<<"output"<<endl;cout<< m_x<<endl; } // static member function
	private:
	  int m_x;
};
#endif


#if 0
class Point{
	public:
	// 在类的非静态成员函数中，使用类的静态成员:静态数据成员+静态成员函数。
	void init(){ cout<<"init"<<endl; output(); cout<<a<<endl; }
	static void output(){cout<<"output"<<endl; } 
	 static int a;
};

int Point::a = 2;
#endif

#if 0
class Point{
	public:
	void init(){ cout<<"init"<<endl;  }
	static void output(){cout<<"output"<<endl; init();}
};

#endif






#if 1
class Employee  
{  
public:  
    Employee() 
    {
    	myid = ++id;
    };  
    Employee(const std::string &n) 
    {
    	myid = ++id;
    	name = n;
    };  
    int get_id() 
    {
    	return myid;
    }  
    const std::string get_name() 
    {
     return name;
     };  
private:  
    std::string name;  
    static int id;  
    int myid;  
};  
int Employee::id = 0;

#endif



#if 0
class Point{

public:
	Point()
	{
		m_nPointCount++;
	}
	~Point()
	{
		m_nPointCount--;
	}
	
	static void output(){cout<<m_nPointCount<<endl;}
	
	
	private:
	static int m_nPointCount;
};

int Point::m_nPointCount = 0;
#endif


const int MAX_NAME_SIZE = 30;

class Student{

	public:
	Student(char* pszName);
	~Student();
	public:
	static void print();
	private:
	char m_name[MAX_NAME_SIZE];
	Student* next;
	Student* prev;
	static Student* m_head;
	static int  m_number;
};


Student* Student::m_head = NULL;
int Student::m_number = 0;

Student::Student(char* pszName)
{
	strcpy(this->m_name,pszName);
	// 建立双向链表，新数据从链表头部插入。
	this->next = m_head;
	this->prev = NULL;
	if(m_head != NULL)
		m_head->prev = this;
	m_head = this;
	m_number++;
}


Student::~Student()
{
	// 析构过程，就是节点脱离过程。
	if(this == m_head) // 该节点就是头节点。
	{
		m_head = this->next;
		//m_head->prev = 	NULL;
		//this->next = NULL;
	}else
	{
	 this->prev->next = this->next;
	 this->next->prev = this->prev;
	}
	//delete this;
}


void Student::print()
{
	cout<<"student number is "<<m_number<<endl;
	for(Student* p = m_head; p!= NULL;p = p->next)
		cout<<p->m_name<<endl;
}





int main()
{

#if 0
	Point::init(); // error:
	
	/*
	error: cannot call member function ‘void Point::init()’ without object
	
	结论：不能 通过类名直接调用  类的非静态成员函数。理由很简单，类的非静态成员函数是属于该类对象的，
	而不属于该类。
	*/
	Point::output();// OK
#endif


#if 0
	Point pt;
	pt.init(); // ok
	pt.output();// OK
	
	/*
	结论：类的对象，可以调用  非静态成员函数（必然的），也可以调用 静态成员函数。
	*/
	
#endif

/*
error: ISO C++ forbids in-class initialization of non-const static member ‘Point::a’
  static int a = 3;
bool char wchar_t 包含被signed或者unsigned修饰的情况。统称integral类型
integral类型的同义词是integer类型。

*/

#if 0
	Point pt1,pt2;
	pt1.a++;
	cout<<pt2.a<<endl;
#endif

#if 0
	 Employee bb;
	 cout<<bb.get_id()<<endl;
	 
#endif

/*

error: invalid use of member ‘Point::m_x’ in static member function

在类的静态成员函数中（属于类），使用 类的非 静态成员（属于一个对象）。肯定是不可以的。

因为静态成员函数属于整个类，在类实例化对象之前，就已经分配空间了，而类的
非静态成员必须在 类实例化对象之后，才有内存空间（因为非静态成员依附于 类的对象。）

所以，比然出错。


结论：静态成员函数中，不能引用非静态数据成员。


*/
#if 0
	Point pt;
	pt.output(); // error
#endif



/*
结论：类的非静态成员函数，可以调用 静态成员函数，但反之不能。
*/

#if 0
	Point pt;
	pt.init();
	#endif
	
	#if 0
	Point pt;
	pt.output(); //error
	/*
	In static member function ‘static void Point::output()’:
statictest.cpp:72:50: error: cannot call member function ‘void Point::init()’ without object

	*/
	#endif
	
	
	#if 0

	/*
	类的静态成员变量必须先初始化，然后才能使用。
	*/
	Point pt;
	//Point::output(); 
	pt.output();
	#endif
	
	
	Student a("AAA");
	Student b("BBB");
	Student c("CCC");
	Student d("DDD");
	Student s("MoreWindows");
	Student::print();
//	a.~Student();
	return 0;
}
