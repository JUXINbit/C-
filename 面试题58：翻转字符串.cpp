#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//�ַ����ķ�ת����
//�����ӣ� ���"I am a student ." ���"student .a am I"
//�������ǳ��򵥣����η�ת

//��תһ������  
void ReverseWords(char* str,int begin,int end)
{
	assert(str);
	char tmp = 0;
	while (begin != end)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
}
void ReverseAll(char* str, int size)
{
	assert(str);
	assert(size);
	int begin = 0;
	int end = size - 2;
	char tmp = 0;
	while (begin != end)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
	//ǰ��ָ�뷨��ȷ����Ҫ��ת���ַ����ĳ���
	int head = 0;
	int tail = 0;  
	while (str[head] != '\0')
	{
		head++;
		while (head != ' ')
		{
			if (str[head] == '\0')
				break;
			head++;
		}
		ReverseWords(str, tail, head - 1);
		tail = head;
	}
}
void test(void)
{
	char str[] = "I am a student.";
	ReverseAll(str, strlen(str) + 1);
	cout << str << endl;
}
int main()
{
	test();
	return 0;
}