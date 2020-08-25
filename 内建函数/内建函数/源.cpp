#include<iostream>
#include<iomanip>
#include<functional>
using namespace std;

void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}

void test02()
{
	plus<int>n;
	cout << n(10, 26) << endl;
}
int main()
{
	test02();
	system("pause");
	return 1;
}