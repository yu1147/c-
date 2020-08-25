#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;


void printMap(const map<int,int>&m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << (*it).first << ",value: " << (*it).second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, int>m1;
	//按first值排序
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);

	//拷贝构造
	
	map<int, int>m2(m1);
	printMap(m2);

	//赋值
	map<int, int>m3;
	m3 = m2;
	printMap(m2);
}

//大小和交换
void test02()
{
	map<int, int>m1;
	//按first值排序
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));

	if (m1.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空" << endl;
		cout << "容器大小" << m1.size();
	}
	
	map<int, int>m2;
	//按first值排序
	m2.insert(pair<int, int>(1, 10));
	m2.insert(pair<int, int>(2, 20));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(4, 50));
	m2.insert(pair<int, int>(4, 40));
	cout << "Before: " << endl;
	printMap(m1);
	printMap(m2);
	m1.swap(m2);
	cout << "After : " << endl;
	printMap(m1);
	printMap(m2);
}


//插入删除

void test03()
{
	map<int, int>m1;
	//按first值排序
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(make_pair(5, 50));
	m1.insert(map<int, int>::value_type(6, 30));
	m1[7] = 70;
	printMap(m1);
	//cout << m1[8] << endl;
	//printMap(m1);
	m1.erase(m1.begin());
	printMap(m1);
	m1.erase(3);
	printMap(m1);

	m1.clear();
	printMap(m1);
}

void test04()
{
	map<int, int>m1;
	//按first值排序
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	map<int,int>::iterator it=m1.find(4);

	if (it != m1.end())
	{
		cout << "查到此元素：" <<(*it).second<< endl;
	}
	//cout << (*it).second << endl;
	int num = m1.count(4);
	cout << num << endl;
}

class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
//排序
void test05()
{
	map<int, int, myCompare>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	
		for (map<int, int,myCompare>::iterator it = m1.begin(); it != m1.end(); it++)
		{
			cout << "key: " << (*it).first << ",value: " << (*it).second << endl;
		}
		cout << endl;
	
}
int main()
{
	test05();
	system("pause");
	return 1;
}