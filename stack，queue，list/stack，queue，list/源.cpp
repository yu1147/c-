#include<iostream>
#include<iomanip>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

//打印列表list
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

//stack 常用借口
void test1()
{
	stack<int>s;
	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的大小" << s.size() << endl;
	while (!s.empty())
	{
		cout << "栈顶元素： " << s.top() << endl;

		s.pop();
	}

	cout << "栈的大小" << s.size() << endl;
}

//queue常用借口
void test2()
{
	queue<Person>q1;
	queue<int>q2;
	
	Person p1("唐僧",30);
	Person p2("孙悟空", 100);
	Person p3("猪八戒", 40);
	Person p4("沙悟净", 50);

	q1.push(p1);
	q1.push(p2);
	q1.push(p3);
	q1.push(p4);

	cout << "队列大小为：" << q1.size() << endl;
	while (!q1.empty())
	{
		cout << "队头元素 --- 姓名： " << q1.front().m_name 
			<< " 年龄： " << q1.front().m_age << endl;
		cout << "队尾元素 --- 姓名： " << q1.back().m_name 
			<< " 年龄： " << q1.back().m_age << endl;
		
		q1.pop();
		cout << "队列大小为：" << q1.size() << endl;

	}

}


//链表list
//构造
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

//赋值交换
void listTest02()
{
	//尾插法
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);

	list<int>l2;
	l2 = l1;
	printList(l2);

	//头插法
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

	cout << "交换前: " << endl;
	cout << "l1: ";
	printList(l1);
	cout << "l5: ";
	printList(l5);

	l1.swap(l5);
	cout << "交换后: " << endl;
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
		cout << "容器list为空" << endl;
	}
	else
	{
		cout << "容器list不为空" << endl;
		cout << "容器的大小： " << l1.size() << endl;
	
	}

	l1.resize(10);
	printList(l1);
	l1.resize(15, 16);
	printList(l1);
	l1.resize(2);
	printList(l1);
}
//插入删除
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
	it++;//it指向100
	l1.insert(it,99);//在100前插数
	//200 99 100 10 20 30
	printList(l1);

	it++;//it指向10
	l1.erase(it);//删掉10,it此时需要重新指向
	// 200 99 100 20 30
	printList(l1);
	it = l1.begin();
	it++;
	it++;//指向100
	l1.erase(it);
	//200 99 20 30
	printList(l1);

	l1.push_back(99);
	printList(l1);
	//yichu
	l1.remove(99);
	printList(l1);

	//清空
	l1.clear();
	printList(l1);
}

//数据存取
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

	cout << "第一个元素为： " << l1.front() << endl;
	cout << "最后一个元素为：" << l1.back() << endl;

}
//反转排序
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
	//list不支持随机访问，故不能使用sort算法
	l1.sort();
	printList(l1);

	l1.sort(myCompare);
	printList(l1);

}

//排序规则
bool comparePerson(Person &p1, Person &p2)
{
	//按照年龄升序
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age < p2.m_age;
	}
	
}

//排序案例
void listAnli()
{
	list<Person>l;

	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名： " << (*it).m_name << " 年龄： " << (*it).m_age << " 身高： " << (*it).m_height << endl;
	}

	//排序
	cout << "-------------------------------" << endl;

	l.sort(comparePerson);
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名： " << (*it).m_name << " 年龄： " << (*it).m_age << " 身高： " << (*it).m_height << endl;
	}
}
int main()
{
	listAnli();
	system("pause");
	return 1;
}