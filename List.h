#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

//template<class T>
/*typedef struct ListNode
{
T _data;
ListNode<T>* _next;
ListNode<T>* _prev;
ListNode(const T& d)
: _data(d)
, _next(NULL)
, _prev(NULL)
{
}
}Node; */                 //�Ҹտ�ʼ��ôд  ���� ��ʵ��֮ǰд����ȷ����Ϊ ��ʱ��ListNode������������������  ����Ҫע������ģ��֮�������������Ͳ�ͬ 


template<class T>                                 //���@��  ListNode��������  ListNode<T>������  �����õ��������ĵط�ֻ��������  ���캯�����Ϳ������캯����
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;
	ListNode(const T& d)      //���캯��
		: _data(d)
		, _next(NULL)
		, _prev(NULL)
	{
	}
};                            //��������Ͳ���ʹ��typedef ��Ϊtypdef���������һ������  ������������  ������������һ������



template<class T>
class List
{
	typedef ListNode<T> Node;
private:
	Node* _head;
	Node* _tail;
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{
	}
	List(const List<T>& s)
		:_head(NULL)
		, _tail(NULL)
	{
		if (s._head)
		{
			Node* cur = s._head;
			while (cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
	}
	List<T>& operator=(List<T>& s)
	{
		if (_head)
		{
			Destory();
		}
		else if (s._head)
		{
			Node* cur = s._head;
			while (cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		else
			_head = _tail = NULL;
		return *this;
	}
	void Destory()
	{
		if (_head == NULL)
		{
			cout << "����Ϊ��" << endl;
			cout << "����" << endl;
		}
		else if (_head->_next == NULL)
		{
			cout << "����" << endl;
			delete _head;
			_head = NULL;
		}
		else
		{
			Node* cur = _head;
			while (cur)
			{
				Node* tmp = cur;
				cur = cur->_next;
				delete tmp;
				cout << "����" << endl;
			}
		}
	}
	~List()
	{
		Destory();
	}
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	Node* Find(const T& d);
	void Print();
	bool Empty();
	size_t Size();
	T& Front();                   //�@�����Ҷ�������Ϊ����ֵ��ʹ����Ȼ��̫�˽�
	T& Back();
};

template<class T>
void List<T>::PushBack(const T& d)
{
	if (_head == NULL)
	{
		_head = new Node(d);
		_tail = _head;
	}
	else
	{
		_tail->_next = new Node(d);
		Node* tmp;
		tmp = _tail->_next;
		tmp->_prev = _tail;
		_tail = tmp;
	}
}

template<class T>
void List<T>::PopBack()                            //�����ⶨ��һ����������ʽ��  ����ֵ+���ڵ����ͣ���������������::�������βη������ͣ��β�����
{
	if (_head == NULL)
	{
		cout << "����Ϊ��" << endl;
	}
	else if (_head->_next == NULL)
	{
		delete _head;
		_head = NULL;
	}
	else
	{
		Node* tmp = _tail->_prev;
		tmp->_next = NULL;
		delete _tail;
		_tail = tmp;
	}
}

template<class T>
void List<T>::PushFront(const T& d)
{
	if (_head == NULL)
	{
		_head = new Node(d);
	}
	else
	{
		Node* tmp = new Node(d);
		Node* cur = _head;
		_head = tmp;
		tmp->_next = cur;
		cur->_prev = tmp;
	}


}
template<class T>
void List<T>::PopFront()
{
	if (!_head)
	{
		cout << "����Ϊ��" << endl;
	}
	else if (_head->_next == NULL)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node* tmp = _head->_next;
		tmp->_prev = NULL;
		delete _head;
		_head = tmp;
	}
}

template<class T>
ListNode<T>* List<T>::Find(const T& d)
{
	if (_head == NULL)
	{
		cout << "����Ϊ��" << endl;
		return NULL;
	}
	else
	{
		Node* cur = _head;
		while (cur)
		{
			if (cur->_data == d)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}
}

template<class T>
bool List<T>::Empty()
{
	return _head == NULL;

}

template<class T>
size_t List<T>::Size()
{
	size_t count = 0;
	Node* cur = _head;
	while (cur)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}

template<class T>
T&  List<T>::Front()                            //�����@��ΪʲôҪ��������  
{
	assert(_head);
	return _head->_data;

}

template<class T>
T&  List<T>::Back()
{
	assert(_head);                          //������Щ�ӿ�  �ö����ж�һ�� �Ͳ�Ҫif else����
	return _tail->_data;
}

template<class T>
void List<T>::Print()
{
	if (_head == NULL)
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
}






//void test()
//{
//	List<int> s1;
//	s1.PushBack(1);
//	s1.PushBack(2);
//	s1.PushBack(3);
//	s1.PushBack(4);
//	s1.PushBack(5);
//	s1.PushBack(6);
//	s1.Print();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.Print();
//	s1.PushFront(0);
//	s1.PushFront(0);
//	s1.PushFront(0);
//	s1.Print();
//	s1.PopFront();
//	s1.PopFront();
//	s1.PopFront();
//	s1.Print();
//	cout << s1.Size() << endl;
//	cout << s1.Empty() << endl;
//	cout << s1.Back() << endl;
//	cout << s1.Front() << endl;
//	List<int> s2(s1);
//	s2.Print();
//	List<int>s3;
//	s3 = s2;
//	s3.Print();
//}
//int main()
//{
//	test();
//	return 0;
//}