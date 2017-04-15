#include<iostream>
using namespace std;

const int LEN = 80;

// cin.getline()
int
main()
{
	char str[81];
	
	int sum = 0,data,i = 0,flag;
	
	cin.getline(str,81);
	
	while(str[i] == ' ' ) ++i; // 跳过前面的空格
	
	while(str[i] != '\0') {
		
		if(str[i] != '0') flag = 10; // 10 进制
	     else {  // str[i] == '0'
	            if( str[i+1] == 'x' || str[i+1] == 'X' ){ // 16进制
	      			flag = 16;
			     	i+=2;// 0x,or 0X 
	     		} else {
	     		 flag = 8;++i; //8 进制 : 0
	     		 }
	     }
	     
	     data = 0;
	     switch(flag) {
	     case 10: while( str[i] != ' ' &&  str[i] != '\0' )  data = data*10+str[i++]-'0';
	                break;
	     case 8: while( str[i] != ' ' &&  str[i] != '\0' )  data = data*8+str[i++]-'0';
	                break; 
	     case 16: while( str[i] != ' ' &&  str[i] != '\0' ){
	     			data = data*16;
	     			if(str[i] >= 'A' && str[i] <='F') data += str[i++]-'A'+10;//A-F
	     			else if(str[i] >= 'a' && str[i] <='f') data += str[i++]-'a'+10; //a-f
	     				else data += str[i++]-'0'; // 0-9
	    			 }
	                break;
	     }
	     sum += data;
	     
	     while(str[i] == ' ' ) ++i; // 跳过空格
	}
	
	cout<<sum <<endl;
	return 0;
}
