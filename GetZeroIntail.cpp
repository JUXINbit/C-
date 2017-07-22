#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
//��Ŀ������  ����N�Ľ׳˽���ж��ٸ�0��  
//���磺  N=10��N��=3628800��N��ĩβ������0

//����һ�� ������⣺ ����׳˽����Ȼ��һ·��ģ  ʱ�临�Ӷ�o��N��  �ռ临�Ӷ�o��1��
int CountNZero(long long num)
{
	assert(num > 0);
	//step1: get the N!
	long long sum = 1;
	size_t ZeroCount = 0;
	while (num && (num - 1))
	{
		sum *= num*(num - 1);
		num -= 2;
	}
	//step2: get the '0'number  in tail of sum
	while (sum)
	{
		if (sum % 10 == 0)
			ZeroCount++;
		sum /= 10;
	}
	return ZeroCount;
}

//--------------------test.c-------------------------------
void test()
{
	cout << CountNZero(10) << endl;
	cout << CountNZero(20) << endl;
	cout << CountNZero(1) << endl;
	cout << CountNZero(8) << endl;
	cout << CountNZero(0) << endl;
	cout << CountNZero(-10) << endl;
}
int main()
{
	test();
	return 0;
}