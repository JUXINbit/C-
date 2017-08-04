#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

//1.ѡ������ һ��ѡ��һ��&һ��ѡ����
//2.����

//ѡ������  -----һ��ѡ��һ������
void ChoseSort1(int* a,size_t size)
{
	assert(a);
	int begin = 0;
	int end = size - 1;
	while (begin != end)
	{
		int minindex = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[minindex])
				minindex = i;
		}
		swap(a[begin], a[minindex]);
		begin++;
	}
}

//һ��ѡ����������Ϊ������С
void ChoseSort2(int* a, size_t size)
{
	assert(a);
	assert(size);
	int begin = 0;
	int end = size - 1;
	while (begin != end)
	{
		int minindex = begin;
		int maxindex = end;
		for (size_t i = 0; i <= end; i++)
		{
			if (a[i] < a[minindex])
				minindex = i;
			if (a[i]>a[maxindex])
				maxindex = i;
		}
		swap(a[begin], a[minindex]);
		swap(a[end], a[maxindex]);
		begin++;
		end--;
	}
}


//������*��
void AdjustDown(int* a,size_t _start,size_t _end)    //���µ����㷨
{
	int parent = _start;
	int left = parent * 2 + 1;
	int right = left + 1;
	int child = 0;
	if (right <= _end)
	{
		child = (a[left] > a[right] ? left : right);
	}
	else
		child = left;
	while (child <= _end)          //�����䣬�տ�ʼ�ǿ����䣬����
	{
		if (a[child] > a[parent])
			swap(a[child], a[parent]);
		else
			break;
		parent = child;
	    left = parent * 2;
		right = parent * 2 + 1;
		if (right <= _end)
		{
			child = a[left] > a[right] ? left : right;
		}
		else
			child = left;
	}
}
void HeapSort(int* a,size_t size)
{
	assert(a);
	assert(size);
	int end = size - 1;
	while (end)
	{
		int start = (end - 1) / 2;           //ע������
		while (start >= 0)                   //���ˣ�ѡ�����ֵ  start=0��ʱ��Χû���ǽ�ȥ
		{
			AdjustDown(a, start, end);
			start--;
		}
		swap(a[0], a[end]);
		end--;
	}
}
void test()
{
	int arr[] = { 3, 6, 5, 2, 0, 9, 1, 8 };
    //ChoseSort1(arr, sizeof(arr) / sizeof(arr[0]));
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
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