#define _CRT_SECURE_NO_WARNINGS 1

//�º���ʵ������һ�����󣬾��Ƕ���ģ�º���ȥ���һЩ���� ��������F�����@��  
//��ô����Ҫ���� operator()�����أ����@�����������������ʹ�ã���ʵ���˷º�������ʱ�������@��
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

template<class T>
class deleteArr
{
public:
	void  operator()(T* ptr)         //operator()������     ע�⣺û�з���ֵ
	{
		delete[] ptr;
	}
};

template<class T>
class Delete
{
public:
	void  operator()(T* ptr)
	{
		delete ptr;
	}
};


template<class T,class Del=Delete<T>>       //ע���@��д Ĭ�ϵ�ʱ����ôд ����д������������Ҫд�����ͣ�����
class SharedPtr
{
private:
	T* _ptr;
	int* _refCount; 
	Del del;                                //�@��Del��ʵ������һ������del del���Ե���Del���еĳ�Ա���� 
public:
	SharedPtr(T* ptr = NULL)
		:_ptr(ptr)
		, _refCount(new int(1))       
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
	SharedPtr(SharedPtr<T, Del>& s)
	{
		if (s._ptr)
		{
			_ptr = s._ptr;
			_refCount = s._refCount;
			(*_refCount)++;
		}
	}
	SharedPtr<T, Del>& operator=(SharedPtr<T, Del>& s)
	{
		if (this != &s)
		{
			if (s._ptr != NULL)
			{
				if (--(*_refCount) == 0)
				{
					del(_ptr);                    //del���Ե���Del�еĳ�Ա���� Ĭ��DelΪDelete ��ô�@������ֻ��һ����Ա����
				}                                //���÷�ʽΪ�� del.operator()(_ptr); д��������del(_ptr); �����@����ǵ��ó�Ա��������
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
			del(_ptr);
			_ptr = NULL;
		}
	}

};

void test()
{  //��ʾʵ����
	SharedPtr<int> p1(new int(10));    //�@�����Ĭ��ģ��������Ǹ�Ĭ��ֵ
	SharedPtr<string> p2(new string);
	SharedPtr<string,deleteArr<string>> p3(new string[10]);//��Ϊǰ�������Ѿ�д������deleteArr �����@���ֶ������������delete[]�Ĺ���
}
int main()
{
	test();
	return 0;
}