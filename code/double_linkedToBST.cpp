// double_linkedToBST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node * tolink(struct node *tail,int num)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(tail==NULL)
	{
		temp->data=num;
		temp->prev=NULL;
		temp->next=NULL;
		tail=temp;
	}
	else
	{
		temp->data=num;
		temp->next=NULL;
		temp->prev=tail;
		tail->next=temp;
		tail=temp;
	}
	return tail;
}
//void show1(struct node *head)
//{
//	struct node *temp;
//	temp=(struct node *)malloc(sizeof(struct node *));
//	temp=head;
//	while(temp->next!=NULL)
//	{
//		printf("%d",temp->data);
//		temp=temp->next;
//	}
//	printf("%d \n",temp->data);
//
//}
//void show2(struct node *tail)
//{
//	struct node *temp;
//	temp=(struct node *)malloc(sizeof(struct node *));
//	temp=tail;
//	while(temp->prev!=NULL)
//	{
//		printf("%d",temp->data);
//		temp=temp->prev;
//	}
//	printf("%d \n",temp->data);
//
//}
struct node * tobst(struct node *head,struct node *tail)
{
	struct node *temp1,*temp2;
	temp1=temp2=(struct node *)malloc(sizeof(struct node));
	
	if(head==tail)
	{
		head->next=head->prev=NULL;
		return head;
	}
	else if(head->next==tail)
	{
		tail->prev=NULL;
		return head;
	}
	else 
	{
		temp1=head;
	temp2=tail;
	while(temp1->data<temp2->data )
	{
		temp1=temp1->next;
		temp2=temp2->prev;
	}
	
	temp2->prev->next=NULL;
	temp2->prev= tobst(head,temp2->prev);
	temp2->next->prev=NULL;
	temp2->next=tobst(temp2->next,tail);
	return temp2;
	}
}
void show3(struct node *temp)
{
	if(temp!=NULL)
	{
		show3(temp->prev);
		printf("%d ",temp->data);
		show3(temp->next);
	}
	printf("\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head,*tail,*root;
	int num,i;
	head=tail=root=(struct node *)malloc(sizeof(struct node));
	head=tail=NULL;


	while(1)
	{
		printf("enter elements into double linked list \n");
		scanf("%d",&num);
		tail=tolink(tail,num);
		if(head==NULL)
			head=tail;
        printf("enter 0 if you don't want to add another element into list or any number to add  \n");
		scanf("%d",&i);
		if(i==0)
			break;
	}
	/*show1(head);
	show2(tail);*/
	root=tobst(head,tail);
	show3(root);
	

	return 0;
}
