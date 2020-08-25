#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;
//选手类
class Person
{
	string m_name;//姓名
	int m_score;  //平均分
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
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); 
		it != v.end(); it++)//每个人打分
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		/*cout << it->getName() << "打分" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/
		//sort
		sort(d.begin(), d.end());
		//去除最高分和最低分
		d.pop_back();
		d.pop_front();

		//取平均分；
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
		cout << it->getName() << "的平均分: " <<it->getScore()<< endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建五名选手
	vector<Person>v;
	createPerson(v);

	//2、给五名选手打分
	setScore(v);

	//3.显示最后得分
	showScore(v);
	system("pause");
	return 1;
}