#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�滻�ַ����еĿո�Ϊ$$$��Ҫ��ʱ�临�Ӷ�ΪO(N)
//���磺��"talk is cheap show me the code"�滻��Ϊ"talk$$$is$$$cheap$$$show$$$me$$$the$$$code"��


//Soultion No.1
void ReplaceBlank(char*& p)
{
	size_t i = 0;
	vector<char>  _v;
	while (p[i] != '\0')
	{
		if (p[i] == ' ')
		{
			_v.push_back('$');
			_v.push_back('$');
			_v.push_back('$');
			i++;
			continue;
		}
		_v.push_back(p[i]);
		i++;
	}
	_v.push_back('\0');
	char* tmp = new char[_v.size()];
	for (size_t i = 0; i < _v.size(); i++)
	{
		tmp[i] = _v[i];
	}
	p = tmp;
}
//��������  ʹ��string  ����뽫�ַ�ָ�븳ֵ����û�а취��string�����ַ��ĵ�ַ��ֵ
//void ReplaceBlank1(char*& p)
//{
//	size_t i = 0;
//	string s1;
//	while (p[i] != '\0')
//	{
//		if (p[i] == ' ')
//		{
//			s1.push_back('$');
//			s1.push_back('$');
//			s1.push_back('$');
//			i++;
//			continue;
//		}
//		s1.push_back(p[i]);
//		i++;
//	}
//	char* tmp = new char[s1.length + 1];
//	 
//}

int main()
{
	char *p = "talk is cheap show me the code";
	ReplaceBlank(p);
	cout << p << endl;
	return 0;
}