#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//K�ṹ�Ķ���������       �������ݽṹ���@�￪ʼ�漰����ɾ��ĵ�

template<class K>
struct SearchBinaryTreeNode
{
	K _data;
	SearchBinaryTreeNode<K>* _left;
	SearchBinaryTreeNode<K>* _right;
	SearchBinaryTreeNode(const K& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{
	}

};
template<class K>
class SearchBinaryTree
{
	typedef SearchBinaryTreeNode<K> Node;
private:
	Node* _root;
public:
	SearchBinaryTree()
		:_root(NULL)
	{
	}

	//�ǵݹ�
	//bool Insert(const K& d)             //ע�⣺β�˲��루�@�������λ�ò��룩            //�@��ʹ��boolֵҲ�������@����������  ��ֹ��������
	//{                                   //���ڶ�����������˵��һ���е㣬����ͨ�����ļ�ֵ�Ƚ����ж������㻹���ҽ��
	//	if (_root == NULL)
	//	{
	//		_root = new Node(d);
	//		return true;
	//	}
	//		Node* parent = NULL;
	//		Node* cur = _root;
	//		while (cur)
	//		{
	//			if (d < cur->_data)
	//			{
	//				parent = cur;
	//				cur = cur->_left;
	//			}
	//			else if (d > cur->_data)
	//			{
	//				parent = cur;
	//				cur = cur->_right;
	//			}
	//			else
	//			{
	//				return false;
	//			}
	//		}
	//		if (d > parent->_data)
	//		{
	//			parent->_right = new Node(d);
	//			return true;
	//		}
	//		else
	//		{
	//			parent->_left = new Node(d);
	//			return true;
	//		}
	//}
	//�ݹ�
	bool InsertR(const K& d)
	{
		return _InsertR(_root, d);
	}
	bool FindR(const K& d)
	{
	    return _FindR(_root, d);
	}
	
	bool RemovR(const K& d)                 //[*]
	{
		return _RemovR(_root, d);
	}
	//bool Find(const K& d)               //ע�⣺����K�ṹ�Ķ��������������ǲ������޸�ֵ�ģ�����޸����������������ܸı�
	//{
	//	if (_root == NULL)
	//	{
	//		return false;
	//	}
	//	Node* cur = _root;
	//	while (cur)
	//	{
	//		if (d < cur->_data)
	//		{
	//			cur = cur->_left;
	//		}
	//		else if (d > cur->_data)
	//		{
	//			cur = cur->_right;
	//		}
	//		else
	//		{
	//			return true;
	//		}
	//	}
	//	return false;
	//}
	void Remove(const K& d)                 //ע�⣺�����
	{
		if (_root == NULL)
			return;
		if (Find(d) == 0)
		{
			cout << "δ�ҵ�" << endl;
			return;
		}
		else
		{
			Node* parent = NULL;
			Node* cur = _root;
			while (cur)
			{
				if (d < cur->_data)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (d > cur->_data)
				{
					parent = cur;
					cur = cur->_right;
				}
				else     // �ҵ��˼�ֵΪd�Ľ��      ��ʼ�����Ƴ�
				{
					//1. ��ΪҶ�ӽ��
					if (cur->_left == NULL&&cur->_right == NULL)
					{
						if (parent == NULL)                          //�@���������ɾ�������һ������ʱ��
						{
							delete cur;
							cur = NULL;
							_root = NULL;   //�ǵø�����ÿ�
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
						else if (cur->_data < parent->_data)          //��Ҷ�ӽ��
						{
							parent->_left = NULL;
							delete cur;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
						else                                     //��Ҷ�ӽ��
						{
							parent->_right = NULL;
							delete cur;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
					}
					//2. ���������Ϊ��  [*]   ע������
					else if (cur->_left == NULL)
					{
						if (parent == NULL)                          //����ֻʣ���Ұ�ߵ�ʱ��
						{
							_root = cur->_right;
							delete cur;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
						if (cur->_data < parent->_data)
						{
							parent->_left = cur->_right;
							delete cur;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
						else
						{
							parent->_right = cur->_right;
							delete cur;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
					}

					// ���������Ϊ��        ע������
					else if (cur->_right == NULL)
					{

						if (parent == NULL)                              //����ֻʣ���ߵ�ʱ��
						{
							_root = cur->_left;
							delete cur;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
						if (cur->_data < parent->_data)
						{
							parent->_left = cur->_left;
							delete cur;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
						else
						{
							parent->_right = cur->_left;
							delete cur;
						}
					}

				    //3. ��������Ҷ���Ϊ��  ��[*]�滻��  ��������Ϊ�����������������ҽ�����������������ڵ㣩
					else
					{
						Node* parent = NULL;
						Node* tmp = cur->_left;        //tmpΪ�����������
						if (tmp->_right == NULL)
						{
							swap(tmp->_data, cur->_data);
							cur->_left = tmp->_left;
							delete tmp;
							cout << "�Ƴ��ɹ�" << endl;
							return;
						}
						else
						{
							while (tmp->_right)        //�������������ҽ��
							{
								parent = tmp;
								tmp = tmp->_right;
							}
							if (tmp->_left == NULL)
							{
								swap(cur->_data, tmp->_data);
								parent->_right = NULL;
								delete tmp;
								cout << "�Ƴ��ɹ�" << endl;
								return;
							}
							else
							{
								parent->_right = tmp->_left;
								delete tmp;
								cout << "�Ƴ��ɹ�" << endl;
								return;
							}
						}
					}
				}
			}
		}
	}
	void InOrder()                           //���ֶ�������������������ļ�ֵ��С����
	{
		_inOrder(_root);
		cout << endl;
	}
protected:
	//�ݹ����
	bool _InsertR(Node*& root, const K& d)
	{
		if (root == NULL)
		{
			root = new Node(d);
			return true;
		}
		if (d < root->_data)
		{
			_InsertR(root->_left, d);
		}
		else if (d>root->_data)
		{
			_InsertR(root->_right, d);
		}
		else
		{
			return false;
		}
	}

	//�ݹ����
	bool _FindR(Node* root, const K& d)
	{
		if (root == NULL)
		{
			return false;
		}
		if (d < root->_data)
		{
			_FindR(root->_left, d);
		}
		else if (d>root->_data)
		{
			_FindR(root->_right, d);
		}
		else
		{
			return true;
		}
	}

	//�ݹ�ɾ��
	bool _RemoveR(Node*& root, const K& d)
	{
		if (root == NULL)
		{
			return false;
		}
		if (d < root->_data)
		{
			_RemoveR(root->_left, d);
		}
		else if (d < root->_data)
		{
			_RemoveR(root->_right, d);
		}
		else                                //�ҵ�
		{
			if (root->_left == NULL)
			{
				Node* cur = root;
				root = root->_right;
				delete cur;
				cur = NULL;
				cout << "�Ƴ��ɹ�" << endl;
			}
			else if (root->_right == NULL)
			{
				Node* cur = root;
				root = root->_left;
				delete cur;
				cur = NULL;
				cout << "�Ƴ��ɹ�" << endl;
			}
			else       //������������Ϊ��
			{
				

				
			}
		}

	}

	void _inOrder(Node* root)
	{
		if (root == NULL)
			return;
		_inOrder(root->_left);
		cout << root->_data<<" ";
		_inOrder(root->_right);
	}
};

void test()
{
	SearchBinaryTree<int> s1;
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		s1.InsertR(arr[i]);
	}
	s1.InOrder();
	cout<<s1.FindR(3)<<endl;
	//s1.Remove(0);
	//s1.InOrder();
	//s1.Remove(1);
	//s1.InOrder();
	//s1.Remove(2);
	//s1.InOrder();
	//s1.Remove(3);
	//s1.InOrder();
	//s1.Remove(4);
	//s1.InOrder();
	//s1.Remove(5);              //������@�￪ʼ�ҵ���     �@��ʱ����ֻʣ��һ�� parent==NULL 
	//s1.InOrder();
	//s1.Remove(6);
	//s1.InOrder();
	//s1.Remove(7);
	//s1.InOrder();
	//s1.Remove(8);
	//s1.InOrder();
	//s1.Remove(9);             //��ֻʣ�����һ������ʱ�� ���ǰ�治��һ��Ҳ��ҵ�
	//s1.InOrder();


}
int main()
{
	test();
	return 0;
}