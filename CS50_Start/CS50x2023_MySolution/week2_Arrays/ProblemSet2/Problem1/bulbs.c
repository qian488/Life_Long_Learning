#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    char word[MAXLEN];
    printf("Message:");
    scanf("%s", word);
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        int Ascii = (int)word[i];
        int bit = 7;
        int Binary[BITS_IN_BYTE] = {0};
        while (Ascii != 0)
        {
            Binary[bit] = Ascii % 2;
            Ascii /= 2;
            bit -= 1;
        }
        
        for (int j = 0; j < 8; j++)
        {
            print_bulb(Binary[j]);
        }
        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
