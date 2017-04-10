#include<iostream>
using namespace std;

// 
int 
main()
{
	int num = 7;
	bool is;
	do{
		is = false;
		is = (num%2 == 1) && (num%3 == 2) && (num%5 == 4) && (num%6 == 5) && (num%7 == 0);
		if(is)
		{
			printf("num is %d\n",num);
			break;
		}
		num += 7;
	}while(true);	

	
	return 0;
}
