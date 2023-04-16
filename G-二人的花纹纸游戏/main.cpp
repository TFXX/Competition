#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	int (*mA)[1000] = new int[1000][1000];
	int (*mB)[50]  = new int[50][50];

	size_t rowA, colA;
	cin >> rowA >> colA;
	for(size_t i = 0; i < rowA; i++)
	{
		for(size_t j = 0; j < colA; j++)
		{
			cin >> mA[i][j];
		}
	}

	size_t rowB, colB;
	cin >> rowB >> colB;
	for(size_t i = 0; i < rowB; i++)
	{
		for(size_t j = 0; j < colB; j++)
		{
			cin >> mB[i][j];
		}
	}

	uint64_t q;
	cin >> q;
	for(; q > 0; q--)
	{
		uint64_t sum = 0;
		size_t row1, row2, col1, col2;
		cin >> row1 >> col1 >> row2 >> col2;
		row1-=1;
		row2-=1;
		col1-=1;
		col2-=1;
		for(size_t i = row1; i <= row2; i++)
		{
			for(size_t j = col1; j <= col2; j++)
			{
				if(mB[(i - row1) % rowB][(j - col1) % colB] == 0)
				{
					sum += mA[i][j];
				}
			}
		}
		cout << sum % 998244353;
		if(q != 1)
		{
			cout << '\n';
		}
	}
	return 0;
}