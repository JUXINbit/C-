#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<stack>
#include<queue>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode(const T& data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
	{
	}
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
private:
	Node* _root;
public:
	BinaryTree()
		:_root(NULL)
	{
	}
	BinaryTree(int* arr, size_t size, int invalid)
	{
		int index = 0;
		_root = _CreateBinaryTree(arr, size, invalid, index);
	}
	void PrevOrder()
	{
		_PrevOrder(_root);
	}
	//�ǵݹ�ǰ�����
	void PrevOrderNR()
	{
		if (_root == NULL)
			return;
		stack<Node*> _s;
		Node* cur = _root;
		while (!_s.empty() || cur)
		{
			while (cur)
			{
				_s.push(cur);
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			Node* tmp = _s.top();
			_s.pop();
			cur = tmp->_right;
		}
		cout << endl;
	}
	//�ǵݹ��������
	void InOrderNR()
	{
		if (_root == NULL)
			return;
		stack<Node*> _s;
		Node* cur = _root;
		while (cur || !_s.empty())
		{
			while (cur)
			{
				_s.push(cur);
				cur = cur->_left;
			}
			Node* tmp = _s.top();
			_s.pop();
			cout << tmp->_data << " ";
			cur = tmp->_right;
		}
	}
	//�ǵݹ�������
	void PostOrderNR()
	{
		if (root == NULL)
			return;
		stack<int> _s;
		Node* cur = _root;
		Node* prev = NULL;
		while (cur || !_s.empty())
		{
			_s.push(cur);
			cur = cur->_left;
		}
		Node* tmp = _s.top();
		if (cur->_right == NULL || cur->_right == prev)
		{
			cout << cur->_data << " ";
			prev = tmp;
			_s.pop();
		}
		cur = tmp->_right;        //������
	}
	//�������
	void LevelOrder()
	{
		if (_root == NULL)
			return;
		queue<Node* > _q;
		Node* cur = _root;
		_q.push(cur);
		while (!_q.empty())     //�@����д���ǲ���Ҫ����cur���ǿյ��Ƕ���Ϊ�յ�����ģ�����ֻ��Ҫһ�������Ϳ���
		{
			if (cur->_left)
				_q.push(cur->_left);
			if (cur->_right)
				_q.push(cur->_right);
			cout << _q.front()->_data << " ";
			_q.pop();
			if (!_q.empty())
				cur = _q.front();
		}
		cout << endl;
	}
	//��������ĸ߶�
	size_t Length()
	{
		if (_root == NULL)
			return 0;
		return _length(_root);
	}
	//��Ҷ�ӽ��ĸ���
	size_t GetLevelNode()
	{
		if (_root == NULL)
			return 0;
		return _GetLevelNode(_root);
	}

	~BinaryTree()
	{

	}
protected:
	Node* _CreateBinaryTree(int* arr,size_t size,int invalid,int& index)
	{
		Node* root = NULL;                                  //ע���ȳ�ʼ��ΪNULL;
		if (index < size&&arr[index] != invalid)
		{
			root = new Node(arr[index]);
			root->_left = _CreateBinaryTree(arr, size, invalid, ++index);        //ǰ��++
			root->_right = _CreateBinaryTree(arr, size, invalid, ++index);
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
	//��������ĸ߶�
	size_t _length(Node* root)
	{
		if (root == NULL)
			return 0;
		size_t LeftLength = _length(root->_left);
		size_t RightLength = _length(root->_right); 
		return LeftLength > RightLength ? LeftLength + 1 : RightLength + 1;
	}
	//��Ҷ�ӽ��ĸ���
	size_t _GetLevelNode(Node* root)
	{
		if (root == NULL)                                //������ȱ©ֻ������������û����������������@��������������Ӽ����������Ƿ���0
			return 0;
		if (root->_left == NULL&&root->_right == NULL)         
			return 1;
		return _GetLevelNode(root->_left) + _GetLevelNode(root->_right);
	}
};

int main()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> B1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	//B1.PrevOrder();
	//B1.PrevOrderNR();
	//B1.InOrderNR();
	//B1.LevelOrder();
	//cout << B1.Length() << endl; 
	cout << B1.GetLevelNode() << endl;
	return 0;
}
