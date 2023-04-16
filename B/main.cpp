#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char **argv)
{
	int64_t a = 0;
	int64_t b = 0;
	cin >> a >> b;
	if(a < 0)
		a = -a;
	if(b < 0)
	{
		cout << -a;
	}
	else
	{
		cout << a;
	}
	return 0;
}