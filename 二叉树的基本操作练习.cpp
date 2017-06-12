#define _CRT_SECURE_NO_WARNINGS 1


//ʹ�õݹ�ʵ�ֶ������Ĺ���  ���ֱ�����ʽ�͸��ֲ���
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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
	
	}
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T>  Node;
private:
	Node* _root;
public:
	BinaryTree()                                    //�޲ι���
		:_root(NULL)
	{
	}
	BinaryTree(T*a, size_t n,const T& invalid)         //���ι���
	{
		size_t index = 0;
		_root = _BinaryTree(a, n, invalid, index);
	}
	BinaryTree(const BinaryTree<T>& b)                  //��������
	{
		_root = _Copy(b._root);
    }
	BinaryTree<T>& operator=(const BinaryTree<T>& b)      //��ֵ�����������
	{
		if (_root)
			_Destroy(_root);
		_root = NULL;
		_root = _Copy(b._root);
		return *this;
	}
	void PrevOrder()                                 //ǰ�����
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()                                  //�������
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()                                //�������
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()                               //�������   ��������   �ǵݹ�
	{
		Node* cur = _root;
		if (_root == NULL)
			return;
		queue<Node*> q1;                            //ע���@��ģ��T��ʲô  ��һ��ʼʹ����T 
		q1.push(cur);
		while (!q1.empty() && cur)                   //cur��=NULL
		{
			q1.push(cur->_left);
			q1.push(cur->_right);
			cout << (q1.front())->_data << " ";
			q1.pop();
			cur = q1.front();
		}
		cout << endl;
	}
	size_t Size()                 //�������
	{
		return _Size(_root);
	}
	size_t LeafSize()             //��Ҷ�ӽ�����
	{
		return _LeafSize(_root);
	}
	size_t KLevelSize(const size_t& K)                //��K���Ҷ�ӽ����
	{
		return _KLevelSize(_root,K);
	}

	size_t Depth()                           //���������   [*]
	{
		return _Depth(_root);
	}
	Node* Find(const T& d)                    //����
	{
		return _Find(_root, d);
	}

	Node*  Copy()                          //[*]   ������
	{
		return _Copy(_root);
	}
	~BinaryTree()
	{
		Destory(_root);
		_root = NULL;
		cout << "����" << endl;
	}
protected:
	Node* _BinaryTree(T* a, size_t n, const T& invalid, size_t& index)                  //����������ã���ջ֡���ٷ��ص�ʱ��ͻ��������
	{
		Node* root = NULL;                      //�����                ���������ǰ��ݹ鹹��
		if (index < n&&a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left=_BinaryTree(a, n, invalid, ++index);
			root->_right=_BinaryTree(a, n, invalid, ++index);
		}
		return root;                      //��������
	}
	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root) 
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}
	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}
	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;                  //��������
		else
			return _Size(root->_left) + _Size(root->_right) + 1;
	}
	size_t _LeafSize(Node* root)
	{
		if (root == NULL)              //ע���@������  ��ϰ��ʱ��д���ˣ��@�������ֻ��һ���ǿյ�ʱ��
			return 0;
		if (root->_left == NULL&&root->_right == NULL)
			return 1;
		else
			return _LeafSize(root->_left) + _LeafSize(root->_right);
	}
	size_t _KLevelSize(Node* root,const size_t& K)    //  �@���տ�ʼ����    [*]
	{
		if (root == NULL)
			return 0;
		if (K == 1)
			return 1;
		if (K > 1)
			return _KLevelSize(root->_left, K - 1) + _KLevelSize(root->_right, K - 1);    
		else
			perror("K is wrong!");
	}
	size_t _Depth(Node* root)                             //�@�������벻��������д
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL&&root->_right == NULL)
			return 1;
		size_t leftDepth = _Depth(root->_left);
		size_t rightDepth = _Depth(root->_right);
		return leftDepth > rightDepth?  leftDepth + 1: rightDepth+1;        //��1�Ǽ��ϸ����     
	}
	Node* _Find(Node* root, const T& d)                     //����[*]   �@��Ĳ��Һͺ���������������Ĳ���������ͬ
	{
		if (root == NULL)
			return NULL;
		if (root->_data == d)
			return root;
		/*else                            //�@��д������
		{
			_Find(root->_left,d);
			_Find(root->_right, d);
		}*/
		Node* tmp = _Find(root->_left,d);
		if (tmp != NULL)                        //ע���@���жϷŵ�λ��
			return tmp;
		_Find(root->_right, d);
	}
	void Destory(Node* root)              //[*]
	{
		if (root == NULL)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;                  //ע���@���deleteһ��Ҫ�������  �൱�ں�����������Ϊ������������������Ҳ�����û�취������
	}

	Node* _Copy(Node* root)
	{
		Node* newroot = NULL;
		if (root == NULL)
			return NULL;
		newroot = new Node(root->_data);
		newroot->_left = _Copy(root->_left);
		newroot->_right = _Copy(root->_right);
		return newroot;
	}

};



// ����
void test()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int brr[] = { 2, 1, 3, '#', '#', 5, '#', '#', 7, 6, '#', 8 };
	BinaryTree<int> b1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	b1.PrevOrder();
	b1.InOrder();
	b1.PostOrder();
	b1.LevelOrder();
	cout<<b1.Size()<<endl;
	cout << b1.LeafSize() << endl;
	cout << b1.KLevelSize(3) << endl;
	cout << b1.Depth() << endl;
	cout << b1.Find(3) << endl;

	BinaryTree<int>  b2(b1);
	b2.InOrder();
	b2.LeafSize();
	b2.PrevOrder();

	BinaryTree<int> b3(brr, sizeof(brr) / sizeof(brr[0]),'#');
	b3.InOrder();

	b3 = b1;
	b3.InOrder();
}
int main()
{
	test();
	return 0;
}