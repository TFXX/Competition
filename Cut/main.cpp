#include <iostream>
#include <algorithm>

int main()
{
	unsigned int* a = new unsigned int[10000];
	size_t n = 0;

	std::cin >> n;

	unsigned long long int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> a[i];
		sum += a[i];
	}

	std::sort(a, a + n);
	
	unsigned long long int ans = 0;

	for (size_t i = 0; i < n; i++)
	{
		
		ans += sum;
		sum -= a[i];
	}

	ans -= a[n - 1];

	std::cout << ans;
	return 0;
}