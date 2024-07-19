//创建动态链表 (以函数调用的方式)
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include <string.h> 
struct student *addNewNodeToLink(struct student *head1, struct student *newNode);
struct student *addStuentInfo(struct student *head);
struct student *queryNodeByXh(struct student *head, int xh);
struct student *queryNodeByXm(struct student *head, char *name);
struct student *queryNodeByNl(struct student *head, int age);
struct student *queryNodeByTz(struct student *head, int weight);
void showNodeInfo(struct student *node);  //输出链表单个结点的具体信息 
void showEditSubMenu();
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
	if (head != NULL)
	{
		printf("\n%8s%8s%8s%8s\n", "学号", "姓名", "年龄", "体重");
		printf("--------------------------------------\n");
		for (p = head; p != NULL; p = p->next)
		{
			printf("%8d%8s%8d%8.1f\n", p->xh, p->xm, p->nl, p->tz);
		}
	}
	else
	{
		printf("链表无数据\n\n");
	}

}
void showNodeInfo(struct student *node)  //输出链表单个结点的具体信息 
{
   printf("该学生详细信息如下：\n");
   printf("学号：%d\n", node->xh);
   printf("姓名：%s\n", node->xm);
   printf("年龄：%d\n", node->nl);
   printf("体重：%.2f\n\n", node->tz);
}



struct student *queryNodeByXh(struct student *head, int xh) //根据学号返回匹配的结点 
{
	struct student *p = NULL;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->xh == xh)
			return p;
	}
	return p;
}

struct student *queryNodeByXm(struct student *head, char *name) //根据姓名返回匹配的结点 
{
	struct student *p = NULL;
	for (p = head; p != NULL; p = p->next)
	{
		if (strcmp(p->xm, name) == 0)
			return p;
	}
	return p;
}
struct student *queryNodeByNl(struct student *head, int age) //根据年龄返回匹配的结点 
{
	struct student *p = NULL;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->nl == age)
			return p;
	}
	return p;
}
struct student *queryNodeByTz(struct student *head, int weight) //根据体重返回匹配的结点 
{
	struct student *p = NULL;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->tz == weight)
			return p;
	}
	return p;
}


struct student *findMaxNode(struct student *head1, int num) //查找链表中的最大值结点  
{ //假如num=1,认为是年龄。num=2，学号， 
	struct student *p, *maxNode = head;

	if (num == 1)
	{
		for (p = head1; p != NULL; p = p->next)
		{
			if (p->nl >maxNode->nl)
			{
				maxNode = p;
			}
		}
	}
	return maxNode;
}

struct student *disconectNode(struct student *head1, struct student *maxNode)
{ //将某一节点从链表中脱离（并非删除） ，返回链表头指针 
	struct student *p1, *p2 = NULL;
	p1 = head1;

	for (; maxNode != p1 && p1->next != NULL;) //查找匹配的结点 
	{ //有匹配的结点或遍历已到结尾，则退出循环 
		//没有匹配结点，则p2紧跟p1前移 
		p2 = p1;	//p2接替p1 
		p1 = p1->next;  //p1前移 
	}

	if (p1 == head1)//头结点  
	{
		head1 = p1->next;  //头指针指向待脱离结点后的结点，如果后面没有结点，自然就是NULL
	}
	else if (p1->next == NULL) //尾结点 
	{
		p2->next = NULL;		//倒数第二的结点，next指向NULL，即变成末尾结点  		  	
	}
	else //中间结点 
	{
		p2->next = p1->next; //将待脱离节点的上一结点p2的next指向待脱离结点p1的下一结点 
	}

	return head1; //返回 某结点脱离后的链表头指针 	

}


struct student *delNode(struct student *head1, struct student *delP) //删除链表中某一匹配的结点 
{
	struct student *p1;
	struct student *p2 = head1;

	for (p1 = head1; p1 != NULL;) //从头遍历链表 
	{
		if (p1->xh == delP->xh) //有匹配的结点 
		{
			if (p1 == head1)  //该匹配结点是首结点 
			{
				head1 = p1->next;
				free(p1);
			}
			else if (p1->next == NULL) //该匹配结点是尾结点
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
		else //遍历过程中没有匹配结点的情况 
		{
			p2 = p1;
			p1 = p1->next;
		}
	}

	return head1;
}

void showMainMenu()
{
	//int mainMenuNum;
	system("cls");
	printf("\n--------学生信息管理系统-----------------\n\n");
	printf("   [1] 添加学生成员        [2] 删除学生成员\n\n");
	printf("   [3] 修改学生信息        [4] 检索学生信息\n\n");
	printf("   [5] 排序学生信息        [6] 浏览学生信息\n\n");
	printf("   [7] 保存学生信息        [0] 退出系统\n\n");
	printf("-------------------------------------------\n");
	printf("\n请输入要操作的功能编号：");
	//return mainMenuNum;
}


struct student * addNewNodeToLink(struct student *head1, struct student *newNode) //将新结点添加到已有链表中 
{
	struct student *p;

	if (head1 == NULL) //当链表还没有任何结点时 
	{
		head1 = newNode;
	}
	else //当链表已有结点时，找到末结点，然后将其next指向新增节点 
	{
		for (p = head1; p->next != NULL; p = p->next);  //遍历到末结点	
		
		p->next = newNode; //把末结点的next指向新增结点	
	}

	return head1;
}


struct student * addStuentInfo(struct student *head) //添加结点信息 
{
	int no, age;
	char name[32];
	float weight;
	while (1)
	{
		printf("\n请输入学生学号（输入0表示结束）：");
		scanf("%d", &no);
		if (no == 0)
		{
			break;
		}
		printf("请输入学生姓名：");
		scanf("%s", name);  //	gets(name); //  	
		printf("请输入学生年龄：");
		scanf("%d", &age);
		printf("请输入学生体重：");
		scanf("%f", &weight); //  gets(name);
		struct student *pnew = (struct student *) malloc(sizeof(struct student));
		if (pnew == NULL)
		{
			break;
		}
		pnew->xh = no;
		strcpy(pnew->xm, name);
		pnew->nl = age;
		pnew->tz = weight;
		pnew->next = NULL;
		head = addNewNodeToLink(head, pnew);
	}
	return head;
}

struct student * editStuentInfo(struct student *head) //信息的编辑功能 
{
	int no, age;
	char name[32];
	float weight;
	
	int editNum;
	char continueToDo;
	
	int flag ;
	
	struct student *editNode = NULL;	
	while (1)	
	{
	    showAllNode(head); 
		printf("请输入待修改学生的学号：");
		scanf("%d", &no);
		editNode = queryNodeByXh(head, no);//查找到匹配的结点 
		 
		if (editNode != NULL)
		{   
			showNodeInfo(editNode);//将该结点的详细信息显示出来 
			showEditSubMenu();	//显示修改子菜单	
		    while(1) 
			{				
			  flag  = 1; //用于判断是否输入非法数字。 
			  printf("你要修改学生的哪个信息：");
			  scanf("%d", &editNum);
			  switch (editNum)
			  {
			   case 0:    //想放弃修改当前结点信息（也许重新选择另一个结点 ，也许是相回主菜单） 
				    flag = 2;                	 
                	break;			  	
		       case 1:
			    	printf("请输入新学号：");
				    scanf("%d", &no);
					editNode->xh = no;
					break;
			   case 2:
					printf("请输入新姓名：");
					scanf("%s", name);
					strcpy(editNode->xm,name);
                	break;
  			   case 3:
					printf("请输入新年龄：");
					scanf("%d", &age);
					editNode->nl = age;
                	break;              
           	   case 4:
					printf("请输入新体重：");
					scanf("%f", &weight);
					editNode->tz = weight;
                	break;
               default:
			    	printf("非法数字，请重新输入："); //非法数字，得重新输入一次 
			    	flag = 0; 
		      }
			  if(flag != 0  ) //退出修改哪一项信息的循环 
			     break;
		   }
		   
			 if(flag == 1 ) 
			 {			 	
			  
			  showNodeInfo(editNode);
		     }
			  getchar();
			  printf("是否继续修改其他同学的信息? \n");
			  printf("按 Y -继续修改，按任意其它键放弃！你的选择：");
		      scanf("%c",&continueToDo);
		      
			  if (continueToDo == 'Y' ||continueToDo == 'y'  )
		      {
			    continue;
		      }	
					
			break;			
		}
		else
		{
			printf("提示：无此学号学生，请重新输入！");
		}
		
		

	}
	return head;
}

void showEditSubMenu() //显示修改信息了菜单 
{
	printf("\n====修改学生信息子菜单=====\n\n");
	printf("[1]学号  [2]姓名  [3]年龄  [4]体重  [0]取消\n\n");	
}

void showQuerySubMenu() //显示修改信息了菜单 
{
	printf("\n====检索学生信息子菜单=====\n\n");
	printf("[1]学号  [2]姓名  [3]年龄  [4]体重  [0]取消\n\n");	
}


struct student *sortLink(int num) //排序链表 
{
	struct student *maxNode;
	newHead = NULL;
	while (head != NULL)
	{//找最大值     
		maxNode = findMaxNode(head, 1);
		//从旧链表中脱离
		head = disconectNode(head, maxNode);
		
		maxNode->next = NULL;
		//将找到的结点加入新链表
		newHead = addNewNodeToLink(newHead, maxNode);
	}
	return newHead;
}

struct student * delStuentInfo(struct student * head) //删除学生信息，这是主菜单第【2】项的功能 
{
	int no;
	char doOrNot;
	struct student *p = NULL;
	printf("\n当前链表数据如下:\n");
	showAllNode(head);
	while (1)
	{
		printf("请输入要删除的学生的学号：");
		scanf("%d", &no);
		//if (no==-1)
		//    break;
		p = queryNodeByXh(head, no);
		if (p==NULL)
		{
			printf("提示：链表中查无此学号！\n");
			continue;
		}
		head = delNode(head, p);
		getchar(); 
		printf("还要继续删除学生记录吗？(Y-继续，任意键返回)\n");
		doOrNot = getchar();
		if (doOrNot != 'Y' && doOrNot != 'y')
		{
			break;
		}
	}
	return head;
}

int saveLinkToFile(struct student * head,char *fileStr) //存盘功能 
{
   FILE *fp;
   int opResult; 
   struct student *node = head;
   if((fp = fopen(fileStr,"wb"))==NULL)
   {
   	printf("文件打开出错！\n");
   	opResult = 1;
   	return opResult;
   	//exit(0);   	
   }
   
   while(node != NULL)
   {
   	fwrite(node,sizeof(struct student),1,fp); //每次写入一个结点 
   	node = node->next;
   } 
   	opResult = 2;   
  if(fclose(fp)) 
  {
  	printf("关闭文件出错\n");
  	opResult = 3;   
	//exit(0); 
  }	
  return opResult;  	
}


struct student *getNodeFromFileToLink(struct student * head,char *fileStr)   
{  //从文件中读取结点然后串接成链表 
   FILE *fp;
   struct student *node = head;
   int recNum = 0; 
   int flag; 
   
   if((fp = fopen(fileStr,"rb"))==NULL)
   {   	
	printf("提示：无法打开数据文件！\n");  	
	head = NULL;
	return head; 
   	//exit(0);   	
   }  
    
   do
   {
   	struct student *newNode = (struct student *) malloc(sizeof(struct student));   	
   	if(fread(newNode,sizeof(struct student),1,fp) == 1) //读取数据成功 
   	{
   	  newNode->next = NULL;
	  recNum++;
	  head = addNewNodeToLink(head,newNode);
	}
	else
	{
		if(feof(fp))
		{			
			printf("提示：数据文件中共有 %d 条记录！详细信息如下：\n",recNum);
		    showAllNode(head);	
			system("pause");
			system("cls");
			break;			
		}	
		
	}
   
   }while(1);
   
  if(fclose(fp)) 
  {
  	printf("关闭文件出错\n");
	exit(0); 
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
	head = getNodeFromFileToLink(head,"stuInfo.dat") ;
		 
	while (1)
	{
		showMainMenu(); //显示主菜单  
		scanf("%d", &mainMenuNum); //输入要选择的菜单项号码 	 
		switch (mainMenuNum)
		{
		case 1:  //增加数据
			system("cls");
			head = addStuentInfo(head);
			printf("\n添加操作后链表数据如下:\n");
			showAllNode(head);
			system("pause");
			break;
		case 2:  //删除数据 
			if (head != NULL)//如果链表有结点 
			{
			  head = delStuentInfo(head);
			  printf("\n删除操作后链表数据如下:\n");
			  showAllNode(head);			
			  break;
			 } 
			else
			{
			  printf("\n提示：链表为空，无可删除的数据！\n\n");
			}
			system("pause");
			break; 
		case 3:  //修改数据 			
			if (head != NULL) //如果链表有结点 
			{
			  head = editStuentInfo(head);
			  printf("\n修改操作后链表数据如下:\n");
			  showAllNode(head);				
			}
			else//如果链表无结点 
			{
			  printf("\n提示：链表为空，无可修改的数据！\n\n");
			}
			system("pause");
			break;
		case 4:  //检索信息 			
			if (head != NULL)//如果链表有结点 
			{ 
			  struct student *queryNode = NULL;
			  int itemNum;
			  int no,age;
			  float weight;
			  char name[32];
			  int breakflag = 1;
			  showQuerySubMenu(); //显示查询子菜单 
			  printf("请输入检索的关键字编号：");
			  scanf("%d",&itemNum);
			  switch(itemNum)
			  {
			  	case 1:
			  		printf("请输入学号：");
			  		scanf("%d",&no);
			  		queryNode = queryNodeByXh(head,no);
			  	    break;
			  	case 2:
			  		printf("请输入姓名：");
			  		scanf("%s",name);
			  		queryNode = queryNodeByXm(head,name);
			  	    break;
			  	case 3:
			  		printf("请输入年龄：");
			  		scanf("%d",&age);
			  		queryNode = queryNodeByNl(head,age);
			  	    break;
			  	case 4:
			  		printf("请输入体重：");
			  		scanf("%f",&weight);
			  		queryNode = queryNodeByTz(head,weight);
			  	    break;			  	    
			  	case 0:
			  	   breakflag = 0;	
				   break;    
			  }
			  
			  
			  if(queryNode != NULL)
			     showNodeInfo(queryNode);
			  else if(breakflag == 1)
			  	 printf("提示：链表中查无成员信息！\n");
			  else if(breakflag == 0)
			     showMainMenu();							   						
			}
			else
			{
			  printf("\n提示：链表为空，暂无可检索的数据！\n\n");
			}
			system("pause");
			break;			
						
		case 5://排序数据 		
			if (head != NULL)//如果链表有结点 
			{
			    newHead = sortLink(1); //按年龄排序 
			    head = newHead;
				printf("\n按年龄排序后链表数据如下:\n");
				showAllNode(head);
			}
			else
			{
			  printf("\n提示：链表为空，无可修改的数据！\n\n");
			}
			system("pause");			
			break;
		case 6: //浏览链表内容 
			showAllNode(head);
			system("pause");
			break;
			
		case 7:  //存盘操作 
			if (head != NULL) //如果链表有结点 
			{ 
			   int result = saveLinkToFile(head,"stuInfo.dat"); //将链表保存到文件中 ，并返回处理结果 
			   if(result == 1)	//文件无法建立 
			   	 printf("\n文件无法打开！\n");
			   else if(result == 2)   //正常保存 
			     printf("\n已将所有数据存入文件！\n");
			   else //文件无法关闭 
			     printf("\n文件无法正常关闭！\n");  
			}
			else //链表无结点 
			{
			  printf("\n提示：链表为空，无可保存的数据！\n\n");
			}
			system("pause");			
			break; 
			
		case 0:
			exit(0);
		}
	}
	return 0;
}
