#define _CRT_SECURE_NO_WARNINGS 1

//�������ķǵݹ����ѵ��
//����ջ
#include<iostream>
#include<queue>
#include<stack>
#include<assert.h>
using namespace std;

template <class T>
struct  BinaryTreeNode
{
	T  _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{
	}
};

template <class T>
class BinaryTree
{
	typedef BinaryTreeNode<T>  Node;
private:
	Node* _root;
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

	//�ǵݹ����
	//�ǵݹ�ʵ��ǰ�����
	void PrevOrderR()
	{
		stack<Node*>  _s;
		_s.push(_root);
		Node* cur = _root;
		cout << cur->_data << " ";
		while (!_s.empty() || cur != NULL)
		{
			while (cur->_left)
			{
				cur = cur->_left;
				cout << cur->_data << " ";
				_s.push(cur);
			}
			while (cur->_right == NULL)
			{
				_s.pop();
				cur = _s.top();
			}
			cur = cur->_right;
			cout << cur->_data << " ";
			_s.push(cur);
		}
	}

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
};
