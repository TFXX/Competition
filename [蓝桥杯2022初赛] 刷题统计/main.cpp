#include <iostream>
#include <cstdint>

int main(int argc, char **argv)
{
	std::uint64_t a, b, n;
	std::cin >> a >> b >> n;
	std::uint64_t d = n / (a * 5 + b * 2);
	n -= d * (a * 5 + b * 2);
	d *= 7;
	if(n)
	{
		if (n > a * 5)
		{
			n -= a * 5;
			d += (n / b) + 6;
		}
		else
		{
			d += (n / a);
			if(n % a != 0)
			{
				d += 1;	
			}
		}
	}
	std::cout << d;
	return 0;
}