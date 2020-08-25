#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;
//ѡ����
class Person
{
	string m_name;//����
	int m_score;  //ƽ����
public:
	Person(string name, int score)
	{
		m_name = name;
		m_score = score;
	}

	void changeScore(int score)
	{
		m_score = score;
	}
	string getName()
	{
		return m_name;
	}

	int getScore()
	{
		return m_score;
	}

	
};


void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); 
		it != v.end(); it++)//ÿ���˴��
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		/*cout << it->getName() << "���" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/
		//sort
		sort(d.begin(), d.end());
		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ���֣�
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);
		}
		int average = sum / d.size();
		(*it).changeScore(average);
	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->getName() << "��ƽ����: " <<it->getScore()<< endl;
	}
}
int main()
{
	//���������
	srand((unsigned int)time(NULL));
	//��������ѡ��
	vector<Person>v;
	createPerson(v);

	//2��������ѡ�ִ��
	setScore(v);

	//3.��ʾ���÷�
	showScore(v);
	system("pause");
	return 1;
}