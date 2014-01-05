// accommodateToac2om2odate.cpp : Defines the entry point for the console application.
//Modify the string "ACCOMMODATE" to get an output of "AC2OM2ODATE"

#include "stdafx.h"
#include<malloc.h>
char * toChar(int t,char *p)
{
	int i=t,n=0;
	while(i)
	{
		i=i/10;
		n++;
	}
	p[n]='\0';
	for(n--,i=n;i>=0;i--)
	{
		p[i]=t%10+48;
		t=t/10;
	}
	return p;
}




char * compress(char *s)
{
	char *p;
	p=(char *)malloc(10*sizeof(char));
	int i=0,t=1,j=0,k=0;
	while(s[i]!='\0')
	{
		if(s[i]==s[i+1])
			t++;
		else
		{
			s[j]=s[i];
			j++;
			if(t>1)
			{
				p=toChar(t,p);
				while(p[k]!='\0')
				{
					s[j]=p[k];
					j++,k++;
				}
				t=1;
				k=0;
			}

			
		}
		i++;
	}
	s[j]='\0';
	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int n;
	printf("enter no of characters in the string \n");
	scanf("%d",&n);
	s=(char *)malloc(sizeof(char));
	printf("enter string\n");
	fflush(stdin);
	gets(s);
	s=compress(s);
	puts(s);
	return 0;
}

