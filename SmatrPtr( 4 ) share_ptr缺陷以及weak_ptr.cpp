#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<memory>
using namespace std;

//shared_ptr��ѭ����������ͽ����ʽ
struct ListNode
{
	int _data;
	weak_ptr<ListNode> _next;        //�������;���ListNode ���@��Ľ��û�ж����ģ����
	weak_ptr<ListNode> _prev;       
	ListNode(int d)
		:_data(d)
	{
		cout << "������" << endl;
	}
	~ListNode()
	{
		cout << "�������" << endl;
	}
};


void test()
{
	shared_ptr<ListNode> n1(new ListNode(3));     //�Զ��ͷſռ�  ����listnode����������
	shared_ptr<ListNode> n2(new ListNode(4));          //�Ҵ����������� ����������������ָ�����ָ��Է���ָ�룬n1��n2���ڷֱ�������������
	//���ֻ�����������д��� �����ֻ��������� 
	n1->_next = n2;
	n2->_prev = n1;                 //��������㻥������  ���д��� ���ִ��벻������

	//��������ĳ�weak_ptr֮�󣬾ͻ�ɹ������������� ��ʵ������ָ������ڸ���shared_ptr��������@�г����µ������������������������ָ���Զ�����
}
int main()
{
	test();
	return 0;
}



//ע�⣺ ��ָ��û�й��캯�� ����ȫ��������shared_ptr����