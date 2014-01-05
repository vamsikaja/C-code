// LinkedList_Reversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
}; 
void display(struct node *head)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->link;
	}
	//printf("%d \n",temp->data);
}
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
			/*return temp2;*/
		}
	
	    
		
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
	head=reverse(NULL,head,head->link);
	display(head);
	return 0;
}

