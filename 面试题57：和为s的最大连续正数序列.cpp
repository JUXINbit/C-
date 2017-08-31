#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

//��Ŀ2�� ����һ��������������15 Ȼ�������������������������  
void PrintArray(int begin, int end)
{
	if (begin >= end)
		return;
	for (size_t i = begin; i <= end; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
void GetVectorSumN(size_t N, int& small, int& big)
{
	assert(N);
	small = 1;
	big = 2;
	int middle = (N + 1) / 2;      //ע��Ϊʲô������ֹ����
	int sum = small + big;
	while (small < middle)
	{
		if (N < 3)
			return;
		if (sum == N)
		{
			PrintArray(small, big);
			big++;
			sum += big;
			continue;
		}
		else if (sum < N)            //���С������������
		{
			big++;
			sum += big;
			continue;
		}
		else                        //������ˣ�ע����ô��
		{
			sum -= small;
			small++;
			continue;
		}
	}
}

void test()
{
	int small = 0;
	int big = 1;
	GetVectorSumN(15, small, big);
}
int main()
{
	test();
	return 0;
}