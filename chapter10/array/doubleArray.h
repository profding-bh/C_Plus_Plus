#ifndef _doubleArray_h
#define _doubleArray_h


struct doubleArray{
int low;
int high;
double* storage;
};


bool initialize(doubleArray &arr, int low,int high);

bool insert(const doubleArray &arr,int index,double value);

bool fatch(const doubleArray &arr,int index,double &value);

void cleanup(const doubleArray &arr);

#endif
