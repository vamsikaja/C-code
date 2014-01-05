// lenth_no_recursion.cpp : Defines the entry point for the console application.
//write a function that takes an integer input and then print it without using "%d"

#include "stdafx.h"
#include<malloc.h>
char * length(int num,char *s)
{
	if(num==0)
	{
		
		return s;
	}
	else
	{
		s--;
		*s=48+num%10;
		
		num=num/10;
		return length(num,s);
	}
}

	

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	char *s;
	s=(char *)malloc(10*sizeof(char));
	printf("enter number\n");
	scanf("%d",&num);
	s=s+10;
	*s='\0';
	s=length(num,s);
	printf("%s",s);
	return 0;
}

