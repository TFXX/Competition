/*
区间内的真素数
内存限制：512Mb
时间限制：1s
提交：372
解决：87
题目描述
找出正整数 M 和 N 之间（ N 不小于 M）的所有真素数。

真素数的定义：如果一个正整数 P 为素数，且其反序也为素数，那么 P 就为真素数。

例如，
11
11，
13
13 均为真素数，因为
11
11 的反序还是为
11
11，
13
13 的反序为
31
31 也为素数。

输入
输入两个数 M 和 N，空格间隔。

输出
按从小到大输出M 和 N 之间（包括M 和 N）的真素数，逗号间隔。如果之间没有真素数，则输出 No。

样例输入1
10 35

样例输出1
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