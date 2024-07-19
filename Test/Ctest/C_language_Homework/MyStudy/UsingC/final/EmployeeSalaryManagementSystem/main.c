#include<stdio.h>
#include"salarysystem.h"
#include"employee.h"

int main() {
    struct Node* employeeList = NULL;
    
    // 加载员工信息
    employeeList = loadFromFile();

    int code;

    //显示进入员工工资管理系统
    Welcome();

    while((code=MainMenu())!=QUIT) {
        // 根据用户选择调用相应功能
        // ...
        switch(code){
            case 1:DataMaintenanceManagement();
                    break;
            case 2:QueryData();
                    break;
            case 3:SortData();
                    break;
            case 4:Statistics();
                    break;
            default:ThrowWorining();
                    break;
        }
        // 保存更改到文件
        saveToFile(employeeList);
    }

    Saybye();
    
    return 0;
}
