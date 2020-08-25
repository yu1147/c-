#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myPrint
{
public:
	myPrint()
	{
		number = 0;
	}
	void operator()(string text)
	{
		cout << text << endl;
		number++;
	}
	int number;
};

void doprint(myPrint &m,string test)
{
	m(test);
}

void test01()
{
	myPrint m1;
	doprint(m1, "hey");
}

class BiggerThanFIve
{
public:
	bool operator()(int val)
	{
		return val < 5;
	}
};

bool open(int val)
{
	return val >25;
}
void test02()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(4);
	v1.push_back(60);
	
	vector<int>::iterator it=find_if(v1.begin(), v1.end(), BiggerThanFIve());//返回迭代器位置,open可以改为
	//biggergreater（）
	if(it==v1.end())
	{ 
		cout << "不存在" << endl;

	}
	else
	{
		cout << "YES,and it's value is :" << (*it) << endl;
	}

}


int main()
{
	test02();
	system("pause");
	return 1;
	
}