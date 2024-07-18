#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int xh;
	char xm[20];
	int cj;
	struct student *next;
};
int size = sizeof(struct student);//结点大小
struct student *head=NULL;
struct student *newhead = NULL;
struct student * sortLink(struct student *head1, int n);
struct student * addNodeToLink(struct student *head1, struct student *pNode);
void browse(struct student *head1);
struct student * editNode(struct student *head1, int xuehao);
struct student * delNode(struct student *head1, int xuehao);
struct student * disConnectNode(struct student *head1, struct student *pNode);
struct student * findMaxNode(struct student * head1, int n);
void info_savelink(struct student *nodes_head);//存盘
struct student *link_allinfo();
void add();
void main()
{
		
	int n;
	int sortFlag;
	head=link_allinfo();
	if (head != NULL)
	{
		printf("\n当前数据表中存在的信息如下：\n\n");
		browse(head);
	}
	while (1)
	{
		system("CLS");
		printf("\n");
		printf("\n");
		printf("%20c", ' ');
		printf("========学生成绩管理系统==============\n");
		printf("\n");
		printf("%20c", ' ');
		printf("|   1. 数据添加       2.数据修改     |\n");
		printf("\n");
		printf("%20c", ' ');
		printf("|   3. 数据删除       4.数据排序     |\n");
		printf("\n");
		printf("%20c", ' ');
		printf("|   5. 数据浏览       6.信息检索     |\n");

		printf("\n");
		printf("%20c", ' ');
		printf("|   7. 存盘		  0. 退出        |\n");
		printf("%20c", ' ');
		printf("======================================\n");

		printf("\n你的操作：");
		scanf("%d", &n);
		int xh;
		switch (n)
		{
		case 1://数据添加
			  add();
			  break;
		case 2://数据修改
				printf("input xh=");
				scanf("%d", &xh);
				head = editNode(head, xh);
				browse(head); //浏览修改后的数据	
				break;
			case 3://数据删除
				printf("\n请输入要删除的学生的学号：");
				scanf("%d", &xh);
				head=delNode(head,xh);
				browse(head); //浏览删除后的数据			
				break;
			case 4://数据排序
				printf("\n按哪种方式排序（1-学号、2-姓名、3-成绩）：");
				scanf("%d", &sortFlag);
				newhead = sortLink(head, sortFlag);
				head = newhead;
				browse(newhead);
				break;
		case 5:
			browse(head); //数据浏览
		    break;
			//case 6://数据查询
			//	search(); break;
		case 7:
			info_savelink(head);
			break;
		case 0:
			exit(0);
		}
	}
}

void add()
{
	struct student *s;
	int xuehao;
	int count = 0;
	while (1)
	{
		if ((s = (struct student *)malloc(sizeof(struct student))) == NULL)
		{
			printf("提示无法开辟内存空间!\n");
		}
		else
		{
			count = count + 1;
			printf("\n请输入第 %d 个学生的信息!（学号为-1则结束输入）\n",count);
			printf("\n     学号：");
			scanf("%d", &xuehao);
			if (xuehao == -1)
			{
				free(s);
				browse(head);
				break;				
			 }
			else
      		{ 
				s->xh = xuehao;
				printf("\n     姓名：");
				scanf("%s", s->xm);
				printf("\n     成绩：");
				scanf("%d", &s->cj);                
				head= addNodeToLink(head, s);//将节点加入链表中
			}
		}
	}
}

struct student * addNodeToLink(struct student *head1,struct student *pNode)
{
	struct student *p=head1;
	pNode->next = NULL;
	if (head1 == NULL)
	{
		head1 = pNode;
	}
	else
	{
      //遍历每个节点
		while (p->next!=NULL)
		{
			p = p->next;
		}
		p->next = pNode;
	}

	return head1;
}


void browse(struct student *head1)
{
	struct student *p=head1;//伴随节点
	printf("\n%10c", ' ');
	printf("%4s%10s%10s\n", "学号", "姓名", "成绩");
	printf("%7c", ' ');
	printf("-----------------------------\n");
	while (p!= NULL)
	{
		printf("%10c", ' ');
		printf("%-4d%10s%10d\n", p->xh, p->xm, p->cj);
		printf("%7c", ' ');
		printf("-----------------------------\n");
		p = p->next;
	}
	printf("\n");
	system("pause");
}


struct student * editNode(struct student *head1, int xuehao)
{  //按输入的学号删除节点
	struct student *p;
	p = head1;
	while (p->xh!=xuehao&&p->next!=NULL)
	{
		p = p->next;
	}
	if (p->xh == xuehao)//有这个人
	{
		int n;
		printf("\n请输入要修改的数据项代码（1--学号，2-姓名，3-成绩)");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("\n原学号为%d,新学号改为:",p->xh);
			scanf("%d", &p->xh);
		}
		else if (n == 2)
		{
			printf("\n原姓名为%s,新姓名改为:", p->xm);
			scanf("%s", p->xm);
		}
		else if(n == 3)
		{
			printf("\n原成绩为%d,新成绩改为:", p->cj);
			scanf("%d", &p->cj);
		}
	}
	else//没这个人
	{
		printf("NO\n");
	}
	return head1;
}



struct student * disConnectNode(struct student *head1, struct student *pNode)
{
	struct student *p1, *p2 = NULL;
	p1 = head1;
	while (pNode!=p1&&p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1 == head1&&p1==pNode)//头节点
	{
		head1 = p1->next;
	}
	else if (p1->next == NULL)//尾节点
	{
		p2->next = NULL;
	}
	else//中间节点
	{
		p2->next = p1->next;
	}
	return head1;
}




struct student * delNode(struct student *head1, int xuehao)
{
	struct student *p1,*p2=NULL;
	p1 = head1;
	while (p1->xh != xuehao&&p1->next!= NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	
	if (p1->xh == xuehao)
	{
		//开头节点		
		if (p1 == head1)
		{
			head1 = p1->next;
		}
		//尾节点
		else if (p1->next == NULL)
		{
			p2->next = NULL;
    	}
		else
		//中间节点
		{

			p2->next = p1->next;

		}
	
			free(p1);

	}
	else
	{
		printf("不存在要删除的内容！\n");

	}

	return head1;

}





struct student * sortLink(struct student *head1, int n)
{   //n 为数据项的编号 1-学号，2-姓名 ，3-成绩
	struct student *maxNode;	
	newhead = NULL;
	while (head != NULL)
	{
		maxNode = findMaxNode(head,n);	//从原链表中找最大节点	
		    //原链表断开该节点		
			head = disConnectNode(head, maxNode);
 		   //把该节点添加到新链表中;
		    newhead = addNodeToLink(newhead, maxNode);
	}
    return newhead;
}


struct student * findMaxNode(struct student * head1, int n)
{//n 为数据项的编号 1-学号，2-姓名 ，3-成绩
	struct student *p1, *p2 = NULL;
	p1 = head1;
	if (n == 1)//学号
	{
		int max = p1->xh;
		while (p1!= NULL)
		{
			if (p1->xh > max)
			{
				max = p1->xh;
			}
			p1=p1->next;
		}

		p1 = head1;

		while (p1!= NULL)
		{
			if (p1->xh == max)
			{
				
				break;
			}
			p1 = p1->next;
		}

		

	}
	else if (n == 2)//姓名
	{
		char maxName[30];
		strcpy(maxName,p1->xm);
		while (p1 != NULL)
		{
			if (strcmp(p1->xm,maxName)>0)
			{
				strcpy(maxName, p1->xm);
			}
			p1 = p1->next;
		}

		p1 = head1;
		while (p1 != NULL)
		{
			if (strcmp(p1->xm, maxName)==0)
			{
				break;
			}
			p1 = p1->next;
		}

	}
	else if (n==3)//成绩
	{
		int max = p1->cj;
		while (p1!= NULL)
		{
			if (p1->cj > max)
			{
				max = p1->cj;
			}
			p1 = p1->next;
		}

		p1 = head1;
		while (p1!= NULL)
		{
			if (p1->cj == max)
			{
				break;
			}
			p1 = p1->next;
		}

	}

	return p1;

}

void info_savelink(struct student *nodes_head)//存盘
{
	FILE *fp;
	struct student *p;
	p = nodes_head;
	if ((fp = fopen("studentInfo.dat", "wb+")) == NULL)
	{
		printf("文件出错\n");
		exit(0);
	}
	while (p != NULL){
		fwrite(p, sizeof(struct student), 1, fp);
		p = p->next;
	};
	fclose(fp);
}



struct student *link_allinfo() //将文件中的内容串成链表
{
	struct student stuinfo, *p1;
	size = sizeof(struct student);
	struct student *listhead = NULL;
	FILE *fp;
	if ((fp = fopen("studentInfo.dat", "rb")) == NULL)
	{
		printf("文件出错\n");
		exit(0);
	}
	fseek(fp, 0L, SEEK_SET);
	fread(&stuinfo, size, 1, fp);

	while (!feof(fp))
	{
		p1 = (struct student *)malloc(size);
		p1->xh = stuinfo.xh;
		strcpy(p1->xm, stuinfo.xm);
		p1->cj = stuinfo.cj;
		p1->next = NULL;
		listhead = addNodeToLink(listhead, p1);
		fread(&stuinfo, size, 1, fp);
	}
	fclose(fp);
	return listhead;
}







