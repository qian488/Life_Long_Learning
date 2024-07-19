//创建动态链表 (以函数调用的方式)
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include <string.h> 
struct student *addNewNodeToLink(struct student *head1,struct student *newNode);
struct student *addStuentInfo(struct student *head);
struct student *sortLink(int num);//排序链表 
struct student *head = NULL;
struct student *newHead = NULL;
struct student
{
	int xh;  //char xh[13]
	char xm[32];
	int nl;
	float tz;
	struct student *next;	
}; 


void showAllNode(struct student *head)  //输出链表内容的函数 
{
	struct student *p;
	if(head != NULL)   
	{
	  printf("\n%8s%8s%8s%8s\n","学号","姓名","年龄","体重");
	  printf("--------------------------------------\n");
	  for(p = head;p != NULL;p = p->next)
	  {
	    printf("%8d%8s%8d%8.1f\n",p->xh,p->xm,p->nl,p->tz); 
	  } 
	} 
	else
	{
	 printf("链表无数据\n\n");	
	}
	  	
} 

struct student *queryNode(struct student *head,int xh)
{
	struct student *p = NULL;
	for(p = head; p != NULL; p = p->next)
	{
		if(p->xh == xh)
		  return p;
	}	
  return p;		
}

struct student *findMaxNode(struct student *head1,int num) //查找链表中的最大值结点  
{ //假如num=1,认为是年龄。num=2，学号， 
	struct student *p,*maxNode = head;
	
	if(num==1)
	{
		for(p=head1;p!=NULL;p=p->next) 
		{
			if(p->nl >maxNode->nl )
			{
				maxNode = p;
			}			
		}		
	}
	return maxNode;	
}

struct student *disconectNode(struct student *head1,struct student *maxNode) 
{ //将某一节点从链表中脱离（并非删除） ，返回链表头指针 
	struct student *p1,*p2=NULL;
	p1 = head1;  

	for(;maxNode != p1 && p1->next != NULL;) //查找匹配的结点 
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

 
struct student *delNode(struct student *head,struct student *delP)
{
	struct student *p1;
	struct student *p2 = head;
	
	for(p1 = head; p1 != NULL; )
	{
	   if(p1->xh == delP->xh) //有匹配的结点 
	   {
	      if(p1 == head)  //该匹配结点是首结点 
	   	  {
	   	    head = p1->next;
		    free(p1);
		  }
	      else if(p1->next == NULL) //该匹配结点是尾结点
		 {
		    p2->next = NULL;
		    free(p1);
		  }
		 else  //该匹配结点是中间结点
		 {
		   p2->next = p1->next;
		   free(p1);	
		}
		break;
      }
     else //没有匹配结点的情况 
	 {
		p2 = p1;
		p1 = p1->next;			
	 }
	}	
	
	return head;
}

void showMainMenu()
{
	//int mainMenuNum;
	system("cls") ;
	printf("\n--------学生信息管理系统-----------------\n\n");
	printf("   [1] 添加学生成员        [2] 删除学生成员\n\n");	
	printf("   [3] 修改学生信息        [4] 检索学生信息\n\n");
	printf("   [5] 排序学生信息        [6] 浏览学生信息\n\n");
	printf("   [7] 保存学生信息        [0] 退出系统\n\n");
	printf("-------------------------------------------\n");
	printf("\n请输入要操作的功能编号：") ;	
	//return mainMenuNum;
 } 
 
 
struct student * addNewNodeToLink(struct student *head1,struct student *newNode) //将新结点添加到已有链表中 
{
  struct student *p;
   
  	if(head1 == NULL) //当链表还没有任何结点时 
    {
   	   head1 = newNode;	
    }
    else //当链表已有结点时，找到末结点，然后将其next指向新增节点 
    {
      for(p = head1;p->next != NULL;p = p->next);  //遍历到末结点	
      p->next = newNode; //把末结点的next指向新增结点	
	}    
  
  return head1;	
}


struct student * addStuentInfo(struct student *head)
{
	int no,age;
	char name[32];
	float weight;
    while(1)
	  {
	  	printf("\n请输入学生学号（输入0表示结束）：");
	  	scanf("%d",&no);
	  	if(no==0)
	  	{
	  		break;
	  	}
	  	printf("请输入学生姓名：");
	  	scanf("%s",name);  //	gets(name); //  	
	  	printf("请输入学生年龄：");
	  	scanf("%d",&age); 
		printf("请输入学生体重：");
	  	scanf("%f",&weight); //  gets(name);
	    struct student *pnew =(struct student *) malloc(sizeof(struct student));	  
	    if(pnew==NULL)	
		{
			break;
		}  
		pnew->xh = no;
		strcpy(pnew->xm,name);
		pnew->nl = age;
		pnew->tz= weight;
		pnew->next = NULL;		
	    head =addNewNodeToLink(head,pnew);	  	
	  }	 	 
	return head;
}

struct student * editStuentInfo(struct student *head)
{
	int no,age;
	char name[32];
	float weight;
	struct student *editNode;
	printf("请输入待修改学生的学号：");
	scanf("%d",&no) ;
	editNode = queryNode(head,no);
	
	printf("你要修改学生的哪个信息：1-学号 2-姓名 3-年龄 4-体重");
	
	
}
void showEditSubMenu()
{
	printf("====修改学生信息子菜单=====\n\n");
	printf("【1】 学号  【2】 姓名\n\n");
	printf("【3】 年龄  【4】 体重\n\n");
	printf("【0】 取消\n");
 } 


struct student *sortLink(int num) //排序链表 
{
 struct student *maxNode;
 newHead  = NULL;
  while(head!=NULL) 
  {//找最大值     
    maxNode = findMaxNode(head,1);
    //从旧链表中脱离
    head = disconectNode(head,maxNode);    
    maxNode->next = NULL;  
    //将找到的结点加入新链表
    newHead = addNewNodeToLink(newHead,maxNode);
 }
 return newHead;	
} 

struct student * delStuentInfo(struct student * head) //删除学生信息，这是主菜单第【2】项的功能 
{ 
    int no;
    char doOrNot; 
    struct student *p;
    printf("\n当前链表数据如下:\n") ;
    showAllNode(head);
	while(1)  
	 {
	  printf("请输入要删除的学生的学号：") ;
	  scanf("%d",&no);
	  //if (no==-1)
	 //    break;
	  p = queryNode(head,no);	  
	  head = delNode(head,p);
	  //system("cls");
	  //showAllNode(head); 
	  printf("还要继续删除学生记录吗？(Y-继续，N-返回主菜单)\n");
	  doOrNot = getchar();
	  if(doOrNot != 'Y')
	    {
	    showMainMenu();
		break;	
		}
    } 	
	return head;	
}

int main()
{
	int mainMenuNum;	
	struct student *p;	
	//原理：
	 //1、先输入一个学生的数据 ，然后判断是否符合停止输入的条件
	 //2、开辟一个结点的内存空间
	 //3、把第一步输入的数据赋值给第2步创建的结点
	 //4、把结点加入到链表中。	 
	while(1)
	 {
	   showMainMenu(); //显示主菜单  
	   scanf("%d",&mainMenuNum); //输入要选择的菜单项号码 	 
	   switch (mainMenuNum) 
	   {  
	 	case 1:  //增加数据
	 	    system("cls");
	 		head = addStuentInfo(head);
	 	    printf("\n添加信息后链表数据如下:\n") ;
	 		showAllNode(head);
	 		system("pause");
	 		break;
	 	case 2:  //删除数据 
	 		head = delStuentInfo(head);
	 		printf("\n删除操作后链表数据如下:\n") ;
	 		showAllNode(head);
	 		system("pause");
	 		break;
	 	case 5://排序数据 
		    newHead = sortLink(1);
		    head = newHead; 
		    if(head !=NULL) 
		    {
		      printf("\n按年龄排序后链表数据如下:\n") ;
		      showAllNode(head);
		      system("pause");
		    }
			break;	
		case 6:		    
		    showAllNode(head);	
			system("pause");	    
		    break;	
		case 0:
		     exit(0);		 		
	   }
     }   	     
	return 0;
}