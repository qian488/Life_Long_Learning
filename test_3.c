#include <stdio.h>
#define  F(n)  3*n

int main()
{
	printf("%d\n", F(5 + 2));
	printf("%d\n", F(2 + 5));
	printf("%d", F((5 + 2)));
	return(0);
}