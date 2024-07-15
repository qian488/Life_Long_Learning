#include<stdio.h>

int main(void)
{
    int st, ed, year = 0;
    do
    {
        printf("Start size:");
        scanf("%d", &st);
    } while (st < 9);

    do
    {
        printf("End size:");
        scanf("%d", &ed);
    } while (ed < st);

    while (st < ed)
    {
        st += st / 3 - st / 4;
        year++;
    }

    printf("Years:%d", year);
    return 0;
}