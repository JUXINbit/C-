#include<iostream>
using namespace std;
class Complex
{
private:
	double _real;
	double _image;
public:
	Complex(double real = 0.0, double image = 0.0)
	{
		cout << "Complex()" << endl;
		real = _real;
		image = _image;
	}
	Complex& operator=(Complex& c)//ʹ��Complex�ķ���ֵ���Ͷ���ʹ��void��������Ϊvoid����ʵ������
	{
		cout << "��ֵ���������" << endl;
		if (this != &c)//�@���if������ʲô������Լ��Ƿ���Լ���ֵ��
		{
			this->_real = c._real;
			_image = c._image;
		}
		return *this;
	}

	~Complex()
	{
		cout << "~Complex()" << endl;
	}
	void Display()
	{
		cout << _real << "+" << _image << "i" << endl;
	}
};
int main()
{
	Complex c1(1.0, 1.0);
	Complex c2(2.0, 2.0);
	c2 = c1;
	c2.Display();
	return 0;
}