#define _CRT_SECURE_NO_WARNINGS 1

//���⣺һ�ο���1��̨�ף�һ�ο���2��̨��  ����n��̨�ף����ж��������ķ���
#include<iostream>
using namespace std;

//����һ��  �ݹ顢����ʱ�临�Ӷȹ���Ч�ʵ�
int jumpFloor(int number)
{
	if (number == 0)
		return 1;
	if (number == -1)
		return 0;
	return jumpFloor(number - 1) + jumpFloor(number - 2);
}
void test(void)
{
	cout<<jumpFloor(20)<<endl;
}
int main()
{
	test();
	return 0;
}