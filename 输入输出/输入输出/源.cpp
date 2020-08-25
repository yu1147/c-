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
	ofs << "姓名：小圆" << endl;
	ofs << "年龄：12" << endl;
	ofs.close();
}

void test02()
{
	ifstream ifs;
	ifs.open("123.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
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
		cout << "打开文件失败" << endl;
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
		cout << "文件打开失败" << endl;
	}
	Person p;
	ifs.read((char *)&p, sizeof(Person));
	cout << " 姓名： " << p.name << " 年龄：" << p.age << endl;
	ifs.close();
}
int main()
{
	test05();
	system("pause");
	return 1;
}