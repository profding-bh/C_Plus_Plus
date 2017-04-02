#include<iostream>


/*

编写一个程序，输入一个句子【以.结束】，统计该句子中元音字母数，辅音字母数，空格数，数字数以及其他字符数.
没有去重，比如a a A，3个元音字母
*/
using namespace std;

int
main()
{
	char ch;
	int n1 = 0,n2 = 0,n3 = 0,n4 =0,n5=0;

	cout<<"Please intput a statement:";
	cin.get(ch);
	while(ch != '.')
	{
		if(ch>='A'&& ch<='Z') ch = ch - 'A'+'a'; // change to lower case
		if(ch>='a'&& ch<='z')
		{
			if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
				++n1;
			else 
				++n2;
		}else if(ch == ' ') ++n3;
			  else if(ch >= '0' && ch <='9') ++n4;
			       else ++n5;
		cin.get(ch);
	}
	cout<<"vowel number is:"<<n1<<endl;
	cout<<"consonant number is:"<<n2<<endl;
	cout<<"space number is:"<<n3<<endl;
	cout<<"digit number is:"<<n4<<endl;
	cout<<"other number is:"<<n5<<endl;
	return 0;
}
