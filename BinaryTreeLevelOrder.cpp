#define _CRT_SECURE_NO_WARNINGS 1

//�������Ĳ������
//���ö���
#include<iostream>
#include<queue>
#include<string>
#include<assert.h>
using namespace std;

//�������
void LevelOrder()
{
	assert(_root);
	Node* cur = _root;
	queue<Node*> _q;
	_q.push(cur);
	while (!_q.empty())
	{
		if (cur->_left)
			_q.push(cur->_left);
		if (cur->_right)
			_q.push(cur->_right);
		cout << _q.front()->_data << " ";
		_q.pop();
		if (!_q.empty())             //ע���@��Ϊʲô���ж�   ��Ϊ���һ��pop  ���ö���Ϊ�գ�һ���յĶ���ȡfront( )�������󣡣�����ס��
			cur = _q.front();
	}
}
int main()
{
	return 0;
}