// Binary2Octal.cpp : Defines the entry point for the console application.
//Take a base-2 number and convert it to base-8

#include "stdafx.h"
#include<malloc.h>

char * toOctal(char *binary,char *octal)
{
	int i=0,j=0,k=0,oct=0,value=0;
	while(binary[i]!='\0')
	{
		   oct=oct<<1;
		   oct=oct+binary[i]-48;
		   k++;
		   if(k==3)
		   {
			   octal[j]=oct+48;
			   k=0;
			   oct=0;
			   j++;
		   }
		   i++;
	}
	if(k==0)
	   octal[j]='\0';
	else
	{
		octal[j+1]='\0';
		value=1;
		for(i--,k=0,oct=0;i>=0;i--)
		{
			oct=oct+(binary[i]-48)*value;
			value=value*2;
			k++;
			if(k==3)
			{
				octal[j]=oct+48;
				j--;
				k=0;
				oct=0;
				value=1;
			}
		}
		octal[j]=oct+48;
		
	}
	return octal;

			

}



int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	char *binary,*octal;
	printf("enter size of binary number \n");
	scanf("%d",&n);
	binary=(char *)malloc(n*sizeof(char));
	octal=(char *)malloc((n/3+1)*sizeof(char));
	printf("enter binary number \n");
	scanf("%s",binary);
	octal=toOctal(binary,octal);
	printf("%s",octal);
	return 0;
}

