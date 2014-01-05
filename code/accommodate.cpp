// accommodate.cpp : Defines the entry point for the console application.
//Take a string "ACCOMMODATE" and then return back "ACOMODATE"

#include "stdafx.h"
#include<malloc.h>
void reduce(char *s)
{
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(s[i]!=s[i+1])
		{
			s[j]=s[i];
			j++;
		}
		i++;
	}
	s[j]='\0';
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int n;
	printf("enter size of string \n");
	scanf("%d",&n);
	s=(char *)malloc(n*sizeof(char));
	printf("enter string \n");
	fflush(stdin);
	gets(s);
	reduce(s);
	puts(s);
	return 0;
}

