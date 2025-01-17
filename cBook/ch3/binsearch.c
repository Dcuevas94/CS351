#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
	int a,b[10], c;
	a = 2;
	b[0] = 3;
	c = 5;
	printf("%d\n", binsearch(a,b,c) );
}
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if ( x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}