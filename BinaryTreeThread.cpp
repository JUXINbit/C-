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
	BinaryTreeNodeTD(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{
		cout << "������������" << endl;
	}

};
template <class T>
class BinaryTree
{
	typedef BinaryTreeNodeTD<T>  Node;
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
	void _InOrderThreading(Node* root,Node*& prev)          //���������������ձ����Ľ��  3 2 4 1 6 5  ����������  
	{                                               //�@���ǵݹ�ʵ������������ʱ�ݹ��ӡ��ʱ�� ǰ�к������cout��λ�ã��@��ͬ�����������Ĵ�����������������������
		if (root == NULL)
			return;
		_InOrderThreading(root->_left,root);
		if (root->_left == NULL)                     
		{
			root->_left = prev;      //����ָ����Ϊ�վ�ָ��ǰ�����Һ���Ϊ����ָ�����
		}
		_InOrderThreading(root->_right,root);    //����ǰ����������� ����ת������������ǰ��������������
	}

	/*void Destory(Node* root)
	{
		if (root == NULL)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;
		root = NULL;
	}*/
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
	void InOrderThreading()
	{
		Node* prev = _root;             //��prev��¼��һ���߹��Ľ��
		_InOrderThreading(_root,prev);
	}
	/*~BinaryTree()
	{
		Destory(_root);
		cout << "����" << endl;
	}*/

};

void test()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int>  b1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	b1.InOrderThreading();
}

int main()
{
	test();
	return 0;
}