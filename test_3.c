#include <stdio.h>
int SUM( int n )
{
	if ( n == 1 )
		return(1);
	else return(n * n + SUM( n - 1 ) );
}




int main()
{
	printf( "SUM=%d", SUM( 5 ) );
	return(0);
}