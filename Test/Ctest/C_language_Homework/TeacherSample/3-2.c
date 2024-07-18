//链表应用（包括新增结点，查找结点（含找到最大值）、删除结点的排序） 
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
struct student *headNew = NULL;  //新链表头指针，指向排序后的首结点 
struct student *head = NULL;     //为初次运行时创建链表的头指针 
void showLink(struct student *head); //排序函数，含找最大值结点、将该结点从旧链表中断开及将该最大值添加到新链表 
struct student *addNode(struct student *head, struct student *newP); //该函数将新结点newP加入到链表尾部 ，返回头指针 
struct student *delNode(struct student *head,struct student *delNode);//该函数为从已存在的链表中删除指定的结点delNode 
struct student * searchNode(struct student *head,int xh);//查找某一符合条件的结点，并返回该节点地址 
struct student * getMaxNode(struct student * head,int num);//在一链表中找出某一符成员的最大结点，并返回该节点地址 
struct student * breakNode(struct student *head,struct student *delNode);//将某一节点从链表中脱离（并非删除） ，返回链表头指针 
struct student * sortLink(int sortFlagNum);//按结点某一成员进行排序，含找最大值结点、将该结点从旧链表中断开及将该最大值添加到新链表，返回排序后的新链表的头指针。 

int main()
{
  //创建动态链表
  
   int num;
   char name[32];
   float score;  
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
	headNew = sortLink(1);//按成绩排序 	
	printf("\n排序后的学生信息如下：\n"); 
    showLink(headNew); //输出新链表 
    
	return 0;
}

struct student * sortLink(int sortFlagNum)
{   //按结点某一成员进行排序，含找最大值结点、
    //将该结点从旧链表中断开及将该最大值添加到新链表，
    //返回排序后的新链表的头指针。 
    //sortFlagNum 为数据项的编号 3-学号，2-姓名 ，1-成绩
	struct student *maxNode;	
	headNew = NULL;
	while (head!=NULL) //当旧链表还存在有结点时，继续循环 
	{
	    maxNode = getMaxNode(head,sortFlagNum);	//从原链表中找最大节点			
		head = breakNode(head,maxNode);  //将该节点从原链表中脱离		
 		maxNode->next = NULL; //把找到最大值的结点的指针域设置为空 
		headNew = addNode(headNew,maxNode);	 //把该节点添加到新链表中;
	}
    return headNew; //返回排序后的新链表指针 
}

struct student * searchNode(struct student *head,int xh) 
{//查找某一符合条件的结点，并返回该节点地址 
  //head为头指针，xh为要查找的结点的学号 
	struct student *p = NULL;
	for(p = head;p != NULL; p=p->next) //遍历链表，直到找到或到结尾 
	{
		if( p->xh == xh) //匹配 
		{
	     break; //退出循环 
		}
	}	
	return p; //返回找到的结点 
	
}

struct student *delNode(struct student *head,struct student *delNode)
{//该函数为从已存在的链表中删除指定的结点delNode 
	struct student *p1,*p2;
	p1=p2 = head;
	for(; p1 != NULL; p1 = p1->next) //遍历链表 
	{
	  if(p1->xh == delNode->xh)	//匹配，退出找到了要删除的节点 
	  {
	  	 if(p1 ==head)//匹配的结点是头结点  
	  	 {
	  	 	head = p1->next; //头指针指向待删除结点后的结点，如果后面没有结点，自然就是NULL 
	  	 	free(p1);//释放待删除的结点 
	  	 	break; //退出循环 
		 }
	  	else if(p1->next == NULL) // //匹配的结点是最末尾的结点
	  	{
	  	    p2->next == NULL; //倒数第二的结点，next指向NULL，即变成末尾结点 
	  	 	free(p1);//释放待删除的结点 
	  	 	break; //退出循环 		  	
		}
		else //除头、尾之外的中间节点 
		{
		   p2->next = p1->next; //将待删除节点的上一结点p2的next指向待删除结点p1的下一结点 
	  	   free(p1);//释放待删除的结点 
	  	   break; //退出循环 
		}    	
	  }
	  else  //遍历时如果循环变量（p1结点)与待删除结点不匹配 
	  {
	  	p2 = p1; 	//则让循环变量p1结点的上一结点p2前进一步（即接替当次循环的p1），p1继续前移 
	  	
	  }
		
	}
	
	return head;	//返回删除匹配节点后的链表头指针。 
	
}

struct student * breakNode(struct student *head1,struct student *delNode)
{ //将某一节点从链表中脱离（并非删除） ，返回链表头指针 
	struct student *p1,*p2=NULL;
	p1 = head1;  

	for(;delNode != p1 && p1->next != NULL;) //查找匹配的结点 
	{ //有匹配的结点或遍历已到结尾，则退出循环 
	  //没有匹配结点，则p2紧跟p1前移 
	  p2 = p1;	//p2接替p1 
	  p1 = p1->next;  //p1前移 
    }

  	if(p1 == head1)//头结点  
	{
	  	head1 = p1->next;  //头指针指向待脱离结点后的结点，如果后面没有结点，自然就是NULL
	}
	else if(p1->next == NULL) //尾结点 
	{
	   p2->next = NULL;		//倒数第二的结点，next指向NULL，即变成末尾结点  		  	
	}
	else //中间结点 
	{
	  p2->next = p1->next; //将待脱离节点的上一结点p2的next指向待脱离结点p1的下一结点 
	}	

    return head1; //返回 某结点脱离后的链表头指针 
}

struct student * getMaxNode(struct student * head,int num)
{
    //最大节点，然后返回该结点 
	struct student *pMaxNode,*p;
	pMaxNode = head;  //head1实际上就是首结点 
	
	if(num == 1)  //num==1 代表用成绩作为比较 
	{
      for(p = head;p!= NULL;p = p->next) //遍历 
	   {
		  if(p->cj > pMaxNode->cj) //循环变量p1的成绩大于临时最大值（参照）
		  {
		  	pMaxNode = p; 	// p1成临时最大值（参照） 	
		  }			 
		} 	
	}
	return pMaxNode;//遍历结束，返回找到大最大值	

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
	for(p = head;p!=NULL;p = p->next)//遍历 
	{
	  printf("学号: %d,姓名：%s,成绩：%.2f\n",p->xh,p->xm,p->cj);//输出 
	}		
}