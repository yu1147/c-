#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PutIntoCup() = 0;
	//放入辅料
	virtual void PutSomething() = 0;

	void doMake()
	{
		Boil();
		Brew();
		PutIntoCup();
		PutSomething();
	}
};

class Coffee:public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮水" << endl;
	};
	//冲泡
	virtual void Brew()
	{
		cout << "泡咖啡粉" << endl;
	};
	//倒入杯中
	virtual void PutIntoCup()
	{
		cout << "倒入杯中" << endl;
	};
	//放入辅料
	virtual void PutSomething() 
	{
		cout << "放入牛奶和糖" << endl;
	};
};

class MilkyTea :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮水" << endl;
	};
	//冲泡
	virtual void Brew()
	{
		cout << "泡奶粉和茶" << endl;
	};
	//倒入杯中
	virtual void PutIntoCup()
	{
		cout << "倒入杯中" << endl;
	};
	//放入辅料
	virtual void PutSomething()
	{
		cout << "放入珍珠" << endl;
	};
};

void make(AbstractDrinking &abs)
{
	abs.doMake();
	//delete abs;
}

void test01()
{
	Coffee s;
	make(s);
	//make(new Coffee);
}

int main()
{
	test01();
	system("pause");
	return 1;
}