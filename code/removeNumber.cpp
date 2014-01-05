// removeNumber.cpp : Defines the entry point for the console application.
//Remove all digits in a given string

#include "stdafx.h"
#include<malloc.h>
char * removeNumbers(char *s)
{
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(!(s[i]>='0'&&s[i]<='9'))
		{
			s[j]=s[i];
			j++;
		}
		i++;
	}
	s[j]='\0';
	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	int n;
	char *s;
	printf("enter length of the string \n");
	scanf("%d",&n);
	s=(char *)malloc(n*sizeof(char));
	printf("enter string \n");
	fflush(stdin);
	scanf("%[^\n]s",s);
	s=removeNumbers(s);
	puts(s);
	return 0;
}

