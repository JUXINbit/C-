#define _CRT_SECURE_NO_WARNINGS 1

//��������ʵ��һ��ջ

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

//��̬ջ
//��̬����ʵ��
template<class T,size_t N>
class MyStack
{
protected:
	T _a[N];
	size_t size;
public:
	MyStack()
		:size(0)
	{
		cout << "����" << endl;
	}
	void Push(const T& t)
	{
		if (size > N)
		{
			cout << "out of range" << endl;
			return;
		}
		else
		{
			_a[size] = t;
			size++;
		}
	}
	//�@�����@��ʵ�ֵ��룿
	void Pop()
	{
		if (_size == 0)
		{
			printf("ջΪ��\n");
			return;
		}
		size--;
	}
	T& Top()
	{
		assert(_size != 0);
		return _a[size];
	}
	bool Empty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}
};



//��̬����ʵ�ֵĶ�̬ջ
template<class T>
class ACStack
{
protected:
	T* _a;
	size_t _size;     //����Ԫ��
	size_t _capacity;  //��������  

	//����[*]       //��̬��������ݷ�ʽ
	void CheckCapacity()
	{
		if (_size >= _capacity)
			_capacity = _capacity * 2 + 1;           //���ݵķ�ʽ

		T* tmp = new T[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			tmp[i] = _a[i];
		}
		delete[] _a;
		_a = tmp;
	}
public:
	ACStack()
		:_a(NULL)
		, _size(0)         //ע���@���Ķ�����  size�������Ԫ��  ��size-1�Ƕ�̬������±�  �@����ʶ����Ҫ
		, _capacity(1)
	{
		cout << "����" << endl;
	}
	//��ջ
	void Push(const T& t)
	{
		if (_size > _capacity)
		{
			cout << "out of range" << endl;
			return;
		}
		//�ڵ�һ�β���Ԫ�ص�ʱ����Ҫע�� ��ʱ_a = NULL
		if (_size == 0)
		{
			_a = new T(t);
			_size++;
			return;
		}
			CheckCapacity();
			_a[_size] = t;
			_size++;  
	}
	//��ջ
	void Pop()
	{
		if (_size == 0)
		{
			printf("ջΪ��\n");
			return;
		}
		_size--;
	}
	T& Top()
	{
		assert(_size != 0);
		return _a[_size - 1];
	}
	bool Empty()
	{
		if (_size == 0)
			return true;
		else
			return false;
	}
	size_t Size()
	{
		return _size;
	}
	void PrintStack()
	{
		if (_size == 0)
		{
			printf("ջΪ��\n");
			return;
		}
		while (_size)
		{
			cout << Top() << " ";
			Pop();
		}
		cout << endl;
	}
};



//-----------------------test-----------------------------
void TestStack()
{
	//MyStack<int, 10> _stack;
	/*_stack.Push(1);
	_stack.Push(2);
	_stack.Push(3);
	_stack.Push(4);
	_stack.Push(5);
	_stack.Push(6);
	_stack.Push(7);
	_stack.Push(8);
	_stack.Push(9);
	_stack.Push(10);
	_stack.Pop();
	_stack.Pop();
	_stack.Pop();
	_stack.Pop();*/

	ACStack<int>  _stac;
	_stac.Push(0);
	_stac.Push(2);
	_stac.Push(3);
	_stac.Push(4);
	_stac.Push(5);
	_stac.Push(6);
	_stac.Push(7);
	_stac.Push(8);
	//_stac.PrintStack();
	_stac.Pop();
	_stac.Pop();
	_stac.Pop();
	_stac.Pop();
	//_stac.PrintStack();
	_stac.Push(9);
	_stac.Push(9);
	_stac.Push(9);
	_stac.Push(9);
	//_stac.PrintStack();
	_stac.Push(0);
	cout << _stac.Size() << endl;
	cout << _stac.Top() << endl;
}
int main()
{
	TestStack();
	return 0;

}