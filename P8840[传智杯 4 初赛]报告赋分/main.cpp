#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	size_t aSize, bSize;
	cin >> aSize >> bSize;
	vector<uint32_t> bigA(aSize + 1);
	for(size_t i = aSize; i > 0; i--)
	{
		cin >> bigA[i - 1];
	}

	vector<uint32_t> bigB(bSize + 1);
	for(size_t i = bSize; i > 0; i--)
	{
		cin >> bigB[i - 1];
	}

	if(bSize > aSize)
	{
		swap(aSize, bSize);
		swap(bigA, bigB);
	}

	uint32_t jinZhi = 2;
	uint32_t more = 0;

	
	for(size_t i = 0; i < aSize; i++)
	{
		if(i < bSize)
		{
			bigA[i] += (bigB[i] + more);
			more = bigA[i] / jinZhi;
			bigA[i] = bigA[i] - more * jinZhi;
			jinZhi += 1;
		}
		else
		{
			bigA[i] += more;
			more = bigA[i] / jinZhi;
			bigA[i] = bigA[i] - more * jinZhi;
			jinZhi += 1;
		}
	}

	if(more != 0)
	{
		bigA[aSize] = more;
		aSize ++;
	}

	for(size_t i = aSize ; i > 0; i--)
	{
		cout << bigA[i - 1] << (i == 1?"":" ");
	}

	return 0;
	
}