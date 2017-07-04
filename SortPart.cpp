#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;


void PrintArr(int* a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


//ֱ�Ӳ�������
void InsertSort(int a[], size_t n)
{
	for (size_t index = 0; index < n; index++)
	{
		int tmp = a[index];
		int end = index - 1;
		while (end != -1)
		{
			if (a[end]>tmp)              //�@���>��<���Կ����������ǽ���
			{
				a[end + 1] = a[end];       //����
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}


//ѡ������ÿ��ѡһ�����֣�����ѡ������
void SelectSort(int a[], size_t n)
{
	size_t end = 0;
	for (; end < n - 1; end++)
	{
		size_t i = end + 1;
		int min = a[i];
		int minindex = i;
		for (; i < n; i++)
		{
			if (a[i] < min)
			{
				min = a[i];
				minindex = i;
			}
		}
		swap(a[end], a[minindex]);
	}
}
//ѡ������ÿ��ѡ���������֣�������С��
void SelectSortD(int a[], size_t n)
{
	int i = 0;
	int j = 0;
	for (; i < n - j; i++, j++)
	{
		int begin = i;
		int end = n - j - 1;
		int min = begin;
		int max = end;
		while (begin != end + 1)        //�տ�ʼ����+1
		{
			if (a[begin] < a[min])
			{
				min = begin;
			}
			begin++;
		}
		begin = i;
		while (end != begin + 1)        
		{
			if (a[end]>a[max])
			{
				max = end;
			}
			end--;
		}
		end = n - j - 1;
		swap(a[begin], a[min]);
		swap(a[end], a[max]);
	}
}
//ѡ�����򡪶���



int main()
{
	//int arr[] = { 2, 5, 4, 9, 3, 6, 1, 8, 7, 0 };
	//int arr[] = { 1, 9, 6, 4, 0, 5, 7, 8, 2, 3 };
	int arr[] = { 0, 3, 6, 4, 1, 5, 7, 8, 2, 9 };
	//string arr[] = { "hahah", "hehe", "huhuhu", "jajxi", "hsu" };
	//int arr[] = { 3, 1, 4, 2 };                                      //������кܶ�ѭ���Ŀ�����Сһ����������
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	SelectSortD(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}

