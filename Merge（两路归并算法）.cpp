#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>

using namespace std;

//��·�鲢��  ��������ı�ϲ���һ������ı�

void MergeAct(int*& a1,int*&a2 ,int n1,int n2)         //�@�ﱨ����Ϊʲô��
{
	int i = 0;
	int j = 0;
	vector<int> _Array;
	while (i < n1 - 1 && j < n2 - 1)     //ֻҪ�������˵��������һ���Ѿ���β���ˡ�
	{
		if (a1[i] <= a2[j])
		{
			_Array.push_back(a1[i]);
			i++;
		}
		else
		{
			_Array.push_back(a2[j]);
			j++;
		}
	}
	while (i <= n1 - 1)              //ע���@��һ����=��  �Һü��ζ�ûд=�ž��Ǵ��
	{
		_Array.push_back(a1[i]);
		i++;
	}
	while (j <= n2 - 1)
	{
		_Array.push_back(a2[j]);
		j++;
	}
	int* tmp = new int[_Array.size()];
	for (size_t m = 0; m < _Array.size(); m++)
	{
		*(tmp + m) = _Array[m];
	}
	a1 = tmp;
}

int main()
{
	int arr1[] = { 1, 4, 6, 9, 10, 17 };
	int arr2[] = { 3, 5, 7, 8, 11 };
	MergeAct(arr1,arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]));
	return 0;
}