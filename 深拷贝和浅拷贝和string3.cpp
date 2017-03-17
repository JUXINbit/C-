#include<iostream>//�@���ֵ���ϰ��Ҫ����ǿ���������Ҫ��
using namespace std;
class String
{
	friend ostream& operator<<(ostream& os, String& s);
private:
	 char *_str;//Ϊ�˸ı�*_str��ֵ�@�ﲻ����const��
public:
	/*String()//�����ʼ��һ������û�и�ֵ����ôӦ�ù����޲κ����������ã������ں���ͻ��������⡣
		:_str(NULL)
	{
		cout << "String()" << endl;
	}*/
	String(const char *str="")//�@��ʹ��const ��ô�����Ҫͬ��ʹ��const����
		:_str(new char[strlen(str)+1])
	{
		strcpy (_str, str);//������str��ֵ��
		cout << "_str" << endl;
	}
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	    
	{
		cout << "const string& s" << endl;
		strcpy(_str, s._str);//strcpy��memcpy֮����ʲô��𣿣�
	}
	String& operator=(const String& s)//=���������//�ǵ�Ҫ�����ж��Ƿ���Ը�ֵ��
	{
		cout << "String& operator=(const String& s)" << endl;
		
		if (&s!=this)//�ж��Ƿ���Ը�ֵ��
		{
		delete[] _str;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
		}//��ͳд�� ���ٿռ�
		
		return *this;//��Ҫ���˷���ֵ;

	}

	~String()//ע�����������������ǣ�
	{
		if (_str != NULL)
		{
			delete[] _str;//���ٿռ�֮��Ҫ��ס���գ�
		}
	}

};
ostream& operator<<(ostream& os, String& s)
{
	os << s._str;
	return os;
}
int main()
{
	String s1("abcdef");
	cout << s1 << endl;//������������
	String s2(s1);//��������
	String s3;//��ʵ�ڳ�ʼ�������ʱ�����ڵ����˹��캯�� ����s3=""  ��ռ�ÿռ��;//�����ں���s3�Լ�����һ��ռ��ʱ���@��""����Ҫ�ͷŵġ�
	s3 = s2;//�@�����Ҫʹ�õ�operator=����������أ�������Ȼ�����ǳ���������⣬���Լ�����s3����һ���Լ��Ŀռ�  
    //����ʲô������ڸ�ֵ����֮ǰ������Ҫ����ֵ�ڵĶ������
	//�������û��д=�ŵ���������أ���ô�@�����Ĭ��ǳ��������������


	/*string str1 = ("abcdef");
	cout << str1 << endl;
	str1[4] = 'w';
	cout << str1 << endl;*/
	system("pause");
	
	return 0;
}