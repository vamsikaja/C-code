// ChangeCase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
char *changeCase(char *s)
{
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]>=65&&s[i]<=90)
			s[i]=s[i]+32;
		else if(s[i]>=97&&s[i]<=122)
			s[i]=s[i]-32;
		i++;
	}
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
	s=changeCase(s);
	puts(s);
	return 0;
}

