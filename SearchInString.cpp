#define _CRT_SECURE_NO_WARNINGS 1

//����һ���ַ����е�һ��ֻ�������ε��ַ���
//���磺��abcdefabcdefabc���е�һ��ֻ��������Ϊ��d����Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)

//����һ��ʹ��һ��26����ĸ�����飬�����е�Ԫ��λ���Ϸ��ó��ֵ���ĸ�ĸ�����Ȼ�����ļ�ѹ������������һ����ĸ������Ӧ�������λ��Ȼ��+1��
//��������֮����һ�������е�ֵ�������2 ֱ���˳���ɲ��ҡ�

#include<iostream>
#include<string>

using namespace std;

char  str[26] = { 0 };
char SearchInString(char *p)
{
	size_t i = 0;
	while (p[i] != '\0')
	{
		str[p[i] - 'a']++;
		if (str[p[i] - 'a'] == 2)
		{
			return p[i];
		}
		++i;
	}
	return 'a';
}
void test()
{
	char*  p = "abcdefabcdefabc";
	cout<<SearchInString(p);
}
int main()
{
	test();
	return 0;
}
