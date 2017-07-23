#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;
//��ά����Ĳ���
//һ����ά�����У�ÿһ�ж����մ����ҵ�����ÿһ�д��ϵ��µ�����ʵ��һ����������һ����ά�����һ��������
//�ж����Ƿ�����������

//����һ�� �����⣬������ά�������һ�飺 ʱ�临�Ӷȣ�o��N*N�� �ռ临�Ӷȣ�o��1��

//����������һ���ж�һ�� ������  ʱ�临�Ӷȣ�o��N��  �ռ临�Ӷȣ�o��1�� ������ ʵ�ָ��ӿ���ֻ�ǵ�һ�ֵ��Ż�����

//�����������þ������Ͻǵ�Ԫ��ֵ �𽥼���������Χ   �䲻�Ƕ��ֲ��ҵ���˼���ڶ��ֲ���һ�� 
bool SearchInDarry(int a[][4],int rows,int lines,int num)
{
	assert(a);
	assert(rows);
	assert(lines);
	int row = 0;                        //ע�����Ͻǣ���һά��Ԫ���Ǵ�0������������
	while (row<rows && lines >= 0)
	{
		if (a[row][lines - 1] > num)
		{
			lines--;
			continue;                   //ע���@���continue  
		}
		if (a[row][lines - 1] < num)
			row++;
		else
			return true;
	}
	return false;
}

//-------------------test------------------------------
void test()
{
	int arr[][4] = { 
		{ 1, 2, 8, 9 }, 
	    { 2, 4, 9, 12 }, 
	    { 4, 7, 10, 13 }, 
	    { 6, 8, 11, 15 } };
	cout << SearchInDarry(arr, 4, 4, 1);
	cout << SearchInDarry(arr, 4, 4, 2);
	cout << SearchInDarry(arr, 4, 4, 9);
	cout << SearchInDarry(arr, 4, 4, 6);
	cout << SearchInDarry(arr, 4, 4, 13);
	cout << SearchInDarry(arr, 4, 4, 15);
	cout << SearchInDarry(arr, 4, 4, -1);
	cout << SearchInDarry(arr, 4, 4, -1);
	cout << SearchInDarry(arr, 4, 4, 3);
	cout << SearchInDarry(arr, 4, 4, 20);
	cout << SearchInDarry(arr, 4, 4, 14);
}
int main()
{
	test();
	return 0;
}