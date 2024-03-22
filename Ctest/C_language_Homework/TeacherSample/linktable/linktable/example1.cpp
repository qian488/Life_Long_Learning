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
int size = sizeof(struct student);//����С
struct student *head=NULL;
struct student *newhead = NULL;
struct student * sortLink(struct student *head1, int n);
struct student * addNodeToLink(struct student *head1, struct student *pNode);
void browse(struct student *head1);
struct student * editNode(struct student *head1, int xuehao);
struct student * delNode(struct student *head1, int xuehao);
struct student * disConnectNode(struct student *head1, struct student *pNode);
struct student * findMaxNode(struct student * head1, int n);
void info_savelink(struct student *nodes_head);//����
struct student *link_allinfo();
void add();
void main()
{
		
	int n;
	int sortFlag;
	head=link_allinfo();
	if (head != NULL)
	{
		printf("\n��ǰ���ݱ��д��ڵ���Ϣ���£�\n\n");
		browse(head);
	}
	while (1)
	{
		system("CLS");
		printf("\n");
		printf("\n");
		printf("%20c", ' ');
		printf("========ѧ���ɼ�����ϵͳ==============\n");
		printf("\n");
		printf("%20c", ' ');
		printf("|   1. �������       2.�����޸�     |\n");
		printf("\n");
		printf("%20c", ' ');
		printf("|   3. ����ɾ��       4.��������     |\n");
		printf("\n");
		printf("%20c", ' ');
		printf("|   5. �������       6.��Ϣ����     |\n");

		printf("\n");
		printf("%20c", ' ');
		printf("|   7. ����		  0. �˳�        |\n");
		printf("%20c", ' ');
		printf("======================================\n");

		printf("\n��Ĳ�����");
		scanf("%d", &n);
		int xh;
		switch (n)
		{
		case 1://�������
			  add();
			  break;
		case 2://�����޸�
				printf("input xh=");
				scanf("%d", &xh);
				head = editNode(head, xh);
				browse(head); //����޸ĺ������	
				break;
			case 3://����ɾ��
				printf("\n������Ҫɾ����ѧ����ѧ�ţ�");
				scanf("%d", &xh);
				head=delNode(head,xh);
				browse(head); //���ɾ���������			
				break;
			case 4://��������
				printf("\n�����ַ�ʽ����1-ѧ�š�2-������3-�ɼ�����");
				scanf("%d", &sortFlag);
				newhead = sortLink(head, sortFlag);
				head = newhead;
				browse(newhead);
				break;
		case 5:
			browse(head); //�������
		    break;
			//case 6://���ݲ�ѯ
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
			printf("��ʾ�޷������ڴ�ռ�!\n");
		}
		else
		{
			count = count + 1;
			printf("\n������� %d ��ѧ������Ϣ!��ѧ��Ϊ-1��������룩\n",count);
			printf("\n     ѧ�ţ�");
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
				printf("\n     ������");
				scanf("%s", s->xm);
				printf("\n     �ɼ���");
				scanf("%d", &s->cj);                
				head= addNodeToLink(head, s);//���ڵ����������
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
      //����ÿ���ڵ�
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
	struct student *p=head1;//����ڵ�
	printf("\n%10c", ' ');
	printf("%4s%10s%10s\n", "ѧ��", "����", "�ɼ�");
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
{  //�������ѧ��ɾ���ڵ�
	struct student *p;
	p = head1;
	while (p->xh!=xuehao&&p->next!=NULL)
	{
		p = p->next;
	}
	if (p->xh == xuehao)//�������
	{
		int n;
		printf("\n������Ҫ�޸ĵ���������루1--ѧ�ţ�2-������3-�ɼ�)");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("\nԭѧ��Ϊ%d,��ѧ�Ÿ�Ϊ:",p->xh);
			scanf("%d", &p->xh);
		}
		else if (n == 2)
		{
			printf("\nԭ����Ϊ%s,��������Ϊ:", p->xm);
			scanf("%s", p->xm);
		}
		else if(n == 3)
		{
			printf("\nԭ�ɼ�Ϊ%d,�³ɼ���Ϊ:", p->cj);
			scanf("%d", &p->cj);
		}
	}
	else//û�����
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
	if (p1 == head1&&p1==pNode)//ͷ�ڵ�
	{
		head1 = p1->next;
	}
	else if (p1->next == NULL)//β�ڵ�
	{
		p2->next = NULL;
	}
	else//�м�ڵ�
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
		//��ͷ�ڵ�		
		if (p1 == head1)
		{
			head1 = p1->next;
		}
		//β�ڵ�
		else if (p1->next == NULL)
		{
			p2->next = NULL;
    	}
		else
		//�м�ڵ�
		{

			p2->next = p1->next;

		}
	
			free(p1);

	}
	else
	{
		printf("������Ҫɾ�������ݣ�\n");

	}

	return head1;

}





struct student * sortLink(struct student *head1, int n)
{   //n Ϊ������ı�� 1-ѧ�ţ�2-���� ��3-�ɼ�
	struct student *maxNode;	
	newhead = NULL;
	while (head != NULL)
	{
		maxNode = findMaxNode(head,n);	//��ԭ�����������ڵ�	
		    //ԭ����Ͽ��ýڵ�		
			head = disConnectNode(head, maxNode);
 		   //�Ѹýڵ���ӵ���������;
		    newhead = addNodeToLink(newhead, maxNode);
	}
    return newhead;
}


struct student * findMaxNode(struct student * head1, int n)
{//n Ϊ������ı�� 1-ѧ�ţ�2-���� ��3-�ɼ�
	struct student *p1, *p2 = NULL;
	p1 = head1;
	if (n == 1)//ѧ��
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
	else if (n == 2)//����
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
	else if (n==3)//�ɼ�
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

void info_savelink(struct student *nodes_head)//����
{
	FILE *fp;
	struct student *p;
	p = nodes_head;
	if ((fp = fopen("studentInfo.dat", "wb+")) == NULL)
	{
		printf("�ļ�����\n");
		exit(0);
	}
	while (p != NULL){
		fwrite(p, sizeof(struct student), 1, fp);
		p = p->next;
	};
	fclose(fp);
}



struct student *link_allinfo() //���ļ��е����ݴ�������
{
	struct student stuinfo, *p1;
	size = sizeof(struct student);
	struct student *listhead = NULL;
	FILE *fp;
	if ((fp = fopen("studentInfo.dat", "rb")) == NULL)
	{
		printf("�ļ�����\n");
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







