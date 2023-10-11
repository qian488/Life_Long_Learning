#include<stdio.h>
#include<string.h>
int main()
{
    char c[10];
    scanf(" %[^\n]", c);
    int m = strlen(c);
    for (int j = m; j >= 0; j--)
    {
        printf("%c", c[j]);
    }
    return 0;
}