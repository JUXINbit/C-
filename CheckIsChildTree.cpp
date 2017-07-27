#define _CRT_SECURE_NO_WARNINGS 1

//�ж����������⣺  �ж�B���Ƿ���A������������

//Ѱ�Һܸ��ڵ���ȵ�A�еĽ��,����ҵ��˾�ȥ�ݹ��ж��Ƿ�������,�����ǰ�Ľ�㲻��Ȼ��ߵ�ǰ�Ľ������Ѱ�Ҳ���������
//��ô����Ҫ��A�еĽ��������µݹ�Ȼ������Һ�root���ڵ���ȵĽ�� Ȼ������ݹ��ж�
//ʵ�����@����ʹ��������ݹ�
//�տ�ʼ�@��ĵݹ�û��д�����������Դ���



//�ж�B�Ƿ���A����������
bool _CheckKidTree(Node* Aroot, Node* Broot)s
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


void test()                                                   //���������������� ���� ��������������������
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int arr2[] = { 2, 6, '#', '#', 4, '#' };
	BinaryTree<int> t1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	BinaryTree<int> t2(arr2, sizeof(arr2) / sizeof(arr2[0]), '#');
	t1.PrevOrder();
	t2.PrevOrder();
	cout << t1.FindKidTree(t2);
}
int main()
{
	test();
	return 0;
}