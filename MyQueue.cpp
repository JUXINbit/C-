#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

//����ṹʵ��һ������  ʵ�ֻ����Ķ��е���ز�����
//��ͷ������
template<class T>
struct QueueNode
{
	T  _data;
	QueueNode<T>* _next;
	QueueNode(const T& data)
		:_data(data)
		, _next(NULL)
	{
	}
};
template<class T>
class MyQueue
{
	typedef QueueNode<T>  Node;
protected:
	Node* _head;
public:
	MyQueue()
		:_head(NULL)
	{
		cout << "������нṹ" << endl;
	}
	void Push(const T& data)        //��β����
	{
		if (_head == NULL)
		{
			_head = new Node(data);
		}
		else
		{
			Node* cur = _head;
			while (cur->_next)
			{
				cur=cur->_next
			}
			Node* newNode = new Node(data);
			cur->_next = newNode;
		}
	}
	void Pop()         //��ͷɾ��   
	{
		if (_head == NULL)    //û��Ԫ��
		{
			printf("����Ϊ��\n");
			return;
		}
		if (_head->_next == NULL)    //��һ��Ԫ��
			_head = NULL;
		else                        //���Ԫ��
		{
			Node* tmp = _head;
			Node* next = _head->_next;
			_head = next;
			delete tmp;
		}
		return;
	}
	T& Front()
	{
		if (_head == NULL)    //û��Ԫ��
		{
			printf("����Ϊ��\n");
			return;
		}
		else
		{
			return _head->_data;
		}
	}
};


void TestQueue()
{
}
int main()
{
	TestQueue();
	return 0;
}