#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PutIntoCup() = 0;
	//���븨��
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
	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	};
	//����
	virtual void Brew()
	{
		cout << "�ݿ��ȷ�" << endl;
	};
	//���뱭��
	virtual void PutIntoCup()
	{
		cout << "���뱭��" << endl;
	};
	//���븨��
	virtual void PutSomething() 
	{
		cout << "����ţ�̺���" << endl;
	};
};

class MilkyTea :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	};
	//����
	virtual void Brew()
	{
		cout << "���̷ۺͲ�" << endl;
	};
	//���뱭��
	virtual void PutIntoCup()
	{
		cout << "���뱭��" << endl;
	};
	//���븨��
	virtual void PutSomething()
	{
		cout << "��������" << endl;
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