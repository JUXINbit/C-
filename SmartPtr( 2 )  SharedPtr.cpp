#define _CRT_SECURE_NO_WARNINGS 1
//  ģ��ʵ������ָ�� SharedPtr

//  ��ǰ����������ȱ�ݵ�����ָ��ı�����  ��ʹ�˸�ţ��������ָ��ĵ�������Ȼ�ˣ����Ǳ������������ȣ�
//��ô��SharedPtr�У������ǰ�治ͬ����Ǽ��������ü�������Խ��Խ�������ü��������������@������˳�������������Ϳ�������

#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

struct S
{
	int a;
	int b;
};

template<class T>
class SharedPtr
{
private:
	T* _ptr;
	int* _refCount;              //���ü���
public:
	SharedPtr(T* ptr=NULL)
		:_ptr(ptr)
		, _refCount(new int(1))       //ע������ռ�ĳ�ʼ��
	{
		cout << "��������ָ��" << endl;
	}
	T& operator*()                      //��Ŀ
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	SharedPtr(SharedPtr<T>& s)
	{
		if (s._ptr)
		{
			_ptr = s._ptr;
			_refCount = s._refCount;
			(*_refCount)++;
		}
	}
	SharedPtr<T>& operator=(SharedPtr<T>& s)
	{
		if (this != &s)
		{
			if (s._ptr != NULL)
			{
				if (--(*_refCount) == 0)
				{
					delete _ptr;
				}
				_ptr = s._ptr;
				_refCount = s._refCount;
				(*_refCount)++;
			}
		}
		return *this;                        //������
	}
	~SharedPtr()
	{
		if (--(*_refCount) == 0)
		{
			cout << "����ָ��ָ�����" << endl;
			delete _ptr;
			_ptr = NULL;
		}
	}

};
void test()
{
	SharedPtr<int> p1(new int(10));
	cout << *p1 << endl;
	*p1 = 20;
	cout << *p1 << endl;
	S* ps = new S;
	SharedPtr<S> p2(ps);              //�����@�￴�ɿ�������
	(*p2).a = 10;
	(*p2).b = 20;
	cout << ps->a << endl;
	cout << ps->b << endl;
	p2->a = 30;
	p2->b = 40;
	cout << ps->b << endl;
	SharedPtr<S> p3(new S);
	p3 = p2;
	cout << p3->a << endl;
	cout << p3->b << endl;
	SharedPtr<S> p4(new S[10]);
	SharedPtr<string> p5(new string);
	//SharedPtr<string> p6(new string[5]);    //�������@��ҵ� ����Ϊʲô  ����ָ��ֻ�Ǹ����ͷ� ������T���в�ͬ �����Զ������� ����ֱ��delete
}                                          //���Ƕ���c++���ࣨstring������һЩ�Զ������� ��Ҫ�ͷſռ��ͬʱ������������ ʹ��delete []  
int main()                                  //��Ȼ�@������ǳ���������⣺�������������µ�����
{
	test();
	return 0;
}

//�@���������ʹ�÷º��������C++��һ���÷�  �@�ַ�����SharedPtr��ø�����