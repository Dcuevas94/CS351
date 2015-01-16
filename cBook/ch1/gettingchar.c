#include <stdio.h>
int main()
{
	int c;
	c = getchar();
	while ( c != '0' ){		//please note, 0 without qoutes will get
							//the char value of 0 instead of the actual 0
		putchar(c);
		c = getchar();
	}
	return 0;
}