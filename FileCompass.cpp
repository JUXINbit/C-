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
		FILE* fout = fopen(filename, "r");        //�@��� "r"��ʲô��˼��   �Զ��ķ�ʽ
		assert(fout);

		//ͳ���ַ����ֵĴ���
		char ch = fgetc(fout);                 //fgetc���÷�
		while (ch!=EOF)                      //EOF���ļ�������־
		{
			Info[ch]._Count++;
			ch = fgetc(fout);
		}


		                                                   //�������ĸ�ĺշ����������ļ��г��ֵ���ĸ���н��ѣ�û�г��־Ͳ���Ҫ������ ������Ҫ�õ�invalid
		CharInfo _invalidInfoNode;
		_invalidInfoNode._Count = 0;                          //���ִ���Ϊ0����ĸ��
		HuffmanTree<CharInfo> _h(Info, 256,_invalidInfoNode);

		string code;
		GetHuffmanCodeII(_h.GetRoot(),code);



		//����ѹ���ļ�����ѹ��
		//1.
		string compassfile = filename;                   //�@���������
		compassfile = compassfile + ".huffman";
		FILE* fIn = fopen(compassfile.c_str(), "w");      //ע���@���c_str().....    �����@��ͻᴴ��һ���µ��ļ�
		assert(fIn);

		//2.
		char value = 0;
		int count = 0;              //Ҫע���@���count�ĸտ�ʼ��ֵ����������ֵ
		fseek(fout, 0, SEEK_SET);     //fseek�����ķ���ֵΪ���Σ�����һ���ļ�ָ��  foutָ��ָ���ļ�����ĸ
		char ch1 = fgetc(fout);        //fgetc��������
		while (ch1!=EOF)
		{
			string& code = Info[ch1]._HUffmanCode;     
			for (size_t i = 0; i < code.size(); i++)
			{
				value <<= 1;                      //ע����λ������ı���������ֵ
				if (code[i] == '1')                //string֧����[]������
				{
					value |= 1;
				}
				else
				{
					value |= 0;
				}
				count++;

				if (count == 8)                   //��8λ��д��ѹ���ļ�����ȥ  Ȼ�����¸�8λ0
				{
					fputc(value, fIn);            //fputc��ʹ��
					value = 0;
					count = 0;
				}
			}
			ch1 = fgetc(fout);
		}

		fclose(fIn);
		fseek(fout, 0, SEEK_SET);
		fclose(fout);

	  
	}
	//��ȡÿһ���ַ��ĺշ������루�ݹ飬�ӵ��������ܣ�[*]
	//void GetHuffmanCode(CharNode* root)
	//{
	//	string _code;
	//	if (root == NULL)                               //��������
	//		return;
	//	if (root->_left == NULL&&root->_right == NULL)
	//	{
	//		CharNode* cur = root;
	//		CharNode* parent = cur->_parent;
	//		while (parent != NULL)
	//		{
	//		    if (cur == parent->_left)
	//			{

	//				_code.push_back('0');
	//			}
	//			if (cur == parent->_right)
	//			{
	//				_code.push_back('1');
	//			}
	//			cur = parent;
	//			parent = cur->_parent;
	//		}
	//		Info[root->_data._ch]._HUffmanCode = _code;    //�ҵ����֮��ֱ�����ɱ���Ž�ȥ
	//		reverse(_code.begin(), _code.end());
	//		return;
	//	}
	//	GetHuffmanCode(root->_left);
	//	GetHuffmanCode(root->_right);
	//}
	
	//�ڶ��ַ�����  
	void GetHuffmanCodeII(CharNode* root, string code)   //�Ӹߴ����µݹ�ݹ���ȥ������Ҷ�ӽ��Ͱѱ���ŵ���ĸ���ĺշ�����������ȥ��
	{
		if (root == NULL)
			return;
		if (root->_left == NULL&&root->_right == NULL)
		{
			Info[root->_data._ch]._HUffmanCode = code;     //ע���@�ﲻ��Ҫ��ת
			return;
		}
		GetHuffmanCodeII(root->_left, code + '0');     //ע�⣺string��֧��+��
		GetHuffmanCodeII(root->_right, code + '1');
	}

	//��ѹ
	void UnCompass(const char* filename)
	{
	   	assert(filename);
		string uncompassfile = filename;
		size_t pos = uncompassfile.rfind('.');
	    
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
