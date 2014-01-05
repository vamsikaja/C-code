// replace _string1_with_string2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void replace(char *a,char *b,int i)
{
while(*(a+i)!='\0' && *b!='\0')
{
*(a+i)=*b;
i++;
b++;
}
printf("%s",a);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *a,*b;
    int i,alen,blen;
	printf("enter string1 length \n");
	scanf("%d",&alen);
	printf("enter string2 length \n");
	scanf("%d",&blen);
	a=(char *)malloc(alen*sizeof(char));
	b=(char *)malloc(blen*sizeof(char));
    printf("enter string a");
    scanf("%s",a);
    printf("enter string b");
    scanf("%s",b);
    printf("enter value of i");
    scanf("%d",&i);
    replace(a,b,i);
	return 0;
}

