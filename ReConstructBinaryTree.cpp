#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using  namespace std;

//�ؽ�������
//��Ҫ˼���ǽ����������ڵ�ǰ������£���˳�����ǰ���������������ȷ����ǰ�ĸ���㣬Ȼ�������������ȷ������������������
//Ҫע������������жϣ�ʲôʱ�򷵻أ�ʲôʱ��ݹ�������ʲôʱ��ݹ���������

typedef struct TreeNode
{
	int _data;
	TreeNode* _left;
	TreeNode* _right;
}Node;

Node* ConstructTree(int* PrevHead, int* PrevTail, int* InorderHead, int* InorderTail)
{
	//�������
	int value = PrevHead[0];
	Node* root = new Node();
	root->_data = value;
	root->_left = NULL;
	root->_right = NULL;
	//��������
	if (PrevHead == PrevTail&&InorderHead == InorderTail)
	{
		if (*PrevHead != *InorderHead)              //����жϵ�Ŀ�ľ������������һ��Ҷ�ӽ���ʱ������������ȣ���ô�@����������һ����������� Ҫ�����ء�
		{
			cout << " INPUT  ERROR" << endl;
			return NULL;
		}
		return root;
	}
	//����������������ҵ�ǰ�ĸ����������û�����ˣ����˵�������ô����������������ߵ����ݵĳ��ȡ�
	int leftlength = 0;
	int* cur = InorderHead;
	while (*cur != value)
	{
		leftlength++;
		cur++;
	}
	int* PrevEnd = PrevHead + leftlength;
	//�ݹ�������
	if (leftlength > 0)           //�ݹ����
	{
		root->_left = ConstructTree(PrevHead + 1, PrevEnd, \
			InorderHead, InorderHead + leftlength - 1);
	}
	if (leftlength < PrevTail - PrevHead)    //�ݹ��ұ�
	{
		root->_right = ConstructTree(PrevEnd + 1, PrevTail, \
			InorderHead + leftlength + 1, InorderTail);
	}
	//�����������������֮��Χroot
	return root;
}

Node* ReCreateBinaryT(int* PrevHead, int* InOrderHead, size_t length)
{
	assert(PrevHead);
	assert(InOrderHead);
	assert(length);
	return ConstructTree(PrevHead, PrevHead + length - 1,\
		             InOrderHead, InOrderHead + length - 1);
}

//****************����**************************
void test()
{
	int arr1[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int arr2[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	size_t length = sizeof(arr1) / sizeof(arr1[0]);
	Node* root = ReCreateBinaryT(arr1, arr2, length);
}
int main()
{
	test();
	return 0;
}