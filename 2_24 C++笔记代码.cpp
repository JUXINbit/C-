#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//extern "C" int add(int x, int y);
//int main()
//{
//
//	add(1, 2);
//	cout << add(1,2) << endl;             //��c++������Ҫ�õ��ⲿ������ʱ����Ҫextern����  ���ǵ��ⲿ��һ��C�����ʱ�� ����Ҫextern��C����
//	return 0;
//}


//2.ȱʡ���� Ĭ�ϲ���:

//int Add(int i = 0, int j = 1)
//{
//	return i + j;
//}
//
//int main()
//{
//	int ret = Add(1, 3);
//	cout << ret << endl;
//	return 0;
//}


//3.����  �����þ��г��ԣ���һ����������ֱ�ӳ�����
int main()
{
	const int &num = 10;
	cout << num << endl;
}//C++�е���ʱ���������г�����


////���ý���˺ܶ�c��ָ���ȱ��֮��    ����c�еĺ�������ʹ��ָ����C++�п��Բ������õķ�ʽ��ø��Ӽ��
//void print(const int& num2)
//{
//	cout << num2 << endl;
//	num2 = 20;
//}
//
//void print(const int *pnum)
//{
//	cout << *pnum << endl;
//	*pnum = 20;
//}
//int main()
//{
//
//
//}   //���ߵĹ�����һ����


//���ڳ�����   ��������˵����ʱ���������м��������Ҫʹ�ó�����ȥ����  

int main()
{
	float d = 1.1f;
	const int &num = d;
	printf("%p\n", &num);
	printf("%p\n", &d); // ���﷢�����ߵĵ�ַ�ǲ�һ����num�@�����õĶ�����һ����ʱ���� ����Ϊ�м���������ת��������Ҫ�����ñ����@�����ݱ��ı�
	return 0;
}

//ע�⣺��C�еĺ�������ջ�ռ�ĵ�ַ���ƣ�������Ϊ����ֵ��ʱ��  ǧ��Ҫ���ؾֲ����������� �ֲ�������ջ�ռ����ٵ�ͬʱҲ��֮��ʧ