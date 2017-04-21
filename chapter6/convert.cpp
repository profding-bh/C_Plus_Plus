#include<iostream>
using namespace std;

const int LEN = 80;

int convertToInt(char str[],int start);
void convertToUpper(char s[]);


void print(int value,int base=10);

int convertToInt(char str[],int i)
{

int data =0,flag;

		if(str[i] != '0') flag = 10; // 10 进制
	     else {  // str[i] == '0'
	            if( str[i+1] == 'X' ){ // 16进制
	      			flag = 16;
			     	i+=2;// 0X 
	     		} else {
	     		 flag = 8;++i; //8 进制 : 0
	     		 }
	     }
	     
	     switch(flag) {
	     case 10: while( str[i] != ' ' &&  str[i] != '\0' )  data = data*10+str[i++]-'0';
	                break;
	     case 8: while( str[i] != ' ' &&  str[i] != '\0' )  data = data*8+str[i++]-'0';
	                break; 
	     case 16: while( str[i] != ' ' &&  str[i] != '\0' ){
	     			data = data*16;
	     			if(str[i] >= 'A' && str[i] <='F') data += str[i++]-'A'+10;//A-F
	     			else  data += str[i++]-'0'; // 0-9
	    			 }
	                break;
	     }
	     return data;
}


void convertToUpper(char s[])
{
 for(int i =0; s[i] != '\0';++i)
 	if(s[i] >='a' && s[i] <= 'z') s[i] = s[i]-32;  // s[i] = s[i]-'a'+'A';
}


// cin.getline()
int
main()
{
	char str[81];
	
	int sum = 0,data,i = 0,flag;
	
	cin.getline(str,81);
	
	convertToUpper(str);
	
	while(str[i] == ' ' && str[i] != '\0' ) ++i; // 跳过前面的空格
	
	while(str[i] != '\0') {
	     sum += convertToInt(str,i);
	      while(str[i] != ' '&&  str[i] != '\0' ) ++i; // 跳过刚刚处理的整数
	      while(str[i] == ' '&& str[i] != '\0' ) ++i; // 跳过空格
	}
	
	cout<<sum <<endl;
	return 0;
}



