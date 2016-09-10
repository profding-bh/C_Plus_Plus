
class Vector
{
	public:
	Vector(int s);
	double& operator[](int i);// subscripting
	int size();
	private:
		double* elem;
		int sz;
}
