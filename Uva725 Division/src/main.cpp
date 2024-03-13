#include <iostream>
#include <iomanip>

using namespace std;

int judge(int a, int b)
{
	if (b < 1234 || b > 98765)
	{
		return -1;
	}

	static int used[10];

	for (int i = 0; i < 10; i++)
	{
		used[i] = 0;
	}

	if (a < 10000 || b < 10000)
	{
		used[0] = 1;
	}

	while ( a != 0)
	{
		used[a % 10] = 1;
		a /= 10;
	}

	while (b != 0)
	{
		used[b % 10] = 1;
		b /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		if (0 == used[i])
		{
			return -1;
		}
	}

	return 0;
}

int main(int agrc, char **argv)
{
	int n = 0;
	cin >> n;
	for (int i = 1234; i <= 98765; i++)
	{
		if(0 == judge(i, i * n))
		{
			cout << setw(5) << setfill('0') << i * n << " / " << setw(5) << setfill('0') << i << " = " << n << endl;
		}
	}
	return 0;
}