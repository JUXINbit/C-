#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void teststring()
{                             //���ǿ��԰��ַ�����ָ����������������ֵ�ʱ��Ϳ������@���ַ���
	char* p = "hahahaha";
	cout << *p << endl;     //�@��ʱ��p����ָ�����ַ���ַ��ָ��
	cout << p << endl;             
	string a = "hhhhhhhh";
	cout << a << endl;
	string b = p;
	cout << b << endl;
	string c = "ooooooo";
	cout << c << endl;
	c = p;
	cout << c << endl;
	cout << p + 1 << endl;    //�@��ʱ��p�Ͳ������@���ַ���
}
int main()
{
	teststring();
	return 0;
}