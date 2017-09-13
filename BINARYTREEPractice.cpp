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
	//���K��Ľ��ĸ���
	size_t GetKLevelNode(int k)
	{
		if (_root == NULL)
			return 0;
		return _GetKLevelNode(_root, k);
	}
	//�ж�һ������Ƿ���һ����������
	bool NodeInTree(Node* node)
	{
		if (_root == NULL || node == NULL)
			return false;
		return _NodeInTree(_root,node);
	}
	//�ж�һ�����Ƿ���ƽ�������
	bool IsBalance()
	{
		if (_root == NULL)
			return false;
		int LeftDep = _length(_root->_left);           //ʹ�õķ����������������ĸ߶ȣ������������ĸ߶�Ȼ����߶Ȳ
		int rightDep = _length(_root->_right);
		if (LeftDep - rightDep < 2)
			return true;
		else
			return false;
	}
	//�������ľ���
	void Mirror()
	{
		if (_root == NULL)
			return;
		_Mirror(_root);
	}
	//�ݹ鿽��һ����
	Node* CopyTree()
	{
		if (_root == NULL)
			return NULL;
		_Copy(_root);
	}

	//�ж�һ�����Ƿ�����ȫ������  :ʹ�ò������
	bool IsFullTree()
	{
		if (_root == NULL)
			return false;
		bool IsFullTree = true;
		queue<Node*> _q;
		Node* cur = _root;
		_q.push(cur);
		while (!_q.empty())
		{
			if (cur->_left)
				_q.push(cur->_left);
			else                         //��Ϊ�գ��ұض�Ϊ��
			{
				if (cur->_right)
					IsFullTree = false;
			}
			if (cur->_right)
				_q.push(cur->_right);
			else                         // ��Ϊ�գ���������һ��
			{
				while (!_q.empty())       //��Ϊ�վͽ�����һ��Ľ��ȫ���Ų�һ�飬�������Ҷ�ӽ���˵������ȫ��������
				{
					_q.pop();
					if (!_q.empty())
					{
						Node* tmp = _q.front();
						if (tmp->_left || tmp->_right)
						{
							IsFullTree = false;
							return IsFullTree;
						}
					}
				}
				IsFullTree = true;
				return IsFullTree;
			}
			_q.pop();
			if (!_q.empty())                
				cur = _q.front();        
		}
		return IsFullTree;
	}

	~BinaryTree()              //�����д�ĵݹ�Ļ���ע�����������deleteһ����  �ݹ麯�����Ѿ�delete��
	{
		_Delete(_root);
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
	//���K����ĸ���
	size_t _GetKLevelNode(Node* root,int k)
	{
		if (root == NULL)          //�����ǲ��ǵ�K���㣬ֻҪ��������NULL����������0
			return 0;
		if (k == 1)
			return 1;
		return _GetKLevelNode(root->_left, k - 1) + _GetKLevelNode(root->_right, k - 1);
	}
	//��һ������Ƿ���һ�ö�������
	bool _NodeInTree(Node* root,Node* node)
	{
		if (root == NULL)
			return false;
		if (root == node)
			return true;
		bool tmp = _NodeInTree(root->_left, node);   //��Ѱ�ҵ�֮��ͻ᷵�ص��������Ҫ��һ�ߵݹ�֮�󷵻�
		if (tmp)
			return true;
		return _Node(root->_right, node);
	}
	//�������ľ���
	void _Mirror(Node* root)
	{
		if (root == NULL)
			return;
		_Mirror(root->_left);
		_Mirror(root->_right);
		swap(root->_left, root->_right);           //����ת
	}
	//�ݹ�����һ�ö�����
	void _Delete(Node* root)
	{
		if (root == NULL)
			return;
		_Delete(root->_left);
		_Delete(root->_right);
		delete root;
		root = NULL;
	}
	//�ݹ鿽��һ����
	Node* _Copy(Node* root)
	{
		if (root == NULL)
			return NULL;
		Node* newNode = new Node(root->_data);
		newNode->_left = _Copy(root->_left);
		newNode->_left = _Copy(root->_right);
		return newNode;
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
	//cout << B1.GetLevelNode() << endl;
	//cout << B1.GetKLevelNode(3) << endl;
	//cout << B1.IsBalance() << endl;
	//B1.Mirror();
	//B1.LevelOrder();
	cout<<B1.IsFullTree();
	return 0;
}
