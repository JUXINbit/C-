#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<assert.h>
#include<math.h>

#define EXP  0.0000001                                 //����һ��ע������ڱȽ�double�ı�����ʱ��궨�徫�ȱȽϣ����Բ���ʹ��d1==d2;�@��

//ģ��C�⺯���е�pow������ʵ����base��exponent�η���ֵ
double MyPower(double base, int exponent)
{

	double result = 1.0;
	//������
	if (base<EXP && base>-EXP && exponent < 0)      //�����Ŀ��������˵����Ϊ0 ��ʱ��ָ��С��0��ʱ�� ����
	{
		printf("0Ϊ�����������Ǹ����η�\n");
		return 0.0;
	}
	if (exponent == 0)
		return result;
	if (exponent > 0)      //ָ��Ϊ��
	{
		int i = 0;
		for (; i < exponent; i++)
		{
			result *= base;
		}
		return result;
	}
	else                 //ָ��Ϊ�������ȡ����
	{
		int i = 0;
		for (; i < -exponent; i++)
		{
			result *= base;
		}
		return 1.0 / result;
	}
}


//************************��������************************
void test(void)
{
	double result = 1.0;
	//result = MyPower(3, 4);
	//result = MyPower(-1, 4);
	//result = MyPower(-2, -3);
	//result = MyPower(-2, 0);
	result = MyPower(0, -4);
	printf("%lf\n", result);
}
int main()
{
	test();
	return 0;
}