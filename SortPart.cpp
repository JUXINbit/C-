#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
#include<stack>
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

//��ȡKeyֵ 
//����ȡ�з�
int GetMid(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;         //��������
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])         //begin mid end
			return mid;
		else                       //begin end mid
		{
			if (a[begin] < a[end])
				return end;
			else
				return begin;
		}
	}
	else   //mid  begin                          
	{
		if (a[mid] > a[end])          //end  mid begin
			return mid;
		else                        
		{
			if (a[begin] < a[end])
				return begin;
			else
				return end;
		}
	}
}
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
//�ڿӷ�  
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
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[begin] = a[end];   
	}
	a[begin] = key;      //begin��end���ĵط�������һ���ӣ�Ȼ���keyֵ����ȥ����
	return begin;
}

//ǰ��ָ�뷨 ���������Ҳ���׳���  
int FSPtrPartSort(int* a, int begin ,int end)
{
	int cur = begin;
	int prev = begin-1;
	while (cur < end)
	{
		if (a[cur] < a[end] && ++prev != cur)
		{
			swap(a[prev], a[cur]);
		}
			++cur;
	}
	swap(a[++prev], a[end]);
	return prev;
}
//�ݹ�
void QuickSort(int* a, int begin, int end)
{
	assert(a);
	int mid = GetMid(a, begin, end);
	swap(a[mid], a[end]);
	if (begin < end)
	{
		//int prev = PartSort(a, begin, end);
		//int prev = WKPartSort(a, begin, end);
		int prev = FSPtrPartSort(a, begin, end);    //ǰ��ָ�뷨
		QuickSort(a, begin, prev-1);
		QuickSort(a, prev + 1, end);
	}
}

//�ǵݹ����      ����[*]
void QuickSortNR(int* a, int begin, int end)
{
	/*int mid = GetMid(a, begin, end);
	swap(a[mid], a[end]);*/
	int Mid = FSPtrPartSort(a, begin, end);    
	stack<int> _s;
	_s.push(begin);
	_s.push(end);
	while (!_s.empty())
	{
			int End = _s.top();
			int tmp = PartSort(a, begin, End) - 1;
			_s.pop();
			_s.push(tmp);
			if (tmp <= begin)
			{
				break;
			}
	}
	stack<int> _s1;
	_s1.push(end);
	_s1.push(Mid);
	while (!_s1.empty())
	{
		int Begin = _s1.top();
		int tmp = PartSort(a, Begin, end) + 1;
		_s1.pop();
		_s1.push(tmp);
		if (tmp > end)
		{
			break;
		}
	}
}


//�鲢����   ʱ�临�Ӷȣ�o(N*lgN)
//�����鲢����ʵ��
void _MergeAct(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int start = begin1;
	int finish = end2;
	//����ΪҪ�������Ҫ�鲢�Ĵ����䣬�������һ������
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)     //Ϊʲô��Ҫ����
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//������˭�Ƚ���������û�н�����ֱ�ӳ����±���
	while (begin1 <= end1)               //�@���Ҹտ�ʼû��д=�ţ��������ˡ���Ϊ���һλҲ��Ҫ����ȥ��
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//һ��Ҫ��ס���鲢ok�����ݴ�tmp���濽��ȥ��ע�⿽�ص�����ȥ
	memcpy(a + start, tmp + start, (finish - start + 1)*sizeof(int));
}

//�ݹ�
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	int mid = begin + (end - begin) / 2;  //���м�λ��
	if (begin >= end)
		return;
	_MergeSort(a, tmp, begin, mid);     //ǰ�벿�ֵݹ�
	_MergeSort(a, tmp, mid + 1, end);   //��벿�ֵݹ�
    //�鲢����
	_MergeAct(a, tmp, begin, mid, mid + 1, end);
}
//�ȿ����ռ�
void MergeSort(int* a,int n)
{
	assert(a);
	int* tmp = new int[n];
	//�ݹ�
	_MergeSort(a, tmp, 0, n - 1);
	delete[] tmp;
}


int main()
{
	//int arr[] = { 2, 0, 4, 9, 3, 6, 1, 8, 7, 5 };
	int arr[] = { 1, 9, 6, 4, 0, 5, 7, 8, 2, 3 };
	//int arr[] = { 0, 3, 6, 4, 1, 5, 7, 8, 2, 9 };
	//int arr[] = { 0, 1, 1, 2, 4, 2, 5, 7, 9, 8, 6, 3 };
	//int arr[] = { 3, 1, 4, 2 }; 
	//int arr[] = { 0, 1 };
	//int arr[] = { 1, 0 };
	//int arr[] = { 1 };
	//string arr[] = { "hahah", "hehe", "huhuhu", "jajxi", "hsu" };

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSortD(arr, sizeof(arr) / sizeof(arr[0]));
	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSortNR(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	//GetMid(arr, 7, 9);
	return 0;
}

