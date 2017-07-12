#define _CRT_SECURE_NO_WARNINGS 1


//쳲��������Ĵ��Ż�����
#include<iostream>
#include<assert.h>
using namespace std;

//******************�ݹ�*********************
//쳲��������еĽⷨ�����еݹ��ʱ�临�ӶȺͿռ临�Ӷȡ�
//��һ��������
int Fibonacci1(int n)
{
	//assert(n);
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

//ǰ��һ�ֽⷨ���Ż� ,��ʵ����Ҳ����Ҫ�@��д����Ϊ֮ǰ��int�϶��Ǵ�������ġ�
long long Fibonacci2(long long n)
{
	//assert(n);
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci2(n - 1) + Fibonacci2(n - 2);
}
//�ݹ��ʱ�临�Ӷ���O��n^2��   �ռ临�Ӷ���O��N��




//  **************�ǵݹ�*****************
//ʹ�������ѭ���������зŽ�ȥ  
//ʱ�临�Ӷ���o��N��   �ռ临�Ӷȣ�o��N��  �����ٵĿռ��С��N�������Կռ临�Ӷ���o��N��
long long FibonacciR1(long long n)
{
	long long* Fibarr = new long long[n + 1];
	Fibarr[0] = 0;
	Fibarr[1] = 1;
	for (long long i = 2; i <= n; i++)
	{
		Fibarr[i] = Fibarr[i - 1] + Fibarr[i - 2];
	}
	return Fibarr[n];
}
//�ٴ��Ż�
//ʱ�临�Ӷ���o��N��  �ռ临�Ӷ���o��1�� ���ٵĿռ��ǳ�����
long long FibonacciR2(long long n)
{
	long long Fibarr[3] = { 0, 1, n };
	for (long long i = 2; i <= n; i++)
	{
		Fibarr[2] = Fibarr[0] + Fibarr[1];
		Fibarr[0] = Fibarr[1];
		Fibarr[1] = Fibarr[2];
	}
	return Fibarr[2];
}


void test()
{
	/*int num = Fibonacci1(1);
	printf("%d\n", num);*/

	/*long long num = Fibonacci2(4);
	printf("%d\n", num);*/
	
	/*long long num = FibonacciR1(100);
	printf("%d\n", num);*/
	
	long long num = FibonacciR2(3);
	printf("%d\n", num);

}
int main()
{
	test();
	return 0;
}