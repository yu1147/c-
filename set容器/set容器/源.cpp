#include<iostream>
#include<iomanip>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
//����

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
	//set�Զ������Ҳ��ظ�
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

//��С�ͽ�����������resize����
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ��" << endl;
		cout << "�����Ĵ�СΪ�� " << s1.size() << endl;
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

//�����ɾ��
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

//���Һ�ͳ��
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
		cout << "�ҵ�Ԫ�أ�" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	cout << s1.count(20) << endl;
}
//set��multiset����
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
//pair����Ĵ���
void test06()
{
	pair<string, int>p("TOM", 20);
	cout << "������" << p.first << " ���䣺" << p.second << endl;

	pair<string, int>p2 = make_pair("JERRY", 30);
	cout << "������" << p2.first << " ���䣺" << p2.second << endl;
}

//SET������
void test07()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);
	//�Ӵ�С
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
	//�Զ����������ͣ�����ָ���������
	set<Person,compare2>s1;
	
	Person p1("����", 40);
	Person p2("����", 38);
	Person p3("�ŷ�", 27);
	Person p4("����", 36);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	for (set<Person,compare2>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "������ " << (*it).m_name << " ���䣺 " << (*it).m_age << endl;
	}
}
int main()
{
	test08();
	system("pause");
	return 1;
}