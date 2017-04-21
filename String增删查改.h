#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;


//class String
//{
//	friend ostream& operator<<(ostream& out, String& s);
//private:
//	char* _str;
//	size_t _size;               //_size�ĺ��壺 �±�    �ַ����ĳ���
//	size_t _capacity;
//public:
//	String(const  char* str = "")               //const���ε�ָ������ǲ����Ը�����һ��ָ��������@������Ȩ�޷Ŵ�      
//		:_str(new char[strlen(str) + 1])
//		, _size(strlen(str))
//		, _capacity(_size)
//	{
//		cout << "����" << endl;
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		:_str(new char[strlen(s._str)+1])
//		, _size(strlen(s._str))
//		, _capacity(_size)
//	{
//		strcpy(_str, s._str);
//		cout << "��������" << endl;
//	}
//	String& operator=(const String& s)
//	{
//		delete[] _str;
//		_size = 0;
//		_capacity = 0;
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//		_size = s._size;
//		_capacity = s._capacity;
//		return *this;
//	}
//	char& operator[](size_t index)
//	{
//		assert(index < _size);
//		return _str[index];
//	}
//	bool operator<(const String& s)            //     <�����������    ʹ��boolֵ
//	{
//		char* str = this->_str;
//		char* src = s._str;
//		while (*str && *src)           //�����ַ�����ÿ��'\0'
//		{
//			if (*str < *src)
//			{
//				return true;    //1          C++��������bool����   0Ϊ��  ��0Ϊ�棨һ����1��
//			}
//			else if (*str > *src)
//			{
//				return false;      //0
//			}
//			else
//			{
//				str++;
//				src++;
//			}
//		}
//		if (*src != 0)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//
//	bool operator==(const String& s)
//	{
//		char* str = this->_str;
//		char* src = s._str;
//		while (*str && *src)
//		{
//			if (*str != *src)
//			{
//				return false;
//			}
//			else
//			 str++;
//			 src++;
//		}
//		if ((*str || *src) == 0)
//			return true;
//		else
//			return false;
//	}
//
//	bool operator>(const String& s)  
//	{
//		/*return !((_str < s._str) || (_str == s._str));*/     //�@�з�ʽ�Ƚϵ����׵�ַ   ֱ������������ȥ�Ƚ�  *this����ָ�Ķ���
//		return !((*this < s) || (*this == s));
//	}
//	bool operator<=(const String& s)
//	{
//		return (*this < s) || (*this == s);
//	}
//	bool operator>=(const String& s)
//	{
//		return (*this > s) || (*this == s);
//	}
//	bool operator!=(const String& s)
//	{
//		return !(*this == s);
//	}
//
//
//	//******************************************************************************************************JX********************
//	void Expend(size_t n)                   //   ����
//	{
//		assert(n > _capacity);
//		_str = (char*)realloc(_str, n + 1);   //���¿��ٿռ�    //��Ȼ�@���@��д��Щ©�� û�п��ǿ��ٿռ�ʧ�ܵ����  
//		_capacity = n;
//	
//	}
//	void PushBack(char ch)      //����ַ�
//	{
//		if (_size == _capacity)
//		{
//			Expend(_size * 2);
//		}
//		_str[_size] = ch;
//		_str[_size + 1] = '\0';
//		_size++;
//	}
//	void Insert(size_t pos,const char ch)    //����λ�ò����ַ�
//	{
//		assert(pos < _size);                 
//		if (_size == _capacity)
//		{
//			Expend(_size * 2);
//		}
//		int end = (int)_size;
//		while (end >= (int)pos)
//		{
//			_str[end + 1] = _str[end];
//			end--;
//		}
//		_str[pos] = ch;
//		_size++;
//	}
//	void Insert(size_t pos, const char* ptr)    //����λ�ò����ַ���     Insert����������
//	{
//		assert(pos < _size);
//		size_t len = strlen(ptr);
//		int  end = (int)_size;                   //�����@��intǿת����Ҫ��������Ǹ���ѭ����bug  ���Ǻ����@����û��Ч��
//		if (_size + len >  _capacity)
//		{
//			Expend(_size + len);
//		}
//		while (end >= (int)pos)                   //˼��Ϊʲô���@��posǰ��Ҫǿת   posԭ�����޷�������  ������ת����int�Ϳ��Ա��������ڵ�һ��λ�ò����ʱ�����
//		{
//			_str[end + len] = _str[end];
//			end--;
//		}
//		size_t i = 0;
//		for (i = 0; i < len; i++)
//		{
//			_str[pos + i] = ptr[i];
//		}
//		_size += len;
//	}
//
//	void Insert(size_t pos, const String& s)      //��һ������ָ����ַ������뵽��һ������ָ����ַ�����ȥ
//	{
//		    Insert(pos, s._str);
//	}
//
//	void Erase(size_t pos, size_t len)               //�Ƴ�
//	{
//		assert(pos < _size);
//		if (pos + len>_size-1)               //�����@��Ϊʲô��Ҫ_size-1;
//		{
//			_str[pos] = '\0';
//			_size = pos;
//		}
//		char* dest = _str + pos;                         //�ַ�����������  ������'\0'ͣ������
//		char* src = _str + pos + len;
//		strcpy(dest, src);
//		_size -= len;
//	}
//	int Find(char ch)                   //�����ַ�
//	{
//		int i = 0;
//		for(i = 0; i < _size; i++)
//		{
//			if (_str[i] == ch)
//				return 1 ;
//		}
//		return 0;
//	}
//	char* Find(const char* ptr)          //�����Ӵ�
//	{   
//		char* p=strstr(_str, ptr);
//		if (p != NULL)
//		{
//			return p;
//		}
//		return NULL;
//	       
//	}
//	~String()
//	{
//		if (_str != NULL)
//		{
//			cout << "����" << endl;
//			delete[] _str;
//			_str = NULL;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//
//};
//ostream& operator<<(ostream& out, String& s)
//{
//	cout << s._str << endl;
//	cout << s._size << endl;
//	cout << s._capacity << endl;
//	return out;
//}
//void test()
//{
//	
//	String s1("Hello");
//	cout << s1;
//	/*s1.PushBack('o');
//	cout << s1;
//	printf("%p\n", &s1);
//	s1.Insert(1, 'E');
//	cout << s1;
//	printf("%p\n", &s1);
//	s1.Insert(1, "ABCDF");
//	cout << s1;
//	printf("%p\n", &s1);*/
//	String s2("Fjuxin");
//	cout << s2;
//	s2.Insert(0, s1);    //��BUG   pos������0             //���@�﷢���Ҳ����ڵ�һ��λ�ò���  Ҳ����pos����0����ȥ  ���������ڲ����ַ��������ڲ�endҲ��size_t����
//	cout << s2;                                              // �Ҳ���ִ�ж��ٴ�end--  ����>pos�� Ҳ��������ѭ��  ����û������� 
//	int i=s2.Find('x');
//	cout << i << endl;                                             //������������  �@�����ֱ����   ������ν�ĺ�������������һ�������ﵽ�����Լ���������͵���������
//	char* src=s2.Find("xin");
//	printf("%p\n", src);
//	cout << (s1 < s2) << endl;
//	return;
//}



//��String��һЩ������ģ��ʵ�ֵĹ����������ֵ����⣺   1.const���εĺ����β�  ��������ʲô�������� ���ߴӵײ� ������ôԼ���@��������  ����Ҫ�ı�һ��const���εı���Ҳ�ǿ��Ե�ʹ��һ��ָ������
//���@����  ����ʹ����_size ��_capacity ��ʵ���Ƕ����±꣨ʵ���ϣ�   ���Ǿ�������Ϊ���±�  ��һЩ������Χ��ѡ����ʱ��ʹ���һЩ���⣨�ǳ�ϸ�ڣ�
//�@������������bug  pos������  ������Ϊpos������ʱ������޷�������  ��������������ʱ����������ѭ��  ����ǿת������ �����Ҳ�̫���ɶ��˼
//��д����д������Ҳ����������C++��Ͷ���   ��������ص�����ں�   ��ʵ�����������������ã������������͵�����������Զ������͵����㣩  ���������ڴ���һ����Ķ���֮�� �ܶ��������Ҫ����ȥ���� 
//�����Ǹ����Ŀռ�ȥ����   
//�@�����������Ƕ����ַ����Ĳ���  Ҳ������ᵽ ����Ӧ������'\0';  �е�ʱ��ҲӦ���������'\0'

//��������  ��Щ������ȷʵû�����  ����const    �Ҿ����һ����ٶ࿴���ַ����@���������  �Ҿ����õ����ࣨ�����Ұ��ҵ��������ˣ�

//���   дʱ���� string���������@����֮���Ҿ�û����   ������Ҫ����һ��������߸ı�һ��������ָ������ݵ�ʱ��   ���Ǿ���Ҫ�õ�дʱ���� ��ʵ��Ϊ�����Ч��  
//����֪��   ���@�δ�������  ���õĶ���дʱ����˼����    ����[]���������û�����¿��ٿռ䰡  ��û������������дʱ������

//


//�����ַ����������ַ������һЩ�������
void test()
{
	//char* p = "abcdef";                       //�@�����ַ�����������̬���� ��ָ��Pָ���� ����ͨ��p������  �����ҷ����Ҳ���ͨ��p�ı���
	//char* str=new char[strlen(p)+1];           //��ֻ���Լ���һ�οռ�  ��һ��ָ��ָ����   �Ҿ���ͨ���@��ָ��ά����
	//strcpy(str, p);
	//printf("%s\n", str);
	//char* ptr = NULL;
	//ptr = str;                             //����ǰһֱ��Ϊ�Ұ�һ��ָ�������ֵ����һ��ָ�����  ��ô�Ǹ�ָ������ǲ����Ըı�ԭ��ָ��ָ��Ŀռ��ֵ��
	//printf("%s\n", ptr);                    //����ͨ��ʵ���ҷ��ֲ��ǵ�   ֻҪһ��ָ��ָ��һ��ռ� ��ô�@��ָ��Ϳ���ά���@���ռ� ���Ը������� �ؼ���������@���ռ��ò����˸ģ�������
	//ptr[1] = 'A';
	//printf("%s\n", ptr);
	//delete[] str;
	char p[] = "abcdef";                 //�@�������pֱ�Ӹ�������Ϊp���ٵ���һ���ַ�����  ����'\0'����   �ؼ������@���������ջ���� p���Բ�����
	printf("%s\n", p);
	p[1] = 'A';
	printf("%s\n", p);
	printf("%d\n", sizeof(p));

}  //�@����Ҳ��������Ϊʲôconst���ε�ָ���ǲ����Դ�����const���ε�ָ����    ��Ϊconst������֮��ָ��ָ��Ķ����ǲ��ܱ��ı�� ����һ�����˵�ָ��֮���������ݸı������Ǻ�����