#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class myArray
{
public:

	//���캯��
	myArray(int Capacity)
	{
		//cout << "����" << endl;
		pAddress = new T[Capacity];
		p_size = 0;
		p_capacity = Capacity;
	}

	//��������
	myArray(myArray &s)
	{
		//cout << "����" << endl;

		p_capacity = s.p_capacity;
		p_size = s.p_size;
		//���
		pAddress = new T[s.p_capacity];
		if (pAddress)
			for (int i = 0; i < p_size; i++)
				this->pAddress[i] = s.pAddress[i];
		
		
	}

	//operator =��ֹǳ��������
	myArray &operator=(myArray& s)
	{
		//cout << "=���" << endl;
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

	//β�巨
	void Push_Back(const T &a)
	{
		if (p_size < p_capacity)
		{
			pAddress[p_size] = a;
			p_size = p_size + 1;
		}
		else return;

	}

	//βɾ��
	void Pop_Back(const T &a)
	{
		if (p_size > 0)
		{
			--p_size;
		}
		else return;
	}

	//ͨ���±귽ʽ���������е�Ԫ��
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

	//������������
	int getCapacity()
	{
		return p_capacity;
	}
	//���������С
	int getSize()
	{
		return p_size;
	}
	//��ӡ����
	//void print()
	//{
	//	for (int i = 0; i < p_size; i++)
	//		cout << pAddress[i]<<" ";
	//	cout << endl;
	//}

	//��������
	~myArray()
	{
		if (pAddress != NULL)
		{
			//cout << "������" << endl;
			delete[] pAddress;
			pAddress = NULL;
		}
	}


private:
	T *pAddress;
	int p_capacity;
	int p_size;



};
