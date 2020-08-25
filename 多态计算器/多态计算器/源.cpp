#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


class abstractCalculator
{
public:
	int m_Num1;
	int m_Num2;
	virtual int getResult() = 0;

};

class AddCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

class MinusCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

class MulCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test01()
{
	abstractCalculator *abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	abc = new MinusCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << " *= " << abc->getResult() << endl;
	delete abc;
}
int main()
{
	test01();
	system("pause");
	return 1;
}