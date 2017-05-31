#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

//�ǵݹ�ʵ�ֵ�AVL�� 

template<class K, class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	int _baf;                         //ƽ������
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode(const K& key, const V& value)
		:_key(key)
		,_value(value)
		,_baf(0)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{
		cout << "����AVL���" << endl;
	}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
private:  
	Node* _root;
public:
	AVLTree()
		:_root(NULL)
	{
	}
	//����
	bool Insert(const K& key, const V& value)
	{
		//����λ�ý��в���
		//����ƽ�����ӽ��е���
		//��ת����֮�󣬽�parent������������
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}

		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key>cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		if (key < parent->_key)                //����
		{
			Node* avlnode = new Node(key, value);
			parent->_left = avlnode;
			avlnode->_parent = parent;
			cur = avlnode;
			(parent->_baf)--;
		}
		else if (key>parent->_key)             //����
		{
			Node* avlnode = new Node(key, value);
			parent->_right = avlnode;
			avlnode->_parent = parent;
			cur = avlnode;
			(parent->_baf)++;
		}

		//�����жϲ��ҵ���ƽ������
		while (parent)               //�ж���������
		{
			//parentΪ��ǰ�����
			Node* pParent = parent->_parent;

			if (parent->_baf == 0)      //�@�����һ��СС������
			{
				break;
			}

			else if (parent->_baf == 1 || parent->_baf == -1)   //���ϵ���
			{
				if (pParent == NULL)
					break;
				if (pParent->_left == parent)
				{
					(pParent->_baf)--;
				}
				else if (pParent->_right == parent)
				{
					(pParent->_baf)++;
				}
			}

			//��ת����
			else if (parent->_baf == 2 || parent->_baf == -2)
			{
				if (parent->_baf == 2)                     
				{
					if (parent->_right->_baf == 1)
					{
						_RotateL(parent);
					}
					else
					{
						_RotateRL(parent);
					}
				}
				else if (parent->_baf == -2)
				{
					if (parent->_left->_baf == -1)
					{
						_RotateR(parent);
					}
					else
					{
						_RotateLR(parent);
					}
				}
				break;                                //���Ұѽ���ƽ�����Ӿ���ֵΪ2�Ľ��������֮�󣬻���Ҫ���ϵ�����ʵ�����ǲ���Ҫ�ģ�ԭ������������Ĺ����й�ϵ
			}
			cur = parent;
			parent = parent->_parent;
		}
	}
	bool Remove(const K& key)        //ע�⣺AVL������ɾ���Ч�ʶ��� O(lg(N))
	{
	}
	bool  Find(const K& key)
	{
		return _Find(_root, key);
	}
	void InOrder()
	{
		_Inorder(_root);
		cout << endl;
	}
	bool IsBalanceTree()     //�ж����Ƿ�ƽ��
	{
		return _IsBalanceTree(_root);
	}
protected:
	void _RotateL(Node* & parent)   //����    �@��parentҪʹ��&��ԭ����ΪҪ�����Ľṹ���и���
	{
		Node* tmp = parent;
		Node* SubR = parent->_right;
		Node* subL = SubR->_left;
		Node* ppParent = parent->_parent;    //parent�ĸ��ڵ�  �ȱ�������

		SubR->_left = parent;
		parent->_parent = SubR;
		parent->_right = NULL;

		if (subL)                           //�����ĵڶ������
		{
			parent->_right = subL;
			subL->_parent = parent;
		}
		//�����ĵ����ֿ��ǣ���baf=2�@����㻹��û�и��ڵ���
		if (ppParent == NULL)       
		{
			_root = SubR;
			SubR->_parent = NULL;
		}
		else
		{
			
			if (ppParent->_left==parent)
			{
				ppParent->_left = SubR;
			}
			else if (ppParent->_right == parent)
			{
				ppParent->_right = SubR;
			}
			SubR->_parent = ppParent;
		}
		//����ƽ������   //�߶Ƚ���
		tmp->_baf = 0;
		SubR->_baf = 0;
		//������ʱ���������ҵ������֮����������и���㣬��ô���ڵ��bafҲһ����ı䣬��Ҫ���ϵ�����    [*]
	
	}
	void _RotateR(Node* &parent)    //�ҵ���
	{
		Node* tmp = parent;
		Node* SubL = parent->_left;
		Node* subR = SubL->_right;
		Node* ppParent = parent->_parent;

		SubL->_right = parent;
		parent->_parent = SubL;
		parent->_left = NULL;
		//�����
		if (subR)
		{
			parent->_left = subR;
			subR->_parent = parent;
		}
		//�����
		if (ppParent == NULL)
		{
			_root = SubL;
			SubL->_parent = NULL;
		}
		else
		{
			if (ppParent->_left == parent)
				ppParent->_left = SubL;
			else
				ppParent->_right = SubL;
			SubL->_parent = ppParent;
		}
		//�����˸����֮�µ����н���ƽ������
		SubL->_baf = 0;
		tmp->_baf = 0;
	}
	void _RotateLR(Node* &parent)       //����˫��    ˼��Ϊʲô����˫����ʱ����Ҫ����һЩ������ƽ�����ӵĸ��ģ�
	{
		Node* Cur = parent;
		Node* CurL = parent->_left;
		Node* Curr = CurL->_right;

		_RotateL(parent->_left);
		_RotateR(parent);

		if (Curr->_baf == 1)
		{
			CurL->_baf = -1;
		}
		else if (Curr->_baf == -1)
		{
			Cur->_baf = 1;
		}
		else 
		    Cur = CurL = Curr = 0;

	}
	void _RotateRL(Node* &parent)      //����˫��      ������������
	{
		Node* Cur = parent;
		Node* CurR = parent->_right;
		Node* Curl = CurR->_left;

		_RotateR(parent->_right);
		_RotateL(parent);
        
		if (Curl->_baf == 1)
		{
			CurR->_baf = 1;
		}
		else if (Curl->_baf == -1)
		{
			Cur->_baf = -1;
		}
		else 
		   Cur = CurR = Curl = 0;

	}
	//����
	void _Inorder(Node* root)
	{
		if (root == NULL)
			return;
		_Inorder(root->_left);
		cout << root->_key << " ";
		_Inorder(root->_right);
	}
	int Depth(Node* root)          //���������  [*]
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL&&root->_right == NULL)
			return 1;
		int leftDepth = Depth(root->_left);
		int rightDepth = Depth(root->_right);

		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}


	bool _IsBalanceTree(Node* root)     //�ж����Ƿ�ƽ��   [*]  
		//�@��һ��O��n^2���㷨�����ϵ��µݹ飬Ȼ�������������ж��Ƿ�ƽ��
	{
		if (root == NULL)
			return true;
		int left = Depth(root->_left);
		int right = Depth(root->_right);

		if (right - left != root->_baf)
		{
			cout << root->_key << ":���ƽ�����Ӵ��󣬽��ƽ�������ǣ�" << root->_baf << endl;
		}

		return abs(left - right) < 2 &&_IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
		
	}

	bool _Find(Node* root ,const K& key)
	{
		if (root == NULL)
			return false;
		if (key < root->_key)
		{
			_Find(root->_left,key);
		}
		else if (key>root->_key)
		{
			_Find(root->_right, key);
		}
		else
		{
			return true;
		}
	}
}; 


//-----------����-------------
void test()
{


	/*int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> A1;
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		A1.Insert(arr[i], 0);
	}
	A1.InOrder();
	A1.InOrder();
	A1.IsBalanceTree();
	cout << A1.IsBalanceTree() << endl;
	cout << A1.Find(2) << endl;*/

	
	//���ڴ������������ʵ������������������������ƽ�����ӵĴ��������ƣ���˫�����������Ҫ������������ĵ���
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> A1;
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		A1.Insert(arr[i],0);
	}

	A1.InOrder();
	A1.IsBalanceTree();
	cout << A1.IsBalanceTree()<<endl;
	cout<<A1.Find(2)<<endl;
	cout << A1.Find(9) << endl;
	A1.InOrder();

}
int main()
{
	test();
	return 0;
}