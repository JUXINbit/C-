#include<iostream>
using namespace std;
class A
{private:
	static int _count;
 public:
	A()
		
	{
		_count++;
	}
	void Display()
	{
		cout << _count << endl;
	}
};
int A::_count = 0;//��������г�ʼ����
int main()
{
	A a1;
	A a2;
	a1.Display();
	a2.Display();
	system("pause");
	return 0;
}