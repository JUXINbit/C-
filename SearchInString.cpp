#define _CRT_SECURE_NO_WARNINGS 1

//����һ���ַ����е�һ��ֻ�������ε��ַ���
//���磺��abcdefabcdefabc���е�һ��ֻ��������Ϊ��d����Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)

//����һ��ʹ��һ��26����ĸ�����飬�����е�Ԫ��λ���Ϸ��ó��ֵ���ĸ�ĸ�����Ȼ�����ļ�ѹ������������һ����ĸ������Ӧ�������λ��Ȼ��+1��
//����һ��֮��͵õ������г��ֵ���ĸ�Ĵ���ͳ�ƣ�Ȼ��ע���ˣ� ����ԭ�����ַ��������ÿһ���ַ����ֵĴ�����Ҫ����2���ͷ���
#include<iostream>
#include<string>
#include<assert.h>

using namespace std;
char  str[26] = { 0 };
char SearchInString(char *p)
{
	assert(p);
	size_t i = 0;
	while (p[i] != '\0')
	{
		str[p[i] - 'a']++;
		++i;
	}
	size_t j = 0;
	while (p[j] != '\0')
	{
		if (str[p[j] - 'a'] == 2)
		{
			return p[j];
		}
		j++;
	}
	printf("û��ֻ�������ε���ĸ\n");
	return 0;
}
void test()
{
	//char*  p = "abjcmkdjefjabcdefakbcm";
	//char*  p = "akbjbkbjsudni";
	char*  p = "";
	cout << SearchInString(p) << endl;
}
int main()
{
	test();
	return 0;
}
