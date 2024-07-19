//DEbug
//创建链表（包括新增结点，查找结点和删除结点） 
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
   struct student *addNode(struct student *head, struct student *newP);
   struct student *delNode(struct student *head,struct student *delNode);
   struct student * searchNode(struct student *head,int xh);
   struct student * getMaxNode(struct student * head,int num);
   void breakNode(struct student *head,struct student *delNode);
   int num;
   char name[32];
   float score;
   struct student *head=NULL; 
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
        head = addNode(head,newP);
	 }
	 else
     {
      	break;
	 }
	} 
    showLink(head); //输出链表结点内容 
   /* 
    printf("请输入要删除的学生的学号："); 
    scanf("%d",&num);
        
    head = delNode(head,searchNode(head,num));
    printf("\n删除后的学生信息如下：\n"); 
    showLink(head); 
    */ 
    ///-----排序--------
	struct student *MaxNode; //找到的最大值结点 
	struct student *p;
	struct student *headNew = NULL;
	//for(p=head;p!=NULL;p=p->next)
	for(int i=1;i<=3;i++)
    {
      MaxNode = getMaxNode(head,1);       
      headNew = addNode(headNew,MaxNode);	
	}
   // printf("\n排序后的学生信息如下：\n"); 
    showLink(headNew); //输出新链表 
    
    
    
	return 0;
}

struct student * searchNode(struct student *head,int xh)
{
	struct student *p = NULL;
	for(p = head;p != NULL; p=p->next)
	{
		if( p->xh == xh)
		{
	     break;
		}
	}	
	return p;
	
}

struct student *delNode(struct student *head,struct student *delNode)
{
	struct student *p1,*p2;
	p1 = p2 = head;
	for(p1  = head; p1 != NULL; p1 = p1->next)
	{
	  if(p1->xh == delNode->xh)	
	  {
	  	 if(p1 ==head)//头结点  
	  	 {
	  	 	head = p1->next; 
	  	 	free(p1);
	  	 	break;
		 }
	  	else if(p1->next == NULL) 
	  	{
	  	   p2->next == NULL;
	  	   free(p1);
	  	   break;		  	
		}
		else
		{
		  p2->next = p1->next;
		  free(p1);
	  	  break;
		}	  	
	  	
	  	
	  	
	  }
	  else  //遍历时不匹配 
	  {
	  	p2 = p1; 	
	  	
	  }
		
	}
	
	return head;	
	
}

void breakNode(struct student *head,struct student *delNode)
{
	struct student *p1,*p2;
	p1 = p2 = head;
	for(p1  = head; p1 != NULL; p1 = p1->next)
	{
	  if(p1->xh == delNode->xh)	
	  {
	  	 if(p1 ==head)//头结点  
	  	 {
	  	 	head = p1->next; 
	  	 	//free(p1);
	  	 	break;
		 }
	  	else if(p1->next == NULL) 
	  	{
	  	   p2->next == NULL;
	  	  // free(p1);
	  	   break;		  	
		}
		else
		{
		  p2->next = p1->next;
		  //free(p1);
	  	  break;
		}	  	
	  	
	  	
	  	
	  }
	  else  //遍历时不匹配 
	  {
	  	p2 = p1; 	
	  	
	  }
		
	}
	
	p1->next = NULL; //将脱离的结点指向为空 
	
	//return head;	
	
}


struct student * getMaxNode(struct student * head,int num)
{
	struct student *pMaxNode,*p;
	pMaxNode = head;  //head实际上就是首结点 
	printf("not ok");
    for(p = head;p != NULL;p = p->next)
	{
		if(num == 1)  //num==1 代表成绩
		{
		  if(p->cj > pMaxNode->cj) 
		  {
		  	pMaxNode = p;
		  }		
		} 
	}
	
	printf("xh: %d,xm：%s,cj：%.2f\n",p->xh,p->xm,p->cj);
	printf("next: %d\n",p->next);
	
	///在这里让pMaxNode脱离原来的链表
	//breakNode(head,pMaxNode);
//	return pMaxNode;
	
}










struct student *addNode(struct student *head, struct student *newP)
{ //添加结点到链表， newP为新增结点的地址 
	struct student *p;
   	if(head==NULL) //当链表还没有任何结点时 
    {
   	     head = newP;	
    }
    else //当链表已有结点时，找到末结点，然后将其next指向新增节点 
    {
      for(p = head;p->next!=NULL;p = p->next);  //遍历到末结点	
      p->next = newP; //把末结点的next指向新增结点	
	}    	
	return head;
}



void showLink(struct student *head)  //遍历并显示链表内容 
{
	struct student *p;
	for(p = head;p!=NULL;p = p->next)
	{
	  printf("学号: %d,姓名：%s,成绩：%.2f\n",p->xh,p->xm,p->cj);
	}	
	
}


