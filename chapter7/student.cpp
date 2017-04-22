#include<iostream>
using namespace std;

std::string test_str()
{
   std::string str="test";
   return str;
}

int
main()
{
#if 0
	class _student { 
public: 
     int a; 
     char b;
protected: 
     int c; 
};
_student st;
st.a='a'; 
st.b="a"; 
st.c=1;
#endif

   std::string str_ref=test_str();
   std::cout<<str_ref<<std::endl;
	return 0;
}
