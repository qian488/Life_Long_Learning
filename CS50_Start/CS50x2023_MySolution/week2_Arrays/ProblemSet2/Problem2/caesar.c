#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int length = strlen(argv[1]);

    for (int i = 0; i < length; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]); 
    string Pt = get_string("plaintext: ");  
    int lengthPt = strlen(Pt);
    printf("ciphertext: ");

    for (int j = 0; j < lengthPt; j++)
    {
        char p = Pt[j]; 
        char c;

        if (isupper(p)) 
        {
            c = (((p - 65) + k) % 26) + 65;
            printf("%c", c);
        }
        else if (islower(p))  
        {
            c = (((p - 97) + k) % 26) + 97;
            printf("%c", c);
        }
        else 
        {
            printf("%c", p);
        }
    }
    printf("\n");
}