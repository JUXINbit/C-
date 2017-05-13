#define _CRT_SECURE_NO_WARNINGS 1

//�ѱ�������һ���㷨    �����԰�������һ�����ʣ�
#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;


template<class T>
class Heap
{
private:
	vector<T> _a;                 //�ѵı���ʵ������vector 
public:
	Heap()     //�޲ι��캯�� ʵ��������vector�Լ�����ȱʡ�Ĺ��캯��
	{
	}
	Heap( T* a, size_t n)    //���캯�����������ֵһһ��vector
	{
		_a.reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			_a.push_back(a[i]);
		}
       
		//�����
		for (int i = (_a.size() - 2) / 2; i >= 0; i--)     //���  �ӵ������Ͻ������ϵ����㷨
		{
			AdjustDown(i);
		}
	}
	 
	


	void AdjustDown(int  root)          //[*]  ���µ����㷨�������ǵ�ǰ�����±꣬���@����㿴�ɸ���㣬���@�������ϵ����ɴ�С
	{
		int parent = root;
		int child = parent * 2 + 1;     //����Ƚ�ѭ���Ķ�������
		while (child<_a.size())                  //���child�����һ��Ԫ��  -> child=_a.size()-1     ע�⣺size�����Ǹ��������±�
		{
			//�Ⱥ��ֵܱȽϴ�С ѡ�����
			if (child != _a.size()-1 && _a[child + 1] > _a[child])
			{
				child++;
			}

			if (_a[parent] > _a[child])
			{
				swap(_a[parent], _a[child]);
				parent = child;
				child = child * 2 + 1;
			}
			else
			{
				break;
			}

		}

	}



};
void test()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int> h1(a, sizeof(a) / sizeof(a[0]));


}
int main()
{
	test();
	return 0;
}