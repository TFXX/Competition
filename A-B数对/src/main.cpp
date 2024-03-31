#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

bool cmp(int64_t x, int64_t y)
{
	return x < y;
}

int main()
{
	uint64_t n;
	int64_t c;

	cin >> n >> c;

	if (c < 0) c = - c;

	vector<int64_t> v(n, 0);

	for (int64_t &num : v)
	{
		cin >> num;
	}

	sort(v.begin(), v.end(), cmp);

	int64_t max = v[n - 1];
	
	uint64_t cnt = 0;
	for (uint64_t i = 0; i < n; i++)
	{
		int64_t e = v[i] + c;
		if(e > max)
			continue;

		uint64_t l = i, h = n - 1;
		uint64_t mid;

		while (l <= h)
		{
			mid = (l + h) / 2;

			if (e > v[mid]) {
				l = mid + 1;
			}
			else if (e < v[mid]) {
				h = mid - 1;
			}
			else {
				for (uint64_t k = mid;v[k] == v[mid]; k--) {
					cnt++;
					if (k == i)
					{
						break;
					}
				}

				for (uint64_t k = mid; v[k] == v[mid]; k++) {
					cnt++;
					if (k == n - 1)
					{
						break;
					}
				}

				cnt -= 1;
				break;
			}
		}
	}

	cout << cnt;
	return 0;
}