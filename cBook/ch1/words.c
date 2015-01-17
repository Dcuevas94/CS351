#include <stdio.h>
#define IN 1	//inside a word
#define OUT 0 	//outside a word

//count lines, words and characters in the input
int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != '0'){
		++nc;
		if ( c == '\n')
			++nl;
		if ( c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("%d (new line) %d (new word) %d (new char)\n", nl, nw, nc);
}