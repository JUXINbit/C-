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
//	Date(int year=2017, int month=10, int day=1)
//		:_year(year), _month(month), _day(day)
//	{
//	}
//	Date(Date& d)
//		:_year(d._year), _month(d._month), _day(d._day)
//	{
//	}
//	~Date()
//	{
//	}
//	void Test();
//	void Display(Date &d)  
//	{
//		Test();
//		cout << d._month << endl;
//		/*_year = 2018;*/
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	
//};
//
//inline void Date::Test()                                                      //�����ⶨ��������Ա����
//{
//	cout << _year << endl;
//}
//int main()
//{
//	Date d(2017, 4, 14);
//	Date d2 = d;
//    Date d3;
//	d3.Display(d2);
//	d.Display(d);
//	d2.Display(d);
//	return 0;
//}

//class Complex
//{
//private:
//	int _real;
//	int _image;
//public:
//	Complex(int real=1,int image=0)
//		:_real(real), _image(image)
//	{
//	}
//	Complex(Complex& d)
//		:_real(d._real), _image(d._image)
//	{
//	}
//	Complex operator+(Complex& c)
//	{
//		Complex temp;
//		temp._real = _real + c._real;
//		temp._image = _image + c._image;
//		return temp;                                      //�@��ע��  return �@�����˺ܶ������ �������� Ȼ������Ȼ���ٻ�������֮�@������
//	}                                                       //һ��Ҫ����@��Ĺ���  �����������ǰ����˵��Ϊʲô���ǲ��ܷ���һ����ʱ������������
//	void operator<<(ostream& out)
//	{
//		out << _real << "+" << _image << "j" << endl;
//	}
//	~Complex()
//	{
//	}
//
//	void Display()
//	{
//		cout << _real << "+" << _image << "j"<<endl;
//	}
//};
//int main()
//{
//	Complex c1(1, 1);
//	Complex c2 = c1;
//	Complex c3 = c2 + c1;
//	Complex c4;
//	c1.Display();
//	c2.Display();
//	c3.Display();
//	c3 << cout;                                //�����������ڶ��������������������ص�ʱ�򣬾Ͳ�����һЩ�ܱ�Ť������ ��ν�����⣿
//	return 0;
//}



//������дһ���������������������������Ľ�������������غ�������Ϊ��Ԫ��
//class Date
//{
//	friend void Display(Date& d);    //��Ԫ
//	friend ostream& operator<<(ostream& out, Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year=2000,int month=10,int day=1)
//		:_year(year), _month(month), _day(day)
//	{	
//	}
//	Date(Date& d)
//		:_year(d._year), _month(d._month), _day(d._day)
//	{
//	}
//	~Date()
//	{
//	}
//};
//void Display(Date& d)
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//}
//
//istream&  operator>>(istream& in, Date& d)
//{
//	in >> d._year;
//	in >> d._month;
//	in >> d._day;
//	return in;
//}
//
//
//ostream& operator<<(ostream& out, Date& d)                //Ϊʲô����Ҫ����Ϊ��Ԫ�أ���Ŀ������ ������Ҫ����������������ʽ��
//                                                            //��Ȼ��coutҪȥ����<<���������غ�������d2������������غ����еĲ�������������������
//{                                                             //�ĳ�Ա������Ȼ�Ƕ���ȥ���� ����d2��ǰ ֻ��������ȥ
//	out << d._year << "-" << d._month << "-" << d._day << endl;       //��ô�������ǲ��ǿ����Լ�дһ�� ����������д�� ��˳���������  
//	return out;
//}  
//                                                                //��������������һ�����⣺������������ⶨ��һ����������ô���ܷ��ʵ�
//int main()                                                 //���ڵĳ�Ա�أ�   �@�����Ҫ����������Ϊ��Ԫ  
//{
//	Date d1;                                               //����ĺ�������������Ϊ��Ԫ  �Ϳɷ������е����г�Ա ����˽
//	Date d2 = d1;
//	Display(d2);
//	cout << d2 << d1 << endl;
//	Date d3;
//	Date d4;
//		cin >> d3 >> d4;
//		cout << d3 << d4;                             //���������������ص�ע��:��д������ʱ����ostream& ��Ϊ����ֵ 
//	return 0;                                        //�@������ʵ���������������
//}


//��Ԫ��
//��һ�����п��Է�����һ�����е����г�Ա
//class Time
//{
//	friend class Date;
//private:
//	int _hour;
//	int _minute;
//	int _second;
//public:
//	Time(int hour=12, int minute=0, int second=0)
//		:_hour(hour), _minute(minute), _second(second)
//	{
//	}
//	Time(Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//	}
//	~Time()
//	{
//	}
//
//};
//class Date
//{
//private:
//	Time _t;
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	Date(Time t, int year = 2010, int month = 10, int day = 1)
//		:_t(t),_year(year), _month(month), _day(day)
//	{
//	}
//	Date(Date& d)
//	{ 
//		_t = d._t;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << "-" << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
//	}
//
//};
//int main()
//{
//	Time t1(23, 59, 59);
//	Date d1(t1,2017,10,01);
//	d1.Display();
//	Date d2 = d1;
//	d2.Display();
//	return 0;
//}





//��ľ�̬��Ա���� �;�̬��Ա����
//class A
//{
//private:
//	 static int _count;          // ����Ա����Ϊһ����̬����ʱ   ��ʼ���Ͳ����ڳ�ʼ���б��г�ʼ�� Ҳ�����ڹ��캯���ڲ� �����ǲ�����������
//	 int num;
//public:
//	A()
//	{   
//		num = 10;
//		_count++;
//	}
//	~A()
//	{
//	}
//	void Display()
//	{
//		cout << _count << endl;
//	}
//	 void SDisplay()
//	{   
//		/*cout << num << endl;*/
//		 cout << _count << endl;
//		cout << "��̬��Ա����" << endl;               //��̬��Ա�������������ڽ��ж��壬 ������ע�����ڵ���ʱ���﷨
//	}
//};
//   int A::_count = 0;       //��Ա������һ����̬������ʱ�� ������������г�ʼ������ʼ����ʽ��
//int main()
//{
//	A a1;
//	A a2;
//	/*a1.SDisplay();*/    //�@�ַ��ʷ�ʽ�ǲ��Ե�  ��̬��Ա�����ǹ��е� ���ܱ�ĳ������������ Ҫ����ֻ����������
//	a1.SDisplay();      //��̬��Ա��������Ҫ���@���ĵ��÷�ʽ��
//	a1.Display();
//	a2.Display();      //����ṹ��2 2  ˼��Ϊʲô  ����̬��Ա�����������ݶ�  ��������ĳ������ 
//	return 0;           //��̬��Ա��ÿһ����Ķ��������е�  �����ĸ�����ȥ�ı��� �����Ǹı���ֵ ������Ϊ����һ��������ó�ֵ
//}

//ע�⣺��̬��Ա����û��������thisָ��
//  ��̬��Ա�����ǲ����Է��ʷǾ�̬��Ա��
// �Ǿ�̬��Ա�����ǿ��Է��ʾ�̬��Ա��






//ǰ��++   ����++������
//class Complex
//{
//private:
//	int _real;
//	int _image;
//public:
//	Complex(int real=1,int image=0)
//		:_real(real), _image(image)
//	{
//	}
//	Complex(Complex& c)
//		:_real(c._real), _image(c._image)
//	{
//	}
//	Complex operator++(int)   //����++    �����intֻ��Ϊ�˽�ǰ�úͺ�������
//	{
//		Complex tmp(*this);     //�@������˿�������
//		_real++;
//		_image++;
//		return tmp;
//	
//	}
//	Complex& operator++()  //ǰ��++
//	{
//		_real++;
//		_image++;
//		return *this;
//	}
//	void Display()
//	{
//		cout << _real << "+" << _image << "j" << endl;
//	}
//	~Complex()
//	{
//	}
//
//
//};
//int main()
//{
//	Complex c1;
//	c1.Display();
//	c1++;
//	Complex c2;
//	++c2;
//	c2.Display();
//	return 0;
//}



