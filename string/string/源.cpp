#include<iostream>
#include<string>
using namespace std;

//��ֵ
void test1()
{
	string str1(5, 'a');
	string str2;
	str2.assign(10,'w' );
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	string str3 = "��";
	str3 += "������Ϸ";
	cout << "str3:" << str3 << endl;

	string str4 = "I";
	str4.append(" love playing games");
	cout << "str4:" << str4 << endl;
}
//����
void test2()
{
	string str1 = "abcdebc";
	int t=str1.find("bc");
	int t2 = str1.rfind("bc");
	cout <<"find pos��" <<t << endl;
	cout << "rfind pos: " << t2 << endl;
}

//�滻
void test3()
{
	string str1 = "abcdf";
	string str2("bss");
	str1.replace(2, 2, str2);
	cout << "str1:" << str1 << endl;

}

//�Ƚ�
void test4()
{
	string str1 = "abcc";
	string str2 = "abcd";
	int ii = str1.compare(str2);
	string str3 = "abcc";
	int ij = str1.compare(str3);
	cout << "ii = " << ii << endl;
	cout << "ij = " << ij << endl;
}

//��ȡ
void test5()
{
	string str1 = "abdsk";
	cout << "at��ʽ����  ��"<<str1.at(2) << endl;
	cout << "�±귽ʽ���ã�" << str1[2] << endl;

}

//���룬ɾ��
void test6()
{
	string str1 = "hello";
	//����
	str1.insert(1, "1111");
	cout << str1 << endl;
	//ɾ��
	string str2 = "he";
	str1.erase(1,4);
	cout << str1 << endl;
}

//���Ӵ�
void test7()
{
	string str1 = "hello";
	string str2=str1.substr(2, 3);
	cout << "�Ӵ�Ϊ��" << str2 << endl;
}

//ʵ�ò���
void test8()
{
	string str1 = "1147669839@qq.com";
	int pos=str1.find("@");
	string account;
	account = str1.substr(0, pos);
	cout << account << endl;
	string office;
	int office_Pos = str1.find(".");
	office = str1.substr(pos + 1, office_Pos - pos-1);
	cout << office << endl;
}
int main()
{
	test8();
	system("pause");
	return 1;
}