// binary2decimal.cpp : Defines the entry point for the console application.
//Convert a given binary number to decimal

#include "stdafx.h"
#include<malloc.h>

int toDecimal(char *s)
{
	int i=0,n=0;
	while(*(s+i)!='\0')
	{
		n=n<<1;
		n=n+s[i]-48;
		i++;
	}
	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int n;
	printf("enter no of digits in the binary number");
	scanf("%d",&n);
	s=(char *)malloc(sizeof(char));
	printf("enter binary no");
	scanf("%s",s);
	printf("the decimal equivalent of %s is %d",s,toDecimal(s));
	return 0;
}

