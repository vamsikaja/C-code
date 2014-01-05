// stringExpand.cpp : Defines the entry point for the console application.
//Given (abc, 2) -> abcabc. Repeat whole string two times one after another.

#include "stdafx.h"
#include<malloc.h>

char * toExpand(char *s,int m,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			s[j*n+i]=s[i];
		}
	}
	s[m*n]='\0';
	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int n,m,i=0;
	printf("enter length of sring\n");
	scanf("%d",&n);
	s=(char *)malloc(n*sizeof(char));
	printf("enter string\n");
	fflush(stdin);
	gets(s);
	while(s[i]!='\0')
		i++;
	n=i;
	printf("enter number how many times we need to xpand each char\n");
	scanf("%d",&m);
	s=(char *)realloc(s,(n+n*(m-1))*sizeof(char));
	s=toExpand(s,m,n);
	puts(s);
	return 0;
}

