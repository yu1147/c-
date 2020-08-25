#include<iostream>
#include<strstream>

using namespace std;
char *parseString(char *pString)
{
	istrstream inp(pString);
	int anumber;
	float balance;
	inp >> anumber >> balance;

	char *pBuffer = new char[128];
	ostrstream outp(pBuffer, 128);
	outp << "a Number = " << anumber << ", balance = " << balance;
	return pBuffer;

}

int main()
{
	char *parseString(char *pString);
	char *str = "1234 100.35";
	char * pBuf = parseString(str);
	cout << pBuf << endl;
	delete[] pBuf;
}