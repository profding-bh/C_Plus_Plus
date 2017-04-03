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


*/


struct doubleArray{
int low;
int high;// data member
double* storage;

// member function
bool initialize(int l,int h);

bool insert(int index,double value);

bool fatch(int index,double &value);

void cleanup();


};



#endif
