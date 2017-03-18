#include <iostream>
#include <assert.h>
using namespace std;

 ���ݽṹ
 ��ͳд��
class String
{
public:
	//String()
	//{
	//	_str = new char[1];
	//	_str[0] = '\0';
	//}

	String(char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	// s1 = s2
	String& operator=(const String& s)
	{
		if (this != &s)
		{
		/*	delete[] _str;
			_str = new char[strlen(s._str)+1];
			strcpy(_str, s._str);*/

			char* tmp = new char[strlen(s._str)+1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
		}

		return *this;
	}

	~String()
	{
		delete[] _str;
		_str = NULL;
	}

	char* GetStr()
	{
		return _str;
	}

private:
	char* _str;
};


class String
{
public:
	//String()
	//{
	//	_str = new char[1];
	//	_str[0] = '\0';
	//}

	String(char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	// s1(s2)
	String(const String& s)
		:_str(NULL)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	// s1 = s2
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String tmp(s);
	//		swap(_str, tmp._str);
	//	}

	//	return *this;
	//}

	// s1 = s2
	String& operator=(String s)
	{
		swap(_str, s._str);

		return *this;
	}

	~String()
	{
		delete[] _str;
		_str = NULL;
	}

	char* GetStr()
	{
		return _str;
	}

private:
	char* _str;
};

// ˼��
// 1.��ͳд��
// 2.�ִ�д��
class String
{
public:
	String(char* str = "")
		:_str(new char[strlen(str)+1])
		,_refCount(new int(1))
	{
		strcpy(_str, str);
	}

	// s1(s2)
	String(String& s)
		:_str(s._str)
		,_refCount(s._refCount)
	{
		++(*_refCount);
	}

	/*String(String& s)
		:_str(NULL)
		,_refCount(NULL)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
		swap(_refCount, tmp._refCount);
	}*/


	//// s1 = s2
	//String& operator=(const String& s)
	//{
	//	// 1.s1��s2�Ƿ�ָ��ͬһ��ռ�
	//	// 2.����s1ָ��ռ�����ü�������s1�����һ�����������ͷ�
	//	if (_str != s._str)
	//	{
	//		this->Release();

	//		this->_str = s._str;
	//		_refCount = s._refCount;
	//		++(*_refCount);
	//	}

	//	return *this;
	//}

	String& operator=(String s)
	{
		swap(_str, s._str);
		swap(_refCount, s._refCount);
		return *this;
	}

	void Release()
	{
		if (--(*_refCount) == 0)
		{
			cout<<"delete"<<endl;
			delete[] _str;
			delete _refCount;
		}
	}

	//String* this
	char& operator[](size_t index)
	{
		// дʱ����
		CopyOnWrite();

		assert(index < strlen(_str));
		return _str[index];
	}

	// const String* this
	const char& operator[](size_t index) const
	{
		assert(index < strlen(_str));
		return _str[index];
	}

	//void PushBack()
	//Insert
	//Erase

	~String()
	{
		Release();
	}

	char* GetStr()
	{
		return _str;
	}

	// s1[0]
	void CopyOnWrite()
	{
		// ������ü�������1������Ҫ���п���
		if (*_refCount > 1)
		{
			char* tmp = new char[strlen(_str)+1];
			strcpy(tmp, _str);
			--(*_refCount);

			_refCount = new int(1);
			_str = tmp;
		}
	}


private:
	char* _str;
	int* _refCount;
};

void f(const String& s)
{
	//const String* this
	//String* const this
	// s.operator[](&s)
	cout<<s[0]<<endl;
}

void TestString()
{
	String s1("hollo");
	String s2(s1);
	String s3(s2);

	f(s1);

	// ����ʱ��Ҳ�´��
	cout<<s1[1]<<endl;
	//s1[1] = 'e';
}


//void TestString()
//{
//	String s1("hollo");
//	String s2(s1);
//	////String s3(s2);
//	//
//	//s1[1] = 'e';
//
//	//String s4("world");
//	//String s5(s4);
//}

int main()
{
	TestString();

	return 0;
}

#include <iostream>
using namespace std;

#include <assert.h>

#include <string>
#include "String.h"


int main()
{
	TestString();

	return 0;
}