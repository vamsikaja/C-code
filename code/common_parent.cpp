// common_parent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};
int common(struct node *root,struct node *m,struct node *n)
{
	int i=0,j=0;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=m;
	while(temp!=root)
	{
		temp=temp->parent;
		i++;
	}
	temp=n;
	while(temp!=root)
	{
		temp=temp->parent;
		j++;
	}
	if(i<j)
	{
		
		while(i!=j)
		{
			n=n->parent;
			if(n==m)
				return n->data;
			j--;
		}
	}
	else if(i>j)
	{
		
		while(i!=j)
		{
			m=m->parent;
			if(m==n)
				return m->data;
			i--;
		}
	}
	while(1)
	{
		if(m->parent==n->parent)
			return m->parent->data;
		m=m->parent;
		n=n->parent;
	}
}

struct node * create(struct node *root)
{
	root->parent=NULL;
	root->data=10;
	root->left=(struct node *)malloc(sizeof(struct node));
	root->right=(struct node *)malloc(sizeof(struct node));
	root->right->left=(struct node *)malloc(sizeof(struct node));
	root->right->right=(struct node *)malloc(sizeof(struct node));
	root->right->left->left=(struct node *)malloc(sizeof(struct node));
	root->right->right->right=(struct node *)malloc(sizeof(struct node));
	root->left->left=(struct node *)malloc(sizeof(struct node));
	root->left->right=(struct node *)malloc(sizeof(struct node));
	root->left->parent=root;
	root->right->parent=root;
	root->left->data=9;
	root->left->left->parent=root->left;
	root->left->left->data=2;
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	root->left->right->parent=root->left;
	root->left->right->data=1;
	root->left->right->left=NULL;
	root->left->right->right=NULL;
	root->left->right=NULL;
	root->right->data=8;
	root->right->left->data=6;
	root->right->left->parent=root->right;
	root->right->left->left->parent=root->right->left;
	root->right->left->left->data=4;
	root->right->left->left->left=NULL;
	root->right->left->left->right=NULL;
	root->right->left->right=NULL;
	root->right->right->parent=root->right;
	root->right->right->data=5;
	root->right->right->left=NULL;
	root->right->right->right->parent=root->right->right;
	root->right->right->right->data=3;
	root->right->right->right->left=NULL;
	root->right->right->right->right=NULL;

	return root;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int i,n;
	struct node *root=(struct node *)malloc(sizeof(struct node));
	//statically creating tree
	root=create(root);
	    printf("\n %d",common(root,root->left->left,root->right->right->right));	
	return 0;
}

