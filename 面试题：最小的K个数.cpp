#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<assert.h>
using namespace std;

//��N�����е���С��K����   ע�⣺�����
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> tmpArr;
	if (k>0)
	{
		if (k == input.size())
			return input;
		if (k > input.size())
			return tmpArr;
		for (int i = 0; i<k; i++)
			tmpArr.push_back(input[i]);
		make_heap(tmpArr.begin(), tmpArr.end());
		for (size_t i = k; i < input.size(); i++)
		{
			if (input[i]<tmpArr.front())  //���С�ڶ��������Ǹ���
			{
				pop_heap(tmpArr.begin(), tmpArr.end());
				tmpArr.pop_back();
				tmpArr.push_back(input[i]);
				push_heap(tmpArr.begin(), tmpArr.end());
			}
		}
	}
	return tmpArr;
}
int main()
{
	////����heap�ӿڵ�ʹ����ϰ
	//int arr[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	//vector<int> v(arr, arr + 8);
	//make_heap(v.begin(), v.end());          //�ײ���ǽ���
	//////�������ʹ��make_heap����ô���µĽӿڶ����޷�ʹ�õģ����ᱨ���κλ�Ӱ���@���ӿ�֮��Ч���ģ����ǷǷ�������
	////pop_heap(v.begin(), v.end());           //�@���ӿ��ǰ������Ǹ����ŵ�����������
	////pop_heap(v.begin(), v.end());           //�ڶ���pop_heap( )�͹ҵ��ˣ�˵���@���ӿڵ�ǰ�������һ����
	////v.pop_back();
	////v.push_back(10);                        //����β��10
	////push_heap(v.begin(), v.end());           //�@����������һ�����ϵ����Ĺ��̣��@���ӿڵ�ǰ����Բ��Ƕ�
	////sort_heap(v.begin(), v.end());           //ͬ�����@���ӿڵ�ǰ���Ǳ���Ҫ��ʹ��make_heap��һ����
	//vector<int>::iterator vit = v.begin();
	//while (vit != v.end())
	//{
	//	cout << *vit << " ";
	//	vit++;
	//}
	//cout << endl;
	//�ܽ᣺ ����make_heap()������push_heap()�ӿڣ������Ľӿڱ����ǽ�������һ����֮�ϵġ�
	return 0;
}


