#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

//��ӡ
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
//ѡ������ÿ��ѡ���������֣�������С��        //����С������0���±꣬����������������ʱ��ͬʱѡ���������ͻ��������
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

void Adjustdown(int root,size_t n,int a[])     //root��ǰ�±�
{
	int parent = root;
	int child = parent * 2 + 1;            //����
	while (child < n)
	{
		if (child != n - 1 && a[child] < a[child + 1])       //ѡ�����Ǹ�����      �@��������жϺ����׳���
		{
			child++;   
		}
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;              //ע���@������Ҳ�д�@��break  ������ѭ����
	}
}
void HeapSort(int arr[],size_t n)
{
	assert(arr);
	//�Ƚ����
	for (int i = (n - 2) / 2; i >= 0; i--)      //ע���@����(n-2)/2   ����(n-1)/2 �տ�ʼд����
	{
		Adjustdown(i, n, arr);
	}
	//���öѶ�������������
	for (size_t i = 1; i < n; i++)
	{
		swap(arr[0], arr[n - i]);
		Adjustdown(0, n - i, arr);
	}
}

//��������ð������  ʱ�临�Ӷ���o��N^2��
void BubbleSort(int* a,size_t n)
{
	for (int end = n - 1; end>0; end--)
	{
		bool exchange = false;
		size_t first = 0;
		size_t second = first + 1;
		while (second != (end + 1))
		{
			if (a[first] > a[second])
			{
				swap(a[first],a[second]);
				exchange = true;
			}
			++first;
			++second;
			if (exchange == false)
			{
				cout << "û�з�������" << endl;
			}
		}
	}
}

//�������򡪿������򣨿��ţ����ݹ飩   
//����ָ�뷨
int PartSort(int* a, int begin, int end)
{
	int key = end;
	while (begin != end)
	{
		while (begin < end && a[begin] <= a[key])     //�@�������֮һ�������������ȵ������������д����ô�ͻ������ѭ��
		{
			begin++;
		}
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		if (begin < end)
		swap(a[begin], a[end]);
	}
	swap(a[begin], a[key]);
	return begin ;
}
//�ڿӷ�    (д����)
int WKPartSort(int* a, int begin, int end)
{
	int key = a[end];
	while (begin != end)
	{
		while (begin < end && a[begin] <= a[end])
		{
			begin++;
		}
		a[end] = a[begin];
		while (begin<end && a[end] > key)
		{
			end--;
		}
		a[end] = a[begin];   
	}
	a[begin] = key;      //begin��end���ĵط�������һ���ӣ�Ȼ���keyֵ����ȥ����
	return begin;
}

//ǰ��ָ�뷨   

void QuickSort(int* a, int begin, int end)
{
	assert(a);
	if (begin < end)
	{
		//int prev = PartSort(a, begin, end);
		int prev = WKPartSort(a, begin, end);
		QuickSort(a, begin, prev-1);
		QuickSort(a, prev + 1, end);
	}
	else
      return;
}

int main()
{
	//int arr[] = { 2, 5, 4, 9, 3, 6, 1, 8, 7, 0 };
	int arr[] = { 1, 9, 6, 4, 0, 5, 7, 8, 2, 3 };
	//int arr[] = { 0, 3, 6, 4, 1, 5, 7, 8, 2, 9 };
	//string arr[] = { "hahah", "hehe", "huhuhu", "jajxi", "hsu" };
	//int arr[] = { 3, 1, 4, 2 };                                      //������кܶ�ѭ���Ŀ�����Сһ����������
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSortD(arr, sizeof(arr) / sizeof(arr[0]));
	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}

