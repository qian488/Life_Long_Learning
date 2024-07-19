#include<stdio.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
#include<stdlib.h>
#include<time.h>

//游戏选项
#define EXIT 0
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

//函数声明
void print_instructions();
uint32_t get_player_move();
uint32_t get_computer_move();
void print_move(uint32_t move);
void determine_winner(uint32_t player_move, uint32_t computer_move);

int main()
{
    //初始化随机数生成器
    srand(time(NULL));

    //打印游戏说明
    print_instructions();

    uint32_t player_move;
    uint32_t computer_move;
    while(1)
    {
       //获取玩家和计算机的选择
       player_move = get_player_move();
       computer_move = get_computer_move();

       //退出游戏选项
       if(player_move==EXIT) break;

        //展示玩家与计算机的选择
        puts("你选择了");
        print_move(player_move);
        puts("计算机选择了");
        print_move(computer_move);

        //判断输赢
        determine_winner(player_move, computer_move);

    }

    puts("游戏已退出");

    return 0;
}

void print_instructions()
{
    //打印游戏说明
    puts("石头，剪刀，布，游戏开始！");
    puts("规则：输入数字，确定猜拳。1是石头，2是布，3是剪刀：");
    puts("========================================================");
}

uint32_t get_player_move()
{
    uint32_t move;
    printf("请选择1石头，2布，3剪刀(0退出游戏)：\n");
    scanf("%d", &move);
    
    while (move < ROCK || move > SCISSORS)
    {
        if (move==EXIT) break;

        printf("无效选择！请重新选择：1石头，2布，3剪刀(0退出游戏):\n");
        scanf("%d", &move);
    }
    
    return move;
}

uint32_t get_computer_move()
{
    return (rand() % (SCISSORS - ROCK + 1)) + ROCK;
}

void print_move(uint32_t move)
{
    switch (move)
    {
    case ROCK:
        puts("石头");
        break;
    case PAPER:
        puts("布");
        break;
    case SCISSORS:
        puts("剪刀");
        break;
    default:
        break;
    }
}

void determine_winner(uint32_t player_move, uint32_t computer_move)
{
    //规则映射
    if (player_move==computer_move)
    {
        puts("平局");
        return;
    }
    
    //定义一个胜利规则而映射，其中key是玩家的移动，值是玩家移动可以打败计算机的移动
    uint32_t s[4] =            {0, ROCK, PAPER, SCISSORS};//0是占位符
    uint32_t winning_move[4] = {0, SCISSORS, ROCK, PAPER};

    if (computer_move==winning_move[player_move])
    {
        puts("你赢了");
    }
    else {
        puts("你输了");
    }
    
}