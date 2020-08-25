#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};

void myPrint(int val)
{
	cout << val << endl;
}
void test1()
{
	vector<Person> v;
	
	Person p1("aaa", 12);
	Person p2("bbb", 152);
	Person p3("ccc", 1);
	Person p4("ddd", 165);
	Person p5("eee", 1655);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << " 年龄：" << it->m_age<<endl;
	}


	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//第一种遍历
	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << " ";
	//	itBegin++;
	//}
	//cout << endl;

	//for_each(v.begin(), v.end(), myPrint);

}

void test2()
{
	vector<Person*> v;

	Person p1("aaa", 12);
	Person p2("bbb", 152);
	Person p3("ccc", 1);
	Person p4("ddd", 165);
	Person p5("eee", 1655);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->m_name << " 年龄：" << (*(*it)).m_age << endl;
	}
}

void test3()
{
	vector<vector<int>>v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{

		for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
		{
			cout << (*it2) << " ";
		}
		cout << endl;
	}
}
int main()
{
	test3();
	system("pause");
	return 1;
}