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
			_root = new Node(key,value);
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
			Node* avlnode = new Node(key,value);
			parent->_left = avlnode;
			avlnode->_parent = parent;
			cur = avlnode;
			(parent->_baf)--;
		}
		else if (key>parent->_key)             //����
		{
			Node* avlnode = new Node(key,value);
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
				if (pParent->_baf == 0)     //�@���ǲ���Ҳ���Բ�д��
					break;
			}

			//��ת����
			else if (parent->_baf == 2 || parent->_baf == -2)
			{
				if (parent->_baf == 2)                      //   *
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
					if (parent->_left->_baf == 1)
					{
						_RotateR(parent);
					}
					else
					{
						_RotateLR(parent);
					}
				}
				break;
			}
			cur = parent;
			parent = parent->_parent;
		}
	}
	bool Remove(const K& key)
	{
	}
	Node* Find(const K& key)
	{
	}
	void InOrder()
	{
		_Inorder(_root);
	}
	bool IsBlanceTree()     //[*]
	{

	}
protected:
	void _RotateL(Node* & parent)   //����    �@��parentҪʹ��&��ԭ����ΪҪ�����Ľṹ���и���
	{
		Node* SubR = parent->_right;
		Node* subL = SubR->_left;
		Node* ppParent = parent->_parent;    //parent�ĸ��ڵ�  �ȱ�������

		SubR->_left = parent;
		parent->_parent = SubR;

		if (subL)                   //�����ĵڶ������
		{
			parent->_right = subL;
			subL->_parent = parent;
		}
		//�����ĵ����ֿ��ǣ���baf=2�@����㻹��û�и��ڵ���
		if (ppParent == NULL)       
		{
			_root = SubR;
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
		parent->_baf == 0;
		SubR->_baf == 0;
		//������ʱ���������ҵ������֮����������и���㣬��ô���ڵ��bafҲһ����ı䣬��Ҫ���ϵ�����    [*]
	
	}
	void _RotateR(Node* &parent)    //�ҵ���
	{
		Node* SubL = parent->_left;
		Node* subR = SubL->_right;
		Node* ppParent = parent->_parent;

		SubL->_right = parent;
		parent->_parent = SubL;
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
		parent->_baf = 0;
	}
	void _RotateLR(Node* &parent)       //����˫��   
	{
		_RotateL(parent->_left);
		_RotateR(parent);


	}
	void _RotateRL(Node* &parent)      //����˫��      ������������
	{
		_RotateR(parent->_right);
		_RotateL(parent);
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
}; 


//-----------����-------------
void test()
{
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	AVLTree<int, int> A1;
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		A1.Insert(arr[i],0);
	}

}
int main()
{
	test();
	return 0;
}