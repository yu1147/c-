#include<iostream>
#include<iomanip>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
//构造

class Person
{
public:
	string m_name;
	int m_age;
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};

class compare2
{
public:
	bool operator()(const Person &s1, const Person &s2)
	{
		return s1.m_age < s2.m_age;
	}
};
class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void printSet(const set<int>&s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}

void printSet(const multiset<int>&s)
{
	for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
void test01()
{
	//set自动排序且不重复
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);
	s1.insert(30);
	printSet(s1);

	
	set<int>s2(s1);
	printSet(s2);

	set<int>s3;
	s3 = s2;
	printSet(s3);

}

//大小和交换，不允许resize（）
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空" << endl;
		cout << "容器的大小为： " << s1.size() << endl;
	}
	set<int>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(60);
	s2.insert(70);
	cout << "Before: " << endl;
	cout << "s1: ";
	printSet(s1);
	cout << "s2: ";
	printSet(s2);

	s1.swap(s2);
	cout << "After : " << endl;
	cout << "s1: ";
	printSet(s1);
	cout << "s2: ";
	printSet(s2);

	
	
}

//插入和删除
void test03()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.erase(20);
	printSet(s1);
}

//查找和统计
void test04()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>::iterator pos = s1.find(20);
	if (pos != s1.end())
	{
		cout << "找到元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	cout << s1.count(20) << endl;
}
//set和multiset区别
void test05()
{
	set<int>s1;
	pair<set<int>::iterator, bool>ret = s1.insert(10);
	if (ret.second)
		cout << "The first insert has succeeded." << endl;
	
	else
		cout << "The first insert has failed." << endl;

	ret = s1.insert(10);
	if (ret.second)
		cout << "The second insert has succeeded." << endl;

	else
		cout << "The second insert has failed." << endl;

	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	printSet(ms);
}
//pair对组的创建
void test06()
{
	pair<string, int>p("TOM", 20);
	cout << "姓名：" << p.first << " 年龄：" << p.second << endl;

	pair<string, int>p2 = make_pair("JERRY", 30);
	cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}

//SET器排序
void test07()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);
	//从大到小
	set<int,myCompare>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	for (set<int, myCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";

	}
	cout << endl;
}
void test08()
{
	//自定义数据类型，都会指定排序规则
	set<Person,compare2>s1;
	
	Person p1("刘备", 40);
	Person p2("关羽", 38);
	Person p3("张飞", 27);
	Person p4("赵云", 36);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	for (set<Person,compare2>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名： " << (*it).m_name << " 年龄： " << (*it).m_age << endl;
	}
}
int main()
{
	test08();
	system("pause");
	return 1;
}