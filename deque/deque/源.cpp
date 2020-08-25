#include<iostream>
#include<iomanip>
#include<deque>//����˫�˶���
#include<algorithm>
using namespace std;


void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//���캯��
void test1()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);
}
//��ֵ
void test2()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	deque<int>d3;
	d3.assign(d2.begin(), d2.end());
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 1000);
	printDeque(d4);


}

//��С
void test3()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	if (d1.empty())
	{
		cout << "��dequeΪ��" << endl;
	}
	else
	{
		cout << "��deque��Ϊ��" << endl;
		cout << "deque�Ĵ�СΪ��" << d1.size() << endl;
	}

	d1.resize(15);
	printDeque(d1);

	d1.resize(16,200);
	printDeque(d1);
}

//����ɾ��
void test4()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);

	}
	printDeque(d1);
	d1.clear();
	for (int i = 0; i < 10; i++)
	{
		d1.push_front(i);
	}
	printDeque(d1);
}

//ȡֵ
void test5()
{
	//at
	//[]
	//front
	//back
}
//����
void test6()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	cout << "Before sort : ";
	printDeque(d1);
	cout << endl;
	cout << "After  sort : ";
	sort(d1.begin(), d1.end());
	printDeque(d1);
	cout << endl;
}
int main()
{
	test6();
	system("pause");
	return 1;
}