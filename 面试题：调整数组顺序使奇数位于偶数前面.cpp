#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;
//��������˳��ʹ������λ��ż��ǰ��

void ReoederOddEven(int arr[],int length)
{
	assert(arr);
	assert(length);
	int begin = 0;
	int end = length - 1;
	while (begin < end)
	{
		while (arr[begin] % 2)  //����
		{
			begin++;
		}
		while (arr[end] % 2 == 0)   //ż��
		{
			end--;
		}
		swap(arr[begin], arr[end]);
	}
}
int main()
{
	int arr[] = { 2, 5, 7, 1, 9, 3, 4, 6 };
	ReoederOddEven(arr, sizeof(arr) / sizeof(arr));
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}