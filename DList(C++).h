

//C++  ʵ��˫������   ��д��ʱ�������ʦ�Ľ���   �Ժ��ڶ�������в�����ʱ��ඨ��һЩ�ڵ�ָ��  �@���߼������׻���  Ҳ�����״�
//   ��������������û�����һЩ����  
#include<iostream>
#include<assert.h>
using namespace std;

typedef int DataType;
typedef struct DListNode       
{
	DataType _data;
	DListNode* _next;                  //ǰ��ָ��                 
	DListNode* _prev;                  //����ָ��
	DListNode(DataType d)               //�ڵ㹹�캯��
		: _data(d)
		, _next(NULL)
		, _prev(NULL)
	{  
	}   
}Node;
class DList
{
private:
	Node* _head;
	Node* _tail;
public:
	DList()
		: _head(NULL)    
		, _tail(NULL)   
	{
	}
	DList(const DList& s)      //��������
		:_head(NULL)
		,_tail(NULL)
	{
		Node* cur = s._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	DList& operator=(const DList& s)           //��������        ǧ��Ҫ���˷���ֵ  ��ÿ��д���������˷���ֵ
	{
		if (_head == NULL)
		{
			Node* cur = s._head;
			while (cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		else
		{
			Clear();
			_head = NULL;
			_tail = NULL;
			Node* cur = s._head;
			while (cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		return *this;
	}
	void PushBack(DataType d)
	{
		if (_head == NULL)
		{
			_head = new Node(d);
			_tail=_head;
		}
		else
		{
			_tail->_next = new Node(d);
			_tail->_next->_prev = _tail;
			_tail = _tail->_next;
		}
	}

	void PopBack()
	{
		if (_head == NULL)
		{
			cout << "����Ϊ��" << endl;
			return;
		}
		else if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node* tmp = _tail;
			_tail->_prev->_next = NULL;    //���������@�з���д  ��Ϊ�@���Ļ���Ҫ�ж�_tail->_prevΪ��Ϊ�� ����Ҳ��Ҫ�ж��ǲ���Ϊ�� 
			_tail = _tail->_prev;                 //���Կ��Զ�������ָ��ָ������Ҫ�����Ķ���   Ȼ�����@����ָ����в���  �������
			delete tmp; 
		}

	}
	void PushFront(DataType d)
	{
		if (_head == NULL)
		{
			_head = new Node(d);
			_tail = _head;
		}
		else
		{
			Node* str = new Node(d);      //�@�����ڲ�����ʱ���Ҷ���������ָ��ָ����Ҫ�������������� 
			Node* ptr = _head;                //�@����������ǳ�����   ����Ҫһ��һ���� �������׳���
			_head = str;
			str->_next = ptr;
			ptr->_prev = str;
		}
	
	}
	void PopFront()
	{
		if (_head == NULL)
		{
			cout << "����Ϊ��" << endl;
			return;
		}
		else if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node* str = _head;
			Node* ptr = _head->_next;     //Ҫ������������ָ�����ס  �򵥿�ݲ�����
			_head = ptr;
			ptr->_prev = NULL;
			delete str;
		}
	}
	void Insert(Node* pos, DataType d)      //�����Ǻ���ѧ�����ݽṹSTL�� ��posλ�ò��붼��ָ����POSǰ����
	{
		assert(pos);
		if (pos == _head)
		{
			PushFront(d);
		}
		else
		{
			Node* ptr = pos;
			Node* str = pos->_prev;
			Node* NewNode = new Node(d);
			str->_next = NewNode;
			NewNode->_next = ptr;
			NewNode->_prev = str;
			ptr->_prev = NewNode;
		}
	
	}

	void Reverse()                    //��������
	{
		/*Node* cur = _head;               //�տ�ʼдǰ��ָ��ͺ���ָ�뽻���ķ���д����  
		while (cur)                         //���������@�ַ���
		{
			Node* tmp = cur;
			swap(_head,_tail);
			cur = cur->_prev;
		}*/
		Node* n1 = _head;                       //�@�ַ�ʽ��ȫ�ǰ����ݵ������Ž�ȥ 
		Node* n2 = _tail;
		while (!(((n1==n2)||(n1->_next==n2))))
		{
			swap(n1->_data, n2->_data);             //swap������std�⺯�� 
			n1 = n1->_next;
			n2 = n2->_prev;                    
		}
	}
	Node* Find(DataType d)
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
	void Print()
	{
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
	void Clear()
	{
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
			cout << "����" << endl;
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
			_head = NULL;
			_tail = NULL;
		}
	}
	void Erase(Node* pos)
	{
		assert(pos);
		if (_head == NULL)
		{
			cout << "����Ϊ��" << endl;
		}
		else if (pos == _head)
		{
			PopFront();
		}
	    else if (pos == _tail)
		{
			PopBack();  
		}
		else
		{
			Node* ptr = pos->_next;
			Node* str = pos->_prev;
			ptr->_prev = str;
			str->_next = ptr;
		}
	}
	~DList()
	{
		if (_head)
		{
			Clear();
		}
	
	}


};
void test()
{
	DList d1;
	d1.PushBack(1);
	d1.PushBack(2);
	d1.PushBack(3);
	d1.PushBack(4);
	d1.PushBack(5);
	d1.Print();
	d1.PopBack();
	d1.Print();
	d1.PushFront(0);
	d1.Print();
	d1.PopFront();
	d1.Print();
	d1.Insert(d1.Find(4), 8);     //��4ǰ�����8
	d1.Print();
	d1.Reverse();
	d1.Print();
	d1.Erase(d1.Find(2));
	d1.Print();
	DList d2(d1);
	d2.Print();
	DList d3;
	d3 = d2;
	d3.Print();
}