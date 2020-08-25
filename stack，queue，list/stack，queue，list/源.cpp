#include<iostream>
#include<iomanip>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

//��ӡ�б�list
void printList(const list<int>&l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}

class Person
{
public:
	Person(string name="no name", int age=19,int height=160)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}

	string m_name;
	int m_age;
	int m_height;
};

//stack ���ý��
void test1()
{
	stack<int>s;
	//��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "ջ�Ĵ�С" << s.size() << endl;
	while (!s.empty())
	{
		cout << "ջ��Ԫ�أ� " << s.top() << endl;

		s.pop();
	}

	cout << "ջ�Ĵ�С" << s.size() << endl;
}

//queue���ý��
void test2()
{
	queue<Person>q1;
	queue<int>q2;
	
	Person p1("��ɮ",30);
	Person p2("�����", 100);
	Person p3("��˽�", 40);
	Person p4("ɳ��", 50);

	q1.push(p1);
	q1.push(p2);
	q1.push(p3);
	q1.push(p4);

	cout << "���д�СΪ��" << q1.size() << endl;
	while (!q1.empty())
	{
		cout << "��ͷԪ�� --- ������ " << q1.front().m_name 
			<< " ���䣺 " << q1.front().m_age << endl;
		cout << "��βԪ�� --- ������ " << q1.back().m_name 
			<< " ���䣺 " << q1.back().m_age << endl;
		
		q1.pop();
		cout << "���д�СΪ��" << q1.size() << endl;

	}

}


//����list
//����
void listTest01()
{
	list<int>l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printList(l1);

	list<int>l2(l1.begin(), l1.end());
	printList(l2);

	list<int>l3(l2);
	printList(l3);

	list<int>l4(10, 55);
	printList(l4);

	
}

//��ֵ����
void listTest02()
{
	//β�巨
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);

	list<int>l2;
	l2 = l1;
	printList(l2);

	//ͷ�巨
	list<int>l3;
	l3.push_front(10);
	l3.push_front(20); 
	l3.push_front(30);
	l3.push_front(40);
	printList(l3);

	list<int>l4;
	l4.assign(l3.begin(), l3.end());
	printList(l4);

	list<int>l5;
	l5.assign(10, 52);
	printList(l5);

	cout << "����ǰ: " << endl;
	cout << "l1: ";
	printList(l1);
	cout << "l5: ";
	printList(l5);

	l1.swap(l5);
	cout << "������: " << endl;
	cout << "l1: ";
	printList(l1);
	cout << "l5: ";
	printList(l5);
}

void listTest03()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);

	if (l1.empty())
	{
		cout << "����listΪ��" << endl;
	}
	else
	{
		cout << "����list��Ϊ��" << endl;
		cout << "�����Ĵ�С�� " << l1.size() << endl;
	
	}

	l1.resize(10);
	printList(l1);
	l1.resize(15, 16);
	printList(l1);
	l1.resize(2);
	printList(l1);
}
//����ɾ��
void listTest04()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_front(100);
	l1.push_front(200);
	l1.push_front(300);
	// 300 200 100 10 20 30 40 
	printList(l1);

	l1.pop_back();
	//300 200 100 10 20 30
	printList(l1);

	l1.pop_front();
	//200 100 10 20 30
	printList(l1);

	list<int>::iterator it = l1.begin();
	it++;//itָ��100
	l1.insert(it,99);//��100ǰ����
	//200 99 100 10 20 30
	printList(l1);

	it++;//itָ��10
	l1.erase(it);//ɾ��10,it��ʱ��Ҫ����ָ��
	// 200 99 100 20 30
	printList(l1);
	it = l1.begin();
	it++;
	it++;//ָ��100
	l1.erase(it);
	//200 99 20 30
	printList(l1);

	l1.push_back(99);
	printList(l1);
	//yichu
	l1.remove(99);
	printList(l1);

	//���
	l1.clear();
	printList(l1);
}

//���ݴ�ȡ
void listTest05()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_front(100);
	l1.push_front(200);
	l1.push_front(300);

	cout << "��һ��Ԫ��Ϊ�� " << l1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << l1.back() << endl;

}
//��ת����
bool myCompare(int v1,int v2)
{
	return v1 > v2;
}
void listTest06()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_front(100);
	l1.push_front(200);
	l1.push_front(300);
	cout << "Before:  " << endl;
	printList(l1);

	cout << "Reverse:  " << endl;
	//list<int>l2;
	l1.reverse();
	printList(l1);

	cout << "Sort:  " << endl;
	//sort(l1.begin(), l1.end());  
	//list��֧��������ʣ��ʲ���ʹ��sort�㷨
	l1.sort();
	printList(l1);

	l1.sort(myCompare);
	printList(l1);

}

//�������
bool comparePerson(Person &p1, Person &p2)
{
	//������������
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age < p2.m_age;
	}
	
}

//������
void listAnli()
{
	list<Person>l;

	Person p1("����", 35, 175);
	Person p2("�ܲ�", 45, 180);
	Person p3("��Ȩ", 40, 170);
	Person p4("����", 25, 190);
	Person p5("�ŷ�", 35, 160);
	Person p6("����", 35, 200);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "������ " << (*it).m_name << " ���䣺 " << (*it).m_age << " ��ߣ� " << (*it).m_height << endl;
	}

	//����
	cout << "-------------------------------" << endl;

	l.sort(comparePerson);
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "������ " << (*it).m_name << " ���䣺 " << (*it).m_age << " ��ߣ� " << (*it).m_height << endl;
	}
}
int main()
{
	listAnli();
	system("pause");
	return 1;
}