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
		num = num / 2;
	}
	cout << count << endl;
	return 0;
}

//�������� ��λ
