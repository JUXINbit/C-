#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//ţ��ˢ�⣬�˽ⷨӦ�ò��Ǻܺ�
void replaceSpace(char* &str, int length)   //��Ŀ���β�û�и����ã�����������þͺ���д��ȥ��
{
	/*int i = 0;
	vector<char> _arr;
	while (i<length)
	{
		if (str[i] != ' ')
		{
			_arr.push_back(str[i]);
		}
		else
		{
			_arr.push_back('%');
			_arr.push_back('2');
			_arr.push_back('0');
		}
		i++;
	}
	_arr.push_back('\0');
	str = new char[_arr.size()];
	for (size_t i = 0; i < _arr.size(); i++)
	{
		str[i] = _arr[i];
	}*/

	//����2�������@�ַ����������⡣
	char* _str = new char[strlen(str) + 1];
	strcpy(_str, str);
	//���ȿռ���Ҫ����ģ���������Ҫ���Ӷ����Ҫ�������㡣
	str = _str;
}

int main()
{
	char* str = "Hello World!";
	replaceSpace(str, strlen(str));
	cout << str << endl;
}