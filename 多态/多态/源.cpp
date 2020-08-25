#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class animal
{

public:
	
	string *name;
	animal()
	{
		cout << "anmal构造函数调用" << endl;
	}
	virtual ~animal()
	{
		cout << "anmal析构函数调用" << endl;
	}
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
	
};

class dog :public animal
{
public:
	dog(string m)
	{
		name = new string(m);
	}
	void speak()
	{
		cout <<*name<< "狗在说话" << endl;
	}
	~dog()
	{
		if (name != NULL)
		{
			cout << "dog析构中" << endl;

			delete name;
			name = NULL;
		}
	}
};

class cat :public animal
{
public:
	cat(string m)
	{
		cout << "cat构造函数调用" << endl;
		name = new string(m);
	}
	void speak()
	{
		cout <<*name<< "猫在说话" << endl;
	}
	~cat()
	{
		if (name != NULL)
		{
			cout << "cat析构中" << endl;

			delete name;
			name = NULL;
		}
	}
		
};


void doSpeak(animal &animal)
{
	animal.speak();
}
void test01()
{
	cat c("TOM");
	doSpeak(c);
}
//
//void test02()
//{
//	animal a;
//	//cat c(cat);
//	cout << "sizeof " << sizeof(a) << "  " <<sizeof(c) << endl;
//}

void test03()
{
	animal *ani = new cat("TOM");
	ani->speak();
	delete ani;
}
int main()
{
	test01();
	system("pause");
	return 1;
}