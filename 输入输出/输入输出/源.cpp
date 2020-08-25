#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;


class Person
{
public:
	char name[40];
	int age;
	
};
void test01()
{
	ofstream ofs;
	ofs.open("123.txt", ios::out);
	ofs << "������СԲ" << endl;
	ofs << "���䣺12" << endl;
	ofs.close();
}

void test02()
{
	ifstream ifs;
	ifs.open("123.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
	}
	char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}
}

void test03()
{
	ifstream ifs;
	ifs.open("123.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
	}
	char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
}
void test04()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "123",18 };
	ofs.write((const char *)&p, sizeof(p));
	ofs.close();
}

void test05()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	Person p;
	ifs.read((char *)&p, sizeof(Person));
	cout << " ������ " << p.name << " ���䣺" << p.age << endl;
	ifs.close();
}
int main()
{
	test05();
	system("pause");
	return 1;
}