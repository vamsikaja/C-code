// length_string_recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>

int length(char *s,int i)
{
	if(s[i]=='\0')
		return 0;
	else
		return 1+length(s,++i);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	s=(char *)malloc(100*sizeof(char));
	printf("enter string\n");
	gets(s);
	printf("length of string \"%s\" is : %d",s,length(s,0));
	return 0;
}

