#define _CRT_SECURE_NO_WARNINGS 1

//���⣺ʲô����������ģʽ��
//   ʲô��������
// ջ�Ͷ����@�������ݽṹ���ص����ʲô��


//#include"List.h"
////   ����
//template<class T,class Container>     //Container���@��������
//class Queue                         //���� �Ƚ��ȳ�
//{
//private:
//	Container _con;
//public:
//	void Push(const T& s)
//	{
//		_con.PushBack(s);
//	}
//	void Pop()
//	{
//		_con.PopFront();
//	}
//	size_t Size()
//	{
//		return _con.Size();             //����@���������������һ��ֵ��һ��Ҫ��סҪ����ֵ
//	}
//	const T& Top()
//	{
//		return _con.Front();             //  ��סҪ����ֵ  �տ�ʼ�Ҿ�д��һ�� _con.Front();
//		
//	}
//	void Print()
//	{
//		//List<T>::Node* tmp = List<T>::_head;
//		while (_con.Empty() == 0)
//		{
//			cout<<Top()<<" ";
//			Pop();                             //�@��һ��Ҫ�������۵Ĳ鿴
//		}
//		//List<T>::_head = tmp;
//		cout << endl;
//	}
//};
//
//
//void test()
//{
//	Queue<int,List<int>> q1;
//	q1.Push(1);
//	q1.Push(2);
//	q1.Push(3);
//	q1.Push(4);
//	//q1.Print();
//	//q1.Pop();                   //�����@���ʱ�����������  ����֮ǰ��Print��ʱ��  �Ͱ�����pop����  Ҳ������Ҫ������������ɶ ��Ҫ�������۵�
//	//q1.Pop();
//	//q1.Pop();
//	//q1.Print();
//	cout<<q1.Size()<<endl;
//
//
//}
//int main()
//{
//	test();
//	return 0;
//}


//Stack  ��
#include"SeqList.h"
#include"List.h"
//template<class T,class Container=SeqList<int>>     //��Ĭ�ϲ�����ģ������б�
//class Stack
//{
//private:
//	Container _con;
//public:
//	void Push(const T& d)      //ѹջ
//	{
//		_con.PushBack(d);
//	}
//	void Pop()                //��ջ
//	{
//		_con.PopBack();
//	}
//	const T& Top()            //ջ��
//	{
//		return _con.Back();
//	}
//	void Print()              //��ӡ
//	{
//		while (_con.Empty()==0)
//		{
//			cout << Top() << " ";
//			Pop();                       //����ջֻ�ܶ�ջ�����в���  �����@���ӡ�������ӡ
//		}
//	}
//
//};

//ģ���ģ�������д��
template<class T, template<class>class Container>   //�@������һ��template<class>����˵���@��ģ������б�����һ��������ģ�� Container��һ������ģ�壬�����@�������ΪStack��ģ�����
class Stack
{
private:
	Container<T> _con;                         //�����治ͬ���@��Ҫ�@��д
public:
	void Push(const T& d)      //ѹջ
	{
		_con.PushBack(d);
	}
	void Pop()                //��ջ
	{
		_con.PopBack();
	}
	const T& Top()            //ջ��
	{
		return _con.Back();
	}
	void Print()              //��ӡ
	{
		while (_con.Empty() == 0)
		{
			cout << Top() << " ";
			Pop();                       //����ջֻ�ܶ�ջ�����в���  �����@���ӡ�������ӡ
		}
	}

};
void test()
{
	Stack < int, List>s1;              //���@��Ϳ��Բ�д��List<int>�@����  �@���ͱ�������ʵ������ʱ��д��Stack<int , List<char>>�@���Ĵ��������鷳
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Pop();
	/*s1.Print();*/      //�@����Ȼ��������  ���Ǵ�ӡ��Ҫ��������  �����Ĳ����޷���ɣ���Ҫ�������ݸ���ô��            
	cout << s1.Top() << endl;
}
int main()
{
	test();
	return 0;
}