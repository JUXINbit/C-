#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;


struct _TrueType
{
	bool get()
	{
		return true;
	}
};

struct _FalseType
{
	bool get()
	{
		return false;
	}
};

template<class T>                           //IsPodType���޹ؽ�Ҫ������
class TypeTraits
{
	typedef  _FalseType IsPodType;
};

template<>
class TypeTraits<int>                       //������������Զ������ͺ�����ʤ���Ŀ��࣬��������ռ�����������Խ������������⻯������˳����������������ʹ��memcpy��Ҳ��Ϊ�����Ч��
{
	typedef  _TrueType IsPodType;
};

template<>
class TypeTraits<double>
{
	typedef  _TrueType IsPodType;
};

template<>
class TypeTraits<float>
{
	typedef  _TrueType IsPodType;
};

template<>
class TypeTraits<char>
{
	typedef  _TrueType IsPodType;
};

template<>
class TypeTraits<size_t>
{
	typedef  _TrueType IsPodType;
};

template<class T>
class TypeTraits<T*>                          //�@��Ҫע�⣺ʵ�������������⻯��Щ�޹ؽ�Ҫ�����ͣ�Ҳ������SeqList����ʹ��memcpy��������ֵ������
{                                           //��Щ�������ͣ��������ı����׼���е����� ���������Զ��������  �ͱ���ʹ��forѭ������
	typedef  _TrueType IsPodType;               //���Ƿ���Ϊʲô�@���T*������T&��Ҳ���޹ؽ�Ҫ�������أ�  ��ΪT*���͵�����ʹ��memcpy������ַû��ʲô���⡣
};                                            //��ò��T*�@���Tֻ��ʹ���������ͣ����������Զ������ͻ��߿�����ģ�






template<class T>
class SeqList
{
private:
	T* _str;
	size_t _size;
	size_t _capacity;
public:
	SeqList();
	~SeqList();
	SeqList(const SeqList<T>& s);
	SeqList<T>& operator=(const SeqList<T>& s);
	void CheckCapcity();
	void PushBack(T s);
	void PopBack();
	void PushFront(T s);
	void PopFront();
	int  Find(T s);
	void Insert(T s);
	void Erase(T s);
	void Print();
};
template<class T>
SeqList<T>::SeqList()
:_str(NULL)
, _size(0)
, _capacity(0)
{

}
template<class T>
SeqList<T>::SeqList(const SeqList<T>& s)
{
	if (s._str)
	{
		T* tmp = new T[s._capacity];                     

		if (TypeTraits<T>::IsPodType().get())             //ʹ��������ȡ,  ����ǰ���ƫ�ػ� �ж�ʵ������ʱ��������Ƿ����޹�ʹ��������
		{
			memcpy(tmp, s._str, sizeof(T)*s._size);
		}   
		else
		{
			for (size_t i = 0; i < s._size; i++)
			{
				tmp[i] = s._str[i];
			}
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
		}
	}
}

template<class T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& s)
{
	if (s._str)
	{

		if (_str)
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}
		T* tmp = new T[s._capacity];
		if (TypeTraits<T>::IsPodType().get())
		{
			memcpy(tmp, s._str, sizeof(T)*s._size);
		}
		else
		{
			for (size_t i = 0; i < s._size; i++)
			{
				tmp[i] = s._str[i];
			}
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
		}
		//��ס�з���ֵ
	}
	return *this;
}
template<class T>
void SeqList<T>::CheckCapcity()
{
	if (_size >= _capacity)
	{
		_capacity = _capacity * 2 + 3;
		T* tmp = new T[_capacity]; 
		if (TypeTraits<T>::IsPodType().get())
		{
			memcpy(tmp, _str, sizeof(T)*_size);
		}
		else
		{
			for (size_t i = 0; i < _size; i++)
			{
				tmp[i] = _str[i];
			}
			delete[] _str;
			_str = tmp;
		}
	}
}

template<class T>
void SeqList<T>::PushBack(T s)             //ע���Ա���������ⶨ��   �տ�ʼд����
{
	CheckCapcity();
	_str[_size] = s;
	_size++;
}

template<class T>
void SeqList<T>::PopBack()
{
	_size--;
}
template<class T>
void SeqList<T>::PushFront(T s)
{
	CheckCapcity();     //Ҫ�������ݼ�סҪ�������
	int i = 0;                           //ע���@������Ĵ���   ���@���ݼ���ѭ������  ����size_t  �������ѭ��
	for (i = _size; i >= 0; i--)          //һ�����г����˽��������� ����������ѭ��
	{
		_str[i + 1] = _str[i];
	}
	_str[0] = s;
	_size++;
}

template<class T>
void SeqList<T>::PopFront()
{
	size_t i = 0;
	for (i = 0; i < _size; i++)
	{
		_str[i] = _str[i + 1];
	}
	_size--;
}

template<class T>
int  SeqList<T>::Find(T s)
{
	size_t i = 0;
	for (i = 0; i < _size; i++)
	{
		if (_str[i] == s)
		{
			return i;   //ע�����@�ﷵ�ص����±�    ��������ֵΪint      ��һ��ʼд����SeqList<T>* �ķ���ֵ
		}
	}
	return NULL;
}
template<class T>
void SeqList<T>::Print()
{
	size_t i = 0;
	for (i = 0; i < _size; i++)
	{
		cout << _str[i] << " ";
	}
	cout << endl;
}

template<class T>
SeqList<T>::~SeqList()
{
	if (_str)
	{
		delete[] _str;
		_size = 0;
		_capacity = 0;
	}
}