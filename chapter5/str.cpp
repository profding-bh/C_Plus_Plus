#include<iostream>
using namespace std;

const int LEN = 80;

// cin.getline()
int
main()
{
	char sentence[LEN+1],prev= ' ';
	
	int i,num = 0;
	
	
	cin.getline(sentence,LEN+1);
	
	for(i=0;sentence[i] != '\0';++i)
	{
		if(prev == ' ' && sentence[i] != ' ' ) ++num;
		prev = sentence[i];
	}
	
	cout<<"单词个数："<<num<<endl;
	return 0;
}
