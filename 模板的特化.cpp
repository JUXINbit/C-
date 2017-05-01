#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;
//���ͱ�̡�����̬˳���+ �ػ�
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
		T* tmp = new T[s._capacity];                      //��C++����  ����new ����malloc realloc  ��Ϊ����һЩ�������Ϳ��ܲ���Ҫ����  �������Զ�������
		//memcpy(tmp, s._str, sizeof(T)*s._size);             //�����ڿ��ٿռ�֮��ض���Ҫ�����ʼ��֮����ܽ��п���  ��ֵ
		for (size_t i = 0; i < s._size; i++)
		{
			tmp[i] = s._str[i];             //�@���������ǰ���memcpy���˲�ͬ  ��string�Լ�������ȥ��������ǵ�����ֵ���� 
		}
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
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
		//memcpy(tmp, s._str, sizeof(T)*s._size);
		for (size_t i = 0; i < s._size; i++)
		{
			tmp[i] = s._str[i];
		}
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
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
		T* tmp = new T[_capacity];            //�@�����з�������֮�������ֵ �����Ҳŷ�Ӧ����new���ؿ��ռ� realloc����������ط����������¿����һ��֮ǰ��ֵ������ 
		/*	memcpy(tmp, _str, sizeof(T)*_size);  */  //������
		for (size_t i = 0; i < _size; i++)
		{
			tmp[i] = _str[i];                 //memcpyʵ������һ��ǳ����  Ҳ����˵�����ٿ�����ʱ��ֻ�ǰ�string��ֵ������ Ȼ��ȴ�����˻����string���������� ֮���Ҳ����@������
		}
		delete[] _str;                      //��ʹ��new�������ݵ�ʱ��ǵ�Ҫ��ԭ���Ŀռ��ͷ�
		_str = tmp;
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





//�ػ��������⻯��   Ϊ�������������⴦��
//1. ȫ�ػ�
template<>
class SeqList<int>     //ʵ�����@���@��������������������������Ҳ��֪��   ���������Ϳ϶���û���   
{                      //ȫ�ػ�֮����������ĳ�Ա����������Ҫģ�����  ���е�T�滻����Ҫ�ػ�����������
private:
	int* _str;
	size_t _size;
	size_t _capacity;
public:
	SeqList();
	~SeqList();
	SeqList(const SeqList<int>& s);
	SeqList<int>& operator=(const SeqList<int>& s);
	void CheckCapcity();
	void PushBack(int s);
	void PopBack();
	void PushFront(int s);
	void PopFront();
	int  Find(int s);
	void Insert(int s);
	void Erase(int s);
	void Print();
};
  //template<>    ���@����Բ�д�@��������  û�б�Ҫ
SeqList<int>::SeqList()
:_str(NULL)
, _size(0)
, _capacity(0)
{

}

SeqList<int>::SeqList(const SeqList<int>& s)
{
	if (s._str)
	{
		int* tmp = new int[s._capacity];                      //��C++����  ����new ����malloc realloc  ��Ϊ����һЩ�������Ϳ��ܲ���Ҫ����  �������Զ�������
		//memcpy(tmp, s._str, sizeof(T)*s._size);             //�����ڿ��ٿռ�֮��ض���Ҫ�����ʼ��֮����ܽ��п���  ��ֵ
		for (size_t i = 0; i < s._size; i++)
		{
			tmp[i] = s._str[i];             //�@���������ǰ���memcpy���˲�ͬ  ��string�Լ�������ȥ��������ǵ�����ֵ���� 
		}
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
	}
}

//template<>
SeqList<int>& SeqList<int>::operator=(const SeqList<int>& s)
{
	if (s._str)
	{

		if (_str)
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}
		int* tmp = new int[s._capacity];
		//memcpy(tmp, s._str, sizeof(T)*s._size);
		for (size_t i = 0; i < s._size; i++)
		{
			tmp[i] = s._str[i];
		}
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
		//��ס�з���ֵ
	}
	return *this;
}
//template<class T>
void SeqList<int>::CheckCapcity()
{
	if (_size >= _capacity)
	{
		_capacity = _capacity * 2 + 3;
		int* tmp = new int[_capacity];            //�@�����з�������֮�������ֵ �����Ҳŷ�Ӧ����new���ؿ��ռ� realloc����������ط����������¿����һ��֮ǰ��ֵ������ 
		/*	memcpy(tmp, _str, sizeof(T)*_size);  */  //������
		for (size_t i = 0; i < _size; i++)
		{
			tmp[i] = _str[i];                 //memcpyʵ������һ��ǳ����  Ҳ����˵�����ٿ�����ʱ��ֻ�ǰ�string��ֵ������ Ȼ��ȴ�����˻����string���������� ֮���Ҳ����@������
		}
		delete[] _str;                      //��ʹ��new�������ݵ�ʱ��ǵ�Ҫ��ԭ���Ŀռ��ͷ�
		_str = tmp;
	}
}

//template<class T>
void SeqList<int>::PushBack(int s)             //ע���Ա���������ⶨ��   �տ�ʼд����
{
	CheckCapcity();
	_str[_size] = s;
	_size++;
}

//template<class T>
void SeqList<int>::PopBack()
{
	_size--;
}
//template<class T>
void SeqList<int>::PushFront(int s)
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

//template<class T>
void SeqList<int>::PopFront()
{
	size_t i = 0;
	for (i = 0; i < _size; i++)
	{
		_str[i] = _str[i + 1];
	}
	_size--;
}

//template<class T>
int  SeqList<int>::Find(int s)
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
//template<class T>
void SeqList<int>::Print()
{
	size_t i = 0;
	for (i = 0; i < _size; i++)
	{
		cout << _str[i] << " ";
	}
	cout << endl;
}

//template<class T>
SeqList<int>::~SeqList()
{
	if (_str)
	{
		delete[] _str;
		_size = 0;
		_capacity = 0;
	}
}


void test()
{
	SeqList<int> s1;   //ͨ�����Կ��Կ����@��ʵ�����@�������ߵ��ػ��汾
	SeqList<double> s2;    //�@�������ߵ�ԭ���汾
}
int main()
{
	test();
	return 0;
}

//2.ƫ�ػ�������ȫ�ػ���
//ʵ���ϣ�ƫ�ػ��Ƕ�ģ������Ľ�һ�����ƣ�����˵���ڶ��������ģ�壬ƫ�ػ�����ָ���ػ����ֲ��������ػ�������ָ���������Ҳ��һ��ƫ�ػ�

//����ʹ�������ڿμ�

