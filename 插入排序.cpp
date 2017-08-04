#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;


//��������   ���ܹ�һ����ȷ��ĳ������λ��
//ֱ�Ӳ���&ϣ������


void InsertSort(int* a, size_t size)
{
	assert(a);
	int NowIndex = 1;
	while (NowIndex != size)
	{
		int cur = NowIndex - 1;
		int tmp = a[NowIndex];
		while (cur >= 0 && a[cur] > tmp)
		{
			a[cur + 1] = a[cur];
			cur--;
			if (cur < 0)
			{
				a[0] = tmp;
				break;
			}
			if (a[cur] <= tmp)
			{
				a[cur + 1] = tmp;
				break;
			}
		}
		NowIndex++;
	}
}


//ϣ������  Ԥ������+ֱ�Ӳ�������

void test(void)
{
	int arr[] = { 5, 6, 1, 0, 9, 3, 4, 2, 8, 7 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
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