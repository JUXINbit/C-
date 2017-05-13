#define _CRT_SECURE_NO_WARNINGS 1
//   ��������������
#include<iostream>
#include<queue>
#include<stack>
#include<assert.h>
using namespace std;

enum  PointerTag
{
	THREAD,             //ǰ������ָ���־
	LINK                //ָ���������ָ���־
};



template <class T>
struct  BinaryTreeNodeTD
{
	T  _data;
	BinaryTreeNodeTD<T>* _left;
	BinaryTreeNodeTD<T>* _right;
	PointerTag _leftTag;
	PointerTag _rightTag;

	BinaryTreeNodeTD(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
		, _leftTag(LINK)
		, _rightTag(LINK)
	{
		cout << "������������" << endl;
	}

};

template<class T>
struct Iterator               //���������                                          [*]
{
	typedef BinaryTreeNodeTD<T> Node;
	Node* _node;
	Iterator(Node* node)
		:_node(node)
	{
		cout << "����һ������������" << endl;
	}
	T& operator*()     //�����������޸�����
	{
		return _node->_data;
	}
	T* operator->()
	{
		return &_node->_data;
	}
	Iterator<T> operator++()
	{
		if (_node->_rightTag = THREAD)
		{
			_node = _node->_right;
		}
		else
		{
			Node* left = _node->_right;
			while (left && left->_leftTag == LINK)
			{
				left = left->_left;
			}
			_node = left;
		}
		return *this;
	}
	bool operator !=(Iterator<T>& it1)
	{
		return  _node != it1._node;
	}

};
template <class T>
class BinaryTree
{
	typedef BinaryTreeNodeTD<T>  Node;
public:
	typedef Iterator<T> Iterator;
private:
	Node* _root;
protected:
	Node* _CreatrTree(T* a, size_t n, const T& invalid, size_t& index)
	{
		Node* root = NULL;
		if (index < n && a[index] != invalid)                   //������
		{
			root = new Node(a[index]);
			root->_left = _CreatrTree(a, n, invalid, ++index);
			root->_right = _CreatrTree(a, n, invalid, ++index);
		}
		return root;                                         //��������
	}

	void _PrevOrder(Node* cur)       //�ݹ�ǰ�����
	{
		if (cur == NULL)
			return;                             //һ��ע�ⷵ������  �����д����������ջ���
		cout << cur->_data << " ";
		if (cur->_leftTag == LINK)
		{
			_PrevOrder(cur->_left);
		}
		if (cur->_rightTag == LINK)
		{
			_PrevOrder(cur->_right);
		}
	}

	void _InOrderThreading(Node* cur,Node*& prev)          //���������������ձ����Ľ��  3 2 4 1 6 5  ����������  
	{                                               //�@���ǵݹ�ʵ������������ʱ�ݹ��ӡ��ʱ�� ǰ�к������cout��λ�ã��@��ͬ�����������Ĵ�����������������������
		if (cur == NULL)
			return;
		_InOrderThreading(cur->_left,prev);
		if (cur->_left == NULL)             //  �ҵ������㣬����ǰ��                
		{
			cur->_left = prev;             // prev��ʲôʱ�򴴽��أ�����  ����������˵  ��һ�������Ľ���ǰ��ΪNULL
			cur->_leftTag = THREAD;
		}
		if (prev && prev->_right == NULL)    //���������ӱȽ����⣬����Ҫcur�Ѿ�����һ����������£��ٴ�����һ������ǰ��
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}                  //���@���һ���ڵ����������� �����Խ�prev����һ������ƶ���
		prev = cur; 
		_InOrderThreading(cur->_right,prev);    //������
	}


	void _PrevOrderThreading(Node* cur, Node*& prev)     //ǰ��������
	{
		if (cur == NULL)
			return;
		if (cur->_left == NULL)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}
		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}

		prev = cur;
		if (cur->_leftTag == LINK)    //�ҵ����⣺Ϊʲô��������֮��Ͳ����ٵݹ���ȥ�ˣ� ��ѭ��
		{
		    _PrevOrderThreading(cur->_left, prev);    //��дһ���@��������жϻᷢ�ֻ�������ѭ��  ջ���
		}

		if (cur->_rightTag == LINK)               //Ϊʲô������������ʱ��û��������ѭ�������⣿ ��Ϊ�������û�й���Ȧ,һֱ��������
		{
		    _PrevOrderThreading(cur->_right, prev);
		}

	}
	

	void Destory(Node* root)       //ע���ͷſռ����ʽ
	{
		if (root == NULL)
			return;
		if (root->_leftTag == LINK)
		{
			Destory(root->_left);
		}
		
		if (root->_rightTag == LINK)
		{
			Destory(root->_right);
		}
		delete root;
		root = NULL;
	}

public:
	BinaryTree()
		:_root(NULL)
	{
		cout << "�޲ι���" << endl;
	}

	BinaryTree(T* a, size_t n, const T& invalid)
	{
		size_t index = 0;
		_root = _CreatrTree(a, n, invalid, index);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
	}

	void InOrderThreading()
	{
		Node* prev =NULL;             //��prev��¼��һ���߹��Ľ��
		_InOrderThreading(_root,prev);
		if (prev)
			prev->_rightTag = THREAD;            //����������
	}

	void PrevOrderThreading()
	{
		Node* prev = _root;
		_PrevOrderThreading(_root, prev);
	}



	void InOrderThd()      //�ǵݹ��������
	{
		Node* cur = _root;
		while (cur)              //cur�϶���Ϊ�� �Ѿ���������֮��� �յĽ��ָ�붼�������ˣ�ע�⣺���һ�����ʵĽ�����Ϊ�գ�
		{
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";

			while (cur->_rightTag == THREAD)        //�@����ǽ����������ĺ��� ֱ������  ���Բ���������ջ���ظ����
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}

		    cur = cur->_right;
	   }
		cout << endl;
	}

	void PrevOrderThd()           //�ǵݹ�ǰ�����   ��ס��������֮��������һ�������ҽڵ�ָ�룬�����Ľ��ָ�붼��Ϊ�� Ҫô��ָ������Ҫô��ָ��ñ�����ʽ����һ�����
	{                                                                    //��ôLINK ��THREAD�Ϳ���������־�ֿ�Ϊ������� ���������������ս������ȥ
		Node* cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
				cur = cur->_right;             //������
		}
		cout << endl;
	
	}


	Iterator Begin()          //�@���Ǵ��  Ӧ���������� ����Ҫѭ���ҵ�
	{
		Iterator itb(_root);
		return itb;
	}
	Iterator End()
	{
		Iterator enit(NULL);    //���һ�����ǿ�
		return enit;
	}

	~BinaryTree()
	{
		Destory(_root);
		cout << "����" << endl;
	}

};

//�������������������������õ��������ʡ���������������������������������������������������������������������������������������������������
template<class T>
void PrintBinaryTree(BinaryTree<T>& b1)        //ע���ӡ����������д��������һЩ���⣬iteratorҪ���У���ӡ����Ҫ����Ķ���
{
	BinaryTree<T>::Iterator it = b1.Begin();
	while (it != b1.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}
//��������������������������������������������������������������������������������������������������������������������������������
void test()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int>  b1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	//b1.InOrderThreading();
	//b1.InOrderThd();
	b1.PrevOrderThreading();
	b1.PrevOrderThd();
	b1.PrevOrder();
	PrintBinaryTree(b1);
}

int main()
{
	test();
	return 0;
}


int main()
{
	
	int a = 1;
	int b = 1;
	int c = 1;
	int i = 0;
	int n = 20;
	for (i = 2; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	printf("%d\n", c);
	return 0;
}