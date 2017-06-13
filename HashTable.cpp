#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//��ϣ�����������������̽�⣩  ʱ�临�Ӷ�o(1)        ����ڸ������ݽṹ��ʱ�临�Ӷ�

enum HashState       //�������ݵ�״̬
{
	EXIST,
	EMPTY,
	DELETE
};

template<class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	HashState _state;
	HashNode(const pair<K ,V>& kv=make_pair(0,0))       //�տ�ʼû�и�pair��Ĭ��ֵ���������vector�����ʱ����vector�����Ĭ�Ϲ��캯�����ͳ�����
		: _kv(kv)
		, _state(EMPTY)
	{
		cout << "�����ϣ���" << endl;
	}
};



//ʹ�÷º���
//�����ͨ����
template<class K>
struct  _HashFunc
{
	size_t operator()(const K& key,size_t size)    //�@��ʹ��һ��size
	{
		return key% size;
	}
};
//�����string
struct _HashFuncstring  
{
	static size_t BKDRHash(const char* str) 
	{
		unsigned int seed = 131;   // 31 131 1313 13131 131313    
		unsigned int hash= 0;    
		while(*str)    
		{        
			hash=hash*seed+ (*str++);   
		}    
		return(hash& 0x7FFFFFFF); 
	}
	size_t operator()(const string str, size_t size)      //�@����C����ַ���,��ôʹ��c_str()?
	{
		return BKDRHash(str.c_str()) % size;        //ע���@���c_str�����ǽ�C++����ַ���ת��ΪC����ַ���...�ǲ����@����
	}
};

template<class K,class V,class _Hashfunctype>
class HashTable
{   
	typedef  HashNode<K, V>  HashNode;
	_Hashfunctype _ht;  
private:
	vector<HashNode> _hash;
	size_t _n;
public:
    HashTable()    //�@����vector��Ĭ�ϵĹ���
		:_n(0)
	{
	}
	bool Insert(const pair<K,V>& kv)     //����һ��pair����
	{
		_CheckCapacity();
		int  index = _ht(kv.first,_hash.size());     //Ѱ���±�
		//����ռ���ֵ
		while (_hash[index]._state == EXIST)
		{
			if (kv.first == _hash[index]._kv.first)  //��ֹ��������
			{
				return false;
			}
			++index;                          //ע���@��Ϊʲô��++index����������жϵ����棬index�����ֵ��sizeС1��
			if (index == _hash.size())       
			{
				index = 0;
			}
		}
		//����ռ�û��ֵ���߱�ɾ����
		_hash[index]._kv = kv;
		_hash[index]._state = EXIST;
		_n++;                                 //_n�������ݵĸ���
		return true;
	}

	HashNode* Find(const K& key)              //����
	{
		size_t index = _ht(key,_hash.size());            
		while (_hash[index]._state == EXIST)
		{
			if (_hash[index]._kv.first == key)
			{
				return &_hash[index];
			}
			index++;
		}
		return NULL;
	}

	bool Rmove(const K& key)                //ɾ��
	{
		HashNode* tmp = Find(key);
		if (tmp)
		{
			tmp->_state = DELETE;           //ʵ���ϲ���������ɾ����ֻ�Ǹ����@�����鵥Ԫ�����ݿ��Ա����ǵ�Ȩ��
			return true;
		}
		else
		{
			return false;
		}
	}

protected:
	rsize_t GetNextPrimeSize(size_t size)               //������
	{
		const  int _PrimeSize = 28;
		static const unsigned long _PrimeList[_PrimeSize] = {
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};
		for (int  i = 0; i < _PrimeSize; i++)
		{
			if (_PrimeList[i]>size)
			{
				return _PrimeList[i];
			}
		}
		return _PrimeList[_PrimeSize - 1];        //�Է���һ���ֵ��������󣬾ͷ�������Ǹ���������
	}

	//size_t _HashFunc(const K& key)            //��ӳ������±�
	//{
	//	return  key % _hash.size();        //������������������ĳ��ȣ��@���;��������ݶ�ɢ�����غ����Ӿͽ��ͣ���ϣ���Ч�ʾͻ�Խ�ߡ�
	//}

	void _CheckCapacity()
	{
		if (_hash.empty())     //����ڸտ�ʼ��ʱ��
		{
			_hash.resize(GetNextPrimeSize(0));
		}
		if (_n * 10 / _hash.size() <= 7)     
		{
			return;
		}
		else               //�غ�����>0.7 ��ʼ����
		{
			HashTable<K, V,_Hashfunctype> newHash;                             //ע���@�����ݵķ�ʽ
			size_t newSize = GetNextPrimeSize(_hash.size());
			newHash._hash.resize(newSize);
			for (size_t i = 0; i < _hash.size(); i++)
			{
				if (_hash[i]._state == EXIST)
				{
					int index = _ht(_hash[i]._kv.first ,newHash._hash.size());   
					newHash._hash[index]._kv = _hash[i]._kv;
					newHash._hash[index]._state = EXIST;
				}
			}
			newHash._n = _n;
			_hash.swap(newHash._hash);        //����vector��swap���н���
		}
	}
};


void test()
{
	/*HashTable<int, int,_HashFunc<int>> Hasht1;
	Hasht1.Insert(make_pair(7, 1));
	Hasht1.Insert(make_pair(72, 1));
	Hasht1.Insert(make_pair(71, 1));
	Hasht1.Insert(make_pair(34, 1));
	Hasht1.Insert(make_pair(5, 1));
	Hasht1.Insert(make_pair(66, 1));
	cout<<Hasht1.Find(34)<<endl;*/

	HashTable<string, string, _HashFuncstring> Hasht2;
	Hasht2.Insert(make_pair("left", "���"));
	//Hasht2.Insert(make_pair(string("right"), string("�ұ�")));
	//Hasht2.Insert(make_pair(string("upside"), string("�ϱ�")));
	//Hasht2.Insert(make_pair(string("down"), string("�±�")));
	//Hasht2.Insert(make_pair(string("inside"), string("���")));
}
int main()
{
	test();
	return 0;
}