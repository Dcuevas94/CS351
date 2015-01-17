#include <stdio.h>
int main() 
{
	int c, i, nWhite, nOther;
	int nDigit[10];
	nWhite = nOther = 0;
	for (i = 0; i < 10; ++i)
		nDigit[i] = 0;
	while ((c = getchar()) != '!')
		if ( c >= '0' && c <= '9')
			++nDigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nWhite;
		else
			++nOther;
		printf("\ndigits\n");
		//prints out (#) #ofoccurences
		//then the white spces and other chars
		for (i = 0; i <10; ++i)
			printf("%d (%d)\n", i, nDigit[i]);
		printf("white space: %d,\nother = %d\n", nWhite, nOther);
}