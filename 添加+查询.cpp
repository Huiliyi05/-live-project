#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
 
#define LEN sizeof(struct information)
 
typedef struct information
{
	char name[20];
	char id[20];
	char time[20];
	struct information *next;
}INFO;
 
 
INFO *add(INFO *head)
{
	INFO *p0 = NULL, *p1, *p2;
	p0 = (INFO *)malloc(LEN);
	p1 = head;
	p2 = head;
	printf("****************************\n");
	printf("������");
	scanf("%s",p0->name);
	printf("ѧ�ţ�");
	scanf("%s",p0->id);
	printf("����ʱ�䣺");
	scanf("%s",p0->time);
	
	/*�ٽ��ڵ�p0��������*/
	/*
	if(head == NULL)
	{
		head = p0;
		head->next = NULL;	
		return head;
	}
	else
	{
		p2->next = p1;
		p2 = p1;
	}while(p1->next != NULL);
	p1->next = p0;
	p0->next = NULL;
	return head;
	*/
	
	
	if(head==NULL)
	{
		head=p0;
		p0->next=NULL;
	}
	else
	{
		while((strcmp(p0->name,p1->name)>0)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if((strcmp(p0->name,p1->name))<=0)
		{
			if(head==p1)
				head=p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}
		printf("\n************************************************************\n");
		printf("\n\n");
	}
	return(head);
}

INFO *print(INFO *head)
{
	INFO *p;
	p = head;
	system("clear");
 
	if(head != NULL)
	{
		printf("���г�Ա��\n");
		while(p != NULL)
		{
			printf("������%s\n",p->name);
			printf("ѧ�ţ�%s\n",p->id);
			printf("����ʱ�䣺%s\n",p->time);
			printf("\n\n");
			p = p->next;
		}
	}
	else
	{
		printf("Ŀǰ����Ϣ��\n\n");
	}
	return head;
	
}

INFO *search(INFO *head)
{
	INFO *p1, *p2;
	char name[10];
	p1 = head;
	p2 = head;
	
	printf("��������Ϊ�ؼ��֣�������Ҫ���ҵĳ�Ա��Ϣ��\n");
	printf("****************************\n");
	scanf("%s",name);
	
	if(head != NULL)
	{
		while(p1 != NULL)
		{
			if(0 == strcmp(p1->name,name))
			{
				printf("�����Ǵ�����Ϣ��\n");
				printf("������%s",p1->name);
				printf("\n");
				printf("ID��%s",p1->id);
				printf("\n");
				printf("ʱ�䣺%s",p1->time);
				printf("\n");
				return head;
			}
			else
			{
				p2 = p1;
				p2->next = p1;
			}
		}
		printf("���޴��ˡ�\n");
	}
	else
	{
		printf("ĿǰΪ�ա�\n");
	}
	
}

int main()
{
	char choose[20];
	INFO *head = NULL;
	head = (INFO *)malloc(LEN);
	system("clear");
	while(1)
	{
		printf("����������Ҫ���еĲ�����\n");
		scanf("%s",&choose);
		switch(choose)
		{
			case 0:return 0;
			case 1:head = print(head);break;
			case 2:head = add(head);break;
			case 3:head = search(head);break;
			case 4:system("clear");break;
		}
	}
}