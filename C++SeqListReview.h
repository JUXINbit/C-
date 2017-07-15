
//*********************************************
//*                                     
//*    ��Ʒ���ƣ���̬˳���Ĵ����ͻ�������
//*    �������ڣ� 2017��7��15��
//*    �汾�ţ�1.1
//*    ���ߣ�����
//*
//*********************************************



#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __C__SEQLISTREVIEW_H__

#define __C__SEQLISTREVIEW_H__    //����Ԥ�����е��������������ʹ��++���žͱ���ͨ��Ϊʲô��

#endif

#include<iostream>
#include<assert.h>
using namespace std;

//C++ʵ�ֶ�̬˳���
typedef int Datatype;
class SeqList
{
private:
	Datatype* _a;
	size_t _size;
	size_t _capacity;
public:
	SeqList()                 //����
		:_a(NULL)
		, _size(0)
		, _capacity(0)
	{
		cout << "����˳���" << endl;
	}

	SeqList(const SeqList& s)   //��������
	{
		if (s._a == NULL)
			_a == NULL;

		Datatype* tmp = new Datatype[s._size];     //��size���ǿ�capacity��
		for (size_t i = 0; i < s._size; i++)       //�����ݵ�ʱ��Ϊʲô��ʹ��malloc  �ڿ�����ʱ��Ϊʲô��ʹ��memcpy  memecpy��һ��ǳ������            
		{
			tmp[i] = s._a[i];     //[]�����ȼ�> .
		}
		_size = s._size;
		_capacity = s._capacity;
		_a = tmp;
	}

	SeqList& operator=(const SeqList& s)    //��ֵ���������    ������ص�
	{
		if (this == &s)    //��ֹ�Ը�ֵ
		{
			return *this;
		}
		if (s._a == NULL)
		{
			_a = NULL;
			return *this;
		}
		if (_a)            //�������ֵ�Ķ������Ԫ�أ��ͽ�Ԫ�ؽ�������  ָ�븳NULL���ٽ��и�ֵ��������ֹ�ڴ�й©
		{
			delete[] _a;
			_a = NULL;
			_size = _capacity = 0;
		}
		Datatype* tmp = new Datatype[s._size];
		for (size_t i = 0; i < s._size; i++)
		{
			tmp[i] = s._a[i];
		}
		_size = s._size;
		_capacity = s._capacity;
		_a = tmp;
		return *this;
	}
	//����
	void CheckCapacity()
	{
		if (_size >= _capacity)
		{
			_capacity = _capacity * 2 + 3;                   //���ݵ�ʱ�������ʹ��_capacity*2+1���ݷ�ʽ���ݷ�ʽ���ݣ���delete[]��ʱ��ͳ�����Ϊʲô��
			Datatype* newarr = new Datatype[_capacity];
			for (size_t i = 0; i < _size; i++)
			{
				newarr[i] = _a[i];
			}
			delete[] _a;             //��ԭ�������ݽ�������
			_a = newarr;
		}
	}
	//β��
	void PushBack(const Datatype& data)     //ע���@���const������
	{
		if (_a == NULL)
		{
			_a = new Datatype(data);
			_size++;
			_capacity++;
			return;
		}
		CheckCapacity();
		_a[_size] = data;
		_size++;
	}
	//����
	~SeqList()
	{
		if (_a)
		{
			delete[] _a;
			_a = NULL;
		}
		_size = _capacity = 0;
	}
	//��ӡ
	void Print()
	{
		if (_a == NULL)
			return;
		for (size_t i = 0; i < _size; i++)
		{
			cout << _a[i] << " ";
		}
		cout << endl;
	}
};
