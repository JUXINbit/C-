#include<iostream>
using namespace std;
class Date 
{  
	friend ostream&  operator<<(ostream& os, const Date& d);
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year=2017,int month=3,int day=14)
		:_year(year), _month(month), _day(day)
	{
	}
	
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
};
 ostream&  operator<<(ostream& os,const Date& d)//cout��ostream�����һ�����󣬶�ostream��һ���࣬����ࣻ  os��һ����ʱ����//Ϊʲô���@����ʽ�Ҳ��ܺ����׵�ȥ���
{                                               //��ʹ��void��Ϊ���ܹ��������������
	os << d._year << "-" << d._month << "-" << d._day<< endl;
	return os;//���뷵��һ��ֵ�������Ҳ�̫����@�����ԭ��֮ǰ����+-��ʱ����return *this;������Ϊʲô��
}
int main()
{
	Date d1;
	cout << d1;
	system("pause");
	return 0;
}