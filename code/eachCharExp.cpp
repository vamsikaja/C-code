// eachCharExp.cpp : Defines the entry point for the console application.
//Given (abc, 2) -> aabbcc. Repeat each char and Expand the string.

#include "stdafx.h"
#include<malloc.h>
char *toExpand(char *s,int m,int n)
{
	int i,j,k=m*n-1;
	for(i=n-1;i>=0;i--)
	{
		for(j=1;j<=m;j++)
		{
			s[k]=s[i];
			k--;
		}
	}
	s[m*n]='\0';
	return s;
}



int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int n,m;
	printf("enter length of sring\n");
	scanf("%d",&n);
	s=(char *)malloc(n*sizeof(char));
	printf("enter string\n");
	fflush(stdin);
	gets(s);
	printf("enter number how many times we need to xpand each char\n");
	scanf("%d",&m);
	s=(char *)realloc(s,(n+n*(m-1))*sizeof(char));
	s=toExpand(s,m,n);
	puts(s); 
    return 0;
}

