#include <stdio.h>
//interesting, counts the spaces and '\n' of an enter.
//counts all characters including the enter on the keyboard
int main()
{
	double nc;
	for ( nc = 0; getchar() != '0'; ++nc)
		; //null statement of a loop.
		printf("%.0f\n", nc);
}