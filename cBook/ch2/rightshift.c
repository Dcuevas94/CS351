#include <stdio.h>
int bitcount(unsigned x);

int main()
{
	int n = 65;
	printf("Value: %d\n", bitcount(n));
}

int bitcount(unsigned x)
{
	int b;

	for ( b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}