#define _CRT_SECURE_NO_WARNINGS 1

#include"RBTree.h"

void test()
{
	RBTree<int, int> R1;
	R1.Insert(7);
	R1.Insert(2);
    R1.Insert(1);
	R1.Insert(4);
	R1.Insert(33);
	R1.Insert(27);
	R1.Insert(3);
	R1.Insert(6);
	R1.Insert(31);
	R1.Insert(0);
	R1.Insert(19);
	R1.Insert(20);
	R1.Insert(25);
	R1.Insert(21);
	R1.Insert(10);
	R1.Insert(13);
	R1.Insert(24);
	R1.Insert(20);
	R1.Insert(8);
	R1.Insert(20);
	R1.Insert(67);
	R1.Insert(5);
	R1.Insert(65);
	R1.Insert(90);
	R1.Insert(14);
	cout<<R1.Insert(2)<<endl;
	R1.InOrderR();                                //������������Ľ�����൱������һ���� ������������˵��������Ľ�����Ǵ�С����
	cout<<R1.Find(3)<<endl;                       //ʵ�����ұȽ������ʵ���Ϊʲô����������ƽ��������Ĳ��ҵķ���ֵ��bool���@����ʵ�ʵ�Ӧ���й�ϵ��
}
int main()
{
	test();
	return 0;
}
