// t9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
#include<string.h>
int g=-1,t=0;
struct node
{
	int num;
	char word[10];
	
};
void tolink(char *s,struct node *a)
{
	g++;
	int i=0,j;
	a[g].num=0;
	strcpy(a[g].word,s);
	
	while(s[i]!='\0')
	{
		a[g].num=a[g].num*10;
		if(s[i]=='a'||s[i]=='b'||s[i]=='c')
			j=2;
		else if(s[i]=='d'||s[i]=='e'||s[i]=='f')
			j=3;
		else if(s[i]=='g'||s[i]=='h'||s[i]=='i')
			j=4;
		else if(s[i]=='j'||s[i]=='k'||s[i]=='l')
			j=5;
		else if(s[i]=='m'||s[i]=='n'||s[i]=='o')
			j=6;
		else if(s[i]=='p'||s[i]=='q'||s[i]=='r'||s[i]=='s')
			j=7;
		else if(s[i]=='t'||s[i]=='u'||s[i]=='v')
			j=8;
		else if(s[i]=='w'||s[i]=='x'||s[i]=='y'||s[i]=='z')
			j=9;
		a[g].num=a[g].num+j;
		i++;
	}
	
	
}
void sort(struct node * a)
{
	int i,j,temp;
	char *ch;
	ch=(char *)malloc(10*sizeof(char));
	for(i=0;i<g;i++)
	{
		for(j=i+1;j<=g;j++)
		{
			if(a[i].num>a[j].num)
			{
				strcpy(ch,a[i].word);
				temp=a[i].num;
				strcpy(a[i].word,a[j].word);
				a[i].num=a[j].num;
				strcpy(a[j].word,ch);
				a[j].num=temp;
			}
		}
	}
}
//int linear(struct node *a,int i,int n)
//{
//	while(a[i].num<n )
//		i++;
//	while(a[i].num-n<10 && t<10)
//	{
//		printf("%s \n",a[i].word);
//		t++;
//		i++;
//	}
//	return i;
//
//
//}
//int binary(struct node *a,int i,int j,int n)
//{
//	if(i==j)
//	{
//		if(a[i].num!=n)
//			i++;
//		i=linear(a,i,n);
//		return i;
//	}
//	else
//	{
//		if(a[(i+j)/2].num>n)
//			return binary(a,i,(i+j)/2,n);
//		else
//			return binary(a,(i+j)/2+1,j,n);
//	}
//}
int search(struct node *a,int i,int n,int n1)
{
	while(n>a[i].num)
		i++;
	while((a[i].num>=n) && (a[i].num<n1)&& t<10)
	{
		printf("%s\n",a[i].word);
		i++;
		t++;
	}
	return i;

}
void t9(struct node *a,int n,int n1)
{
	int i=0;
	while(n<a[g].num && t<10)
	{
		i=search(a,i,n,n1);
		n=n*10;
		n=n+2;
		n1=n1*10;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *a;
	a=(struct node *)malloc(80368 * sizeof(struct node));
	char ch;
	char *s;
	int n;
	
	s=(char *)malloc(10*sizeof(char));
	int i=0,j=0;
	FILE *fp=fopen("dictionary.txt","r");
	
	while(1)
	{
		ch=fgetc(fp);
		
		
		while(ch!='\n'&& ch!=EOF)
		{
			s[i]=ch;
			i++;
			ch=fgetc(fp);
			
		}
		s[i]='\0';
		tolink(s,a);
		i=0;
		if(ch==EOF)
		break;
	}
	
	printf("\n please wait dictionary is getting sorted\n");
	sort(a);
	for(i=0;i<=g;i++)
	{
		printf("%s  %d\n",a[i].word,a[i].num);
	}
	
	printf("enter search number");
	scanf("%d",&n);
	t9(a,n,n+1);
			

	return 0;
}

