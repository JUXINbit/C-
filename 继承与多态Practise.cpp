#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;
//class Dad                      //������ 
//{
//protected:
//	string name;
//public:
//	Dad()
//	{
//		cout << "���캯��" << endl;
//		name = "JUXIN";
//	}
//	void Display()
//	{
//		cout << name << endl;
//	}
//
//};
//
//class Son :public Dad               //������
//{
//private:
//	int num;                 
//public:
//	void Display()
//	{
//		cout << num << endl;
//		cout << name << endl;
//	}
//
//};
//int main()
//{
//	Son s1;                  //�̳й�ϵ��  �����ڸ���ĳ�Ա�ᱻ�̳�����  ����ʵ����һ����������ʱ��ʵ���ϵ����˸���Ĺ��캯��
//	s1.Display();                 //Ҳ����˵ ��ʵ������������൱������ʵ��������������游��ĳ�Ա �ٳ�ʼ������ĳ�Ա
//}

//���ڵ�������  �����涼�ǵ�������  �����������͵���������� 
//�����Ƕ����  ��ô�̳�   ������ʵ������ʱ��ֻ��̳и����Ĭ��ֵ��

class Student
{
protected:
	string _name;
public:
	Student(string name="hh")                               //ȱʡ�Ĺ��캯��  ��������Ķ����ڹ����ʱ���Զ�����
		:_name(name)            //�@�������string��Ĺ��캯��          
	{
		cout << "���๹��" << endl;
	}
	void Display()
	{
		cout << _name << endl;
	}

};
class person:Student
{
private:
	int _num;
public:
	person(int num=10)
		:_num(num)
	{
		cout << "���๹��" << endl;
	}
	void Display()
	{
		cout << _num << endl;
		cout << _name << endl;
	}

};
int main()
{
	Student s1("xiaohong");
	Student s2(s1);
	s1.Display();
	s2.Display();
	person p1;            //������ʵ����һ��person�����ʱ�� Ҫ����p1�Ĺ��캯��  ����person�Ĺ��캯���ڲ��ֻ���ø���Ĺ��캯��
	p1.Display();               //���Ҹ���Ĺ��캯���϶��Ǵ�Ĭ��ֵ��  ��Ȼû������ ����������˵û�к��ʵĹ��캯��
	return 0;
}