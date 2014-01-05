// factorial.cpp : Defines the entry point for the console application.
//Factorial of a number

#include "stdafx.h"

int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		n=n*fact(n-1);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("enter no that you want to find the factorial \n");
	scanf("%d",&n);
	printf("factorial of given no is %d",fact(n));
	return 0;
}

