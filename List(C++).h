
//                                 C++ ʵ������
#include<iostream>
using namespace std;


typedef int DataType;
typedef struct ListNode              //�е�������BuyNode     ��������new����һ���ڵ㲢�ҳ�ʼ��
{
	DataType _data;
	ListNode* _next;
	ListNode(DataType d)          //ListNode��һ�����캯��   ��ʼ��һ���ڵ�   ������ʹ��new��ʱ����Զ����ýڵ�Ĺ��캯��
		:_data(d)                                    //�൱��һ��new Node��d���Ͱ�C�������BuyNode�ɵ��������鶼�ɺ���  
		,_next(NULL)
	{
	}
}Node;
class List
{
private:
	Node* _head;
	Node* _tail;                   //��ʵ��C����д�����������û��_tail��β�ڵ㣩 �����@����_tail  ��ÿ�β�����ʱ��  _tailҲ��Ҫ����Ӧ�ĸ���
public:                                        //����Ŀ�ľ���Ϊ�����б�Ҫ��ʱ��ֱ����_tail�� ʡȥÿ�ζ�Ҫѭ���ҵ����һ���������һ����ǰһ��
	List()
		:_head(NULL)
		,_tail(NULL)
	{
	}
	List(const List& l)                       //���������ʱ���ڳ�ʼ���б�������г�ʼ�� ��Ȼ���������PushBack������ʱ��ͻ��
		:_head(NULL)
		, _tail(NULL)                 //����@�ﲻ��ֵΪNULL����ֱ�ӹҵ�
	{
		Node* cur = l._head;
		while (cur)
		{
			PushBack(cur->_data);         //�����ĸ���
			cur = cur->_next;
		}
		/*_head = l._head;*/                //��ԭ������ôд�� û�뵽��Ȼд����һ��ǳ���� ������д������� �����@����ô��ȷʵ��Ӧ��
		
	}

	List& operator=(const List& l)          //��ֵ���������
	{
		if (_head)
		{
			Desdroy();              //�����ĸ���  
		}
		_head = NULL;
		_tail = NULL;
		Node* cur = l._head;
		while (cur)
		{
			PushBack(cur->_data);        
			cur = cur->_next;
		}
		return *this;                    //��ֵ��������ؼǵ÷���ֵ
	}
	void PushBack(DataType d)
	{
		if (_head == NULL)
		{
			_head = new Node(d);
			_tail = _head;
		}
		else
		{
			Node* cur = _head;
			while (cur->_next != NULL)
			{
				cur = cur->_next;
			}
			cur->_next = new Node(d); 
			_tail = cur->_next;
		}
	}
	void PopBack()
	{
		if (_head == NULL)
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
			Node* cur = _head;
			while (cur->_next != _tail)
			{
				cur = cur->_next;
			}
			delete _tail;
			cur->_next = NULL;
			_tail = cur;
		}
	}
		void PushFront(DataType d)
		{                                  
			if (_head == NULL)
			{
				_head = new Node(d);
				_head = _tail;
			}
			else
			{
				Node* tmp = _head;
				_head = new Node(d);
				_head->_next = tmp;
			}
		}
		void PopFront()
		{
			if (_head)
			{

				if (_head->_next == NULL)
				{
					delete _head;
					_head = _tail = NULL;
				}
				else
				{
					Node* tmp = _head;
					_head = _head->_next;
					delete tmp;
				}
			}

		}
		Node* Find(DataType d)
		{
			if (_head == NULL)
			{
				cout << "����Ϊ��" << endl;
			}
			else
			{
				Node* cur = _head;
				while (cur != NULL)
				{
					if (cur->_data == d)
						return cur;
					cur = cur->_next;
				}
				return NULL;
			}
		}
	void Print()
	{
		Node* cur = _head;
		if (_head == NULL)
		{
			cout << "����Ϊ��" << endl;
		}
		else
		{
			while (cur != NULL)
			{
				cout << cur->_data <<" ";
				cur = cur->_next;
			}
		}
		cout << endl;
	}
	void Desdroy()                         //��պ���    ��ΪҪ������ ���԰��������ó���дһ��
	{
		if (_head->_next == NULL)
		{
			cout << "����" << endl;
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			Node* cur = _head;
			while (cur != NULL)
			{
				cout << "����" << endl;
				Node* tmp = cur;
				cur = cur->_next;
				delete tmp;
			}
		}
	}
	~List()
	{
		if (_head)
		{
			Desdroy();
		}
	}
};

	void test()
	{
		List s1;
		s1.PushBack(1);
		s1.PushBack(2);
		s1.PushBack(3);
		s1.PushBack(4);
		s1.Print();
		s1.PopBack();
		s1.Print();
		s1.PushFront(6);
		s1.PushFront(7);
		s1.PushFront(8);
		s1.PopFront();
		s1.Print();
		cout<<s1.Find(7)<<endl;         //�����ַ
		s1.Print();
		List s2(s1);
		s2.Print();
		List s3;
		s3.PushBack(1);
		s3.PushBack(1);
		s3.PushBack(1);
		s3.PushBack(1);
		s3.PushBack(1);
		s2 = s3;
		s2.Print();
	}