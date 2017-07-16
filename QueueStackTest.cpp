#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<assert.h>
using  namespace std;


//Ŀ��һ��ʵ��һ��ջҪ�� push pop min������ջ����Сֵ����ʱ�临�Ӷ���  o��1��
//����һ ��һ��ջ
template<class T>
class MyOneStack
{
private:
	stack<T> _stc;
	T Min;
public:
	MyOneStack()       //��Ա���������Լ���ȱʡ���캯��
	{
		cout << "����" << endl;
	}
	void Push(const T& data)
	{
		if (_stc.empty())
		{
			Min = data;
			_stc.push(data);
			_stc.push(data);
			return;
		}
		if (data < Min)
			Min = data;
		_stc.push(data);
		_stc.push(Min);
	}
	void PopMin()                  //ע�⣺ÿ��pop����pop��������С��Ԫ�غ�ջ����pop����С��Ԫ��֮�󣩵�Ԫ�ء��@����ʵ���˹���
	{
		if (_stc.empty())
		{
			return;
		}
		_stc.pop();
		_stc.pop();
	}
};

//�������� ʹ�ø���ջ
template<class T>
class MyDoubleStack
{
private:
	stack<T> _stac1;
	stack<T> _stac2;
public:
	MyDoubleStack()
	{
	}
	void Push(const T& data)
	{
		if (_stac1.empty() && _stac2.empty())
		{
			_stac1.push(data);
			_stac2.push(data);
			return;
		}
		if (data <= _stac2.top())
		{
			_stac1.push(data);
			_stac2.push(data);
		}
		else
			_stac1.push(data);
		return;
	}
	void Pop()
	{
		if (_stac1.empty())
			return;
		if (_stac1.top() > _stac2.top())
		{
			_stac1.pop();
		}
		else if (_stac1.top() == _stac2.top())
		{
			_stac1.pop();
			_stac2.pop();
		}
	}
	T& GetMin()
	{
		assert(!_stac2.empty());
		return _stac2.top();
	}
};

//Ŀ���������ջʵ��һ������

//Ŀ������ ��������ʵ��һ��ջ
template<class T>
class DoublQueStack
{
private:
	stack<T> _stk1;
	stack<T> _stk2;
public:
	DoublQueStack()
	{
	}
	void Push(const T& data)
	{
	}
	void Pop()
	{
	}
};

void test1()
{
	MyOneStack<int>  _M;
	_M.Push(6);
	_M.Push(3);
	_M.Push(5);
	_M.Push(2);
	_M.Push(9);
	_M.Push(0);
	_M.Push(7);
	_M.Push(1);
	_M.PopMin();
}
void test2()
{
	MyDoubleStack<int>  _MD;
	_MD.Push(2);
	_MD.Push(3);
	_MD.Push(6);
	_MD.Push(5);
	_MD.Push(0);
	_MD.Push(9);
	_MD.Push(7);
	_MD.Push(8);
	_MD.Push(1);
	_MD.Push(4);
	_MD.Pop();
	_MD.GetMin();
}
int main()
{
	test2();
	//test1();
	return 0;
}