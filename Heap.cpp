#define _CRT_SECURE_NO_WARNINGS 1

//�ѱ�������һ���㷨    �����԰�������һ�����ʣ�
#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;



template<class T>
struct LessThan                                  //ʹ�÷º���  ʵ�ִ��С�ѵĴ�������ͬһ�δ���  дһ���Ƚ���
{
	T left;
	T right;
	bool operator()(const T& left, const T& right)             
	{
		return left < right;
	}
};

template<class T>
struct MoreThan
{
	T left;
	T right;                                        //�@��ĳ�Ա������дҲûʲô  ������Ҳ����ֻ�г�Ա�������һ���Ĳ�������һ��Ҫ�г�Ա����
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};


template<class T,class Compare=MoreThan<T>>
class Heap
{
private:
	vector<T> _a;                 //�ѵı���ʵ�����Ƕ�vector�Ĳ���
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
       
		//    ����     //�����ǽ���ѻ��ǽ�С�ѣ� ����ʹ�����µ����㷨  ֻ�����µ��ıȽϲ�һ������
		for (int i = (_a.size() - 2) / 2; i >= 0; i--)     //���  �ӵ�������ѭ���������µ����㷨
		{
			AdjustDown(i);  //���µ����㷨  
		}
		
	}
	 
	void AdjustDown(int  root)          //[*]  ���µ����㷨�������ǵ�ǰ�����±꣬���@����㿴�ɸ���㣬���@����㿪ʼ���ϵ����ɴ�С
	{
		Compare con;
		int parent = root;
		int child = parent * 2 + 1;     //����Ƚ�ѭ���Ķ�������
		while (child<_a.size())                  //���child�����һ��Ԫ��  -> child=_a.size()-1     ע�⣺size������  ���������±�
		{
			//�Ⱥ��ֵܱȽϴ�С ѡ�����
			if (child != _a.size() - 1 && con(_a[child + 1] , _a[child]))
			{
				child++;
			}

			if (con(_a[child] , _a[parent]))
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

	void AdjustUp(int root)   //���ϵ����������β������һ�����ݣ�����Ϊ��� (�����β������)
	{
		int child = root;
		int parent = (child - 1) / 2;                //������������������������������-1��/2���ǵ��ڸ���� ��һ��ʼ��Ϊ��������-1��/2��ֵ��������/2��һ���� ���Ǹ���㣬��Ϊ����������Ҳ��һ�������Ƿ��������������/2���𰸲��Ǹ����
		while (parent >= 0)
		{
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (parent - 1) / 2;
			}
			else
				break;
		}
	}


	void Push(const T& d)
	{
		_a.push_back(d);
		AdjustUp(_a.size()-1);              //�����һ�����������ϵ���
	    
	}
	
	void Pop()         //ɾ����Ͻ��
	{
		swap(_a[_a.size() - 1], _a[0]);
		_a.pop_back();
		AdjustDown(0);
	}

	bool IsHeap()                 //�ж��Ƿ��Ǵ��
	{
		for (size_t i = 0; i <= (_a.size() - 2) / 2; i++)
		{
			if (_a[i] < _a[i * 2 + 1] || _a[i] < _a[i * 2 + 2])
			{
				return false;
			}
		}
		return true;
	
	}

	


	void PrintHeap()
	{
		for (size_t i = 0; i < _a.size(); i++)                 //���⣺vector�Լ�Ҳ���Լ��ĵ�����
		{
			cout << _a[i] << " ";
		}
		cout << endl;
		
	}

};


void test()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int> h1(a, sizeof(a) / sizeof(a[0]));          //�����Ƚ����ģ������ͻ��Զ�����ȱʡ��ģ�����
	h1.PrintHeap();
	Heap<int, LessThan<int>>h2(a, sizeof(a) / sizeof(a[0]));
	h2.PrintHeap();
	/*h1.Push(20);
	h1.PrintHeap();
	h1.Pop();
	h1.PrintHeap();*/


}
int main()
{
	test();
	return 0;
}