#define _CRT_SECURE_NO_WARNINGS 1

#include"HuffmanTree.h"
 
typedef size_t LongType;
struct CharInfo               //�@���������Ľ��@�ṹ��Ϊ��ĸ��
{
	char _ch;
	LongType _Count;
	string  _HUffmanCode;
	//�@�ﲻд���죬��Ϊ�շ�������տ�ʼ��ʱ���ʺ�����  ����Ĭ�ϵĹ��캯��

	bool operator !=(const CharInfo& ch)
	{  
		return this->_Count != ch._Count;
	}

	bool operator < (const CharInfo& ch)
	{
		return this->_Count < ch._Count;
	}

	CharInfo operator+(const CharInfo& ch)
	{
		CharInfo tmpInfo;
		tmpInfo._Count = this->_Count + ch._Count;
		return tmpInfo;
	}
	
};
class FileCompass
{
public:
	typedef HuffmanTreeNode<CharInfo> CharNode;
private:
	CharInfo Info[256];
public:
	FileCompass() //������256����ĸ�Ľṹ��   ��ʼ��
	{
		for (size_t i = 0; i < 256; i++)
		{
			Info[i]._ch = i;
			Info[i]._Count = 0;
		}
	}
	void Compass(const char* filename)//   ѹ���ļ�
	{
		assert(filename);
		FILE* fout = fopen(filename, "r");        //�@��� "r"��ʲô��˼��
		assert(fout);

		//ͳ���ַ����ֵĴ���
		char ch = fgetc(fout);                 //fgec���÷�
		while (ch!=EOF)                      //EOF���ļ�������־����
		{
			Info[ch]._Count++;
			ch = fgetc(fout);
		}


		                                                   //�������ĸ�ĺշ����������ļ��г��ֵ���ĸ���н��ѣ�û�г��־Ͳ���Ҫ������ ������Ҫ�õ�invalid
		CharInfo _invalidInfoNode;
		_invalidInfoNode._Count = 0;                          //���ִ���Ϊ0����ĸ��
		HuffmanTree<CharInfo> _h(Info, 256,_invalidInfoNode);

		GetHuffmanCode(_h.GetRoot());

	
	}
	//��ȡ�շ������루�ݹ飬�ӵ��������ܣ�[*]
	void GetHuffmanCode(CharNode* root)
	{
		string _code;
		if (root == NULL)                               //��������
			return;
		if (root->_left == NULL&&root->_right == NULL)
		{
			CharNode* cur = root;
			CharNode* parent = cur->_parent;
			while (parent != NULL)
			{
			    if (cur == parent->_left)
				{
					_code.push_back('0');
				}
				if (cur == parent->_right)
				{
					_code.push_back('1');
				}
				cur = parent;
				parent = cur->_parent;
			}
			Info[root->_data._ch]._HUffmanCode = _code;    //�ҵ����֮��ֱ�����ɱ���Ž�ȥ
			return;
		}
		GetHuffmanCode(root->_left);
		GetHuffmanCode(root->_right);
	
	}


	//��ѹ
	void UnCompass(const char* filename)
	{
	
	}

};


void testCompass()
{
	FileCompass fcps;
	fcps.Compass("TestInput.txt");

}
int main()
{
	testCompass();
	return 0;
}
