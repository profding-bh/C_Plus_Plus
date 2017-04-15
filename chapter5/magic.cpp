#include<iostream>
using namespace std;


#define MAX 15

int
main()
{

	int magic[MAX][MAX]={0};
	
	int row,col,count,scale;
	cout<<"input scale\n";
	cin>>scale;
	
	row=0;
	col=(scale-1)/2; //scale 为奇数
	
	magic[row][col]=1;
	// 填魔阵的规则：
	// 第一个元素，放在第一行中间一列
	// 下一个元素放在当前元素的上一行，下一列
	// 如果上一行，下一列已经有内容了（不为0），则下一个元素的存放位置为当前列的下一行。
	for(count=2;count<=scale*scale;count++)
	{
		if(  magic[ (row-1+scale)%scale ][ (col+1)%scale ]  == 0) // 上一行，下一列为空
		{
				row = (row-1+scale) %scale;// 用这个行号
				col = (col+1)%scale;// 用这个列号
		}
		else
			  row = (row+1) %scale; // 当前列的下一行。填数
		magic[row][col] = count;
	}
	
	for(row=0;row<scale;++row)
	{
		for(col=0;col<scale;++col)
		{	
			cout<<magic[row][col]<<'\t';
		}
		cout<<"\n";
	}
	
	return 0;
}


