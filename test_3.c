#include <stdio.h>

void printBinary(int num) {
    for(int i = 7; i >= 0; i--) {
        if(num & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    for(int num = -7; num <= 7; num++) {
        printf("数字: %d\n", num);

        printf("8位源码: ");
        printBinary(num);

        printf("反码: ");
        printBinary(~num);

        printf("补码: ");
        printBinary(num < 0 ? num + 256 : num);

        printf("\n");
    }
    return 0;
}