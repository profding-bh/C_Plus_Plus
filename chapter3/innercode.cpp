#include<iostream>
#include<cmath>


using namespace std;

// 输A-Z的内码
int
main()
{
	for(char ch = 'A';ch<='Z';++ch )
		cout<<ch<<'('<< int(ch) <<')'<<endl;
	return 0;
}
