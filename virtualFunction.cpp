#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//������μ̳еĶ����Ժ���������  ������̳�

class A
{
public:                     //ע�������public�����޶�����Ȼ���������������޷����ʸó�Ա
	string _name;
};
class B: virtual public A
{
protected:
	int _num;
};
class C :virtual public A
{
protected:
	int _age;
};
class D :public B, public C
{
protected:
	string _majority;
};
int main()
{
	D dd;
	A* pa = &dd;
	B* pb = &dd;
	C* pc = &dd;
	D* pd = &dd;
	return 0;
}