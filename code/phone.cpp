// phone.cpp : Defines the entry point for the console application.
//Using standard phone mapping convert a string to a number representation

#include "stdafx.h"
#include<malloc.h>

char * toPhone(char *s)
{
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='a'||s[i]=='b'||s[i]=='c')
			s[i]='2';
		else if(s[i]=='d'||s[i]=='e'||s[i]=='f')
			s[i]='3';
		else if(s[i]=='g'||s[i]=='h'||s[i]=='i')
			s[i]='4';
		else if(s[i]=='j'||s[i]=='k'||s[i]=='l')
			s[i]='5';
		else if(s[i]=='m'||s[i]=='n'||s[i]=='o')
			s[i]='6';
		else if(s[i]=='p'||s[i]=='q'||s[i]=='r'||s[i]=='s')
			s[i]='7';
		else if(s[i]=='t'||s[i]=='u'||s[i]=='v')
			s[i]='8';
		else if(s[i]=='w'||s[i]=='x'||s[i]=='y'||s[i]=='z')
			s[i]='9';
		else if(s[i]==' ')
			s[i]='0';
		else if(!(s[i]>='0'&&s[i]<='9'))
		s[i]='1';
		i++;
	}
	*(s+i)='\0';
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
	s=toPhone(s);
	puts(s);
	return 0;
}

