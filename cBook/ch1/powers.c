#include <stdio.h>

int power(int m, int n);

//compute the power of x^y
int main()
{
	int i;
	printf("power, 2^x, -3^x\n");
	for ( i = 0; i < 10; ++i)
		printf("%5d %3d%7d\n", i, power(2,i), power(-3, i));
	return 0;
}
//power function
int power(int base, int n)
{
	int i, p;
	p = 1;
	for ( i = 1; i <= n; ++i)
		p = p * base;
	return p;
}