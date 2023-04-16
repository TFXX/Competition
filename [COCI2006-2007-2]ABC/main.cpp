#include <stdio.h>

#define SIZE 3

int main(int argc, char **argv)
{
	int numTable[SIZE] = { 0 };
	for (unsigned int i = 0; i < SIZE; i++)
	{
		scanf((SIZE - i == 1)?("%d"):("%d "), numTable + i);
		for (unsigned int j = i; j > 0; j--)
		{
			if (numTable[j] < numTable[j - 1])
			{
				int temp = numTable[j];
				numTable[j] = numTable[j - 1];
				numTable[j - 1] = temp;
			}
		}
	}

	char string[SIZE + 1];
	scanf("%s", string);

	for (unsigned int i = 0; i < SIZE; i++)
	{
		printf((SIZE - i == 1)?("%d"):("%d "), numTable[string[i] - 'A']);
	}
	return 0;
}