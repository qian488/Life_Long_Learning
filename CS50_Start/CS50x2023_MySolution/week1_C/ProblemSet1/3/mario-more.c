#include<stdio.h>

int main(void){
    int height;
    do{
        printf("Height:");
        scanf("%d", &height);
    } while (height > 8 || height < 1);

    for (int i = 1; i <= height; i++)
    {
        int len = height - i + 1;
        for (int j = 1; j <= len; j++)
        {
            printf(" ");
        }

        for (int k = len; k <= height; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int l = len; l <= height; l++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}