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


*/


class doubleArray{
private:
int low;
int high;// data member
double* storage;

public:
// belows are inline函数。 
bool doubleArray::initialize(int l,int h)
{
	low = l;
	high = h;
	storage = new double [high-low+1];//
	if(NULL == storage) 
		return false;
	else
		return true;
}

//setter
bool doubleArray::insert(int index,double value)
{
	if(index < low || index > high) return false;
	storage[index-low] = value;
	return true;
}

//getter
bool doubleArray::fatch(int index,double &value)
{
	if(index < low || index >high) return false;
	value = storage[index-low];
	return true;
	
}
//purge
void doubleArray::cleanup()
{
if(storage) delete[] storage;
}


};



#endif
