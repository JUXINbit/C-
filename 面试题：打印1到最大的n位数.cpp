#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
//��ӡ1������nλ��
using namespace std;
//�����ַ�����һλ
bool IncreaseNum(char* str,int n)
{
	assert(str);
	int i = n - 1;
	while (str[i] == 9)
	{
		str[i] = 0;
		i--;
		if (i < 0)
			return true;
	}
	str[i]++;
	return false;
}
void PintNum()
{

}
void  PrintOneToN(int n)
{
	assert(n);
	//����һ����ʼ��
	char* NumArr = new char[n + 1];
	NumArr[n] = 0;
	for (int i = 0; i < n; i++)
	{
		NumArr[i] = '0';
	}
	while (!IncreaseNum(NumArr,n))
	{
		cout << NumArr << endl;
	}
}

int main()
{
	PrintOneToN(2);
	return 0;
}