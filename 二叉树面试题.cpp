#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<assert.h>

using namespace std;

template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{
		cout << "������������" << endl;
	}
};


//�ݹ齨��һ��������
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
private:
	Node* _root;
protected:
	Node* _CreateTree(T* a, size_t n, const T& invalid, size_t& index)  //�@���index�ɵ����@���������Ǹ�����������������������@����������⣬������Ϊջ֡��ԭ���������ڵ�ص�ʱ��index��ֵҲ�᷵�أ��@��Ľ���취�ǣ�  &
	{
		//index = 0;  //ע�⣺�@��ǧ���ܸ��±�һ����ֵ���ݹ���������
		Node* root = NULL;
		if (index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, n, invalid, ++index);    //���ֵ����⣺  ��һ��ʼд����index++�����ǳ���������ѭ����ע�ⴴ�����µ�ջ֡�ͻ�����µ�index
			root->_right = _CreateTree(a, n, invalid, ++index);
		}
		return root;
	}
	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _MirrorTree(Node* root)
	{
		if (root == NULL)
			return;
		swap(root->_left, root->_right);    //������������������
		_MirrorTree(root->_left);
		_MirrorTree(root->_right);
	}
	//�������Ĳ��ң�������ô��д  ʱ�临�Ӷȣ�o��N*N��
	bool _FindParent(Node* root, Node* _node)
	{
		if (root == NULL)
			return false;
		if (root->_data == _node->_data)
			return true;
		bool tmp = _FindParent(root->_left, _node);
		if (tmp == true)
			return true;
		_FindParent(root->_right, _node);
	}

public:
	BinaryTree()                                             //�޲ι��캯��
		: _root(NULL)
	{
	}
	BinaryTree(T* a, size_t n, const T& invalid)                 //���εĹ��캯��      //ע�⣺�޲εĵݹ��ǲ���д�ڹ��еĳ�Ա�������������Ϊʲô��
	{
		size_t index = 0;                                     //ע���@��Ϊʲô���ǰ�index�����ó�������ʼ��0
		_root = _CreateTree(a, n, invalid, index);
	}
	//�������
	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}
	//��Ŀһ�� �������ľ���
	void MirrorTree()
	{
		_MirrorTree(_root);
	}
	//�ҹ��������Ƚڵ� 
	//����һ��   ʹ����������
	//ʱ�临�Ӷ�o��N*N��
	Node*  FindParent(Node* node1, Node* node2)
	{
		assert(node1);
		assert(node2);
		vector<Node*> _arr1;
		vector<Node*> _arr2;
		while (node1 != _root)
		{
			_arr1.push_back(node1);
			node1 = node1->parent;
		}
		_arr1.pop_back(_root);        //�����@��д��ѭ����������Ҫ���_root��������
		while (node2 != _root)
		{
			_arr2.push_back(node2);
			node2 = node2->parent;
		}
		_arr2.pop_back(_root);
		for (size_t i = 0; i < _arr1.size(); i++)
		{
			for (size_t j = 0; j < _arr2.size(); j++)
			{
				if (_arr1[j] = _arr2[i]);
				return _arr[j];
			}
		}
		cout << "���Ҵ���" << endl;
		return NULL;
	}

	//��������
	//����  
	//ʱ�临�Ӷȣ�������o��N*N*N��
	Node* FindParent2(Node* _node1, Node* _node2)
	{
		assert(_node1);
		assert(_node2);
		while (_node1 != NULL)
		{
			bool tmp = _FindParent(_node1, _node2);
			if (tmp == true)
				return _node1;
			_node1 = _node1->parent;
		}
		return NULL;
	}
};
//���������������������
Node* _FindParent(Node* root, Node* node1, Node* node2)
{
	if (root == NULL)
		return;
	if ()
}
Node FindPublicParent(Node* node1, Node* node2)
{
	assert(node1);
	assert(node2);
	return _FindParent(_root, node1, node2);
}


int main()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	t1.PrevOrder();
	t1.MirrorTree();
	t1.PrevOrder();
	return 0;
}
