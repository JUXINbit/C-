#define _CRT_SECURE_NO_WARNINGS 1
//��ջ��˳����12345��   �Ϸ��ĳ�ջ˳����45321   �Ƿ��ĳ�ջ˳����43512
#include<iostream>
#include<assert.h>
#include<stack>
using namespace std;
//�@������ѵ���������жϲ���һ���������У����������е����ֶ�ѹջ��֮����Ȼû���ҵ���һ�����������֣��Ͳ���һ����ȷ��������
bool PushAndPop(const int* InArr,size_t size1,const int* OutArr,size_t size2)
{
	assert(InArr);
	assert(OutArr);
	stack<int> _s;
	int PushPtr = 0;
	int PopPtr = 0;
	if (size1 != size2)
		return false;
	while (PopPtr != size2)
	{
		if (_s.empty())          //��ڷ���ջ�ǿյĻ�������pushһ��Ԫ��
			_s.push(InArr[PushPtr++]);
		while (PushPtr != size1&&_s.top() != OutArr[PopPtr])
		{
			_s.push(InArr[PushPtr++]);
			if ((PushPtr == size1)&&(_s.top() != OutArr[PopPtr]))
			{
				return false;
			}
		}
		if (PushPtr == size1)                     //�@���ǳ���Ĺؼ��ط����@��û�м��@���жϾ͵���������
		{
			if (_s.top() != OutArr[PopPtr])
				return false;
		}
		_s.pop();
		PopPtr++;
	}
	if (PopPtr == size2&&_s.empty())
		return true;
	else
		return false;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 5, 3, 2, 1 };
	//int arr2[] = { 4, 3, 5, 1, 2 };
	cout << PushAndPop(arr1, sizeof(arr1) / sizeof(arr1[0]), arr2, sizeof(arr2) / sizeof(arr2[0]));
	return 0;
}