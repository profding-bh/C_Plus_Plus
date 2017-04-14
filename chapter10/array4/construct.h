#ifndef _construct_h
#define _construct_h

class doubleArray{
private:
int low;
int high;// data member
double* storage;

public:

//doubleArray(int l,int h);

doubleArray(int l=0,int h=1);


bool insert(int index,double value);

bool fatch(int index,double &value);


// purge
 ~doubleArray();


};

#endif




