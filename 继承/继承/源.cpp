#include<iostream>
#include<string>
using namespace std;

class gong
{
public:
	int m_a;
};
class SA:virtual public gong
{
public:
	int m_aa;
};

class SB:virtual public gong
{
public:
	int m_ab;
};

class SC:public SA,public SB
{
public:
	int m_ac;
};

void test01()
{
	
	SC c1;
	c1.SB::m_a = 5;
	c1.m_a = 10;
	cout << c1.m_a << endl;
	cout << c1.SB::m_a << endl;
}

int main()
{
	test01();
	system("pause");
	return 1;
}