#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//���Ϊs������
//ʹ������ָ��
bool GetSumIsS(int* a, int size,int sum, int& index1, int& index2)
{
	assert(a);
	if (index1<0 || index2>size - 1)
		return false;
	while (index2 > index1)
	{
		if (a[index1] + a[index2] == sum)
			return true;
		if (a[index1] + a[index2] < sum)     //�Ӻ�С�ˣ�����С������ǰ��һ��λ��
		{
			index1++;
			continue;
		}
		else
		{
			index2--;                      //���˾��ô����������һ��λ��
			continue;
		}
	}
	return false;
}

int main()
{
	int arr[] = { 1, 2, 4, 7, 11, 15 };
	int index1 = 0;
	int index2 = sizeof(arr) / sizeof(arr[0]) - 1;
	if (GetSumIsS(arr, sizeof(arr) / sizeof(arr[0]), 15, index1, index2));
	cout << index1 <<" and "<< index2 << endl;
	return 0;
}