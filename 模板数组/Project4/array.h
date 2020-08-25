#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class myArray
{
public:

	//构造函数
	myArray(int Capacity)
	{
		//cout << "构造" << endl;
		pAddress = new T[Capacity];
		p_size = 0;
		p_capacity = Capacity;
	}

	//拷贝函数
	myArray(myArray &s)
	{
		//cout << "拷贝" << endl;

		p_capacity = s.p_capacity;
		p_size = s.p_size;
		//深拷贝
		pAddress = new T[s.p_capacity];
		if (pAddress)
			for (int i = 0; i < p_size; i++)
				this->pAddress[i] = s.pAddress[i];
		
		
	}

	//operator =防止浅拷贝问题
	myArray &operator=(myArray& s)
	{
		//cout << "=深拷贝" << endl;
		if (pAddress)
		{
			delete pAddress;
			pAddress = NULL;
			p_size = 0;
			p_capacity = 0;
		}
		p_capacity = s.p_capacity;
		p_size = s.p_size;
		pAddress = new T[s.p_capacity];
		if (pAddress)
			for (int i = 0; i <p_size; i++)
				this->pAddress[i] = s.pAddress[i];
		
		return *this;
	}

	//尾插法
	void Push_Back(const T &a)
	{
		if (p_size < p_capacity)
		{
			pAddress[p_size] = a;
			p_size = p_size + 1;
		}
		else return;

	}

	//尾删法
	void Pop_Back(const T &a)
	{
		if (p_size > 0)
		{
			--p_size;
		}
		else return;
	}

	//通过下标方式访问数组中的元素
	T Get_Array(int i)
	{
		if (i >= 0 && i < p_size)
		{
			return pAddress[i];
		}
		else exit(0);

	}

	T& operator[](int index)
	{
		if (index >= 0 && index < p_size)
		{
			return pAddress[index];
		}
		else exit(0);
	}

	//返回数组容量
	int getCapacity()
	{
		return p_capacity;
	}
	//返回数组大小
	int getSize()
	{
		return p_size;
	}
	//打印数组
	//void print()
	//{
	//	for (int i = 0; i < p_size; i++)
	//		cout << pAddress[i]<<" ";
	//	cout << endl;
	//}

	//析构函数
	~myArray()
	{
		if (pAddress != NULL)
		{
			//cout << "析构中" << endl;
			delete[] pAddress;
			pAddress = NULL;
		}
	}


private:
	T *pAddress;
	int p_capacity;
	int p_size;



};
