#include<iostream>
using namespace std;


#if 0
namespace
{
	class Caa{
		public:
		  int a;
	};

}


int
main(void)
{
	Caa a;
	a.a = 3;
	cout<<a.a<<endl;
	return 0;
}
#endif


#if 0


namespace  Eddy
{
	class Caa{
		public:
		  int a;
	};

}

int
main(void)
{
	Eddy::Caa a;
	a.a = 3;
	cout<<a.a<<endl;
	return 0;
}

#endif

#if 1

void 
f5(int x)
{
 //int x; error
	{
		int x;// ok!
	}
}
// The names of function arguments are considered declared in the outermost block of
	// a function.
int
main(void)
{
	
	return 0;
}
#endif

