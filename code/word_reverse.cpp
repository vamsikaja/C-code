// word_reverse.cpp : Defines the entry point for the console application.
//convert "hello world vamsi" to "vamsi world hello"

#include "stdafx.h"
#include<malloc.h>
void wordreverse(char *s,int n,int t)
{
int i;
char a;
for(i=0;i<=t/2;i++)
{
a=*(s+n-i);
*(s+n-i)=*(s+n-t+i);
*(s+n-t+i)=a;
}
}
void reversestr(char *s)
{
int i=0,t;
while(*(s+i)!='\0')
{
t=-1;
while(*(s+i)!=' '&&*(s+i)!='\0')
{
t++;
i++;
}
if(t!=-1)
wordreverse(s,i-1,t);
if(*(s+i)=='\0')
break;
i++;
}
wordreverse(s,i-1,i-1);
printf("%s",s);
}



int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int n;
	printf("enter size of string");
	scanf("%d",&n);
	s=(char *)malloc(n*sizeof(char));
    printf("enter the string");
	fflush(stdin);
    scanf("%[^\n]",s);
    reversestr(s);
	return 0;
}

