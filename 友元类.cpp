#include<iostream>
using namespace std;

class Time
{
	friend class Date;//��ס���ùؼ���class��
private:
	int _hour;
	int _minute;
	int _second;
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
	}

};

class Date
{ private:
	int _year;
	int _month;
	int _day;
	Time _t;//���@������һ��Time���͵Ķ���_t��
public:
	Date(int year=2017,int month=3, int day=16)
		:_year(year)
		, _month(month)
		, _day(day)
		, _t(1,1,1)//�Ҳ�֪��ΪʲôҪ���@�︳ֵ��Ϊʲô���������ط���_t��ֵ��
	{
	  
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		cout << _t._hour << "-" << _t._minute << "-" << _t._second << endl;//����Ϊ��Ԫ֮������ܵ�����ȥ����Time��
    }
}; 
int main()
{
	Date d1;//�@���ڳ�ʼ�������ʱ�򲻽�����Date����Time;
	d1.Display();
	return 0;
}