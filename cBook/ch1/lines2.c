#include <stdio.h>
#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline2(void);
void copy(void);

int main()
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while (( len = getline2()) > 0)
		if ( len > max ){
			max = len;
			copy();
		}
	if (max > 0) //there was a ling 
		printf("%s\n", longest);
	return 0;
}

//getline2
int getline2(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != '0' && c != '\n'; ++i)
		line[i] = c;
	if ( c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

//void copy
void copy(void)
{
	int i;
	extern char line[], longest[];
	i = 0;
	while( (longest[i] == line[i]) 	!= '\0')
		++i;
}