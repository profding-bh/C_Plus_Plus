#include"construct.h"

// constructor
/*
doubleArray::doubleArray(int l,int h)
{
	low = l;
	high = h;
	storage = new double [high-low+1];//
}
*/

// constructor
doubleArray::doubleArray(int l,int h):low(l),high(h)
{
	storage = new double [high-low+1];//
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
 doubleArray::~doubleArray()
{
	if(storage)
		 delete[] storage;
}






