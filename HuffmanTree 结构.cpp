#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

template<class T>
struct HuffmanTreeNode
{
	HuffmanTreeNode<T>* _left;
	HuffmanTreeNode<T>* _right;
	T _data;                        //�@���dataʵ������Ȩ��(weight)
	HuffmanTreeNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{
	
	}
};
template<class T>
struct WeitLessThan        
{
	bool operator()(const HuffmanTreeNode<T>* _left, const HuffmanTreeNode<T>* _right) const
	{
		return _left->_data < _right->_data;
	}
};

template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
private:
	Node* _root;
public:
	HuffmanTree()  //�޲ι���
		:_root(NULL)
	{
	}
	HuffmanTree(T* a,size_t n)         //������һ������
	{
		//template<class T>                                            //�տ�ʼ��дģ������б�ĳ����ˣ�˵ģ������ֻ����ȫ�������ռ�����෶Χ�ڡ� ��������дһ�������࣬����Ҫʲôģ�� ����Node*���͵�
		//struct WeitLessThan         //�@���ṹ��һ��Ҫ�����@���� ��ʵҲ���Է�������
		//{
		//	bool operator()(const Node* _left, const Node* _right) const
		//	{
		//		return _left->_data < _right->_data;
		//	}
		//};

		//����С��ѡ��������������С����
		//����
		Heap<Node*, WeitLessThan<T>> minHeap;
		for (size_t i = 0; i < n; i++)
		{
			minHeap.Push(new Node(a[i]));
		}
		while (minHeap.Size()>1)                  //ע���@��ѭ�������� Ϊʲô��>1
		{
			                                   //ѡ��Ȩֵ��С���������
			Node* left = minHeap.Top();
			minHeap.Pop();
			Node* right = minHeap.Top();
			minHeap.Pop();
			                                     //���츸���Ȼ����������
			Node* parent = new Node(left->_data + right->_data);
			parent->_left = left;
			parent->_right = right;
			                                    //���Ӻ�֮���ٷŻ�ȥ�Ƚ� // ע�⣺�Ż�ȥ�Ƚ�ûɶ�ر�ģ�Ҫ֪���ǷŻص��������棬���ӺõĲ������ʲôӰ��
			minHeap.Push(parent);
		}
		    _root = minHeap.Top();                 //ע�⣺Ϊʲô�@����min.Top();
	}
	~HuffmanTree()
	{
	
	}
};

void test()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	HuffmanTree<int> h1(arr,sizeof(arr)/sizeof(arr[0]));

}
int main()
{
	test();
	return 0;
}