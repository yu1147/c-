#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;



class Person
{
public:

	void visit() //const
	{
		m_b = 10;
	}
	Person()
	{

	}
	Person(int a, int b) :m_a(a), m_b(b)
	{

	}
	friend Person& operator++(Person &p);//前自增（全局）
	
	//Person &operator ++()//前自增
	//{
	//	m_a++;
	//	return (*this);
	//}
	//Person operator ++(int )//后自增
	//{
	//	Person temp(m_a, m_b);
	//	m_a++;
	//	return (temp);
	//}
	void Changea(int x)
	{
		m_a = x;
	}
	int geta()
	{
		return m_a;
	}
	int m_b;
	friend Person operator +(Person &p, Person &b);
	friend Person operator++(Person &p, int);
	/*{
		Person temp;
		temp.m_b = b.m_b + p.m_b;
		temp.m_a = b.m_a + p.m_a;
		return temp;
	}*/
	friend ostream &operator <<(ostream &cout, Person &p);
private:
	int m_a;
};

Person operator +(Person &p, Person &b)
{
	Person temp;
	temp.m_b = b.m_b + p.m_b;
	temp.m_a = b.m_a + p.m_a;
	return temp;
}
void test01()
{
	Person p1;
	p1.m_b = 10;
	p1.Changea(20);
	Person p2;
	p2.m_b=30;
	p2.Changea(50);
	Person p3;
	p3 = p1 + p2;
	cout << p3.m_b <<"  "<< p3.geta() << endl;
}

Person& operator++(Person &p)//前自增（全局）
{
	++p.m_b;
	++p.m_a;
	return p;
}

Person operator++(Person &p,int)//后自增（全局）
{
	Person temp=p;
	++p.m_b;
	++p.m_a;
	return temp;
}
//前自增
//void test02()
//{
//	Person p1(10, 20);
//	Person p2(30, 40);
//	Person p3 = p1 + p2;
//	cout << p3.m_b << "  " << p3.geta() << endl;
//	Person p4 = (++p3)++;
//	cout << "p4 "<<p4.m_b << "  " << p4.geta() << endl;
//	cout << p3.m_b << "  " << p3.geta() << endl;
//};

ostream &operator <<(ostream &cout, Person &p)
{
	cout << p.m_b<<"    "<<p.m_a ;
	return cout;
}
void test03()
{
//	ofstream myf("abc.txt");
//	Person p1(20, 30); 
	Person p2(40, 50);
//	/*myf >> p1 << endl;
	cout<< p2 << endl;
}
//全局前自增
void test04()
{
	Person p1(10, 20);
	Person p2(30, 40);
	Person p3 = p1 + p2;
	cout << p3.m_b << "  " << p3.geta() << endl;
	Person p4 = p3++;
	cout << "p4 " << p4.m_b << "  " << p4.geta() << endl;
	cout << p3.m_b << "  " << p3.geta() << endl;
}

class apple
{
public:
	int a;
private:
	int b;
protected:
	int c;
};

class pear :public apple
{
public:
	int d;
};
void test05()
{
	apple p;
	p.a = 2;
	pear t;
	cout << sizeof(t) << endl;
	
}
int main()
{
	//ofstream fin("abc.txt");
	//int bt,at;

	test05();
	system("pause");
	return 1;
}