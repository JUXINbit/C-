//#define _CRT_SECURE_NO_WARNINGS 1
//
//class A
//{
//private:
//	int _a;
//	int _b;
//	int _c;
//public:
//	void SetA();
//	void SetB();
//	void SetC();
//};
//
//void A::SetA()           //��������  ���ⶨ��
//{
//
//}
//void A::SetB()
//{
//
//}
//void A::SetC()
//{
//
//}
//int main()
//{
//	A a;
//	a.SetA();
//	a.SetB();
//	a.SetC();
//	return 0;
//}
#include<iostream>
using namespace std;
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	void SetDate(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//void Display()
//	//{
//	//	cout <<_year << "-" << _month << "-" << _day << endl;
//	//	cout << this->_year << endl;
//	//}
//	void Display()
//	{
//		cout << this << endl;
//	}
//
//};
//int main()
//{
//	Date A;
//	/*A.SetDate(2017, 4, 13);*/
//	cout << &A << endl;
//	A.Display();                                 //�@��thisָ��ʵ�������@����ʵ������һ������ĵ�ַ
//	return 0;
//}

class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year=1999, int month=10, int day=10)                     //���캯��   ��ʼ������
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	void Display()
	{
		;
	}
	~Date()
	{
		cout << "��������" << endl;
	}
};
int main()
{                               //���캯���ڴ���һ�������ʱ���Զ�����һ��
	Date A(2017,4,13);
	Date B;                   //����ȱʡ���캯�������캯�������˳�ʼ����ֵ��
	return 0;
}

  



