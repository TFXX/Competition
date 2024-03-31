#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s, t;
	s.reserve(100008);
	t.reserve(100008);
	cin >> s >> t;

	vector<uint32_t> sxt(s.length() + 1);
	sxt[0] = 0;
	for (size_t i = 1; i <= s.length(); i++)
	{
		sxt[i] = sxt[i - 1] + ((s[i - 1] == 'X')?(1):(2));
	}

	vector<uint32_t> txt(t.length() + 1);
	txt[0] = 0;
	for (size_t i = 1; i <= t.length(); i++)
	{
		txt[i] = txt[i - 1] + ((t[i - 1] == 'X') ? (1) : (2));
	}


	uint32_t q;
	cin >> q;

	size_t a, b, c, d;
	for (uint32_t i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;
		//scanf("%zu %zu %zu %zu", &a, &b, &c, &d);
		uint32_t s_x_cnt = sxt[b] - sxt[a - 1];

		uint32_t t_x_cnt = txt[d] - txt[c - 1];

		int32_t delta = s_x_cnt - t_x_cnt;

		if (delta < 0)
			delta = -delta;
		if (delta % 3 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}