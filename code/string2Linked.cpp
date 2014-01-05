// string2Linked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
struct node
{
	char ch;
	struct node *link;
};
struct node * tolinked(char c,struct node *head)
{
	struct node *temp,*r;
	temp=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		temp->ch=c;
		temp->link=NULL;
		head=temp;
		
	}
	else
	{
		r=(struct node *)malloc(sizeof(struct node));
		temp=head;
		while(temp->link!=NULL)
			temp=temp->link;
		r->ch=c;
		r->link=NULL;
		temp->link=r;
	}
	return head;
}
struct node * tolink(char *s,struct node *head)
{
	int i=0;
	while(s[i]!='\0')
	{
		head=tolinked(*(s+i),head);
		i++;
	}
	return head;
}

void display(struct node *head)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=head;
	while(temp!=NULL)
	{
		printf("%c",temp->ch);
		temp=temp->link;
	}
}
	


		







int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int n;
	struct node *head;
	printf("enter size of string");
	scanf("%d",&n);
	s=(char *)malloc(n*sizeof(char));
	head=(struct node*)malloc(sizeof(struct node));
	head=NULL;
	printf("enter string \n");
	fflush(stdin);
	gets(s);
	
	head=tolink(s,head);
	display(head);

	return 0;
}

