#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//RAII

//��TΪ�������͵�ʱ��
//template<class T>
//class AutoPtr            //��һ�������ָ��
//{
//protected:
//	T* _ptr;
//public:
//	AutoPtr(T* ptr=NULL)
//		:_ptr(ptr)
//	{
//		cout << "ԭ��ָ�빹������ָ��" << endl;
//	}
//	T& operator*()        //'*'������   ֮ǰ����д��˫Ŀ����������أ��������this���в��������������ǵ�Ŀ���������д���� ��ס��������Զ��this
//	{
//		return *_ptr;
//	}
//
//	~AutoPtr()
//	{
//		cout << "�ͷ�ָ��ָ��Ŀռ�" << endl;
//		delete _ptr;
//		_ptr = NULL;
//	}
//
//};
//
//void test()
//{
//	int* pa = new int(4);
//	AutoPtr<int> p1(pa);      //�@���൱�� ��paָ����ָ��Ŀռ�Ĺ���Ȩ����������ָ�����p1 ��ô֮��pa���Բ���ִ��ʲô���� һ�н�������p1
//	cout << *p1 << endl;      //�@��������ԭ��ָ��һ��������
//	*p1 = 10;                //Ϊʲô������Ľ����ó�Ա������Ҫ����T& �������T�@��ͻ�ִ�д���
//	cout << *p1 << endl;
//    
//}
//int main()
//{
//	test();
//	return 0;
//}


// ��T������������ʱ

struct A         //����һ��A��
{
	int a;
	int b;

};

//template<class T>
//class AutoPtr
//{
//private:
//	T* _ptr;
//public:
//	AutoPtr(T* ptr=NULL)
//		:_ptr(ptr)
//	{
//		cout << "��������ָ��" << endl;
//	}
//	//Ȩ�޵�ת��-----AutoPtr
//	AutoPtr(AutoPtr<T>& a)     //�������캯��   �@��Ͳ���const������
//	{
//		this->_ptr = a._ptr;
//		a._ptr = NULL;            //�@�����AutoPtr��һ������ȱ�� ԭ����AutoPtr�Ͳ��ܹ���ָ��������� �@����������֮������һЩ����
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& a)
//	{
//		if (this != &a)
//		{
//			delete _ptr;               //�Ҹտ�ʼ�п���  ��ʵdelete �� free������NULLָ���ʱ�򲢲��ᱨ�� ֻ������ȥִ�� �����@���������ͷ�Ұָ�룬��ȻҪ��סdelete��free֮��ָ����NULL��ֹҰָ��
//			_ptr = a._ptr;
//			a._ptr = NULL;
//		}
//		return *this;
//	}
//	T& operator*()        
//	{
//	    return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//	~AutoPtr()
//	{
//		cout << "�ͷ�ָ����ָ��Ŀռ�" << endl;
//		delete _ptr;
//		_ptr = NULL;
//	}
//
//};
//void test()
//{
//    //�������һ��ԭ����A���ָ��
//	//A* pp = new A;      //Aû���캯�����Ͳ���ʼ����
//	//(*pp).a = 10;
//	//(*pp).b = 20;
//	//pp->a = 30;
//	//pp->b = 40;
//	//��ô���Ͼ���һ��ԭ��ָ��������ɵ�һЩ����
//	//�����Ҫ��һ��ԭ��ָ�뽻��һ������ָ����в����Ļ� ����Ҫ���ͬ��������Ļ���ô����Ҫ����һЩ�������ﵽ�ҵ�Ŀ�� �鴦�������operator* �������@�˻���Ҫoperator->������
//
//
//	A*  pa = new A;
//	AutoPtr<A> p1(pa);      //p1ָ��һ��A�����������
//	(*p1).a = 10;
//	(*p1).b = 20;          //*�������ܹ����Զ���������ɶ��Լ������ڲ��ĳ�Ա�ķ���
//	p1->a = 30;
//	p1->b = 40;            //������չ���Ļ�����p1.operator->(this->b)=40,��ô��д�Ļ����� ��p1->->b=40 Ҳ����_ptr->b=40�������@���и����������Ż���Ϊ����ǿ�ɶ��ԣ������@����@��д��
//
//	AutoPtr<A> p2(p1);
//	cout << p2->a << endl;
//	AutoPtr<A> p3;
//    p3 = p2;
//	cout << p3->a << endl;
//                    
//}
//int main()
//{
//	test();
//	return 0;
//}
//���Ͼ���ģ����һ������ָ���е�AutoPtr   �������Ƕ�֪�������д��ڵĺ����ص����ȱ��





//ʵ��������98���ִ��ָ��AutoPtr�ڿ����в�����һЩ���⣬��������ָ��ķ�չʵ����һֱ��Χ���@������Ľ������
//  2. ScopedPtr

  //�@���ͱȽϴֱ��� �����@���濽�����캯���͸�ֵֻ�������ˣ������Ǳ����������޷����ʣ�����û�ж������ ��
   //�������ˣ��@��ָ����ǲ����������ָ��֮������й��ڿ����Ĺ��������ܹ��찡��ȡ���ݰ�֮��

template<class T>
class ScopedPtr
{
protected:
	T* _ptr;
	//������������������һ�ַ���
protected:
	ScopedPtr(ScopedPtr<T>& a);                     //ע�⣺���@�����ӿ�����Ϊ��������ҪĿ����Ϊ�˷�ֹ������������ж���Ȼ��ʹ�� 
	ScopedPtr<T>& operator=(ScopedPtr<T>& a);        //����г�Ա��������������Ϊ˽�У���ô�������ǲ��ܶ�֮���ж���ģ���Ϊ���ʲ�����֮ǰ��һֱ����⣩

public:
	ScopedPtr(T* ptr = NULL)
		:_ptr(ptr)
	{
		cout << "��������ָ��" << endl;
	}

	T& operator*()        
	{
	    return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~ScopedPtr()
	{
		cout << "�ͷ�ָ����ָ��Ŀռ�" << endl;
		delete _ptr;
		_ptr = NULL;
	}

};

void test()
{
	int* p1 = new int(10);
	ScopedPtr<int>  s1(p1);
	cout << *s1 << endl;
	*s1 = 20;
	cout << *s1 << endl;
	ScopedPtr<A> s2(new A);
	s2->a = 10;
	s2->b = 20;
	(*s2).a = 30;
	(*s2).b = 40;
	//ScopedPtr<A> s3(s2);       //�����޷�������protect�ĳ�Ա  
}
int main()
{
	test();
	return 0;
}



//ʵ��������ָ��Ҫ���������������ô����Ҫ�� һ��Ҫ�����ͷ�ָ�루��Ϊ����ָ��ʵ���������Ķ�������ڽ����Ѿ������õĶ��󰡣�ֻ����һ�������������Ҿͻ��ͷŵ���
//����Ҫ�ܹ������ԭ��ָ�������Ĺ��ܡ�    ���Ǿ�����Ϊ�������⣨�����������Գ����˺ܶ಻һ���İ汾��ʵ���Ͼ����@����

//��ν��������  1. ֻ������������
//              2.������˽�л��߱�������ֹ������������ж������