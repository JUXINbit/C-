#include<iostream>
using namespace std;

class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1900, int month = 1, int day = 1)//���캯��
	{
		cout << "Date" << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	
	Date(Date& d)//�������캯��
	{
		_year = d._year;//�@�鲻̫��
		_month = d._month;
		_day = d._day;

	}
	~Date()
	{

	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
};
int main()
{
	Date d1(2017, 3, 12);
	Date d2 = d1;
	d1.Display();
	d2.Display();
		return 0;
}