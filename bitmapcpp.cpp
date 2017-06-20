#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<errno.h>
#include<assert.h>
using namespace std;


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
		_bimp[index] |= (1 << pos);           //�κ�����1��Ϊ�κ���
		return true;
	}
	bool Reset(const size_t& num)
	{
		size_t index = num / 8;
		size_t pos = num % 8;
		_bimp[index] &= (~(1 << pos));
		return true;

	}
	bool Find(const size_t& num)
	{
		size_t index = num / 8;
		size_t pos = num % 8;
		if (_bimp[index] & (1 << pos))
		{
			return true;
		}
		else
			return false;
	}
};

//----------------------test-----------------------
void testBitmap()
{
	bitmap _bp;
	_bp.InitBitmap(-1);
	_bp.Create(3);
	_bp.Create(89);
	_bp.Create(56);
	_bp.Create(35);
	_bp.Create(89);
	_bp.Create(44);
	_bp.Create(67);
	_bp.Create(23);
}
int main()
{
	testBitmap();
	return 0;
}