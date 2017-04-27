#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
 //���ͱ�̡�����̬˳���
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
	int Find(T s);
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
void SeqList<T>:: PushBack(T s)             //ע���Ա���������ⶨ��   �տ�ʼд����
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
		_str[i+1] = _str[i];
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
		cout << _str[i] <<" ";
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
//SeqList<int>  ����
//void test()
//{
//	SeqList<int>s1;
//	s1.PushBack(1);
//	s1.PushBack(2);
//	s1.PushBack(3);
//	s1.PushBack(4);
//	s1.PopBack();
//	s1.PushFront(1);
//	s1.Print();
//	s1.PopFront();
//	s1.Print();
//	cout << s1.Find(3) << endl;
//	SeqList<int> s2(s1);
//	s2.Print();
//	SeqList <int>s3;
//	s3 = s2;
//	s3.Print();
//}
//SeqList<string>  ����
void test()
{
	SeqList<string> s1;
	s1.PushBack("11");
	s1.PushBack("22");
	s1.PushBack("33");
	s1.PushBack("44");
	//s1.PushBack("55");
	s1.Print();
	SeqList<string>s2(s1);                                             //��������ģ��ʵ������string�� ֪����string���µ���� ��ô������ʹ��std::string��ʱ��Ӧ����ôʹ�ã�����
	s2.Print();
	SeqList<string>s3;
	s3 = s2;
	s3.Print();
}
int main()
{
	test();
	return 0;
}