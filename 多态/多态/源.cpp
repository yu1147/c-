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
		cout << "anmal���캯������" << endl;
	}
	virtual ~animal()
	{
		cout << "anmal������������" << endl;
	}
	virtual void speak()
	{
		cout << "������˵��" << endl;
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
		cout <<*name<< "����˵��" << endl;
	}
	~dog()
	{
		if (name != NULL)
		{
			cout << "dog������" << endl;

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
		cout << "cat���캯������" << endl;
		name = new string(m);
	}
	void speak()
	{
		cout <<*name<< "è��˵��" << endl;
	}
	~cat()
	{
		if (name != NULL)
		{
			cout << "cat������" << endl;

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