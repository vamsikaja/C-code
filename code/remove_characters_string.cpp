// remove_characters_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void min(char *a,int i,int j)
{
while(*(a+j+1)!='\0')
{
*(a+i)=*(a+j+1);
i++,j++;
}
*(a+i)='\0';
printf("%s",a);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	char *a;
    int i,j;
	printf("enter length of string");
	scanf("%d",&n);
	a=(char *)malloc(n*sizeof(char));
    printf(" \n enter the string");
	fflush(stdin);
    scanf("%[^\n]s",a);
    printf("enter values of i & j");
    scanf("%d %d",&i,&j);
    min(a,i,j);
	return 0;
}

