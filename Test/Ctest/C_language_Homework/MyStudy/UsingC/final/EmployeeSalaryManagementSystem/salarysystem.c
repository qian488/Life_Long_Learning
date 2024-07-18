#include<stdio.h>
#include"salarysystem.h"

//系统欢迎指令
void Welcome(void){
    printf("Welcome to Employee salary management system (ESMS)!!!\n");
}
//系统退出指令
void Saybye(void){
    printf("Thank you and goodbye.\n");
}
//系统主界面
int MainMenu(void){
    int code,status;

    printf("Enter the number of the operation:\n");
    printf("(1) DataMaintenanceManagement\n");
    printf("(2) QueryData\n");
    printf("(3) SortData\n");
    printf("(4) Statistics\n");
    printf("(0) Quit\n");

    while((status=scanf("%d",&code))!=1 || (code<1||code>4)){
        if(status!=1) scanf("%*s");
        printf("Enter an integer from 1 to 4, please.\n");
    }

    return code;
}
//进入数据维护管理界面
void DataMaintenanceManagement(void){
    printf("Welcome to DataMaintenanceManagement.\n");

    int code,status;

    printf("Enter the number of the operation:\n");
    printf("(1) Basic information maintenance and management\n");
    printf("(2) Salary data maintenance and management\n");
    printf("(0) Quit\n");

    while((status=scanf("%d",&code))!=1 || (code<1||code>2)){
        if(status!=1) scanf("%*s");
        printf("Enter an integer from 1 or 2, please.\n");
    }

    switch(code){
        case 1:BasicInformation();
                break;
        case 2:SalaryData();
                break;
        default:ThrowWorining();
                break;
    }
}
//进入查询数据界面
void QueryData(void){
    printf("Welcome to QueryData.\n");

}
//进入排序界面
void SortData(void){
    printf("Welcome to SortData.\n");

}
//进入统计界面
void Statistics(void){
    printf("Welcome to Statistics.\n");

}
//提供系统错误信息
void ThrowWorining(void){
    printf("worning!worning!!worning!!!\n");
}