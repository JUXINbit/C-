#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year, int month, int day)
//	{
//		cout << "���캯��" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(Date &d)
//	{
//		cout << "�������캯��" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	~Date()
//	{
//		cout << "��������" << endl;
//	}
//};
//
//
//int main()
//{
//	Date d(2017, 4, 13);
//	Date d2(d);
//	d.Display();
//	return 0;
//}


//������
class Complex
{
private:
	int _real;
	int _image;
public:
	Complex(int real=1,int image=0)
	{
		_real = real;
		_image = image;
	}
	Complex(Complex &d)
	{
		_real = d._real;
		_image = d._image;
	}
	Complex operator+(Complex &a)            //���@��  operator+��ǧ�򲻰�����������ֵ��  ֮ǰҲ���ᵽ�ֲ��������ܷ�������  
	{
		Complex tmp;
		tmp._real = _real + a._real;
		tmp._image = _image + a._image;
		return tmp;
	}
	Complex& operator=(Complex &a)            //��ֵ�����������
	{
		_real = a._real;                       //���������������  ����Ϊʲô������ ˵����һ ������ԭ��֮һ ����Ч��Ҳ��ԭ��֮һ
		_image = a._image;
		return *this;                          //���⣺Ϊʲô���@��Ҫ����һ��*this  �������Ĵ𰸴����˵Ϊ������ 
	}
	Complex& operator+=(Complex &a)
	{
		_real = _real + a._real;
		_image = _image + a._image;
		return *this;
	}
	~Complex()
	{
	}
	void Display()
	{
		cout << _real << "+" << _image << "j" << endl;
	}

};
int main()
{
	Complex a(1, 1);
	Complex a1 = a;
	Complex a3 = a + a1;
	Complex a4;
	a4 = a3;
	a4 += a3;
	a4.Display();
	a3.Display();
	a1.Display();
	a.Display();
	return 0;
}

