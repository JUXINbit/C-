#define _CRT_SECURE_NO_WARNINGS 1

//���⣺һ�ο���1��̨�ף�һ�ο���2��̨��  ����n��̨�ף����ж��������ķ���
#include<iostream>
using namespace std;

//����һ��  �ݹ顢����ʱ�临�Ӷȹ���Ч�ʵ�
//int jumpFloor(int number)
//{
//	if (number == 0)
//		return 1;
//	if (number == -1)
//		return 0;
//	return jumpFloor(number - 1) + jumpFloor(number - 2);
//}
//

//��������

int jumpFloor(int number)
{
	//������ʵ��һ��쳲��������У����ǵݹ飩
	//n��3��ʼ
	if (number == 0)
		return 0;
	if (number == 1)
		return 1;
	if (number == 2)
		return 2;
	if (number >= 3)
	{
		int t = 0;
		int arr[3] = { 1, 2, t };
		for (int i = 2; i<number; i++)
		{
			arr[2] = arr[0] + arr[1];
			arr[0] = arr[1];
			arr[1] = arr[2];
		}
		return arr[2];
	}
}

//void test(void)
//{
//	cout<<jumpFloor(20)<<endl;
//}
int main()
{
	cout<<jumpFloor(4)<<endl;
	//test();
	return 0;
}