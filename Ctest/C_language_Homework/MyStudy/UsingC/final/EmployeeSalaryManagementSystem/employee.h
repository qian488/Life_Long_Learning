#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLen 50

typedef enum { MANAGER, TECHNICIAN, SALESMAN, SALESMANAGER } Position;

typedef struct {
    int id; // 职工号
    char name[MaxLen]; // 姓名
    char gender[MaxLen]; // 性别
    char department[MaxLen]; // 部门
    Position position; // 岗位
    int seniority; // 工龄
    union { // 工资数据
        struct { int baseSalary; } manager;
        struct { int workHours; } technician;
        struct { float sales; } salesman;
        struct { float departmentSales; } salesManager;
    } salaryData;
    float monthlySalary; // 当月工资
} Employee;

// 链表节点
struct Node {
    Employee emp;
    struct Node* next;
};