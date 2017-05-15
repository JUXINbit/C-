#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

//���ȼ�����   ��STL��������������ģʽ�Ķ�  
//ģ��ķ���������ģ��  ���������Ӹ������    ģ����ģ�庯����֧�ַ�����룬���������ֻ����һ���ļ�hpp�� 
//�����@����Ĳ�����������ģʽʵ�ֵĶѣ����У���ֻ��������  ��������ģʽ��ģ������б�����������ģ����� ���ҳ�Ա������һ������ģ�岻�Ǿ��������
template<class T ,class Compare=MoreThan<T>>
class PriorityQueue
{
private:
	Heap<T, Compare> _h;
public:
	PriorityQueue()               //�޲ι��캯��
	{
	}
	PriorityQueue(T* a,size_t n)             //���ι��캯��
	{
		for (size_t i = 0; i < n; i++)
		{
			_h.Push(a[i]);
		}
	}
	void Push(const T& p)                   //���
	{
		_h.Push(p);
	}
	void Pop()                             //����
	{
		_h.Pop();
	}
	void Print()                                //�ӵĴ�ӡ
	{
		while (!(_h.Empty()))
		{
			cout << _h.Front()<<" ";
			Pop();
		}
		cout << endl;
	}
};




--------------------------------------------------���ԡ�����������������������������������������������
void test()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	PriorityQueue<int,MoreThan<int>> pQ (a, sizeof(a) / sizeof(a[0]));
	//pQ.Print();
	pQ.Push(20);
	//pQ.Print();
	//pQ.Pop();
	pQ.Print();
}
int main()
{
	test();
	return 0;
}
