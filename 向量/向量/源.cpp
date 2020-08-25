#include<iostream>
#include<cmath>
using namespace std;

class Vector
{
private:
	int n;
	double *p;
public:
	//构造函数
	Vector(const int dim = 0, const double* x = NULL) :n(dim), p(NULL)
	{
		if (n <= 0)
		{
			n = 0;
			return;
		}
		p = new double[n];
		if (p)
			for (int i = 0; i < n; i++)
			{
				p[i] = (x == NULL) ? 0 : x[i];
			}

		
	}
	//拷贝函数
	Vector(const Vector &v):n(0),p(NULL)
	{
		*this = v;
	}
	//析构
	virtual ~Vector()
	{
		if (p)
		{
			delete[] p;
			n = 0;
			p = NULL;
		}
	}

	//赋值运算符
	Vector& operator=(const Vector &v)
	{
		if (this == &v)return *this;
		if (p)
		{
			delete[] p;
			n = 0;
			p =NULL;
		}
		if (v.n <= 0)
			return *this;
		p = new double[v.n];
		if (p)
		{
			for (int i = 0; i < n; i++)
			{
				p[i] = v.p[i];
			}
		}
		return *this;
	}
	double max()const
	{
		if (n == 0)return 0;
		double max = p[0];
		for (int i = 1; i < n; i++)
		{
			if (max < p[i])
				max = p[i];
		}
		return max;
	}
	double min()const
	{
		if (n == 0)return 0;
		double min = p[0];
		for (int i = 1; i < n; i++)
		{
			if (min > p[i])
				min = p[i];
		}
		return min;
	}
	double range()
	{
		if (n <= 0)return 0;
		
		return this->max() - this->min();
	}

	

};

int main()
{
	double u[4] = { 1.1, 2.3,2.2,1.5 };
	Vector a(4, u);
	double t = a.range();
	cout << t << endl;
	system("pause");
}