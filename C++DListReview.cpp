#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

//C++˫������ϰ  ��ͷ�ڵ��β���
template<class T>
struct  DListNode
{
	T _data;
	DListNode<T>* _next;
	DListNode<T>* _prev;

	DListNode(const T& data)
		:_data(data)
		, _next(NULL)
		, _prev(NULL)
	{
		cout << "������" << endl;
	}
};

template<class T>
class DList
{
	typedef DListNode<T> Node;
private:
	Node* _head;
	Node* _tail;
public:
	DList()
		:_head(new Node(T()))
		,_tail(_head)
	{
		_head->_next = _head;
		_head->_prev = _head;
		cout << "��������ͷ���" << endl;
	}
	DList(const DList<T>& l1)
	{
		_head = new Node(T());
		_tail = _head;
		if (l1._head->_next == l1._head)
		{
			return;
		}
		Node* cur = (l1._head)->_next;
		while (cur != l1._head)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	//��ֵ���������
	DList<T>& operator=(const DList<T>& l1)
	{
		if (this != &l1)
		{
			if (l1._head->_next == l1._head)
			{
				return *this;
			}
			if (_head->_next != _head)       //��ԭ���Ķ���Ϊ�յ�ʱ���ͷ�ԭ���Ŀռ�
			{
				Destory();
			}
			Node* cur = l1._head->_next;
			while (cur != l1._head)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		return *this;
	}
	//β��
	void PushBack(const T& data)
	{
		Node* newnode = new Node(data);
		_tail->_next = newnode;
		newnode->_prev = _tail;
		newnode->_next = _head;
		_head->_prev = newnode;
		_tail = newnode;
	}
	//ͷ��
	void PushFront(const T& data)
	{
		Node* newnode = new Node(data);
		Node* tmp = _head->_next;
		_head->_next = newnode;
		newnode->_prev = _head;
		newnode->_next = tmp;
		tmp->_prev = newnode;
	}
	void PopBack()
	{}
	void PopFront()
	{}
	Node* Find(const T& data)
	{
		if (_head->_next == _head)
			return NULL;
		else
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				if (cur->_data == data)
					return cur;
				cur = cur->_next;
			}
			return NULL;
		}
	}
	//ʵ�����λ�õĲ����ɾ��
	void Insert(const T& data,Node* pos)
	{}
	void Erase(Node* pos)
	{}
	bool Empty()
	{
		if (_head->_next == _head)
			return true;
		else
			return false;
    }
	//������ͷ����destory
	void Destory()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* tmp = cur;
			cur = cur->_next;
			delete tmp;
		}
		_head->_next = _head;     //��ס�Լ��տ�ʼ����ô����ģ����滹��Ҫ�ظ������״̬
		_head->_prev = _head;
		_tail = _head;
	}
	~DList()
	{
		Destory();
		delete _head;
		_head = _tail = NULL;
	}
	void Print()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
};

//----------------test-----------------------------
void test()
{
	DList<int> d1;
	d1.PushBack(1);
	d1.PushBack(2);
	d1.PushBack(3);
	d1.PushBack(4);
	d1.PushBack(5);
	d1.PushBack(6);
	d1.Print();
	DList<int> d2(d1);
	d2.Print();
	DList<int> d3;
	d3.PushBack(7);
	d3.PushBack(8);
	d3.PushBack(9);
	d3.PushBack(10);
	d1 = d3;
	d1.Print();
}
int main()
{
	test();
	return 0;
}