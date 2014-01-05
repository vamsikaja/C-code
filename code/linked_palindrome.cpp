// linked_palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>


struct node
{
	int data;
	struct node *link;
}; 
struct node * reverse(struct node *temp1,struct node *temp2,struct node *temp3)
{
	    temp2->link=temp1;
		temp1=temp2;
		temp2=temp3;
		
		if(temp2==NULL)
		{
			
			return temp1;
		}
		else
		{
			temp3=temp3->link;
		    reverse(temp1,temp2,temp3);
			
		}
}

void palindrome(struct node *head)
{
	int temp=0;
	struct node *temp1,*temp2,*temp3;
	
	temp1=temp2=head;
	while(temp2->link!=NULL && temp2->link->link!=NULL)
	{
		temp1=temp1->link;
		temp2=temp2->link->link;
	}
	if(temp2->link==NULL)
		temp=1;
	temp2=temp1->link;
	temp1->link=NULL;
	head=reverse(NULL,head,head->link);
	if(temp==1)
	    temp1=head->link;
	temp3=temp2;
	while(temp2!=NULL)
	{
		if(temp1->data!=temp2->data)
		{
			
			break;
		}
		temp1=temp1->link;
		temp2=temp2->link;
	}
	if(temp2==NULL)
		printf("\n palindrome");
	else
		printf("\n not palindrome");
	temp1=head;
	
	head=reverse(NULL,head,head->link);
	temp1=head;
	while(temp1->link!=NULL)
		temp1=temp1->link;
	temp1->link=temp3;
}

void display(struct node *head)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=head;
	while(temp->link!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->link;
	}
	printf("%d \n",temp->data);
}


struct node * tolinkedlist(int n,struct node *head)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=n;
	temp->link=head;
	head=temp;
	return head;
}


struct node * tolink(int n,struct node *head)
{
	while(n)
	{
		head=tolinkedlist(n%10,head);
		n=n/10;
	}
	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	int n;
	printf("enter no");
	scanf("%d",&n);
	head=NULL;
	head=tolink(n,head);
	//display(head);
	
	palindrome(head);
	//display(head);
	return 0;
}




