#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ʹ���������жϴ�С�˴洢    �п�
void test1()
{
	const int num = 10;
	char* p = (char*)&num;
	if (*p == 0)
		cout << "���" << endl;
	else
		cout << "С��" << endl;
}

void test2()
{
	union Utest
	{
		int i;
		char a;
	}ut;
	ut.i = 1;          //ע����ʹ�������жϵ�ʱ��������char��ֵ���ж�int ��Ϊchar��ֵȷ���˵��ǿռ���ʣ����ֽڿռ������ֵ���@��intҲ�����ֵ�޷��ж�
	if (ut.a==1)
		cout << "С��" << endl;
	else
		cout << "���" << endl;
}
//�����@��������٣�������  ʹ���������жϴ�С�˴洢�ȳ�ʼ��int����ģ�  �ڿ�char��С�ģ�  �����֮��Ϊ���ֵ
void test3()
{
	union                 //union�������û������������
	{
		int i;
		char a[2];
	}*p,u;
	
	p = &u;
	p->a[0] = 0x39;
	p->a[1] = 0x38;
	cout << p->i << endl;
}

//С�˻��£����������Ƕ��٣�
void test4()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
}
int main()
{
	test4();
	return 0;
}