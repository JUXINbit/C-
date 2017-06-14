#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;


//��ϣͰ   ����ϣ�� �����������ϣ��ͻ��
//Ͱ������治��Ҫ״̬����һ��ԭ��ͰҲ��ּ�ڽ����ϣ��ͻ,��������Ҫ�����ڲ���ķ�ʽ��ȥ��Զ

template<class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	HashNode<K, V>* _next;
	HashNode(const pair<K,V>& kv)
		:_kv(kv) 
		,_next(NULL)
	{
		cout << "�����ϣ���" << endl;
	}
};

//ע���@���������
template<class K, class V>
class HashBucket;

//������[*]
template<class K, class V>
struct HashBucketIterator
{
	typedef HashNode<K, V> Node;
	typedef HashBucketIterator<K, V>  Iterator;
	//ע������
	Node* _node;
	HashBucket<K, V>* _Hash;         //ע���@��ΪʲôҪ������һ����ϣͰ����ָ�룬��ʲô�ã��ɲ����Դ�һ��������ȥ������ָ�룬Ҳ���Ե����˷ѿռ�
	//����;
	HashBucketIterator(Node* node,HashBucket<K,V>* Hash)
		:_node(node)
		, _Hash(Hash)
	{
	}
	//��������
	HashBucketIterator(const Iterator& it)
	{
		_node = it._node;
		_Hash = it._Hash;
	}
	K& operator*()
	{
		return _node->_kv.first;
	}
	K* operator->()
	{
		return &_node->_kv.first;
	}
	//[*]
	Iterator& operator++()
	{
		size_t Nowindex = _node->_kv.first % _Hash->_hash.size();      //�@��ʵ������������������������ݣ���Ҫ������Ԫ
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else    //�ص��������±�������
		{
			Nowindex++;
			while (Nowindex < _Hash->_hash.size() && _Hash->_hash[Nowindex] == NULL)
			{
				Nowindex++;
				if (Nowindex == _Hash->_hash.size())      //�ж��Ѿ��������
				{
					_node = NULL;
					return *this;
				}
			}
			_node = _Hash->_hash[Nowindex];
		}
		return *this;                               
	}
	//Iterator& operator--()     //���������Ƴ�˫�򣬵�����--����ʵ��
	//{
	//	;
	//}
	bool operator==(const Iterator& it)
	{
		return (_node == it._node) && (_Hash == it._Hash);
	}
	bool operator!=(const Iterator& it)
	{
		return _node != it._node;
	}
	
};

template<class K ,class V>
class HashBucket
{
	typedef HashNode<K, V> Node;
	friend struct HashBucketIterator<K, V>;            //ע���@�ﶨ����Ԫ��Ŀ�ģ���Ϊ�@����������Щ���⣬���Ըտ�ʼ��һֱ�಻��
public:
	typedef HashBucketIterator<K, V>  Iterator;        
private:
	vector<Node*> _hash;
	size_t _n;
public:
	HashBucket()                                        //Ĭ�ϵĹ���
		:_n(0)
	{
	}
	bool Insert(const pair<K, V>& kv)         //��ϣͰ�ļ�ֵ������ʲô���
	{
		_CheckCapacity();
		size_t index = _HashFunc(kv.first, _hash.size());
		Node* prev = _hash[index];
		while (prev)                       //��ֹ��ֵ����
		{
			if (prev->_kv.first == kv.first)
			{
				return false;
			}
			prev = prev->_next;
		}

		Node* tmp = new Node(kv);
		Node* cur = _hash[index];
		_hash[index] = tmp;
		tmp->_next = cur;

		_n++;
	}
	Node* Find(const K& key)                         //������������ֳ���Ч��
	{
		size_t index = _HashFunc(key, _hash.size());
		Node* cur = _hash[index];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}

	bool Remove(const K& key)     //˼��λʲô�@���Remove����ʹ�������Findȷ��λ�ã�
	{
		size_t index = _HashFunc(key, _hash.size());
		Node* prev = NULL;
		Node* cur = _hash[index];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				if (prev == NULL)           //���ɾͷ���
				{
					_hash[index] = cur->_next;
				}
				else                       //ɾ�м������β���
				{
					prev->_next = cur->_next;
				}
				delete cur;
				_n--;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}

	void Resize(const size_t& size)                      //˼��Ϊʲô��Ҫ�@������ ��Ч���Ͽ����@�����б�Ҫ
	{
		_hash.resize(GetNextPrimeSize(size));
	}

	size_t HashSize()
	{
		return _hash.size();
	}
	size_t HashNum()
	{
		return _n;
	}

	//����������
	Iterator Begin()
	{
		for (size_t i = 0; i < _hash.size(); i++)
		{
			if (_hash[i] != NULL)
			{
				Iterator itbegin(_hash[i],this);      //ע���@����this  �տ�ʼ����ô���벻��������ڲ���ô���Լ�����ȥ 
				return itbegin;
			}
		}

		return Iterator(NULL, this);
	}
	Iterator End()
	{
		Iterator itend(NULL, this);
		return itend;
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
		for (int i = 0; i < _PrimeSize; i++)
		{
			if (_PrimeList[i]>size)
			{
				return _PrimeList[i];
			}
		}
		return _PrimeList[_PrimeSize - 1];        
	}
	//�����±�
	size_t _HashFunc(const K& key, size_t size)  
	{
		return key % size;
	}
	void _CheckCapacity()                            //����
	{
		if (_hash.empty())
		{
			_hash.resize(GetNextPrimeSize(0));
		}

		if (_hash.size() == _n)                          //��ϣͰ���غ������ǿ��Կ��Ƶ�1�ģ������Ҿ��ĺ���֣�ʵ�����ҳ���1Ҳ�ǿ��Եġ��غ����Ӻ�Ч�ʵ����������Ĺ�ϵ
		{
		    size_t newSize = GetNextPrimeSize(_hash.size());
			HashBucket<K, V> newBucket;                //�����±�
			newBucket._hash.resize(newSize);
			for (size_t i = 0; i < _hash.size(); i++)   //����ԭ�� ,��ô����ԭ��ģ���ô��ԭ�����±�ģ� ÿһ�����ݶ�Ҫ���²���λ�ã��Ƚ��鷳����ȴ���룡
			{
				Node* cur = _hash[i];
				while (cur)
				{
					Node* next = cur->_next;   //��������
					//��ȡ�����еĽ��Ȼ��ͷ���±��������½��
					size_t index = _HashFunc(cur->_kv.first, newBucket._hash.size());
					cur->_next = newBucket._hash[i];
					newBucket._hash[i] = cur;
					//ԭͰ����һ�����
					cur = next;
				}
				_hash[i] = NULL;                   //�@��һ��Ҫ�ÿգ���Ȼ������ԭ���ʱ��ͻ��������
			}
			_hash.swap(newBucket._hash);             //���⣺�@����������swap���ԭ����vector��������  ���⡣
		}
	}
};

//������ʹ��
template<class K,class V>
void PrintHashBucket(HashBucket<K,V>& Hb)
{
	HashBucket<K, V>::Iterator it = Hb.Begin();
	while (it != Hb.End())
	{
		cout << *it <<" ";
		++it;
	}
	cout << endl;
}


//-------------------------------����-----------------------
void test()
{
	HashBucket<int, int> Hb1;
	//insert
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 3));
	Hb1.Insert(make_pair(rand(), 4));
	Hb1.Insert(make_pair(rand(), 4));
	Hb1.Insert(make_pair(rand(), 4));
	Hb1.Insert(make_pair(rand(), 4));
	Hb1.Insert(make_pair(rand(), 4));
	Hb1.Insert(make_pair(rand(), 4));

	//find
	cout << Hb1.Find(1124) << endl;
	cout << Hb1.Find(11942) << endl;
	cout << Hb1.Find(491) << endl;
	cout << Hb1.Find(67) << endl;
	cout << Hb1.Find(89) << endl;
	cout << Hb1.Find(52) << endl;
	//remove
	cout<<Hb1.Remove(11942)<<endl;
	cout << Hb1.Remove(491) << endl;
	//resize                                   //ʵ�����@���resize�Ǵ��ڵ�����ģ����resie��������տ�ʼ��ʱ��ʹ�ã���ô���������ݶ���û�н������ڹ�ϣ�������²��֡�
	Hb1.Resize(100000);
	cout << Hb1.HashSize() << endl;
	Hb1.Resize(200000);
	cout << Hb1.HashSize() << endl;


	HashBucket<int, int> Hb2;
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));
	//Hb2.Insert(make_pair(rand(), 3));

	//����������
	//PrintHashBucket(Hb1);              //��Ϊresize��ԭ���@��ʹ��ںܴ������
	PrintHashBucket(Hb2);
}
int main()
{
	test();
	return 0;
}