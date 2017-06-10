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
	~BinaryTree()
	{
		_Destory(_root);
		cout << "����" << endl;
	}

	void PrevOrderNR()                      //ǰ�����
	{
		stack<Node*> s1;
		if (_root == NULL)
			return;
		Node* cur = _root;
		while (cur || !s1.empty())
		{
			while (cur)
			{
				s1.push(cur);
				cout << cur->_data << " ";
				cur = cur->_left;
			}

			Node* tmp = s1.top();                   //��ϰ��ʱ������@�����Ӧ�ö���һ����������ջ����ֵ  ÿ��ѭ�������һ��
			s1.pop();

			cur = tmp->_right;
		}
		cout << endl;
	}

	void InOrderNR()                      //�������
	{
		stack<Node*> s1;
		if (_root == NULL)
			return;
		Node* cur = _root;
		while (cur || !s1.empty())
		{
			while (cur)
			{
				s1.push(cur);
				cur = cur->_left;
			}

			Node* tmp = s1.top(); 
			cout << tmp->_data << " ";
			s1.pop();

			cur = tmp->_right;                 //��ת���ұ߽��
		}
		cout << endl;
	}

	void PostOrder()                           //[*]  ����  
	{
		stack<Node*>  s1;
		Node* cur = _root;
		Node* prev = NULL;
		while (cur||!s1.empty())    
		{
			while (cur)
			{
				s1.push(cur);
				cur = cur->_left;
			}
			Node* tmp = s1.top();

			//���ջ���Ĳ���
			if (tmp->_right == NULL || tmp->_right == prev)
			{
				cout << tmp->_data << " ";
				prev = tmp;
				s1.pop();
			}
			else
				cur = tmp->_right;
		}
		cout << endl;
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
	void _Destory(Node* root)
	{
		if (root == NULL)
			return;
		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
		root = NULL;
	}

};
void test()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int>  b1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	b1.PrevOrderNR();
	b1.InOrderNR();
	b1.PostOrder();
}
int main()
{
	test();
	return 0;
}


