#define _CRT_SECURE_NO_WARNINGS 1
//��̬�滮����������ظ��ַ������ַ����ĳ��Ⱥ�λ��

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

typedef struct GetLongestSubStrFlag
{
	size_t sptr;
	size_t Fsptr;
}GetStr;
GetStr GetLongestSubString(const string& str)      //ע��������ַ���Ϊ���ַ���
{
	GetStr Get;
	if (str.size() == 0)            //������ַ���
		perror("�������");
	int length = str.size();
	size_t MaxFsptr = 0;           //��һ��������¼�������ֵ��
	Get.sptr = 0;
	Get.Fsptr = 0;            //��ָ����ַ���Ϊ��β����̲��ظ��Ӵ��ĳ���  �տ�ʼ����ʼֵ0
	int *ass = new int[26];        //���26���ַ���Ӧ�ĳ������ַ����е��±�ֵ
	for (size_t i = 0; i < 26; i++)  
	{
		ass[i] = length;
	}
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == length)              //��λ��֮ǰ�������ֹ�����Ӽ�¼    
		{
			ass[str[i] - 'a'] = i;
			Get.Fsptr++;
			if (Get.Fsptr > MaxFsptr)
				MaxFsptr = Get.Fsptr;
			continue;
		}
		//��λ��֮ǰ���ֹ����鿴λ�ü��������������
		else
		{
			int d = i - ass[str[i] - 'a'];      
			if (d <= Get.Fsptr)            //ע����ڵ����
			{
				if (Get.Fsptr > MaxFsptr)
					MaxFsptr = Get.Fsptr;
				Get.Fsptr = d;
				Get.sptr = ass[str[i] - 'a'] + 1;              //����ͷָ��λ��
			}
			else
			{
				Get.Fsptr++;
				if (Get.Fsptr > MaxFsptr)
					MaxFsptr = Get.Fsptr;
			}
			ass[str[i] - 'a'] = i;
			continue;
		}
	}
	Get.Fsptr = MaxFsptr;
	return Get;
}
int main()
{
	//string str("arabcacfr");
	//string str("acbadefgaaaaa");
	//string str("aaaaaaaaaaaa");
	string str("a");
	//string str;
	cout << GetLongestSubString(str).Fsptr << endl;      //��Ӵ��ĳ���
	return 0;
}






