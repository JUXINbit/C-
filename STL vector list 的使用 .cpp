#define _CRT_SECURE_NO_WARNINGS 1

//STL��ʹ���Ƿǳ���Ҫ�� ��ѧϰSTL�ĵ�һ�׶ξ���һ��Ҫ����ʹ��STL
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
//1. vector�Ļ���ʹ��

template<class T>
void Print(vector<T>& v)
{
	vector<T>::iterator itv = v.begin();
	while (itv != v.end())
	{
		cout << *itv << " ";
		itv++;
	}
	cout << endl;

}
int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	vector<int>::iterator itv = v1.begin();
	while (itv!=v1.end())
	{
		cout << *itv << " ";
		itv++;
	}
	cout << endl;
	Print(v1);
	cout << v1.capacity() << endl;
	//v1.reserve(10);                       //ע��reserve��ʹ��
	//cout << v1.capacity() << endl;
	v1.resize(12);
	Print(v1);
	cout << v1.capacity() << endl;
	v1.resize(5);
	Print(v1);
	cout << v1.capacity() << endl;
	v1.resize(5, 4);                //[*] �����ֵû�з�Ӧ,��˼������ֻ��������Ԫ�ص�Ԫ�����������û�и�ֵ��resize�ĵڶ���������������
	Print(v1);
	v1.resize(12, 6);
	Print(v1);
	v1.reserve(2);      //����������֮���û����С�˽���������ǲ������õġ�
}



//2.std::list
//������vector
//int main()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(1);
//	l1.push_back(1);
//	PrintMyVector(l1);
//	return 0;
//}