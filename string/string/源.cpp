#include<iostream>
#include<string>
using namespace std;

//赋值
void test1()
{
	string str1(5, 'a');
	string str2;
	str2.assign(10,'w' );
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	string str3 = "我";
	str3 += "爱玩游戏";
	cout << "str3:" << str3 << endl;

	string str4 = "I";
	str4.append(" love playing games");
	cout << "str4:" << str4 << endl;
}
//查找
void test2()
{
	string str1 = "abcdebc";
	int t=str1.find("bc");
	int t2 = str1.rfind("bc");
	cout <<"find pos：" <<t << endl;
	cout << "rfind pos: " << t2 << endl;
}

//替换
void test3()
{
	string str1 = "abcdf";
	string str2("bss");
	str1.replace(2, 2, str2);
	cout << "str1:" << str1 << endl;

}

//比较
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

//存取
void test5()
{
	string str1 = "abdsk";
	cout << "at方式调用  ："<<str1.at(2) << endl;
	cout << "下标方式调用：" << str1[2] << endl;

}

//插入，删除
void test6()
{
	string str1 = "hello";
	//插入
	str1.insert(1, "1111");
	cout << str1 << endl;
	//删除
	string str2 = "he";
	str1.erase(1,4);
	cout << str1 << endl;
}

//求子串
void test7()
{
	string str1 = "hello";
	string str2=str1.substr(2, 3);
	cout << "子串为：" << str2 << endl;
}

//实用操作
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