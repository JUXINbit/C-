#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//class Array
//{
//private:
//	size_t _sz;         //����Ĵ�С
//	int* _ptr;          //������Ԫ�ص�ַ
//public:
//	Array(size_t sz = 5)
//		: _sz(sz)
//		, _ptr(NULL)
//	{
//		cout << "Array" << endl;
//		if (_sz > 0)
//		{
//			_ptr = new int[_sz];
//		}
//	}
//	~Array()
//	{
//		cout << "~Array" << endl;
//		if (_ptr != NULL)
//		{
//			delete[] _ptr;
//		}
//	}
//};
//int main()
//{
//	//Array a;                        //ʵ����һ������a
//	Array* parray = new Array;      //���@����new��һ��ָ��Array���ָ��  ������ù��캯������������  ��ʵ��ʵ����������˼���
//	delete parray;
//	return 0;
//}  //�������Զ������ͣ��ȿ��ٿռ� �ڵ��ù��캯��    �ȵ����������� ���ͷſռ�



//ģ��ʵ��new/delete���ʽ
//class A
//{
//private:
//	int _a;
//public:
//	A(int a=10)
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//int main()
//{
//	A* pa = (A*)operator new(sizeof(A));           //���ٿռ�
//	new(pa) A(20);                               //��λnew���ʽ  ��ʼ������ָ��ָ��Ŀռ�
//	//delete pa
//	pa->~A();                       //�������� һ��                  
//	return 0;
//}



//ģ��ʵ��new[]/delete[]

class A
{
private:
	int _a;
public:
	A(int a=10)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
int main()
{
	/*A* pa = new A[10];
	delete[] pa;*/
	A* pa = (A*)operator new(10*sizeof(A)+4);    //paΪ�׵�ַ    ���4���ֽڵ���˼��Ҫ��Ŷ������ ��һ������
	*(int*)pa = 10;                           //��һ���ĸ��ֽڴ�Ŷ������Ϊ10��
	pa = (A*)((int*)pa + 1);                //  ������Ŷ�������Ŀռ�λ��  ע��ǿ������ת��			ǿת֮������ͱ����ת���������
	int i = 0;
	for (i = 0; i < 10; i++)                 //����10�ι���
	{
		new(pa + i) A;               //new��λ���ʽ�����Ѿ�����õĿռ�������ù��캯����ʼ��һ������
	}
	for (i = 0; i < 10; i++)                  //����10������
	{
		(pa + i)->~A();
	}
	return 0;
}
//ʵ���϶����Զ���������˵  new/delete������ص���ǻ���ù�������� �������ǿ��ٿռ�



//C++��̬�ڴ����ļ������㣺 1.c��c++�Ķ�̬�ڴ������ʲô����ֱ���ʲô���� ��   
//                            2.new([])/delete([])�ײ����ʵ�֣�
//                            3.ΪʲôҪ�ɶ�ʹ�ã�