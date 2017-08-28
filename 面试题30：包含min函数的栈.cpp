#define _CRT_SECURE_NO_WARNINGS 1
//ջ��������
#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Stack
{
private:
	stack<T> _s;
	T _min;
public:
	void Push(T data)
	{
		if (_s.empty())
			_min = data;
		if (data < _min)
			_min = data;
		_s.push(data);
		_s.push(_min);
	}
	void Pop()
	{
		if (!_s.empty())
		{
			_s.pop();
			_s.pop();
		}
	}
	T top()
	{
		if (!_s.empty())
		{
			_s.pop();
			return _s.top();
			_s.pop();               //ע���ȡ��top������֮����Ҫ������pop();
		}
	}
	T Min()
	{
		if (!_s.empty())
			return _s.top();
	}
};
int main()
{
	Stack<int> _s;
	_s.Push(3);
	_s.Push(2);
	_s.Push(5);
	_s.Push(7);
	_s.Push(1);
	_s.Push(2);
	_s.Push(9);
	//cout << _s.top() << endl;
	cout << _s.Min() << endl;
	return 0;
}