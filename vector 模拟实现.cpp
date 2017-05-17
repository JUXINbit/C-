#define _CRT_SECURE_NO_WARNINGS 1

//ģ��STL�е�vector
#include<iostream>
#include<assert.h>
#include<string>
#include"TypeTaritsV.h"
using namespace std;


template<class T>
class Vector
{
public:
	typedef T* Iterator;    //std�е�vector������ԭ��ָ����Ϊ��������ע�⣺ԭ��ָ�����ͱ������һ��������
	typedef const T* ConstIterator;
	typedef TypeTarits<T>  TypeTarits;
private:
	Iterator _start;
	Iterator _finish;
	Iterator _EndofStorage;
public:
	Vector()
		:_start(NULL)
		,_finish(NULL)
		,_EndofStorage(NULL)
	{
		cout << "����" << endl;
	}

	Vector(const Vector<T>& v)    //[*]      ע��vector����Ŀ�������ķ�ʽ   1.��� 2.ʹ�ÿ����ݸ�����û��ѡ�񿽱������ķ�ʽ 3.ʹ��������ȡ
		:_start(NULL)            // ע�⣺ ��������һ��Ҫ��ʼ��
		,_finish(NULL)
		,_EndofStorage(NULL)
	{
		Expand(v.Size());          //vector��������ʹ���˿���size�ķ�ʽ   Ϊʲô��������
		if (TypeTarits::IspodType().get())    //ʹ��������ȡ    std::vector�е�ʵ�ַ�ʽ
		{
			memcpy(_start, v._start, sizeof(T)*v.Size());
		}
		for (size_t i = 0; i < v.Size(); i++)    //������������ͣ��@�����ʹ��memcpy��ΪЧ�ʸߣ�����������Զ������;Ͳ���ʹ�ã����Կ���ʹ��������ȡ
		{
			_start[i] = v[i];      //�@�������[]���������
		}
		_finish = _start + v.Size();
		_EndofStorage = _finish;

	}
	Vector<T>& operator=(const Vector<T>& v)
	{
		if (_start)
			Destory();
		Expand(v.Size());      
		if (TypeTarits::IspodType().get())
		{
			memcpy(_start, v._start, sizeof(T)*v.Size);
		}
		for (size_t i = 0; i < v.Size(); i++)    
		{
			_start[i] = v[i];      
		}
		_finish = _start + v.Size();
		_EndofStorage = _finish;
	
	}

	size_t Capacity()
	{
		return _EndofStorage - _start;
	}
	size_t Capacity() const 
	{
		return _EndofStorage - _start;
	}

	size_t Size()
	{
		return _finish - _start;
	}
	size_t Size() const 
	{
		return _finish - _start;
	}

	void Expand(size_t n)   //[*] ���� ��n����Ŀռ�Ȼ������
	{
		if (n <= Capacity())
			return;
		size_t size = Size();                //��size��С��������
		Iterator newstart = new T[n];        //����T��Ĭ�Ϲ��캯�����г�ʼ��,�������ݺ��

		for (size_t i = 0; i < size; i++)
		{
			newstart[i] = _start[i];
		}

		delete[] _start;                 //���@���Ѿ���_start�ͷ��� �������Ҫ����Size()���Ҳ���_start
		_start = newstart;
		//_finish = _start + Size();        ��ԭ����ôд�����ˡ�
		_finish = _start + size;
		_EndofStorage = _start + n;
	}

	void PushBack(const T& d)
	{
		if (_finish >= _EndofStorage)
		{
			size_t capacity = Capacity();
			size_t size = Size();
			capacity = capacity + capacity / 2;               //   STL��ʹ��1/2�����ݣ�����Ҫ�����������
			if (capacity < size + 1)
			{
				capacity = size + 1;
			}
			Expand(capacity);
		}
		*_finish = d; //[*]
		_finish++;
	}

	void PopBack()
	{
		if (_start == NULL || Size() == 0)
			return;
		Iterator tmp = _finish-1;
		delete _finish;
		_finish = tmp;
	}

	//resize ��ģ��   ����Ҫ  
	void Resize(size_t n,const T& d=T())     //  ����Ҫ//Ĭ��ֵΪȱʡֵ      capacity��ֵ�����˾Ͳ�����С��  
	{
		if (n > Capacity())     //�@������
			Expand(n);
		size_t size = Size();
		if (n < size)
		{
			Iterator tmp = _start + n;
			while (tmp != _finish)
			{
				tmp->~T();
			}
			_finish = _start + n;
		}
		else
			Iterator tmp = _finish;
		    while (tmp != (_start + n))
		   {
			    *tmp = d;
		   }
			_finish = _start + n;
	}
	void Reverse(size_t n)// ����
	{
		Expand(n);
	}

	//ע�⣺�@��Ĳ����ɾ�������漰��������ʧЧ������
	void Insert(Iterator pos, const T& d)
	{
	}
	void Erase(Iterator pos)
	{
	
	}
	Iterator Begin()
	{
		return _start;
	}

	Iterator Begin()const     //ΪConstIterator����
	{
		return _start;
	}

	Iterator End()
	{
		return _finish;
	}

	Iterator End() const
	{
		return _finish;
	}
	//************************************���±��������������Ϊ�˴ﵽ�����ڵ������Ĺ�Чʹ��Vector�������[]ʵ���������ӡ*******************
	//��д
	T& operator[](size_t index)
	{
		if (index >= Size())
		{
			perror("index");
		}
		return _start[index];
	}
	//ֻ��
	const T& operator[](size_t index) const 
	{
		if (index >= Size())                    //ע�⣺ �@���Size()��Ԫ�ظ���
		{
			/*cout << "Խ��" << endl;
			return NULL;*/
			perror("index");
		}
		return _start[index];
	}

	void Destory()
	{
		delete[] _start;                       //ע��ϸ�ڣ� delete[]
		_start = NULL;
		_finish = NULL;
		_EndofStorage = NULL;
	}
	~Vector()
	{
		if (_start == NULL)
			return;
		Destory();
		cout << "����" << endl;
	}
};

// �����ӡ
template<class T>
void PrintVector(Vector<T>& v)
{
	//-------------------------ʹ�õ�������ӡ-------------------------------------
	//Vector<T>::Iterator itv = v.Begin();    
	//while (itv != v.End())              //ԭ��ָ�뱾�����һ��������
	//{
	//	cout << *itv << " ";           //��Ϊ��ԭ��ָ�룬�����@д++  ��= ����Ҫ������ 
	//	itv++;
	//}
	//cout << endl;
	//-------------------------ʹ��[]�����ش�ӡ------------------------------------
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	
}
template<class T>      //------------------------------const������ʵ��----------------------------------
void cPrintVector(const Vector<T>& v)
{
	Vector<T>::ConstIterator itv = v.Begin();
	while (itv!=v.End())
	{
		cout << *itv << " ";
		itv++;
	}
}
void test()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	PrintVector(v1);
	v1.Reverse(10);
	PrintVector(v1);
	//v1.Resize(2);
	Vector<int> v2 = v1;
	PrintVector(v2);
	cPrintVector(v2);
}
int main()
{
	test();
	return 0;
}