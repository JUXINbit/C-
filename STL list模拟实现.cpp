#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;
	ListNode(const T& d)   
		:_data(d)
		,_next(NULL)
		,_prev(NULL)
	{
	    
	}
};

template<class T>
struct ListIterator
{
	typedef ListNode<T> Node;
	Node* _node;
	ListIterator(Node* node)
		: _node(node)
	{
		cout << "�������������" << endl;     //ע�� ����������Ҫд�������� ��û�@����Ҫ ������������Ǳ����͸���
	}
	T& operator*()
	{
		return _node->_data;            //���������� _node->_data��Ȼ���� ���Է�������
	}
	T* operator->()
	{
		return &(_node->_data);
	}
	ListIterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	bool operator!=(ListIterator<T>& l1)
	{
		return  _node != l1._node;
	}
};
//****************************************************************************************************************


template <class T>
class List
{
	typedef ListNode<T> Node;
public:
	typedef ListIterator<T> Iterator;          //��������Ҫʹ�� ������Ϊpublic
private:
	Node* _head;                  //Ϊʲô���@������д��List<T>*  
	Node* _tail;
public:
	List()
		:_head(new Node(T()))        //�@�����ʾû��Ĭ�Ϲ��캯�����ã������@��Ҫ��һ���������ݣ���ס������+( )�����@�����һ����������T( )��ʾT���͵�һ����������
		,_tail(_head)
	{
		cout << "����" << endl;
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& d)   //���@�ﲻ��Ҫ����û��ͷ�ڵ�����⣬ֱ�Ӻ�������   �����ʹ�ó������ݹ�������Ҫʹ��const���Σ�const���εı�������һ������
	{
		Node* cur = _tail;
		Node* tmp = new Node(d);
		cur->_next = tmp;
		tmp->_next = _tail;
		cur->_prev = tmp;
		tmp->_prev = cur;
		_tail = tmp;
	}

	Iterator Begin()
	{
		return Iterator(_head->_next);         //  Ϊɶ�@��Ҫ�@�����أ� ����һ��Iterator����ֵ���������󣿣�
	}
	Iterator End()
	{
		return Iterator(_head);
	}
	~List()
	{
		if (_head)
		{
			cout << "����" << endl;
			Node* cur = _head;
			while (cur!=_tail)
			{
				Node* tmp = cur;
				cur = cur->_next;
				delete tmp;
			}
			delete _tail;
			_head = NULL;
			_tail = NULL;
		}
	
	}
};
template <class T>
void PrintList(List<T>& l1)
{
	List<T>::Iterator it = l1.Begin();          //�@������˵������ĸ�ֵ���������  ���ǵ���������û��д��Ϊʲô������Ϊǳ����Ҳû��Ӱ��
	while (it != l1.End())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test()
{
	List<int> l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.PushBack(5);
	PrintList(l1);
}
int main()
{
	test();
    return 0;
}