#define _CRT_SECURE_NO_WARNINGS 1

//���ü���+дʱ��������ϰ     []�����������
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
	friend ostream& operator<<(ostream& out, String& s);
private:
	char* _str;
	int* _refCount;
public:
	String(const char* str = "")   //���캯��
		:_str(new char[strlen(str)+1])
		, _refCount(new int(1))
	{
		cout << "����" << endl;
		strcpy(_str, str);
	}
	String(String& s)              //��������
	{
		cout << "��������" << endl;
		_str = s._str;
		_refCount = s._refCount;
		++(*_refCount);
	}
	String& operator=(String& s)    //��ֵ���������
	{
		if (this != &s)
		{
			if (--(*_refCount) == 0)
			{
				delete[] _str;
				delete _refCount;
			}
			_str = s._str;
			_refCount = s._refCount;
			++(*_refCount);
		}
		return *this;                       //�ǵ÷���ֵ
	}
	char& operator[](size_t index)
	{
		assert(index < strlen(_str));                 //�@����д���Ǵ��ڴ����
		return _str[index];
	}

	~String()
	{
		if (NULL != _str)
		{
			if (--(*_refCount) == 0)            //�@���ж��Լ�ָ��Ŀռ���û����������ָ��
			{
                cout << "����" << endl;
				delete[] _str;
				delete _refCount;
				_str = NULL;
			}
		}
	}

};
ostream& operator<<(ostream& out, String& s)
{
	out << s._str;
	/*cout << s._refCount;*/
	return out;
}
int main()
{
	String s1("hello\n");
	cout << s1;
	String s2(s1);
	cout << s2;
	String s3(s2);
	String s4(s3);
	cout << s4;
	String s5("BIT\n");
	s4 = s5;
	cout << s4;
	s5[1] = '0';
	cout << s5;
	return 0;
}