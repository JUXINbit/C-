#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//��������е�1�ĸ���
//����һ�� ��ģ��
int main()
{
	int num = 0;
	cout << "���������֣�" << endl;
	cin >> num;
	int count = 0;
	while (num)
	{
		if (num % 2 == 1)       //Ϊɶ????  �����
			count++;
		//num = num / 2;
		num = num >> 1;
	}
	cout << count << endl;
	return 0;
}
//�@���ķ��������⣬��num�Ǹ�����ʱ�򣬾ͻ�������⡣

//��������  ��λ    ��λ���㲻�����������Ǹ����������鷳
//int main()
//{
//	int num = 0;
//	cout << "���������֣�" << endl;
//	cin >> num;
//	int i = 0;
//	int count = 0;
//    for (; i < 32; i++)
//	{
//	     if ((num >> i) & 1 == 1)
//		    count++;
//	}
//	cout << count << endl;
//	return 0;
//}


//�������� ��λ����   ��������ʱ�临�Ӷȵ�

//int main()
//{
//	int num = 0;
//	cout << "���������֣�" << endl;
//	cin >> num;
//	int count = 0;
//	while (num)
//	{
//		num = num&(num - 1);
//		count++;
//	}
//	cout << count << endl;
//	return 0;
//}


