#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
//��Ŀ������ ��һ�������е�ǰ���ɸ�Ԫ���ƶ��������ĩβ�������������ת
//����һ�����������һ����ת�������ת�����е���С����
//���磺 ����{3,4,5,1,2}��������{1,2,3,4,5}��һ����ת���ҳ�������С������  ��С����Ϊ1

//������ʹ�ö��ֲ��ҵı���  ��������ָ�룬ÿ����С���ҷ�Χ��һ��


//[***�������***]���˵������ȣ���ôû�а취�жϲ�����С�ռ䣬�@�������ֻ�ܱ���
int SpecialStation(const int a[], int begin, int end)
{
	int tmp = a[begin];
	for (size_t i = begin + 1; i <= end; i++)
	{
		if (a[i] < tmp)
		{
			tmp = a[i];
		}
	}
	return tmp;
}
int FindInRevsArr(const int a[],size_t length)
{
	assert(a);
	assert(length);
	int PrevIndex = 0;
	int BackIndex = length - 1;
	//����û����ת�����
	if (a[0] < a[length - 1])
	{
		return a[0];
	} 
	while (a[PrevIndex] >= a[BackIndex])    //�@���ѭ������������˼���Ǳ�֤����ָ����ǰ����������
	{
		if (BackIndex - PrevIndex == 1)
			break;
		int MidIndex = PrevIndex + ((BackIndex - PrevIndex) >> 1);  //��ƽ��ֵ��ϰ�߿��������

		//һ��Ҫ���ǵ��������:  �����������ȵ�ʱ��ע��ֻ����������Ȳ�����������������������һ������һ�����ǿ������������������ִ�е�
		if (a[MidIndex] == a[PrevIndex] && a[MidIndex] == a[BackIndex])
			return SpecialStation(a, PrevIndex, BackIndex);
		//ע��㣺 ���ж�����Ķ���ȵ���������жϲ���ȵ������������Ǿͻ���ִ�

		//ÿ�ο��м��Ԫ��������ǰ��ĵ������ֻ��Ǻ���ĵ�������
		//�����ǰ��ģ�����ǰָ�������С��Χ����֮�ú�ָ��ǰ����С��Χ��ÿ����Сһ�벢��ȷ��ǰ��ָ��һ������ǰ�沿��һ�����ں���
		if (a[MidIndex] >= a[PrevIndex])
			PrevIndex = MidIndex;
		else if (a[MidIndex] <= a[BackIndex])      //�@���ҵ�������< ������<=  ����Ҳ��  Ȼ���ڳ����ظ����ֵ�ʱ��ͳ����˴���
			BackIndex = MidIndex;
	}
	return a[BackIndex];
}
void test()
{
	int arr[] = { 1, 1, 1, 0, 1, 1, 1 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	cout << FindInRevsArr(arr, size) << endl;
}
int main()
{
	test();
	return 0;
}
