#include<iostream>
using namespace std;
inline int Max(int x, int y)//������������ʵ��C����ĺ궨���� #define ������C++���治�ú궨��
{
	return x > y ? x : y;
}
int main()
{
	int max = Max(2, 3);//�@����ʵ�൱��int max=2>3?2:3;  ֱ�Ӱѱ�Ӧ�õ��õĺ�����������ֲ���@������
	cout << max << endl;
	return 0;
}