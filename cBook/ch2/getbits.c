#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);

int main()
{	
	int x = 4;
	printf("Result of bit shiffting:\n");
	printf("%6.6d %6.6x %6.6u\n", getbits(x,4,3), getbits(x,4,3), getbits(x,4,3));

}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}