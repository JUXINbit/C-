//
////���õ�string����
//#include<iostream>
//using namespace std;
//#include<string>
//int main()
//{
//	string str1("hello world.");
//	string str2(str1);//�@����õ��ǿ������캯����
//	string str3=str2;//�@����õ���operator=����������أ�
//	cout << str1 << endl;
//	cout << str2 << endl;
//	cout << str3 << endl;
//	system("pause");
//	return 0;
//}
////�@����һ���������͵�string
////�����Զ���һ��string������������Ǹ�����Ĺ��ܣ�


#include<iostream>
using namespace std;
class String
{
	friend ostream& operator<<(ostream& os, String& s);
 private:
	 const char *_str;
public:
	String(const char *str)//�@��ʹ��const ��ô�����Ҫͬ��ʹ��const����
		:_str(str)
	{
		cout << "_str" << endl;
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
	cout << s1;

	return 0;
}