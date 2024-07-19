#include<stdio.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>

char get_level(uint32_t grade);

int main()
{
    uint32_t grade;
    printf("Please put your grade:\n");
    scanf("%" SCNu32 "", &grade);
    printf("The level is:%c", get_level(grade));
    return 0;
}

char get_level(uint32_t grade)
{
    char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
    return grades[grade / 10];
}