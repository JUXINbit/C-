#define _CRT_SECURE_NO_WARNINGS 1

//���⣺ʲô����������ģʽ��
//   ʲô��������
// ջ�Ͷ����@�������ݽṹ���ص����ʲô��


#include"List.h"

template<class T,class Container>     //Container���@��������
class Queue                         //���� �Ƚ��ȳ�
{
private:
	Container _con;
public:
	void Push(const T& s);
	void Pop();
	size_t Size();
	void Print();
};

template<class T,class Container>
void Queue<T, List<T>>::Push(const T& s)
{
	_con.PushBack(s);
}

template<class T, class Container>
void Queue<T, List<T>>::Print()
{
	_con.Print();
}
void test()
{
	Queue<int,List<int>> q1;
	

}
int main()
{
	test();
	return 0;
}