#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

template<class T>
void myswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void sort(T str, int num)
{
	
	for (int i = 0; i < num; i++)
	{
		int max = i;
		for (int j = i+1; j < num; j++)
			if (str[j] > str[max])
				max = j;
		if (max != i)
			myswap(str[max], str[i]);

	}

}
template<class T>
void print(T str, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (i % 10 == 0&&i)cout << endl;
		cout << str[i] << " ";
		
	}
	cout << endl;
}

void test01()
{
	char str1[] = "dsafbx";
	int num = sizeof(str1) / sizeof(char);
	sort(str1, num);
	print(str1, num);
}

void test02()
{
	int str2[] = { 10,3,4,5,12,20,99,21,23,34,124,1232 };
	int num = sizeof(str2)/sizeof(int);
	sort(str2, num);
	print(str2, num);


}

int main()
{

	test02();
	system("pause");
	return 1;

}



