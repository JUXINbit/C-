#define _CRT_SECURE_NO_WARNINGS 1

//STL��ʹ���Ƿǳ���Ҫ�� ��ѧϰSTL�ĵ�һ�׶ξ���һ��Ҫ����ʹ��STL
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
//1. vector�Ļ���ʹ��

//int main()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//	vector<int>::iterator it1 = v1.begin();    //�տ�ʼ���벻ͨ��������ʵ�ִ�ӡvector �������ָ���û�ж�������������Ҳ�����׵������������Ǻ���Ҫ��
//	while (it1 != v1.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//	//cout << *(v1.end()-1) << endl;
//	return 0;
//}

//��print����д�ں������� ���@�����ӷ���
//void PrintMyVector(const vector<int>& v)             //����ʹ��const���ε�ʱ�� vector����ĵ�����Ҳ����Ҫʹ��const_iterator ��Ȼû��ʹ��
//{
//	vector<int>::const_iterator  it = v.begin();      //const������ʹ�ú���Ҫ
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//template <class T>
//void PrintMyVector(vector<T>& v)                 //��ģ�������ʹ��   �Ѵ�ӡ���������ģ�庯�� �@���Ļ���ӡ�͸��ӷ�����     
//{
//	vector<T>::iterator  it = v.begin();
//	while (it != v.end())
//	{
//		//*it = 1;             //�������Ķ����ܹ���vector��Ԫ�ؽ����޸�
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//�ټ�һ��
template <class T>
void PrintMyVector(T& v)                 
{
	T::iterator  it = v.begin();
	while (it != v.end())
	{
		//*it = 1;            
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
//int main()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	PrintMyVector(v1);
//	vector<string> v2;
//	v2.push_back("hh");
//	v2.push_back("jj");
//	v2.push_back("kk");
//	PrintMyVector(v2);
//	/*vector<int> v2;
//	v2.push_back(4);
//	v2.push_back(5);
//	v2.push_back(6);
//	v2.push_back(7);
//	PrintMyVector(v2);*/
//	return 0;
//}



//2.std::list
//������vector
int main()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	PrintMyVector(l1);
	return 0;
}