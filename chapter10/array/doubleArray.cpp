#include<iostream>
#include"doubleArray.h"
using namespace std;


// init
bool initialize(doubleArray &arr, int low,int high)
{
	arr.low = low;
	arr.high = high;
	arr.storage = new double [high-low+1];//
	if(NULL == arr.storage) 
		return false;
	else
		return true;
}

//setter
bool insert(const doubleArray &arr,int index,double value)
{
	if(index < arr.low || index >arr.high) return false;
	arr.storage[index-arr.low] = value;
	return true;
}

//getter
bool fatch(const doubleArray &arr,int index,double &value)
{
	if(index < arr.low || index >arr.high) return false;
	value = arr.storage[index-arr.low];
	return true;
	
}
//purge
void cleanup(const doubleArray &arr)
{
if(arr.storage) delete[] arr.storage;
}



