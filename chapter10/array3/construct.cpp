#include<iostream>
#include"construct.h"
using namespace std;

/*
doubleArray array2(array1);
void f(doubleArray array);
doubleArray arr;
f(arr);


*/

// constructor
doubleArray::doubleArray(int l,int h)
{
	low = l;
	high = h;
	storage = new double [high-low+1];//
}

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
void doubleArray::cleanup()
{
if(storage) delete[] storage;
}



