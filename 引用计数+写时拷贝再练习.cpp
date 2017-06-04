#define _CRT_SECURE_NO_WARNINGS 1
//���ü���+дʱ����˼�������      ͨ��[]��������������дʱ����     
#include<iostream>
#include<assert.h>
using namespace std;

class String
{
private:
	char* _str;
	int* _refCount;
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
		, _refCount(new int(1))             //����һ�����οռ���ָ��ά��
	{
		strcpy(_str, str);
		cout << "����" << endl;
	}
	String(const String& s)
		:_str(s._str)
	{
		cout << "��������" << endl;
		_refCount = s._refCount;
		*(_refCount)++;
	}
	char& operator[](size_t index)             //����ڲ��Ժ�������ע�ͳ��������� ���@���[]���ؽ�����дʱ���� //�@����д����   Ҫ����һ��char&
	{
		if (--(*_refCount) != 0)      //����Ҫ�ı�Ķ�����ָ��Ŀռ仹�������Ķ���ָ���ʱ�� ��Ҫ�������������  ��Ҫ�Լ����¿��ٿռ�
		{
			                                       //�@���ͽ���˶������ָ��ͬһ�����ݵĶ�����һ��Ҫ���иı䣨������Ӱ��������������ݣ���ʱ��
			char* ptr = _str;
			_str = new char[strlen(ptr) + 1];         //���¿��ٿռ�  ��Ӱ�������Ķ���
			_refCount = new int(1);
			strcpy(_str, ptr);
		}
		assert(index < strlen(_str));
		return _str[index];                         
	}
	const char& operator[](size_t index) const  //�����������±����ı�һ������ָ��Ŀռ�����ݵ�ʱ��  ��Ҫдʱ�����ؿ��ռ� 
	{                                          //�����@���Ļ�ò��ÿ��ʹ�õ�[]�����ؿ��ռ� �����ڶ���ʱ��ò�Ʋ���Ҫ�ı��ַ���������
		assert(index < strlen(_str));
		return _str[index];                          //����cout<<s1[5]<<endl;  ����Ҫ����ʱ�򲢲���Ҫ���¿��ٿռ����ַ��������ü���  ����
	}                                               //���Ǳ���Ҫ�ٴ�����һ��[]����  ר�Ź���ȡʹ��

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			if (--(*_refCount) == 0)              //�@��ע�⣺   *_refCount���жϵ�ʱ���Ѿ��ı���  ���ܽ�û��ȥ ���ı���  ������ϰ��ʱ����ִ���
			{
				delete[] _str;
			}
			_str = s._str;
			_refCount = s._refCount;
			*(_refCount)++;
		}
		return *this;
		
	}
	void Print()
	{
		cout << _str << endl;
	}
	~String()
	{
		if (_str)
		{
			if (--(*_refCount) == 0)          //������ʱ���Լ����������ж�
			{
				cout << "����" << endl;
				delete[] _str;
				_str = NULL;                //ע��ϰ��  ��ֹ����ָ��
			}

		}
	}
};
int main()
{
	String s1("hello");
	s1.Print();
	String s2(s1);
	s2.Print();
	s2[1] = 'E';           //дʱ����
	s2.Print();
	s1.Print();           //���@�����Ƿ�����ԭ������Ҫ�ı�s2���������   ���Ƿ���s1Ҳ��֮�ı���  ��Ϊs2��s1ָ��ͬһ��ռ� 
	s1 = s2;
	s1.Print();
	String s3 = "HELLO";
	String s4 = "HHHHH";
	s4 = s3;
	s4.Print();
	String s5 = "jjjjj";
	s5.Print();
	cout << s5[2] << endl;     //��
	return 0;
}