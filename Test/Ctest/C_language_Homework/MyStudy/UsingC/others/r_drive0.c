#include <stdio.h>
extern unsigned int rand0(void);

int main(void){
    
    for(int count=0;count<5;count++) printf("%d\n",rand0());

    return 0;
}