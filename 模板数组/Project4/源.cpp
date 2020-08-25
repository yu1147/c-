#include"array.h"
#include<iomanip>

class Person
{
	string m_name;
	int m_age;


public:
	Person(string name = "no name", int age = 0)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}


};

template<class T>
void print2(myArray<T> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
		cout << arr[i] << " " << endl;
}

void printPerson(myArray<Person>&s)
{
	int t = s.getSize();
	for (int i = 0; i < t; i++)
	{
		cout << "姓名：" <<left<<setw(9)<< s[i].getName() << " 年龄为：" << s[i].getAge() << endl;
	}
}

void test2()
{
	myArray<Person>arr4(10);

	Person p1("孙悟空",100);
	Person p2("韩信", 545);
	Person p3("赵云",12);
	Person p4("刘婵",5);
	Person p5("刘备",64);

	arr4.Push_Back(p1);
	arr4.Push_Back(p2);
	arr4.Push_Back(p3);
	arr4.Push_Back(p4);
	arr4.Push_Back(p5);

	printPerson(arr4);
	cout << "容器容量为：" << arr4.getCapacity() << endl;
	cout << "容器大小为：" << arr4.getSize() << endl;
	
}
void test1()
{
	myArray <int>arr1(5);
	
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1的输出为：" << endl;
	print2<int>(arr1);

	//arr1.print();
	arr1.Get_Array(2);
	//myArray<int>arr2(arr1);
	//myArray<int>arr3(10);
	//arr3 = arr1;
}
int main()
{
	test2();

	system("pause");
	return 1;
}