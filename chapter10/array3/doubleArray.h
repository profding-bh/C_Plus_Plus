#ifndef _doubleArray_h
#define _doubleArray_h


/*


class 类名{

	private:
	私有数据成员和成员函数；
	public:
	公有数据成员和成员函数；
};

私有成员只能被  类中成员函数访问。



直接定义在类中的函数，为inline函数，内联函数。

工具函数：通常设计为private.用户不需要知道细节。


*/


class doubleArray{
private:
int low;
int high;// data member
double* storage;

public:
// member function
bool initialize(int l,int h);

bool insert(int index,double value);

bool fatch(int index,double &value);

void cleanup();


};



#endif
