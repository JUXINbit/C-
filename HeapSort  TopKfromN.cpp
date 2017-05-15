#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;

//�ѵ����ã�ʵ���϶���һ���㷨һ��˼�룬������ģ��ѵ�ʱ����������һ�������ˣ�ʵ����ֻ��������ѣ�ֻ����vector����֮�ϼ��������ϵ����㷨�����µ����㷨���@���Ļ����ǿ���
//�����@����������������һЩ���������


//1.   N����������ǰK��������  �����N�ǳ��󣬶�����һ��ʱ�临�Ӷ�̫�󣬶��Һܿ����ڴ�Ų��£��@�����Ҫʹ�õ��ѣ�
//     ʹ��С��


//void AdjustDown(int root, size_t n, int a[])          //���µ���ΪС��      //���⣺�Ҹտ�ʼ��ʱ���ǰ��@����������TopFromK()�����  ���Ǿͻ�������� Ϊʲô��
//{                                                  //�Ҿ����ҷ���һ���ͼ�����һ���������ڲ���ô����������һ��������ֻ�ܸ�����������
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child<n)
//	{
//		if (child != n - 1 && a[child + 1] <a[child])
//		{
//			child++;
//		}
//
//		if (a[child]<a[parent])
//		{
//			swap(a[parent], a[child]);
//			parent = child;
//			child = child * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void TopKformN()
//{
//	const size_t N = 100000;
//	const size_t K = 10;
//	int a[N] = { 0 };
//	for (size_t i = 0; i < N; i++)
//	{
//		a[i] = rand() % N;
//	}
//	int heap[K] = { 0 };
//	for (size_t i = 0; i < K; i++)
//	{
//		heap[i] = a[i];
//	}
//
//	for (int i = (K - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(heap[(K - 2) / 2], K, heap);
//	}
//
//
//	for (size_t i = K + 1; i < N; i++)                       //�@��һ��һ��ȥ��
//	{                                                     //���������������ȸ�����ģ��ͺ͸�����滻���滻������Ӹ�������µ���
//		if (a[i]>heap[0])
//		{
//			heap[0] = a[i];
//			AdjustDown(heap[0], K, heap);
//		}
//	}
//	for (int i = 0; i < K; i++)
//	{
//		cout << heap[i] << " ";
//	}
//
//
//}
//int main()
//{
//	TopKformN();
//	return 0;
//}




//2.  ���ʵ������    ��С��ʵ������ʱ�临�Ӷȴ�Ч�ʵͣ�
//3.  С��ʵ�ֽ���    
//����Ϊ�������� ��  ��������ֻҪ�����µ��������������ľ���

void AdjustDown(int root, size_t n, int* a)                       //ע���@���root���±�             
{                                                 
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child != n - 1 && a[child + 1] >a[child])
		{
			child++;
		}

		if (a[child]>a[parent])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


//������
void HeapSort(int* a,size_t n)                 
{
    //����
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(i, n, a);
	}
	//����   ���Ѷ����ݣ����ֵ�������������n��1�����µ��� ѭ������
	for (int i = 1; i < n;i++)
	{
	    swap(a[n - i], a[0]);
		AdjustDown(0, n - i , a);
	}
	
}

void test()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	HeapSort(a,sizeof(a)/sizeof(a[0]));
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " ";
	}
}
int main()
{
	test();
	return 0;
}