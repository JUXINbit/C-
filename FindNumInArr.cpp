#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;
//�������г��ִ����������鳤��һ�������
//����һ�� ����֮����һ��ָ��ָ���м��±괦 �ض���Ŀ������ �� �¼����Ӷȣ� o��N*lgN��
//�������� �ݹ�Ķ����㷨ʵ��  ʱ�临�Ӷȣ� o��N��
//�������� ������������ԣ�ʹ����������  ����һ�����飬ʱ�临�Ӷȣ�o��N��


//����һ�� �ݹ�Ķ����㷨��




//����Ҫ����Ҫ��������������Ƿ���������ĿҪ���
bool CheckMoreThanHalf(const int* a, int length, int num)
{
	int size = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (a[i] == num)
			size++;
	}
	if (size * 2>length)
		return true;
	else
		return false;
}
//�������� ������������ ������һ���ļ��� 
//�@����������˼���ǣ� ֻҪ�����������ִ�������Ԫ�صĴ����������鳤�ȵ�һ�룬�@���ķ�����һ����������ȷ��
int SearchNumInArr(const int* a ,size_t n)
{
	assert(a);                     //���������ָ���Ƿ�Ϊ��
	assert(n);                     //��������ĳ����Ƿ�Ϊ0
	int TargeNum = 0;
	int tmpnum = a[0];
	int count = 1;
	for (size_t i = 1; i < n; i++)
	{
		if (a[i] == tmpnum)
			count++;
		else
			count--;
		if (count == 0)
		{
			tmpnum = a[i];
			count = 1;
			TargeNum = a[i];
		}
	}
	if (CheckMoreThanHalf(a, n, TargeNum))
		return TargeNum;
	else
	{
		printf("INPUT ERROR");
		return 0;
	}
}

void test()
{
	//int arr[] = { 1, 2, 3, 2, 2, 2, 4, 5, 2 };
	int arr[] = { 1, 2, 3, 2, 2, 2, 4, 5, 7, 9, 10, 13, 15, 3 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	cout << SearchNumInArr(arr, size) << endl;
}
int main()
{
	test();
	return 0;
}