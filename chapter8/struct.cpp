
/*
struct  结构体类型名 {
	字段声明；
};
*/




#include<iostream>
using namespace std;




struct dateT{
int month;
int day;
int year;
};



struct student{
char no[10];
char name[10];
dateT bir;
int chinese;
int math;
int english;
};



int
main()
{
	student stu = {"001","eddy",{89,76,88},77,89,89};


cout<<stu.no<<endl;
cout<<stu.name<<endl;
cout<<stu.bir.month<<endl;
cout<<stu.bir.day<<endl;
cout<<stu.bir.year<<endl;
cout<<stu.chinese<<endl;
cout<<stu.math<<endl;
cout<<stu.english<<endl;

student stu2[2] = {{"001","eddy",{89,76,88},77,89,89},{"001","sss",{89,76,88},77,89,89}};

cout<<stu2[1].no<<endl;
cout<<stu2[1].name<<endl;
cout<<stu2[1].bir.month<<endl;
cout<<stu2[1].bir.day<<endl;
cout<<stu2[1].bir.year<<endl;
cout<<stu2[1].chinese<<endl;
cout<<stu2[1].math<<endl;
cout<<stu2[1].english<<endl;

	return 0;
}
