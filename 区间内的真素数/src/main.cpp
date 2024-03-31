/*
�����ڵ�������
�ڴ����ƣ�512Mb
ʱ�����ƣ�1s
�ύ��372
�����87
��Ŀ����
�ҳ������� M �� N ֮�䣨 N ��С�� M����������������

�������Ķ��壺���һ�������� P Ϊ���������䷴��ҲΪ��������ô P ��Ϊ��������

���磬
11
11��
13
13 ��Ϊ����������Ϊ
11
11 �ķ�����Ϊ
11
11��
13
13 �ķ���Ϊ
31
31 ҲΪ������

����
���������� M �� N���ո�����

���
����С�������M �� N ֮�䣨����M �� N���������������ż�������֮��û��������������� No��

��������1
10 35

�������1
11,13,17,31

*/

#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

uint64_t f(uint64_t n)
{
	uint32_t t = 0;
	
	for (; n != 0; n /= 10)
		t = t * 10 + n % 10;

	return t;
}

uint32_t g(uint64_t n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}


int main(int argc, char **argv)
{
	uint64_t m, n;
	cin >> m >> n;

	uint64_t *a = new uint64_t[n + 1]();

	a[0] = 1;
	a[1] = 1;
	for (uint64_t i = 2; i <= n; i++)
	{
		if (1 == a[i])
			continue;

		for (uint64_t j = i * i; j <= n; j += i)
			a[j] = 1;
	}

	uint64_t cnt = 0;
	for (uint64_t i = m; i <= n; i++)
	{
		if (1 == a[i])
			continue;

		if (1 == g(f(i)))
		{
			if (0 != cnt)
			{
				cout << ",";
			}
			cout << i ;
		}

		cnt++;
	}

	if (0 == cnt)
	{
		cout << "No";
	}

	delete[] a;
	return 0;
}