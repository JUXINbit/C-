#define _CRT_SECURE_NO_WARNINGS 1


//�@����ע���������  ������е��ַ������ظ�����ô��  ʹ�ñ�־λ
#include<iostream>
#include<string>
using namespace std;
char GetTheFirstChrInString(const string& str)
{
	if (str.size() == 0)
		perror("errorinput");
	int* ass = new int[26];
	for (size_t i = 0; i < 26; i++)
	{
		ass[i] = -1;
	}
	int length = str.size();
	for (size_t i = 0; i < length; i++)
	{
		if (ass[str[i] - 'a'] == -1)     //�״γ���
			ass[str[i] - 'a'] = i;
		else                           //�ظ�����
			ass[str[i] - 'a'] = -1;
	}
	int Min = 0;
	int MinIndex = 0;
	bool JusOnce = false;                //ע���@��,�տ�ʼû�п��ǵ������û��ֻ����һ�ε�
	for (size_t i = 0; i < 26; i++)
	{
		if (ass[i] != -1)
		{
			Min = ass[i];
			MinIndex = i;
			JusOnce = true;           //ֻ������һ��
			break;
		}
	}
	if (!JusOnce)
		return '\0';                  //������ֻ������һ�ε��ַ�
	for (size_t i = 0; i < 26; i++)
	{
		if (ass[i] != -1)
		{
			if (ass[i] < Min)
			{
				Min = ass[i];
				MinIndex = i;
			}
		}
	}
	return MinIndex + 'a';
}
//  TEST
int main()
{
	//string str("abaccdeff");
	//string str("aaaaaaaa");
	//string str("awertyu");
	//string str("kwertyu");
	string str;
	cout << GetTheFirstChrInString(str) << endl;
	return 0;
}