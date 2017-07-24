#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
//�滻�ո����Ž⣺ ʱ�临�Ӷȣ� o��N�� �ռ临�Ӷȣ�o��1��
//ǰ���ַ�ָ��󷨺�
using namespace std;
void ReplaceBlank(char str[], size_t length,int Maxlength)
{
	assert(str);
	assert(length);
	//������滻���������ĳ���
	size_t i = 0;
	size_t count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (count == 0)
	{
		printf("�����滻\n");
		return;
	}
	size_t newlength = length + count * 2;
	if (newlength > Maxlength)                //�ַ��������������ռ�
		return;
	//��������ָ��һǰһ�󣬴Ӻ���ǰ��ʼ�滻
	int FastIndex =length - 1;
	int SlowIndex= newlength - 1;
	while (FastIndex!= SlowIndex)
	{
		while (str[FastIndex]!=' ')
		{
			str[SlowIndex--] = str[FastIndex--];
		}
		FastIndex--;
		if (SlowIndex - FastIndex >= 3)
		{
			str[SlowIndex--] = '0';
			str[SlowIndex--] = '2';
			str[SlowIndex--] = '%';
		}
		else
		{
			printf("����\n");
			return;
		}
	}
}

void test(void)
{
	//char string[] = "hello the world";    //��֮ǰ���������ռ䣬���ž�ӲͷƤ�Ѻ����ֵ�����ˣ����淴�������ֵӦ�ò�Ӱ�죬���Ƿ����@��������ʵ���ˣ����Ƿ��ص�ʱ��ҵ���˵��ջ���ƻ�
	const int Maxlength = 100;              //�����ҹԹԸ��˴�ռ䣬˳�����С�
	char string[Maxlength] = "hello the world";
	size_t length = strlen(string) + 1;
	ReplaceBlank(string, length, Maxlength);	
	size_t i = 0;
	while (string[i] != '\0')
	{
		cout << string[i] << " ";
		i++;
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}

