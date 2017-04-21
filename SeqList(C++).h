#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

typedef int DataType;
class SeqList
{  
private:
	DataType* _str;
	size_t _size;
	size_t _capacity;
public:
	SeqList()                   //����  ��ʼ��
		:_str(NULL)
		, _size(0)
		, _capacity(0)
	{
	}
	SeqList(const SeqList& s)            //��������
	{
		if (s._str)
		{
			_str = new DataType[s._capacity];          //new ���ü����ֽ���  ���һ�����캯��
			memcpy(_str, s._str, sizeof(DataType)*s._size);
			_size = s._size;  
			_capacity = s._capacity;
		}
		else
			_str = NULL;
	}
	SeqList& operator=(const SeqList& s)       //��ֵ���������
	{
		if (this != &s)
		{
			if (s._str)
			{
				if (_str)
				{
					free(_str);                            //�������ֵ�Ķ���ԭ���Ѿ�ָ��һ��ռ�
				}
					_str = new DataType[s._capacity];
					memcpy(_str, s._str, sizeof(DataType)*s._size);
					_size = s._size;
					_capacity = s._capacity;
				
			}
			else
				_str = NULL;
		}
		return *this;
	}
	void CheckCapacity()                //����
	{
		if (_size == _capacity)
			/*_str = (DataType*)realloc(_str, sizeof(DataType)* 2 + 3);
		_capacity=? */
		_capacity = _capacity * 2 + 3;
		_str = (DataType*)realloc(_str, sizeof(DataType)*_capacity);
	}
	void PushBack(DataType d)       //ͷ��
	{
		CheckCapacity();
		_str[_size] = d;
		_size++;
	}
	void PopBack()                    //βɾ
	{
		_size--;
	}
	void PushFront(DataType d)                         //ͷ��
	{
		CheckCapacity();
		int i = 0;
		for (i = _size; i >= 0; i--)
		{
			_str[i+1] = _str[i];
		}
		_str[0] = d;
		_size++;
	}
	void PopFront()                                     //ͷɾ
	{
		size_t i = 0;
		for (i = 0; i < _size - 1; i++)
		{
			_str[i] = _str[i + 1];
		}
		_size--;
	}
	void Print()                                //��ӡ
	{
		size_t i = 0;
		for (i = 0; i < _size; i++)
		{
			cout << _str[i] <<" ";
		}
		cout << endl;
	}
	int  Find(DataType d)                      //����
	{
		size_t i = 0;
		for (i = 0; i < _size; i++)
		{
			if (_str[i] == d)
				return i;
		}
		return -1;
	}
	~SeqList()                                 //����
	{
		if (_str)
		{
			free(_str);
			_str = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
};


void test()
{
	SeqList s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PopBack();
	s1.PopFront();
	s1.PushFront(1);
	s1.PushFront(2);
	s1.Print();
	cout << s1.Find(3) << endl;
	SeqList s2(s1);
	s2.PushBack(5);
	s2.PushBack(6);
	s2.PushBack(7);
	s2.PushBack(8);
	s2.PushBack(9);
	s2.Print();
	SeqList s3;
	s3 = s2;
	s3.Print();
	s1 = s3;
	s1.Print();
}

