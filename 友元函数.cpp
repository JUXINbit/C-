#include<iostream>
using namespace std;
class Date
{
	friend void Display(const Date& d);//��friend �ټ������ⶨ���һ����ӡ������ô�ͳ���һ����Ԫ����
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year=2017,int month=3,int day=14)//���캯��
		: _year(year)
		, _month(month)
		, _day(day)//��ʼ���б�
	{
		}

};
void Display(const Date& d)//���@���һ��ǲ�̫���ף�const Date& d�������� ����Ϊʲôdiaplay��ӡ���������ⶨ��͵��@��д��
{
	cout << d._year << "-" << d._month << "-" << d._day << endl;//ע��d.
}
int main()
{
	Date d1;
	Display(d1);//���ȿ���ȷ������Display���ǳ�Ա��������ô����ʹ��d1.Display()����������ĳ�Ա������ֻ�ܰ�d1��ֵ�Ž�ȥӲ�����ĵ��ã�
	//�����������������d1�����ǳ�Ա��������˽�еģ�����û�����ʣ�ֻ�ܹ�����Ԫ������Ҳ�ǵ���Ϊɶ�����������ã� void Display(const Date& d) 
	return 0;

}