// count_VowelsConsonants.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>

void tocount(char *s)
{
	int nv=0,nc=0,i=0;
	while(s[i]!='\0')
	{
		if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122))
		{
			if(s[i]>=97 && s[i]<=122)
			{
		        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			       nv++;
		        else
			       nc++;
			}
			else
			{
				if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
			       nv++;
		        else
			       nc++;
			}
		}

		i++;
	}
	printf("no. of vowels =%d\n no. of consonants=%d",nv,nc);
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
	tocount(s);
	return 0;
}

