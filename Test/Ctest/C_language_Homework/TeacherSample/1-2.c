//创建链表 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int xh;
	char xm[32];
	float cj;
    struct student *next;	 //long 
};

int main()
{
  //创建动态链表
   void showLink(struct student *head);
   int num;
   char name[32];
   float score;
   struct student *head=NULL; 
   struct student *p; 
   printf("每个结点占%d个字节\n",sizeof(struct student));
   printf("float占%d个字节\n",sizeof(float));
   while(1)
   {
     printf("请输入学号(输入0表示结束)：");
   	 scanf("%d",&num);
   	 if(num==0)
   	 {
   		break;
	 }
 
   	 printf("请输入姓名：");
   	 scanf("%s",name);
   	 printf("请输入成绩：");
   	 scanf("%f",&score);   
   
   	 struct student *newP = (struct student *) malloc(sizeof(struct student));
     
	 if(newP!=NULL) 
     {
    	newP->xh = num;
        strcpy(newP->xm, name);
        newP->cj = score; 
        newP->next=NULL; 
	 }
	 else
    	{
	    	break;
	   }
    
     	if(head==NULL)
    	{
   	     head = newP;	
        }
        else
        {
      	  for(p = head;p->next!=NULL;p = p->next);        	
      	  p->next = newP;	
	    }     
	} 
 
    showLink(head); 
	return 0;
}


void showLink(struct student *head)  //遍历并显示链表内容 
{
	struct student *p;
	for(p = head;p!=NULL;p = p->next)
	{
	  printf("学号: %d,姓名：%s,成绩：%.2f\n",p->xh,p->xm,p->cj);
	}	
	
}

