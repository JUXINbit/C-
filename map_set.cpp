#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>    //��ס����.h
#include<map>
#include<set>
#include<stack>

using namespace std;


void testmap()
{
	////map<string, int> m1;
	////m1.insert(make_pair("haha", 3));
	////m1.insert(make_pair("hehe", 4));
	////m1.insert(make_pair("xixi", 3));         //���ַ�ʽ��һ���ġ�  pair��һ������ ���@��ʵ����
	////m1.insert(make_pair("hiahia", 3));
	////m1.insert(make_pair("huohuo", 3));
	////map<string, int>::iterator it1 = m1.begin();                 //Ϊɶstd::map�еĵ�����ʵ�ֵ���const��
	////while (it1 != m1.end())
	////{
	////	cout << it1->first << endl;
	////	it1++;   
	////}
	//////cout << endl;

	////���ʹ��insertͳ�Ƴ��ֵĸ���ˮ�����ֵĴ�����
	////insert�Ĳ��룺�������ֵ�����࣬Ҳ���ǲ���map�д��ڵ�keyֵ�Ľ��ͻ�ʧ�ܡ�
	//string str[] = { "����", "����", "ƻ��", "��ݮ", "����", "����", "����" };
	//map<string, int> mp1;
	//for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	//{
	//	//mp1.insert(make_pair(str[i], 1));       //ֱ�ӵĲ���������keyֵ������

	//	//map<string, int>::iterator it = mp1.find(str[i]);      //�@����ȱ���
	//	//if (it != mp1.end())
	//	//{
	//	//	it->second++;
	//	//}
	//	//else
	//	//{
	//	//	mp1.insert(make_pair(str[i], 1));           //�@����ٴα���
	//	//}

	//	  //�ڶ��ַ���
	//	  pair<map<string, int>::iterator, bool> bit;     //��������@���insert ʵ����insert���ص���һ��pair�ṹ�壬����Ķ����Լ�����
	//	  bit = mp1.insert(make_pair(str[i], 1));
	//	  if (bit.second == false)
	//	  {
	//		  bit.first->second++;
	//	  }
	//}
 //   
	//mp1.insert(make_pair("ƻ��", 6));             //�����@��ͻ����ʧ��
	//
	////�����ַ���
	//mp1["ƻ��"]++;      //ע���@������ʵ������second
	//mp1["ƻ��"]++;
	//mp1["ƻ��"]++;
	//mp1["ƻ��"]++;
	//mp1["ƻ��"]++;
	//mp1["ƻ��"]++;
	//mp1["ƻ��"]++;
	//mp1["ƻ��"]++;
	////�@��ʵ�ֵ�operator[]ʵ���ϲ����������λ�õĲ��룬ʵ������һ������keyֵ����value����������ء�

	//mp1["����"];
	//mp1["����"];      //ʵ�����Ѿ������ˡ�������
	//mp1["����"] = 100;  

	//
	//map<string, int>::iterator it = mp1.begin();
	//while (it != mp1.end())
	//{
	//	cout << it->first << ":" << it->second << endl;
	//	it++;
	//}
	////eraseʹ��
	//size_t num = mp1.erase("ƻ��");
	//cout << "ɾ��Ԫ�ظ���:" << num << endl;
	//map<string, int>::iterator it1 = mp1.erase(mp1.find("����"));
	////cout << it1->first << endl;    �ҵ�


	//-----------------------------------------------multimap---------------------------------------
	/*multimap<string, string> multmp;
	multmp.insert(make_pair("oringe", "����"));
	multmp.insert(make_pair("apple", "ƻ��"));
	multmp.insert(make_pair("pipche", "����"));
	multmp.insert(make_pair("left", "���"));
	multmp.insert(make_pair("banana", "�㽶"));
	multmp.insert(make_pair("strowbreey", "��ݮ"));
	multmp.insert(make_pair("left", "ʣ��"));
	multmp.insert(make_pair("left", "ʣ��"));
	multmp.insert(make_pair("left", "ʣ��"));
	multmp.insert(make_pair("left", "ʣ��"));
*/

	//����
	/*multimap<int, int> multmp1;
	multmp1.insert(make_pair(1, 1));
	multmp1.insert(make_pair(2, 1));
	multmp1.insert(make_pair(5, 1));
	multmp1.insert(make_pair(3, 1));
	multmp1.insert(make_pair(4, 1));
	multmp1.insert(make_pair(7, 1));
	multmp1.insert(make_pair(6, 1));
	
	multimap<int, int>::iterator it = multmp1.begin();
	while (it != multmp1.end())
	{
		cout << it->first <<":"<<it->second<< endl;
		it++;
	}*/


    //ͳ�Ƴ��ִ�������ǰK��ˮ�� 
     string str[] = { "����", "����", "ƻ��", "��ݮ", "����", "����", "����", 
                "����", "����", "ƻ��", "��ݮ", "����", "����", "����", 
				"����", "����", "ƻ��", "��ݮ", "����", "����", "����", "����", "⨺���", "�㽶", "������", 
				"�ƹ�", "ƻ��", "��ݮ", "����", "����", "����", "����", "⨺���", "�㽶", "������", "�ƹ�",
				"��ݮ", "����", "����", "����", "����", "ƻ��", "����", "ƻ��", "����", "ƻ��", "����", "ƻ��",
				"⨺���", "�㽶", "������", "⨺���", "�㽶", "������" ,"⨺���", "�㽶", "������", "⨺���", "�㽶", 
				"������", "����", "����","����", "����","����", "����","����", "����","����", "����","����", "����",
				"ɣ��","ɣ��","����","����",
				"ɣ��", "����" ,"ɣ��", "����" ,"ɣ��", "����" ,"���","���"};
    map<string, int>  mp;
	for(size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		map<string, int>::iterator it = mp.find(str[i]);
		if (it != mp.end())
		{
			mp[str[i]]++;
		}
		else
		{
			mp.insert(make_pair((str[i]), 1));
		}
	}
	map<string, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << " : " << it->second << endl;
		it++;
	}
}
void testset()
{
	set<int> st;
	st.insert(1);
	st.insert(2);
	st.insert(1);
	st.insert(6);
	st.insert(8);
	st.insert(9);
	st.insert(3);
	st.insert(5);
	st.insert(7);
	st.insert(7);
	st.insert(7);
	st.insert(2);
	st.insert(5);
	st.insert(5);
	st.insert(5);
	st.insert(5);

	set<int>::iterator sit = st.begin();
	while (sit != st.end())
	{
		cout << *sit << " ";
		sit++;
	}
	cout << endl;
}
int main()
{
	testmap();
	//testset();
	return 0;
}
