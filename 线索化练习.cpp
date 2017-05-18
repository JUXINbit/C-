#define _CRT_SECURE_NO_WARNINGS 1

   // ���������������Լ��������ǵݹ飩��ϰ
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;


enum PointerType
{
	THREAD,
	LINK
};

template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	PointerType  _leftype;
	PointerType  _rightype;

	BinaryTreeNode(const T& d)
		: _data(d)
		, _left(NULL)
		, _right(NULL)
		, _leftype(LINK)
		, _rightype(LINK)
	{
		cout << "������������"<<endl;
	}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
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

	void _BinaryTreeThreading(Node* cur, Node*& prev)   //����������  (�ݹ�)        //��ϰ��ʱ�������˼�������  &  ���´���  !!!
	{
		if (cur == NULL)
			return;
		_BinaryTreeThreading(cur->_left, prev);
		if (cur->_left == NULL)
		{
			cur->_left = prev;             //һֱ������ߵĽ�㣬  prev�ſ�ʼ������  ֮ǰһֱ����NULL
			cur->_leftype = THREAD;
		}
		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightype = THREAD;
		}
		prev = cur;
		_BinaryTreeThreading(cur->_right, prev);     //������
	}

	void _PrevThreading(Node* cur, Node* & prev)   //ǰ��������
	{
		if (cur == NULL)
			return;
		if (cur->_left == NULL)
		{
			cur->_left = prev;
			cur->_leftype = THREAD;      //��סҪ���
		}
		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightype = THREAD;
		}
		prev = cur;

		if (cur->_leftype == LINK)               //��������Ŀ�ľ���������ָ��Ȼ��������  ���������ߵĻ����Ǹ��������⣬Ϊ�˱�������ݹ飬�@����Ҫ�жϣ��ܿ���THREAD��ǵĽ��
		{
			_PrevThreading(cur->_left, prev);
		}
		if (cur->_rightype == LINK)           
		{
			_PrevThreading(cur->_right, prev);
		}
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

	void BinaryTreeThreading()       //����������                 ��ע�⣺���ܼ�ǰ����������������������
	{
		Node* prev = NULL;
		_BinaryTreeThreading(_root,prev);
	}
	void BinaryTreeThd()            //����ǵݹ����
	{
		Node* cur = _root;               //���ڷǵݹ�  1.������Ҫ��һ�����ָ��curָ��ǰ��㣬��ѭ������ݹ� 
		while (cur)                   //��curΪ��ʱ  �������еı���  �������еķǵݹ� ��ѭ���Ŀ�ʼ���Ƿ��ʽ��Ŀ�ʼ
		{
			while (cur->_leftype == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			
			while (cur->_rightype == THREAD)    //ΪʲôҪ��while��  ����������Ļ���  �ͻ����  ��һ��������ָ��һֱ���������������ĸ���㴦
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			//(if (cur->_right==LINK))
			cur = cur->_right;                         //   �ǵݹ�Ҳ��Ҫ�ܿ�����������
		}
	}

	void PrevThreading()    //ǰ��������
	{
		Node* prev = _root;
		_PrevThreading(_root, prev);
	}

	void PrevThd()    //ǰ��ǵݹ����
	{
		Node* cur = _root;
		while (cur)
		{
			while (cur->_leftype == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightype == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;                   //Ҫ֪���@һ�������   ������
		}
	
	}

};



void test()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int>  b1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	//b1.BinaryTreeThreading();
	//b1.BinaryTreeThd();
	b1.PrevThreading();
	b1.PrevThd();
}
int main()
{
	test();
	return 0;
}