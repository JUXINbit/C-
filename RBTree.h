#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>

using namespace std;


//�����
//���صĹ����ʵ��ԭ��
//��ɾ��ʱ�临�Ӷ�
//��ת�ĸ����������
#define RED  1
#define BLACK  0

//���@����ʵ����ת��ʱ���Ҳ�û�н�������Ϊ�ں������㲻���ڷ���һ���ǣ����������������ʱ����������д����ת��Ϊ�ڵ�һ��д��֮��ҵ��ˣ����ֶ��ڲ�����������������ת����Ҫ���⿼�ǵģ����Ծ�����д����ת
template<class K,class V>
struct RBTreeNode
{
	K _key;
	V _value;
	int _colour;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	RBTreeNode(const K& key)
		: _key(key)
		, _value(0)
		, _colour(RED)                        //Ĭ��Ϊ��ɫ��ԭ��
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{
		cout << "����RB���" << endl;
	}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V>  Node;
private:
	Node* _root;
public:
	RBTree()
		:_root(NULL)
	{
	}
	bool Insert(const K& key)
	{
		//ȷ�������ΪBLACK
		//Ѱ��λ�ò�����
		//�������ת��ɫ������
		//-----------------------------------------------------------------------------
		if (_root == NULL)
		{
			_root = new Node(key);
			_root->_colour = BLACK;
			return true;
		}
		//������
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)             //�������Ĳ�����Զ���ǲ���Ҷ�ӽ�㣬�@��������������
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
		cur = new Node(key);
		cur->_parent = parent;
		if (parent->_key > cur->_key)
		{
			parent->_left = cur;
		}
		else if (parent->_key < cur->_key)
		{
			parent->_right = cur;
		}
		//������Ͽ�ʼ����
		Node* Gparent = parent->_parent;
		if (parent->_colour == BLACK)
		{
			return true;
		}
		while (parent->_colour == RED&&Gparent)      //����ϲ����Ǻ�ɫ���߸����Ļ����Ͳ���Ҫ���ϵ����ˣ�ʵ�����@��ѭ����Ϊ���Ǹ�����Ҫ��ת��������ǵ�
		{
			if (parent->_key < Gparent->_key)     //p���� u����
			{
				Node* Uparent = Gparent->_right;   //�ҵ�������
				if (Uparent&&Uparent->_colour == RED)  //���������Ϊ��
				{
					parent->_colour = BLACK;
					Uparent->_colour = BLACK;
					Gparent->_colour = RED;
					cur = Gparent;
					Gparent = Gparent->_parent;             //���ϵ���
				}
				else if (Uparent&&Uparent->_colour == BLACK)  //���������Ϊ�� Ҫ��ת+����cur��parent�����λ��
				{
					if (cur->_key < parent->_key)     //cur��parent�����  ���ҵ���+��ɫ
						SubR(Gparent);
					else if (cur->_key>parent->_key)  //cur��parent���ұߣ�����˫��+��ɫ
						SubLR(Gparent);
					return true;               //�˴ε�����Ϻ�ֱ��return������Ҫѭ��
				}
				else                               //���岻����   ������һ��
				{
					if (cur->_key < parent->_key)
						NusubR(Gparent);
					else if (cur->_key>parent->_key)
						NusubLR(Gparent);
					return true;
				}
			}
			else if (parent->_key > Gparent->_key)   //p���ұߣ�u�����
			{
				Node* Uparent = Gparent->_left;
				if (Uparent&&Uparent->_colour == RED)  //���������Ϊ��
				{
					parent->_colour = BLACK;
					Uparent->_colour = BLACK;
					Gparent->_colour = RED;
					cur = Gparent;
					Gparent = Gparent->_parent;             //���ϵ���
				}
				else if (Uparent&&Uparent->_colour == BLACK)  //���������Ϊ�� 
				{
					if (cur->_key > parent->_key)
						SubL(Gparent);                         //����        
					else if (cur->_key<parent->_key)
						SubRL(Gparent);                         //����˫��
					return true;
				}
				else                               //���岻����   ������һ��
				{
					if (cur->_key > parent->_key)
						NusubL(Gparent);
					else if (cur->_key < parent->_key)
						NusubRL(Gparent);
					return true;
				}
			}
		}
		_root->_colour = BLACK;
		return true;
	}
	bool Remove(const K& key)  //ɾ��
	{
	}
	bool Find(const K& key)     //����
	{
		return _Find(_root, key);
	}
	bool IsRBTree()   //[*]        �տ�ʼ�������@��Ϊʲô�Ҳ���AVL��һ��ʵ��һ���ж�ƽ�⣬����ʵ���ϲ���Ҫ��ֻ��Ҫ�ж�������Ƿ������������������
    {                           //������������Ȼ���ܱ�֤����ƽ�⣨�·�����������·����������
         //��Ҫ�����Ҫ�� 1. �����Ϊ��
		 //                 2. ���ܳ��������ĺ�ɫ���
		 //                 3. ��ÿ���ڵ㣬�Ӹýڵ㵽�����к��Ҷ�ڵ�ļ�·���ϣ���������ͬ��Ŀ�ĺ�ɫ�ڵ�
		if (root == NULL)
			return false;
		if (_root&&_root->_colour == RED)  //�����Ϊ��ɫ��ֱ��pass
			return false;
		return _IsRBTree(_root);           //�õݹ��ж���������������Ƿ����
	}
	void InOrderR()
	{
		_InOrderR(_root);
		cout << endl;
	}
protected:
	void _InOrderR(Node* root)
	{
		if (root == NULL)
			return;
		_InOrderR(root->_left);
		cout << root->_key <<" ";
		_InOrderR(root->_right);
	}
	
	bool _IsRBTree(Node* root)   //�ݹ��ж�ƽ��
	{
		if (root == NULL)
			return true;
		if ((root->_colour == RED) && (root->_parent->_colour == RED))
			return false;
		return _IsRBTree(root->_left) && _IsRBTree(root->_right);

		//�жϺ�ɫ�����Ŀ


	}
	void SubR(Node* Gparent)    //�ҵ���   
	{
		Node* Rparent = Gparent->_parent;         //Gparent �ĸ����
		Node* parent = Gparent->_left;
		Node* cur = parent->_right;
		//���ӵ�ʱ��ע��������
		if (Rparent)                 //���Gparent���Ǹ����
		{
			if (Rparent->_left == Gparent)
			{
				parent->_parent = Rparent;
				Rparent->_left = parent;
			}
			else if (Rparent->_right == Gparent)
			{
				parent->_parent = Rparent;
				Rparent->_right = parent;
			}
		}
		else if (Rparent == NULL)           //���Gparent���Ǹ���㣬����Ҫ���и����Ľ���  �@������ر����׺���
		{
			_root = parent;
		}

		Gparent->_left = cur;
		cur->_parent = Gparent;

		parent->_right = Gparent;
		Gparent->_parent = parent;

		//��ɫ
		parent->_colour = BLACK;
		Gparent->_colour = RED;
	}
	void NusubR(Node* Gparent)          //for no nucle subR
	{
		Node* Rparent = Gparent->_parent;
		Node* parent = Gparent->_left;

		if (Rparent)
		{
			if (Rparent->_left == Gparent)
			{
				Rparent->_left = parent;
				parent->_parent = Rparent;
			}
			else if (Rparent->_right == Gparent)
			{
				Rparent->_right = parent;
				parent->_parent = Rparent;
			}
		}
		else
		{
			_root = parent;
		}
		parent->_right = Gparent;
		Gparent->_parent = parent;
		Gparent->_left = NULL;      //[*]

		//��ɫ
		parent->_colour = BLACK;
		Gparent->_colour = RED;
	}

	void SubL(Node* Gparent)               //����
	{
		Node* Rparent = Gparent->_parent;
		Node* parent = Gparent->_right;
		Node* cur = parent->_left;

		if (Rparent)                   //Gparent�Ǹ����
		{
			if (Rparent->_left == Gparent)
			{
				parent->_parent = Rparent;
				Rparent->_left = parent;
			}
			else if (Rparent->_right == Gparent)
			{
				parent->_parent = Rparent;
				Rparent->_right = parent;
			}
		}
		else                           //GparentΪ�����
		{
			_root = parent;
		}

		Gparent->_right = cur;
		cur->_parent = Gparent;

		parent->_left = Gparent;
		Gparent->_parent = parent;
		//��ɫ
		Gparent->_colour = RED;
		parent->_colour = BLACK;
	}
	void NusubL(Node* Gparent)                        //for no uncle subL 
	{
		Node* Rparent = Gparent->_parent;
		Node* parent = Gparent->_right;

		if (Rparent)
		{
			if (Rparent->_left == Gparent)
			{
				Rparent->_left = parent;
				parent->_parent = Rparent;
			}
			else if (Rparent->_right == Gparent)
			{
				Rparent->_right = parent;
				parent->_parent = Rparent;
			}
		}
		else
		{
			_root = parent;
		}
		parent->_left = Gparent;
		Gparent->_parent = parent;
		Gparent->_right = NULL;
		//��ɫ
		parent->_colour = BLACK;
		Gparent->_colour = RED;
	}
	void SubLR(Node* Gparent)        //С����+����
	{
		Node* Pparent = Gparent->_left;
		Node* parent = Pparent->_right;
		Node* curL = parent->_left;
		//С����
		Pparent->_right = curL;     //���@�������curL�Ǳض����ڵģ�����Ϊ�ڣ�
		curL->_parent = Pparent;

		parent->_left = Pparent;
		Pparent->_parent = parent;

		Gparent->_left = parent;
		parent->_parent = Gparent;

		//����
		SubR(Gparent);
	}
	void NusubLR(Node* Gparent)
	{
		Node* parent = Gparent->_left;
		Node* cur = parent->_right;

		Gparent->_left = cur;
		cur->_parent = Gparent;
		cur->_left = parent;
		parent->_parent = cur;
		parent->_right = NULL;
		//����
		NusubR(Gparent);

	}
	void SubRL(Node* Gparent)        //С����+����
	{
		Node* Pparent = Gparent->_right;
		Node* parent = Pparent->_left;
		Node* curR = parent->_right;

		//С����
		Pparent->_left = curR;
		curR->_parent = Pparent;

		parent->_right = Pparent;
		Pparent->_parent = parent;

		Gparent->_right = parent;
		parent->_parent = Gparent;

		//����
		SubL(Gparent);
	}
	void NusubRL(Node* Gparent)
	{
		Node* parent = Gparent->_right;
		Node* cur = parent->_left;

		Gparent->_right = cur;
		cur->_parent = Gparent;
		cur->_right = parent;
		parent->_parent = cur;
		parent->_left = NULL;
		//����
		NusubL(Gparent);
	}

	//��תС�᣺ÿһ����ת��Ӧ����һ��������տ�ʼ�ڵ�������ת����֮���ҵ�p g u������λ�ö����ˣ�����Ҫ��λ�ô���ȥ�𣬺��������ҵ���תֻ������ת��������Ϊ��
	//��Ϊ��Ҫ��ת��������ǵ������˾�ֱ�ӷ��صĲ������ϵ����ģ����ϵ�����Ҫλ����Ϣ��������AVL����Ҫ��ת�Ķ���ƽ�����Ӿ���ָΪ2�ģ����@���Ľ�������Ͼ�����ת�����֮��
	//��ֱ�ӽ������е�����������˵�Ҽ�Ȼ��ת����ֻ����ת���ˣ����ĺ���λ�þͽ���������һ�㣺��ת����Ҫ������ɫ�ģ�������ɫ����ת�����ڲ�����תһ����ɡ�

	bool _Find(Node* root,const K& key)
	{
		if (root == NULL)
			return false;
		if (root->_key > key)
		{
			_Find(root->_left, key);
		}
		else if (root->_key < key)
		{
			_Find(root->_right, key);
		}
		else
			return true;
	}
};
