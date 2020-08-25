#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

//vector 容器构造
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



	//区间
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	//n个elem构造
	vector<int>v3(10, 100);
	printVector(v3);

	vector<int>v4(v3);
	printVector(v4);
}


//赋值
void test2()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//赋值
	vector<int>v2;
	v2 = v1;
	printVector(v2);

	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	//n个elem方式
	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}

//容量和大小
void test3()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())//
		cout << "v1为空" << endl;
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为 " << v1.capacity() << endl;
		cout << "v1的大小为 " << v1.size() << endl;
	}
	v1.resize(15,100);//后面的100默认为0
	printVector(v1);

	v1.resize(5);
	printVector(v1);
}
//插入和删除
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
//取值
void test5()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout <<left<<setw(18)<<"[]下标方式调用:" << v1[2] << endl 
		<<left<<setw(18)<< "at方式调用:" << v1.at(2) << endl;
	cout << "第一个元素为" << v1.front() << endl;
	cout << "最后一个元素为" << v1.back() << endl;
}
//互换
void test6()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "交换前" << endl;
	printVector(v1);
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(10-i);
	}
	printVector(v2);

	cout << "交换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//实际用途
void test7()
{
	vector<int>v1;
	for (int i = 0; i < 10000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1的容量为：  " << v1.capacity() << endl;
	cout << "v1的大小为：  " << v1.size() << endl;
	v1.resize(3);
	cout << "v1的容量为：  " << v1.capacity() << endl;
	cout << "v1的大小为：  " << v1.size() << endl;

	//巧用swap收缩内存
	vector<int>(v1).swap(v1);
	cout << "v1的容量为：  " << v1.capacity() << endl;
	cout << "v1的大小为：  " << v1.size() << endl;

}

//预留空间
void test8()
{
	vector<int>v;

	//利用reserve预留空间
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