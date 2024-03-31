#include <iostream>
#include <string>

using namespace std;
int main(int agrc, char **argv)
{
	string s(32, '\0');

	cin >> s;

	for (size_t i = 0; i < 3; i++)
		s.push_back(s[i]);

	const string sn(s.c_str() + 3);

	for (const char &a : sn)
	{
		//cout << num static_cast<uint8_t>(a);
		printf("%d", a);
	}
}