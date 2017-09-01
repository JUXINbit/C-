#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
///////////////////����LZ77ѹ���㷨���ļ�ѹ��/////////////////
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<assert.h>
#include<vector>
using namespace std;

const size_t N = 2 * 32 * 1024;     //���û���Ϊ64k
enum{ SlipBlock = 32 * 1024 };      //�������ô�СΪ32k
typedef long long LongType;

class  ZipCompress
{
private:
	vector<unsigned char> _windows;
	size_t _frist;                   //���������������ļ���
	size_t _last;                    //���������������ļ��е����Ľ�����־
public:
	ZipCompress()
	{
		_windows.reserve(N);        //64k���һ������
		_frist = 0;                
		_last = 0;                 
	}
	string Compress(const string& filename)
	{
		return _ZipFileCompress(filename);
	}
	string UnCompress(const string& filename)
	{
		return _ZipFileUnCompress(filename);
	}
protected:
	//�ļ�ѹ��
	string _ZipFileCompress(const string& filename)
	{
		assert(filename.c_str());
		string CompressFileName = filename;
		CompressFileName += ".zip";
		FILE* fInput = fopen(filename.c_str(), "rb+");  //ֻ����ʽ���ļ���ȡ�ַ�
		assert(fInput);
		FILE* fOut = fopen(CompressFileName.c_str(), "wb+"); //������д�ķ�ʽ��ѹ���ļ�
		assert(fOut);
        FILE* pWindows = fopen(filename.c_str(), "rb+");  //ָ�򻬶����ڵ��ļ�ָ��
		assert(pWindows);

		int ch = 0;
		ch = fgetc(fInput);   //���ļ��ж�ȡһ���ַ�
		LongType count = 0;
        //�ж��Ƿ���Ҫѹ��  �ظ����ַ����ֳ���3�ξ���Ҫѹ����
		unsigned char buf = 0;
		int flag = 7;             //���buf�����˼�λ��û��ʲô��˼
		
		while (ch != EOF)       //û�ж����ļ���β
		{
			int length = 0;
			long distance = 0;
			long OFFSET = ftell(fInput);//��ǰ��ȡ�����ַ������ļ���ʼ�ľ���

			if (OFFSET <= SlipBlock)
			{
				fseek(pWindows, 0, SEEK_SET);    //��ȡ���ַ�ƫ���ļ�ô�г���32k����ô����ָ��һֱָ���ļ�����λ��
				distance = OFFSET - 1;          //Ϊʲô��-1��
			}
			if (distance > 1)
			{
				fseek(fInput, OFFSET - 1, SEEK_SET);          //finput������һ���ֽ�
				length = FindRepetition(pWindows, fInput, distance);
				fseek(fInput, OFFSET, SEEK_SET);             //�ص�ԭ����λ��
			}
		}
		if (length>0)             //���ظ���,��1��ʾ���ظ���
		{
			fseek(fInput, length - 1, SEEK_CUR);

			buf |= (1 << flag);        //�Ȱ�flag��һλ��� ���ó�1
			flag--;
			if (flag < 0)    //buf��8λ�Ծ�������ϣ�����д��
			{
				fputc(buf, fOut);
				flag = 7;
				buf = 0;
			}

			//��������distance��lengthд��
			int pos = 15;
			while (pos >= 0)                    //���������ֽڵ�distance
			{
				if (distance&(1 << pos))        //���length�ĵ�posλΪ1
					buf |= (1 << flag);         //��buf��д1
				else
					buf &= (~(1 << flag));       //��buf��д0
				flag--;
				if (flag < 0)                    //buf��8λ�Ծ�������ϣ�����д��
				{
					fputc(buf, fOut);
					flag = 7;
					buf = 0;
				}
				pos--;
			}

			pos = 7;                             //������д��length
			while (pos >= 0)
			{
				if (length&(1 << pos))           //���length�ĵ�posλΪ1
					buf |= (1 << flag);           //��buf��д1
				else
					buf &= (~(1 << flag));       //��buf��д0
				flag--;
				if (flag < 0)                    //buf��8λ�Ծ�������ϣ�����д��
				{
					fputc(buf, fOut);
					flag = 7;
					buf = 0;
				}
				pos--;
			}
			count += 3;              //����һ��distance��һ��length��count�������ֽ�
		}
		else                             //����ַ�����ͨ�ַ�
		{
			buf &= (~(1 << flag));       //��flag��һλ���ó�0
			flag--;
			if (flag < 0)                //buf��8λ�Ѿ�������ϣ�����д��
			{
				fputc(buf, fOut);
				flag = 7;
				buf = 0;
			}

			//����������ch����ַ�
			int pos = 7;
			while (pos >= 0)
			{
				if (ch&(1 << pos))                //���ch�ĵ�posλΪ1
					buf |= (1 << flag);           //��buf��д1
				else
					buf &= (~(1 << flag));        //��buf��д0
				flag--;
				if (flag < 0)                     //buf��8λ�Ծ�������ϣ�����д��
				{
					fputc(buf, fOut);
					flag = 7;
					buf = 0;
				}
				pos--;
			}
			count++;              //����һ���ַ���count++һ��
		}
		ch = fgetc(fInput);
	}

	if (flag != 7)       //�������bitλ����һ������������ں��油0
	{
		fputc(buf, fOut);
	}
	fwrite(&count, 1, 8, fOut);
	fclose(fInput);
	fclose(fOut);
	fclose(pWindows);                             //�رմ���ָ����ָ����ļ�
	return FirstCompressFileName;
	}
	//�ļ���ѹ
	string  _ZipFileUnCompress(const string& filename)
	{

	}
protected:
	int FindRepetition(FILE*& pWindows, FILE*& fInput, long& distance)     //������Ҫ�ǽ�����������������ݣ��������ڴ�С��64k����ҪΪ��������ĺ�����ƥ���Ӵ�����󳤶Ⱥ;���
	{
		long OFFSET1 = ftell(pWindows);   //��ǰ�Ĵ��ھ����ļ���λ�õľ���
		long OFFSET2 = ftell(fInput);     //��ǰ��Ҫ�Ƚϵ��ַ���
		int ch = 0;

		if ((size_t)OFFSET2 > _last)      //_last�ǻ������������ַ������ļ���ͷ�ľ��룬��ȡ���ַ�λ���Ѿ������˻������ڣ�ʵ���Ͼ���һ�����������
		{
			_windows.clear();
			for (size_t i = 0; i < N; i++)    //��������������ַ�����pwindow��ʼ��������
			{
				ch = fgetc(pWindows);
				if (ch == EOF)
					break;
				_windows.push_back(ch);    
			}
			_frist = OFFSET1;       //����pWindowsָ���λ��
			_last = _windows.size() + OFFSET1;     //���������ַ��������ļ��е�λ��
		}
		int length = GetRepetitionlength(fInput, distance, OFFSET1);
		return length;
	}
	//��ȡ����Ӵ������Լ�����distance
	int GetRepetitionlength(FILE* fInput, long& distance, long& pWindowsPos)   
	{
		long OFFSET = ftell(fInput);     //��ȡ���ַ������ļ���ͷ��Զ
		vector<unsigned char> v;
		if (Getch(fInput, v) == false)   //�Ƚ���һ���ַ��ŵ�v��
			return 0;
		//////////ѹ������////////////////
		size_t size = OFFSET - pWindowsPos;
		size_t index = pWindowsPos - _frist;
		int length = 0;                //�ַ���ƥ��ĳ���
		for (; index < size; ++index)
		{
			//���ҵ���һ��ƥ����ַ�
			if (_windows[index] == v[0])        
			{
				size_t flag = index;
				size_t i = 0;
				while ((flag < size) && (length < 255))   //length����1���ֽ�
				{
					if (i == v.size() - 1)               //�@�첻̫��
					{
						if (Getch(fInput, v) == false)      //����ƥ�䣬����ͳ��ֹͣ������ѭ��
							break;
					}
					if (_windows[flag] == v[i])            //ͳ�Ƴ���
					{
						length++;
						flag++;
						i++;
					}
					else
						break;
				}
				if (length >= 3)
				{
					distance = OFFSET - (index + _frist);     //��ԭ���ľ����Ϊƥ����Ӵ��ľ���Ȼ����������@�����ܽ�����������������
					return length;
				}
				length = 0;                                   //����һ��ѭ��֮ǰ��������0;
			}
		}
		return 0;
	}

	//������ӱȽ�����
	bool Getch(FILE* fInput, vector<unsigned char>& v)   //���ļ��л�ȡһ���ַ�����ʱ������
	{
		int ch = 0;
		ch = fgetc(fInput);
		v.push_back(ch);
		if (ch == EOF)
			return false;
		else
			return true;
	}
};
void TestLZ77Compress()
{
	ZipCompress CompressDoxc;
	CompressDoxc.Compress("����.pdf");
}
int main()
{
	TestLZ77Compress();
	return 0;
}