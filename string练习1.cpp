#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class String
{
	friend ostream& operator<<(ostream& os, String& s);
private:
	 char* _str;
public:
	String(const char* str="")//һ��Ҫ���Ϊɶ�����ڹ��캯����ʱ���Ҫ���ٿռ䣻
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
		cout << "���캯��" << endl;
		cout << _str << endl;
	}
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
		cout << "�������캯��" << endl;
		
	}
	String& operator=(const String& s)//��ֵ����������أ�
	{
		if (&s != this)
		{ 
			delete[] _str;
			_str=new char[strlen(s._str) + 1];//������ǳ�ʼ���б�
			strcpy(_str, s._str);
		} 
		return *this;
	}
	~String()
	{   
		if (_str != NULL)//�ǵ�ַ��Ϊ��
		{  
			delete[] _str;
			_str = NULL;
		}
		
		cout << "��������" << endl;
	}
};
ostream& operator<<(ostream& os, String& s)
{
	os << s._str;
	return os;
}
int main()
{
	String s1("Fighting!");
	String s2(s1);
	cout << s2 << endl;
	String s3("JUXIN");
	s2 = s3;//�@�����Ҫһ��operator=�ĸ�ֵ������������ˣ�ע�������ص�ʱ����Ҫ�ͷ���������ǰ�湹�캯����""���ַ���ռ�õĿռ�Ŷ
	//s1[4] = 'T';//������Ҫʵ�ָ��������ĳ����ĸ�ͱ���Ҫ����[]����������أ�

	

	system("pause");
	return 0;
}