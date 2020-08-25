#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

//vector ��������
void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
void test1()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}


	printVector(v1);



	//����
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	//n��elem����
	vector<int>v3(10, 100);
	printVector(v3);

	vector<int>v4(v3);
	printVector(v4);
}


//��ֵ
void test2()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//��ֵ
	vector<int>v2;
	v2 = v1;
	printVector(v2);

	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	//n��elem��ʽ
	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}

//�����ʹ�С
void test3()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())//
		cout << "v1Ϊ��" << endl;
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ " << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ " << v1.size() << endl;
	}
	v1.resize(15,100);//�����100Ĭ��Ϊ0
	printVector(v1);

	v1.resize(5);
	printVector(v1);
}
//�����ɾ��
void test4()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	v1.pop_back();
	printVector(v1);

	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//shanchu
	v1.erase(v1.begin());
	printVector(v1);
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}
//ȡֵ
void test5()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout <<left<<setw(18)<<"[]�±귽ʽ����:" << v1[2] << endl 
		<<left<<setw(18)<< "at��ʽ����:" << v1.at(2) << endl;
	cout << "��һ��Ԫ��Ϊ" << v1.front() << endl;
	cout << "���һ��Ԫ��Ϊ" << v1.back() << endl;
}
//����
void test6()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "����ǰ" << endl;
	printVector(v1);
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(10-i);
	}
	printVector(v2);

	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//ʵ����;
void test7()
{
	vector<int>v1;
	for (int i = 0; i < 10000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1������Ϊ��  " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ��  " << v1.size() << endl;
	v1.resize(3);
	cout << "v1������Ϊ��  " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ��  " << v1.size() << endl;

	//����swap�����ڴ�
	vector<int>(v1).swap(v1);
	cout << "v1������Ϊ��  " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ��  " << v1.size() << endl;

}

//Ԥ���ռ�
void test8()
{
	vector<int>v;

	//����reserveԤ���ռ�
	v.reserve(100000);
	int num = 0;
	int *p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
}
int main()
{
	test8();
	system("pause");
	return 1;
}