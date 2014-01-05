// space_remove.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void space(char *a)
{
   int i,j;
   i=j=0;
   while(*(a+i)!='\0')
   {
       if(*(a+i)!=' ')
       {
           *(a+j)=*(a+i);
           j++;
       }
       i++;
  }
  *(a+j)='\0';
  printf("%s",a);
}


int _tmain(int argc, _TCHAR* argv[])
{
	char *a;
	int n;
	printf("enter sizeof string\n");
	scanf("%d",&n);
	a=(char *)malloc(n*sizeof(char));
    printf("\n enter the string \n");
	fflush(stdin);
    scanf("%[^\n]s",a);
    space(a);
	return 0;
}

