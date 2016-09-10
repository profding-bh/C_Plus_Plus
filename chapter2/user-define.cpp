#include<iostream>
using namespace std;



struct Vector
{
	int sz;
	double* elem;
};


Vector v;

void Vector_init(Vector& v,int s)
{
	v.elem = new double[s];
	v.sz = s;
}


double read_and_sum(int s)
{
	Vector v;
	Vector_init(v,s);
	for(int i = 0; i!=s;++i)
		cin>>v.elem[i];

	double sum = 0;
	for(int i = 0; i!=s;++i)
		sum += v.elem[i];
	return sum;
}


void f(Vector v, Vector& rv, Vector *pv)
{
	int i1 = v.sz;
	int i2 = rv.sz;
	int i3 = pv->sz;
}

#if 0
class Vector
{
	public:
	Vector(int s):elem{new double[s]},sz{s}{}
	double& operator[](int i){return elem[i];}// subscripting
	int size(){return sz;}
	private:
		double* elem;
		int sz;
}
#endif



Vector::Vector(int s):elem{new double[s]},sz{s}
{	
}

double& Vector::operator[](int i)
{
	return elem[i];
}


int Vector::size()
{
	return sz;
}


/*

存在2种：
enum  & enum class:

*/

enum class Color {red,blue,green};
enum class Traffic_light {green,yellow,red};

Color col = Color::red;
Traffic_light light = Traffic_light::red;

Color x = red; // which red?

Color y = Traffic_light::red; //error:that red is not a Color

Color c = 2;// error: 2 is not a Color

int i = Color::red;// error: Color::red in not an int


Traffic_light& operator++(Traffic_light& t )
{
	switch(t)
	{
//wrapper around
		case Traffic_light::green: return t =  Traffic_light::yellow;
		case Traffic_light::yellow: return t =  Traffic_light::red;
		case Traffic_light::red: return t =  Traffic_light::green;
	}
}


namespace My_code{

		class complex {/*....*/};
		complex squrt(complex);
		int main();
}


int My_code::main()
{
	complex z {1,2};
	auto z2 = sqrt(z);
	std::cout<<'{'<<z2.read()<<','<<z2.imag()<<"}\n";
	//...
}



double& Vector::operator[](int i)
{
	if(i<0 || size()<= i) throw out_of_range{"Vector::operator[]"}
	return elem[i];
}


void f1(Vector& v)
{
	//...
	try{
		v[v.size()] = 7;
	}
	catch(out_of_range){
		// handle range error...
	}

}
Vector v(-27);


Vector::Vector(int s)
{
	if(s<0) throw length_error{};

	elem = new double[s];
	sz = s;
}



void test()
{
	try(){
		Vector v(-27);
	}
	catch(std::length_error){
		// handle negative size
	}
	catch(std::bad_alloc){
		// handle memory exhaustion
	}
}


// Static Assertions


static_assert(4<=sizeof(int),"integers are too small");











int
main()
{
	
	std::cout<<"Hello,World\n";

	My_code::main();
	return 0;
}
