#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

struct AA              //����һ��AA����
{
	int a;
	int b;
};

template<class T>
struct NodeList
{
	T _data;
	NodeList<T>* _next;
	NodeList<T>* _prev;
	NodeList(const T& a)     //Ϊʲô�@�ﲻ��const���Ǵ��   ��ס�������г����� Ȩ�޷Ŵ���Σ�յ�
		:_data(a)          //[*]
		,_next(NULL)
		,_prev(NULL)
	{
		cout << "������" << endl;
	}

};

//      ������
template<class T,class ref,class ptr>
struct ListIterator                      //��������Ŀ�ľ��Ǳ������� û�б�Ҫд��������������������Ҳ�����ˣ� Ҳû��д��ֵ������Ϳ������죬��ʱ����ô����
{
	typedef NodeList<T> Node;
	Node* _node;
	ListIterator(Node* node)
		:_node(node)
	{
		cout << "����һ��������" << endl;
	}
	ref operator*()
	{   
		return _node->_data;         //�����������@��������Ȼ���� ���Է�������
	}
	ptr operator->()
	{
		return &_node->_data;
	}
	ListIterator<T,ref,ptr>& operator++()    //ע�⣺�@����ǰ��++
	{
		_node = _node->_next;
		return *this;
	}
	ListIterator<T, ref, ptr> operator++(int)      //����++           ���⣺��Ȼ֪���@���һ����int����Ϊ������ǰ�úͺ��� �����Ƕ�����ô֪���õ�����һ����
	{
		ListIterator<T, ref, ptr> tmp = (*this);
		_node = _node->_next;
		return tmp;                              //   ע�ⲻ�ܷ�����ʱ����������  
	}
	bool operator!=(const ListIterator<T,ref,ptr>& l1)
	{
		return this->_node != l1._node;
	}

};


// ����
template<class T>
class List
{
	typedef NodeList<T> Node;
private:
	Node* _head;
public:
	typedef ListIterator<T, T&, T*> Iterator;
	typedef ListIterator<T,const T&,const T*> ConstIterator;        //�����������const �һ��ǲ�̫����
public:
	List()
		:_head(new Node(T()))           //���ڹ�����������
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(const T& d=T())
	{
		Node* tmp = new Node(d);
		Node* cur = _head->_prev;
		cur->_next = tmp;
		tmp->_next = _head;
		tmp->_prev = cur;
	   _head->_prev = tmp;
	}
	void PopBack()
	{
		/*if (_head->_next = _head)
		{
			cout << "û����Ч�ڵ�" << endl;
			return;
		}
		else
		{
			Node* tail = _head->_prev;     //�@����PopBack������
			Node* tmp = tail->_prev;
			tmp->_next = _head;
			_head->_prev = tmp;
			delete tail;  
			tail = NULL;  
		}*/
		Node* tail = _head->_prev;
		Node* prev = tail->_prev;

		delete tail;

		prev->_next = _head;
		_head->_prev = prev; 
	}
	Iterator Find(const T& d)        //ͨ��������������
	{
		Iterator it = Begin();
		while (it != End())
		{
			if ((*it) == d)
				return it;
			it++;
		}
		return End();
	}

	//���λ�õĲ����ɾ��

	void Insert(Iterator pos, const T& d)     //ע�⣺������Ĳ�����Ҫ�����ǲ�����ͷ�ڵ������  ��ʵ����Ҫ����Ϊ�@��һ��˫��ѭ������������Ҫ������ô��
	{
		assert(pos._node)   //ע����Ե�ʹ��
		{
		     
		}
	
	}
	ConstIterator Begin() const
	{
		ConstIterator Bit(_head->_next);                  //�����Ǳ�����Ч�ڵ�   �Ǵӵڶ�����ʼ��
		return Bit;
	}
	Iterator Begin()
	{
		Iterator Bit(_head->_next);                    
		return Bit;
	}
	ConstIterator End() const      //const���εĳ�Ա���������Ա�const�������
	{
		ConstIterator Eit(_head);
		return Eit;
	}
	Iterator End()
	{
		Iterator Eit(_head);
		return Eit;
	}
	void Destory()      
	{
		Iterator it = Begin();
		while (it != End())
		{
			cout << "�������" << endl;
			Node* tmp = it._node;
			it++;
			delete tmp;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		Destory();
		_head = NULL;
	}
};



//   ��ӡ   ע�⣺�����������壺1.���úܶ�������ʹ�õ�������ʹ��ͬ���ķ�ʽ�������޸����� 2.�ܹ��������ӡ����
template <class T>
void PrintList(List<T>& l1)
{
	List<T>::Iterator  it = l1.Begin();   //ע��㣺�@���l1�Ƿ�const���εĶ��� ��const������Ե��� const��Ա����   
	while (it != l1.End())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

//template <class T>
//void PrintList(const List<T>& l1)
//{
//	List<T>::ConstIterator  it = l1.Begin();  //const���εĶ���ֻ�ܵ���const��Ա�������в�����������������ûдconst���ε�Begin()��ʱ�������û��ͨ����
//	while (it != l1.End())                  //const���εĶ���ʵ�����ǲ�ϣ�����������޸ģ�����ʵ�����@�������õ������ӿڲ���Գ�Ա�������в�����������ֻ�е�����������Ϊ�˴ﵽ����ʹ��std::list�ĵ�����������Ч����
//	{                                      //���Ǳ�������дһ��const���������Ե�������������ݽ���constԼ���������մﵽĿ�ģ����Խ�������������Ϊʲô���Զ���ĵ�������ģ������б���Ҫ�������������ˣ�ʵ������Ϊ�˸��ã�
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}





//--------------------------------------------------����------------------------------------------------
void test()
{
	
	//int a = 10;
	//const char& b = a;   //��ʱ�������г��ԣ��������ʱ�����;ֲ�����������,�������ֵ��ʱ��ʵ�����Ǹ���ʱ����ֻ�Ǵ�ֵ ��������Ҫ����һ�����г����Եı�����ʱ����Ҫע���Ƿ����const

	
	//const int& b = 1;      //���г����Ե�������Ҫ��ֵ�����г����Ե���
	



	List<int> l1;
	int a = 1;
	l1.PushBack(a);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	PrintList(l1);
	List<AA> l2;
	l2.PushBack(AA());
	l2.PushBack(AA());
	l2.PushBack(AA());
	l2.PushBack(AA());
	//PrintList(l2);
	List<AA>::Iterator it = l2.Begin();               //�@���it��ָ��AA�ṹ���ָ��
	while (it != l2.End())
	{
		it->a = 1;
		cout << it->b << " ";                //�����Զ������͵�ʱ���->���ؿ����õ�����ָ����ʽ���ڵĽṹ�����ݡ�
		it++;
	}
	List<string> l3;
	l3.PushBack("aa");                   //���������  ����ȱʡ����   string���ù��캯�� ��ʼ���ַ���Ϊ��  ""
	l3.PushBack("bb");
	l3.PushBack("cc");
	l3.PushBack("dd");
	l3.PushBack("ee");
	PrintList(l3);
	l3.PopBack();
	PrintList(l3);
	List<string>::Iterator pos = l3.Find("cc");
	List<string>::Iterator bit = l3.Begin();
	//cout << *pos << endl;
	//cout << pos - bit << endl;   //�@������������ָ������õ�Ԫ�ظ���  ��������-��
	
}
int  main()
{
	test();
	return 0;
}