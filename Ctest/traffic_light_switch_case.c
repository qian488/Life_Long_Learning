#include<stdio.h>
#include<stdint.h>

int main()
{
    //状态机
    //管理复杂状态的转换

    //枚举

    uint8_t traffic_light_state = 0;//初始状态：红灯

    switch (traffic_light_state)
    {
    case 0:
        puts("红灯");
        traffic_light_state = 1;
        break;
    case 1:
        puts("绿灯");
        traffic_light_state = 2;
        break;
    case 2:
        puts("黄灯");
        traffic_light_state = 0;
        break;
    default:
        puts("???");
        break;
    }
    
    return 0;
}