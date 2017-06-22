#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<errno.h>
#include<assert.h>
using namespace std;

//λͼ  ʱ�临�Ӷ�o��1��  ��ʡ�ռ䵫��ֻ�����������͵�����Ӧ�á���֧�ּ�ֵ����
//λ�����������,��λ��λ���������
class bitmap
{
private:
	vector<char>  _bimp;
public:
	bitmap()
		:_bimp(NULL)
	{
		cout << "����λͼ" << endl;
	}
	void InitBitmap(const size_t& size)
	{
		_bimp.resize(size / 8 + 1, 0);         //�����Ҫ�Ž�ȥ�����ĸ�����ע���@��ΪʲôҪ+1
	}
	bool Create(const size_t& num)                //����λͼ
	{
		size_t index = num / 8;
		size_t pos = num % 8;
		_bimp[index] |= (1 << pos);              //1���κ�������1  0���κ��������κ���
		return true;
	}
	bool Reset(const size_t& num)
	{
		size_t index = num / 8;
		size_t pos = num % 8;
		_bimp[index] &= (~(1 << pos));          //1���κ����붼���κ�����0���κ����붼��0
		return true;

	}
	bool Find(const size_t& num)
	{
		size_t index = num / 8;
		size_t pos = num % 8;
		if (_bimp[index] & (1 << pos))         //1���κ����붼���κ�����0���κ����붼��0
		{
			return true;
		}
		else
			return false;
	}
};

