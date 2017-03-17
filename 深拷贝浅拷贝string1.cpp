//#include<iostream>
//using namespace std;
//class Array
//{private:
//	int _sz;
//	int *_ptr;
//public:
//	Array(int sz=4)
//		 :_sz(sz)
//		 ,_ptr(new int [_sz])//���ٶ�̬�ռ�;
//	{
//		cout << "Array()" << endl;
//	}//�������ҪĿ�ľ��Ǹ�_ptr���ٿռ䣻
//	Array(const Array& arr)
//	{
//		_ptr = arr._ptr;
//		_sz = arr._sz;
//	}//�@�����ִ�Ŀ���������̣���ϵͳĬ�ϵ��õĿ������캯����ǳ������
//	~Array()
//	{
//		cout << "~Array()" << endl;
//		if (_ptr != NULL)
//		{
//			delete[] _ptr;
//		}
//
//	}
//};
//int main()
//{
//	Array arr1;
//	Array arr2(arr1); 
//    system("pause");
//	return 0;
//} 


////������һ��ǳ���������лῨס��
//



#include<iostream>
using namespace std;
class Array
{
private:
	int _sz;
	int *_ptr;
public:
	Array(int sz = 4)
		:_sz(sz)
		, _ptr(new int[_sz])//���ٶ�̬�ռ�;
	{
		cout << "Array()" << endl;
	}//�������ҪĿ�ľ��Ǹ�_ptr���ٿռ䣻
	
	Array(const Array& arr)
		:_sz( arr._sz)
		, _ptr(new int[_sz]) //Ŀǰ�@���ǿ�������ͬ��С�Ŀռ䣨��arr2�Լ��ģ�����������û�п�����
	
	{
		cout << "Array(const Array& arr)" << endl;
		memcpy(_ptr, arr._ptr, _sz*sizeof(int));//�@����arr1�Ǹ�������������ݣ�
	}
	
	~Array()
	{
		cout << "~Array()" << endl;
		if (_ptr != NULL)
		{
			delete[] _ptr;
		}

	}
};
int main()
{
	Array arr1;
	Array arr2(arr1);
	system("pause");
	return 0;
} 