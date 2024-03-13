#include <iostream>
#include <cstdint>

using namespace std;

double JFC(uint64_t k)
{
	double delta = sqrt(1 + 8 * k);
	return 1.0f + delta / 4;
}

int main(int argc, char **argv)
{
	uint32_t q = 0;
	cin >> q;
	for(; q > 0; q--)
	{
		uint64_t k = 0;
		cin >> k;

		uint64_t n = ceil(JFC(k));
		uint64_t downK = n * (2 * n - 1);
		uint64_t dx = k - downK;

		uint64_t a = 0;
		uint64_t b = a + 1;
		uint64_t c = 0;
		while(k > b)
		{
			k -= b;
			a += 4;
			b = a + 1;
			c += 1;
		}
		/*
		bool n = false;
		k -= 1;
		if(k > a / 2)
		{
			n = true;
			k -= a / 2;
		}

		int64_t y = 0;
		if(k > a / 4)
		{
			y = c - k + a / 4;
		}
		else
		{
			y = k;
		}

		if(n)
		{
			y = -y;
		}

		cout << y;
		if(q != 1)
		{
			cout << '\n';
		}
		*/
	}
	return 0;
}