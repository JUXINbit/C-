#define _CRT_SECURE_NO_WARNINGS 1
//��һ�����������е�1�ĸ�������������ż����
#include<iostream>
using namespace std;

int test(int value,int bits)
{
	int count = 0;
	while (bits)
	{
		if (value & 1 == 1)
			count++;
		value = value >> 1;
		bits--;
	}
	return count;
}
int main()
{
	cout << test(10, 32) << endl;
	return 0;
}