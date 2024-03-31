#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>

using namespace std;

struct s{
	const char *p;
	size_t length;
};

bool cmp(s& s1, s& s2)
{
	if (s1.p == s2.p) {
		return s1.length < s2.length;
	}

	size_t min = (s1.length < s2.length)?(s1.length):(s2.length);

	for (size_t i = 0; i < min; i++) {
		if (s1.p[i] != s2.p[i])
			return s1.p[i] < s2.p[i];
	}

	return s1.length < s2.length;
}

int main()
{
	string problems;
	cin >> problems;
	uint64_t k;
	cin >> k;
	vector<s> v;


	s temp;
	const char *f = problems.c_str();
	const char *l = problems.c_str() + problems.length();
	//for (size_t i = 0; i < problems.length(); i++)
	for (const char *i = f; i < l; i++)
	{
		for (size_t j = 1; i + j <= l; j++)
		{
			temp.p = i;
			temp.length = j;

			bool bF = false;
			for (s &s_ : v) {
				if (s_.length == temp.length) {
					if (strncmp(s_.p, temp.p, temp.length) == 0)
					{
						bF = true;
					}
				}
			}

			if (bF)
			{
				continue;
			}

			v.push_back(temp);

			sort(v.begin(), v.end(), cmp);

			if (v.size() > 5)
			{
				v.pop_back();
			}
		}
	}

	for (size_t i = 0; i < v[k-1].length; i++)
	{
		cout << v[k-1].p[i];
	}
	return 0;
}