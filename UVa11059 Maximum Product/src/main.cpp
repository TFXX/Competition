#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>

using namespace std;

int64_t prod(vector<int> &s, size_t a, size_t b)
{
	int64_t c = s[a];
	for (size_t i = a + 1; i <= b; i++)
	{
		c *= s[i];
	}

	return (c < 0)?(0):(c);
}

int main(int argc, char **argv)
{
	size_t n;
	
	cin >> n;

	vector<int> s(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	int64_t max = 0;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i; j < n; j++)
		{
			int c = prod(s, i, j);
			if (c > max)
			{
				max = c;
			}
		}
	}

	cout << max << endl;
	return 0;
}