#include<stdio.h>
#include<limits.h>

enum ret_code{
 SUCCESS = 0,
 ERROR = INT_MAX
};


/**
@brief: 原来字符串的处理，不是一遍就可以搞定的。可能同一个字符串，需要进行多遍遍历，
每一次遍历，判定一种情况。

*/
int strtoint(char* string)
{
 int number = 0;
 if(!string) return ERROR; // 为空
 char* str = string;

 while( *str != 0)
 {
	if((*str < '1' || *str > '9') && (*str != '+') && ( *str != '-')) 
		return ERROR; // 含有不是"+","-"的 非法字符
	str++;
 }
 

 str = string; // 重新指向开头
 ++str; // 从第2个字符开始

  while( *str != 0)
 {
		if( *str == '+' ||  *str == '-' ) return ERROR;  //跳过第一个字符,但剩下字符中含有'+','-'
		++str;
 }


 str = string; // 重新指向开头
 if(*str == '+' || *str == '-' )  ++str; // 第一个字符是: + , -

  while( *str != 0)
 {
		number = number * 10 + *str - '0';
		++str;
 }

 str = string;// 重新指向开头
 if(*str != '-' )  return number; // 正数加号,不用写
 else  return -number; // // 第一个字符是: -
}

int
main()
{
	int ret = 0;
//	ret = strtoint("123");
//	printf("ret is %d\n",ret);

//	ret = strtoint(NULL);
//	printf("ret is %d\n",ret);
	
	ret = strtoint("a123");
	printf("ret is %d\n",ret);

	ret = strtoint("+123");
	printf("ret is %d\n",ret);

	ret = strtoint("-123");
	printf("ret is %d\n",ret);

ret = strtoint("12+3");
	printf("ret is %d\n",ret);
	return 0;
}
