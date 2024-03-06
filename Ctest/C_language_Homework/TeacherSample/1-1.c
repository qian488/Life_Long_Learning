//创建链表 
#include<stdio.h> 
struct student
{
	int xh;
	char xm[32];
	float cj;
    struct student *next;	
};

int main()
{
  //创建静态链表
    struct student s1={10001,"zs",601};
    struct student s2={10002,"lisi",586};
    struct student s3={10001,"wangwu",566};
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;
	struct student *head;
	head = &s1;

	struct student *p;
	for(p = head;p!=NULL;p = p->next)
	{
	  printf("学号: %d,姓名：%s,成绩：%.2f\n",p->xh,p->xm,p->cj);
	}	
	return 0;
}