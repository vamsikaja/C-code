// Inorder_successor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
struct node
{
	int num;
	struct node *left;
	struct node *right;
};
struct node * createnode(int n)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->num=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node * create(struct node *temp,int n)
{
	if(temp==NULL)
		temp=createnode(n);
	else if(n>temp->num)
		temp->right=create(temp->right,n);
	else
		temp->left=create(temp->left,n);
	return temp;
}
void inorder(struct node *temp,int n)
{
	static int t;
	if(temp!=NULL && t!=2)
	{
	
		
		inorder(temp->left,n);
		if(t==1)
		{
			t=2;
			printf("%d",temp->num);
		}
		if(temp->num==n )
			t=1;
		inorder(temp->right,n);
		
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,t;
	struct node *root;
	root=(struct node *)malloc(sizeof(struct node));
	root=NULL;
	do
	{
		printf("enter no you want add into BST \n");
		scanf("%d",&n);
		root=create(root,n);
		printf("enter 0 if you don't want to insert elements into tree else 1");
		scanf("%d",&t);
	}while(t);
	printf("enter no you want find the inorder successor");
	scanf("%d",&n);
	inorder(root,n);
    return 0;
}

