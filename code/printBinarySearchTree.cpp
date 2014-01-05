// dll2bst.cpp : Defines the entry point for the console application.
// to print a BST .Input is taken in the form of sorted double linked list

#include "stdafx.h"
#include<malloc.h>
#include<math.h>
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
int depth(struct node *root)
{
	int r=1;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=root;
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
		r++;
	}
		return r;
}
void show(int **s,int d,struct node *root,int p,int q)
{
	int i,j,k;
	if(root!=NULL)
	{
		i=p;j=q;
		s[i][j]=root->data;
		if(d>0 && root->prev!=NULL)
		{
			
			    for(k=0;k<(d-1)*(d-1)+1;k++)
				s[++i][--j]=47;
		
		}
		i++;j--;
	    show(s,d-1,root->prev,i,j);
	    i=p,j=q;
	     
		if(d>0 && root->next!=NULL)
			{
				
	     
			for(k=0;k<(d-1)*(d-1)+1;k++)
				s[++i][++j]=92;
	      
		}
		 i++;j++;
	show(s,d-1,root->next,i,j);
}
}






int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head,*tail,*root;
	int num,i,d=0,j,m;
	head=tail=root=(struct node *)malloc(sizeof(struct node));
	head=tail=NULL;
	int **s;

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
	/*show3(root);*/
	d=depth(root);
	//printf("%d \n",d);
	if(d==1)
		m=1;
	else if(d==2)
		m=3;
	else if(d==3)
		m=6;
	else if(d==4)
		m=12;
	s=(int **)malloc(m*sizeof(int *));
	for(i=0;i<m;i++)
	{
		s[i]=(int *)malloc((2*m-1)*sizeof(int));
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<2*m-1;j++)
		{
			s[i][j]=32;
		}
	}
	if(m==1)
		s[0][0]=root->data;
	else
	{
	   j=(2*m-2)/2;
	    show(s,d-1,root,0,j);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<2*m-1;j++)
		{
			if(s[i][j]==32 ||s[i][j]==92 ||s[i][j]==47)
				printf("%c ",s[i][j]);
			else
				printf("%d ",s[i][j]);
		}
		printf("\n");
	}


	return 0;
}

