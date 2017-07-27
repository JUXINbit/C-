#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
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

	void _PrevOrder(Node* root)    //ǰ�����
	{
		if (root == NULL)       //��������
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	void _InOrder(Node* root)    //�������
	{
		if (root == NULL)       //��������
			return;
		_InOrder(root->_left);             //Ҫ�ѵݹ鿴�����˵ݹ����ײ���д����,�@�����������߼�
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void _PostOrder(Node* root)   //�������
	{
		if (root == NULL)        //��������
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}

	void _LevelOrder(Node* root)     // �������  ʹ�÷ǵݹ�  ʹ��queue���Ƚ��ȳ�ԭ��                                             [*]
	{
		queue<Node*> q;
		if (root)                       //��������
			q.push(root);
		else
			return;
		while (!q.empty())               //���в�Ϊ����ѭ��
		{
			Node* cur = q.front();
			cout << cur->_data << " ";
			if (cur->_left)
				q.push(cur->_left);
			if (cur->_right)
				q.push(cur->_right);
			q.pop();                     //�@��ʵ������ͨ��pop���������ߵģ�����������ڵݹ������
		}
		cout << endl;
	}

	size_t _Size(Node* root)         //�������
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)    //  ���@���ݹ��еķ�������
			return 1;
		return _Size(root->_left) + _Size(root->_right) + 1;             //�@��ǵ�+1   ��Ϊ�и����
	
	}

	size_t _LeafSize(Node* root)     //��Ҷ�ӽ�����
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL&&root->_right == NULL)
			return 1;
		return _LeafSize(root->_left) + _LeafSize(root->_right);
		
	
	}

	size_t _GetKLevel(Node* root, size_t k)    //���K�������
	{
		if (root == NULL)
			return 0;                         //ע���@��ķ���ֵ��size_t�����ܹ�дreturn��һ��Ҫ����һ��ֵ0���@���ط�
		if (k == 1)
			return 1;
		if (k > 1)
			return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);      //β�ݹ�
		else
		{
			cout << "'k' is wrong" << " ";
			return 0;
		}
		  
	}
	//��Ҷ�ӽ��ĸ�����ϰ: �ݹ�
	size_t GetLevelNumP(Node* root)
	{
		if (root == NULL)         //ע���@�������������ֻ���������Ļ�ֻ���������Ľ��
			return 0;
		if (root->_left == NULL && root->_right == NULL)
			return 1;
		return GetLevelNum(root->_left) + GetLevelNum(root->_right);
	}
	//��K��Ľ��ĸ���:�ݹ�
	size_t GetKLevelNumP(Node* root,int K)
	{
		if (root == NULL)
			return 0;		
		if (K < 1)                   //�@������ʵ����Ӧ���б�Ҫ
			return 0;
		if (K == 1)
			return 1;

		return GetKLevelNumP(root->_left, K - 1) + GetKLevelNumP(root->_right, K - 1);
	}

	size_t _Depth(Node* root)          //������������
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)
			return 1;
		size_t leftdepth = _Depth(root->_left);        //����Ϊʲô��Ҫ�����߽��бȽ�
		size_t rightdepth = _Depth(root->_right);
		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;     //��Ҫ����+1 �����
	}

	Node* _Find(Node* root,const T& t) //����                                                                                     [*]
	{
		/*if (root == NULL)
			return NULL;
		Node* tmp = _Find(root->_left, t);
		if (root->_data == t)
		{
			return root;
		}
		_Find(root->_right, t);*/
		if (root == NULL)
			return NULL;
		if (root->_data == t)
			return root;
		Node* tmp = _Find(root->_left, t);
		if (tmp)
			return tmp;
		return _Find(root->_right, t);         //������
	}

	Node* _Copy(Node* root)               //������ʵ���Ͼ������ڹ��� ���Ƿ�ʽ�ϲ�һ������   �������Ŀ�������                           [*]
	{
		if (root == NULL)
			return NULL;
		Node* copyroot = new Node(root->_data);
		copyroot->_left = _Copy(root->_left);
		copyroot->_right = _Copy(root->_right);  
		return copyroot;
	}

	void Destory(Node* root)
	{
		if (root == NULL)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;              //�ͷŵ�ǰ���
		root = NULL;
	}
	//�ж�B�Ƿ���A����������
	bool _CheckKidTree(Node* Aroot,Node* Broot)
	{
		if (Broot == NULL)
			return true;
		if (Aroot == NULL&&Broot)
			return false;
		if (Aroot->_data == Broot->_data)
			return _CheckKidTree(Aroot->_left, Broot->_left) && _CheckKidTree(Aroot->_right, Broot->_right);
		else
			return false;
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


	BinaryTree(const BinaryTree<T>& t)                         //��������
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)             //��ֵ���������
	{
		if (_root)
			Destory(_root);
		_root = _Copy(t._root);
		return *this;
	}


	void PrevOrder()                                         //ǰ�����
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()                                            //�������
	{
		_InOrder(_root);
		cout << endl;
	}
	void  PostOrder()                                        //�������
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()                                         //�������        (�@���ò����ݹ飬���Կ��Բ����@��д)
	{
		_LevelOrder(_root);
	}
	size_t Size()                                            //������
	{
		return _Size(_root);
	}
	size_t LeafSize()                                         //Ҷ�ӽ�����
	{
		return _LeafSize(_root);
	}
	size_t GetKLevel(size_t k)                                 //K����
	{
		return _GetKLevel(_root, k);
	}
	size_t Depth()                                            //�������
	{
		return _Depth(_root);
	}
	Node* Find(const T& d)                                    //����
	{
		return _Find(_root, d);
	}

	//Ѱ�Һܸ��ڵ���ȵ�A�еĽ��,����ҵ��˾�ȥ�ݹ��ж��Ƿ�������,�����ǰ�Ľ�㲻��Ȼ��ߵ�ǰ�Ľ������Ѱ�Ҳ���������
	//��ô����Ҫ��A�еĽ��������µݹ�Ȼ������Һ�root���ڵ���ȵĽ�� Ȼ������ݹ��ж�
	//ʵ�����@����ʹ��������ݹ�
	//�տ�ʼ�@��ĵݹ�û��д�����������Դ���
	bool CheckKidTree(Node* root1, Node* root2)
	{
		if (root1 == NULL)
			return false;
		bool result = false;
		if (root1->_data == root2->_data)
			result = _CheckKidTree(root1, root2);
		if (!result)
			return CheckKidTree(root1->_left, root2);
		if (!result)
			return CheckKidTree(root1->_right, root2);
		return result;
	}
	bool FindKidTree(const BinaryTree<T>& t)
	{
		if (this->_root == NULL)
			return false;
		if (t._root == NULL)
			return false;
		return CheckKidTree(this->_root, t._root);
	}
	~BinaryTree()                                             //����
	{
		Destory(_root);
		_root = NULL;
		cout << "����" << endl;
	}

};



void test()                                                   //���������������� ���� ��������������������
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int arr2[] = { 2, 6, '#', '#', 4, '#' };
	BinaryTree<int> t1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	BinaryTree<int> t2(arr2, sizeof(arr2) / sizeof(arr2[0]), '#');
	t1.PrevOrder(); 
	t2.PrevOrder();
	cout << t1.FindKidTree(t2);
	/*t1.InOrder();
	t1.PostOrder();
	t1.LevelOrder();
	cout << t1.Size() << endl;
	cout << t1.LeafSize() << endl;
	cout<<t1.GetKLevel(3)<<endl;
	cout << t1.Find(3) << endl;

	BinaryTree<int> t2(t1);
	t2.PrevOrder();
	t2.InOrder();
	t2.PostOrder();
	t2.LevelOrder();
	cout << t2.Size() << endl;
	cout << t2.LeafSize() << endl;
	cout << t2.GetKLevel(3) << endl;
	cout << t2.Find(3) << endl;

	BinaryTree<int> t3;
	t3 = t1;
	t3.PrevOrder();
	t3.InOrder();
	t3.PostOrder();
	t3.LevelOrder();*/
}
int main()
{
	test();
	return 0;
}