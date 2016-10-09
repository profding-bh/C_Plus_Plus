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


#if 1


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
