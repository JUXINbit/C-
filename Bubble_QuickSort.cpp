#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;


//��������ð������
void Bubble_Sort(int* a,size_t size)
{
	assert(a);
	assert(size);
	int end = size - 1;
	while (end)
	{
		bool flag = false;                //���ӱ�־λ��һ���Ż�
		for (int i = 0; i < end; i++)
		{
			if (a[i]>a[i + 1])
			{
				swap(a[i], a[i + 1]);
				flag = true;
			}
		}
		if (flag == false)
			break;
		end--;
	}
}


//����  �ݹ�
//����ȡ��
int GetMid(int* a, int begin, int end)    //�����±�
{
	assert(a);
	//assert(end);
	if (end - begin < 0)
	{
		perror("indexerr");
		return 0;
	}
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] > a[end])
	{
		if (a[mid] >= a[begin])
			return begin;
		else
		{
			if (a[mid] >= a[end])
				return mid;
			else
				return end;
		}
	}
	else if (a[begin] < a[end])
	{
		if (a[mid] <= a[begin])
			return begin;
		else
		{
			if (a[mid] <= a[end])
				return mid;
			else
				return end;
		}
	}
	else
		return begin;

}
//����ָ��
int PartSort(int* a, int left, int right)
{
	assert(a);
	int begin = left;
	int end = right;
	int key = a[end];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)    //ע��������ע����>= �������ȵ�Ԫ�صĻ����ܿ��ܾ���ѭ����
		{
			begin++;
		}
		while (begin < end&&a[end] >= key)
		{
			end--;
		}
		if (begin < end)
		swap(a[begin], a[end]);
	}
	if (begin == end)
	{
		swap(a[begin], a[right]);
		return begin;
	}
}
//�ݹ����
void QuickSort(int* a, int begin, int end)
{
	if (begin < end)
	{
		int MidValueIndex = GetMid(a, begin, end);       //ʹ������ȡ������������һ��ֵ���м�ֵ��
		swap(a[MidValueIndex], a[end]);

		int Mid = PartSort(a, begin, end);
		QuickSort(a, begin, Mid - 1);
		QuickSort(a, Mid + 1, end);
	}
	else
		return;
}

void test()
{
	//��������  ���@��ʹ�����������Ĳ����������̿ɲⳣ��⡣
	int arr[] = { 5, 4, 3, 1, 6, 5 };
	//int arr[] = { 1, 1, 1, 1, 1, 1 };
	//Bubble_Sort(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}