#define _CRT_SECURE_NO_WARNINGS 1


//��������к�Ϊĳһֵ��·��
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
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
	void PrintList()
	{
		_PrintList(_root);
		cout << endl;
	}


	void FindPath(const size_t targe)
	{
		vector<T> _a;
		size_t sum = 0;
		_FindPath(_a, _root, targe, sum);
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
	void _PrintList(Node* root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_PrintList(root->_left);
		_PrintList(root->_right);
	}

	//��ӡ�洢·��������  ���⣺ Ϊʲô���ǲ�ʵ��ջ�أ� 
	//ʵ��������ĿҪ��������Ҫ��ӡ����·���������ջ�Ļ��������ӡ
	void PrintVector(vector<T> a)
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	//Ѱ�Ҳ��Ҵ�ӡ·��
	void _FindPath(vector<T>& a, Node* root, const size_t targe, size_t sum)
	{
		//��������: ��Ҷ�ӽ���ҵ�ǰ���ֵ��ܺ͵���Ŀ����
		if (root == NULL)
		{
			if (targe == sum)
				PrintVector(a);
			return;
		}
		//û��Ҷ�ӽ��
		a.push_back(root->_data);
		sum += root->_data;
		//�ݹ�����
		_FindPath(a, root->_left, targe, sum);
		_FindPath(a, root->_right, targe, sum);
		a.pop_back();
	}
};
void test()
{
	int arr[] = { 10, 5, 4, '#', '#', 7, '#', '#', 12, '#', '#' };
	BinaryTree<int> t1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	t1.PrintList();
	t1.FindPath(22);
}
int main()
{
	test();
	return 0;
}

