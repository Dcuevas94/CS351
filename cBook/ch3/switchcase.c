#include <stdio.h>
//count digits, white space, others...
int main()
{
	int c, i, nWhite, nOther, nDigit[10];
	nWhite = nOther = 0;
	for (i = 0; i < 10; i++)
		nDigit[i] = 0;
	while ((c = getchar()) != '!'){
		switch(c) {
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				nDigit[c-'0']++;
				break;
			case ' ':
			case '\n':
			case '\t':
				nWhite++;
				break;
			default:
				nOther++;
				break;
		}
	}
	printf("digits:\n ");
	for(i = 0; i < 10; i++)
		printf("%d (%d)\n",i, nDigit[i] );
	printf("white space: %d, other: %d\n", nWhite, nOther );
	return 0;
}