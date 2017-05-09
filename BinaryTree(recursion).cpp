#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
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
		,_left(NULL)
		, _right(NULL)
	{
		cout << "������������" << endl;
	}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
private:
	Node* _root;
protected:
	Node* _CreateTree(T* a, size_t n,const T& invalid, size_t& index)  //�@���index�ɵ����@���������Ǹ�����������������������@����������⣬������Ϊջ֡��ԭ���������ڵ�ص�ʱ��index��ֵҲ�᷵�أ��@��Ľ���취�ǣ�  &
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
public:
	BinaryTree()            //�޲ι��캯��
		: _root(NULL)
	{
	}
	BinaryTree(T* a, size_t n, const T& invalid)      //���εĹ��캯��      //ע�⣺�޲εĵݹ��ǲ���д�ڹ��еĳ�Ա�������������Ϊʲô��
	{
		size_t index = 0;
		_root = _CreateTree(a, n, invalid, index);
	}
	BinaryTree(const BinaryTree<T>& t)
	{}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		return *this;
	}
	void PrevOrder() //ǰ�����
	{
	}
	void Inorder()   //�������
	{
	}
	void  PostOrder()  //�������
	{
	}
	void LevelOrder()   //�������
	{
	}
	size_t Size()      //������
	{
	}
	size_t LeafSize()   //Ҷ�ӽ�����
	{
	}
	size_t GetKLevel(size_t k)   //K����
	{
	}
	size_t Depth()  //�������
	{
	}
	Node* Find(const T& d)  //����
	{
	}




//  �ǵݹ�
//1.ǰ��
	//  curָ��ǰ��Ҫ���ʵĽ�� ������·ִ�У�ʹ��stack����·������η���ѹջ��cur==NULL����·Ϊ��  pop��������ϵĽ��->  cur->right�����ҽ��  ѭ������
	void PrevOrderN()
	{
		stack<Node*> s1;    
		Node* cur = _root;
		while (cur || !(s1.empty()))
		{
			while (cur)
			{
				cout << cur->_data << " ";
				s1.push(cur);
				cur = cur->_left;
			}
			Node* tmp = s1.top();
			s1.pop();
			cur = tmp->_right;
		}
            
	}

};

void test()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(arr,sizeof(arr)/sizeof(arr[0]),'#');
	t1.PrevOrderN();
}
int main()
{
	test();
	return 0;
}