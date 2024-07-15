#include <stdio.h>

char check_card(long long n);
char check_validity(int s);

int main(void)
{
    int t = 0;
    long long number;
    char card, validity;
    int index = 1;
    int s1 = 0; // Sum of odd digits
    int s2 = 0; // Sum of even digits*2
    int sum = 0; // Total Sum

    printf("Number: ");
    scanf("%lld", &number);

    while (number != 0)
    {
        t = number % 10;    

        if (index % 2 == 1)
        {
            s1 = s1 + t;
        }
        else
        {
            int even = t * 2;
            if (even > 9)
            {
                s2 = s2 + (even / 10) + (even % 10);    
            }
            else
            {
                s2 = s2 + even;
            }
        }

        if (number >= 10 && number <= 99) 
        {
            card = check_card(number);
        }
        number = number / 10;
        index++;
    }

    sum = s1 + s2;
    validity = check_validity(sum);
    index -= 1;
    
    if (validity == 'V' && card == 'A' && index == 15)  // American Express uses 15-digit numbers
    {
        printf("AMEX\n");
    }
    else if (validity == 'V' && card == 'M' && index == 16) // MasterCard uses 16-digit numbers
    {
        printf("MASTERCARD\n");
    }
    else if (validity == 'V' && card == 'V' && (index == 13 || index == 16)) // Visa uses 13- and 16-digit numbers
    {
        printf("VISA\n");
    }
    else if (validity == 'I' && card == 'I')
    {
        printf("INVALID\n");
    }
}

char check_card(long long n)
{
    if (n == 34 || n == 37) //  All American Express numbers start with 34 or 37
    {
        return ('A');   // American
    }
    else if (n >= 51 && n <= 55)    // Most MasterCard numbers start with 51, 52, 53, 54, or 55
    {
        return ('M');   // MasterCard
    }
    else if ((n / 10) == 4) // All Visa numbers start with 4
    {
        return ('V');
    }
    else
    {
        return ('I');   // Invalid
    }
}

char check_validity(int s)
{
    return (s % 10) ? 'I' : 'V'; // Invalid or Valid
}