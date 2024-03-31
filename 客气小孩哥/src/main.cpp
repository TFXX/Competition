#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

void f(uint64_t &v1, uint64_t &v2)
{
	v2 += (v1 / 2);
	v1 = (v1 % 2);
}

bool g(uint64_t &n, uint64_t &m)
{
	if (n < 2 && m < 2)
		return false;
	else if (n > m)
		f(n, m);
	else
		f(m, n);
	return true;
}

int main()
{
	uint64_t n, m;
	cin >> n >> m;
	//scanf("%llu %llu", &n, &m);
	while (true)
	{
		if (!g(n, m)) {
			cout << "Alice";
			break;
		}
		if (!g(n, m)) {
			cout << "Brown";
			break;
		}
	}
	return 0;
}