// csvfile.cpp : Defines the entry point for the console application.
//printing of csv file that contains exactly 4 columns with variable row size

#include "stdafx.h"
#include<malloc.h>
int *t;
char **str;
void toprint(char *s,int n)
{
	FILE *fp;
	char ch;
	int i,j,k;
	for(i=0;i<n;i++)
		str[i]=(char *)malloc(t[i]*sizeof(char));
	
	
	fp=fopen(s,"r");
	for(i=0;i<n;i++)
		str[i][t[i]+1]='\0';
	
	
		
		while(1)
	   {
		   for(i=0;i<n;i++)
		{
			for(j=0;j<=t[i];j++)
			{
				str[i][j]=' ';
			}
		}
		i=0;
		j=0;
		while(i<n)
		{
			ch=fgetc(fp);
		    while(ch!=','&& ch!='\n'&&ch!=EOF)
		    {
				str[i][j]=ch;
				j++;
				ch=fgetc(fp);
			}
			 if(i==n-1)
			 {
				for(k=0;k<n;k++)
				printf("%s",str[k]);
				printf("\n");
				while(ch!='\n'&& ch!=EOF)
					ch=fgetc(fp);
			 }
			j=0;
			i++;
		 }
		  if(ch==EOF)
			break;
		  
		  
		}
		
}
void tocount(FILE *fp,int n,char *s)
{
	/*int t1=0,t2=0,t3=0,t4=0;*/
	int i=0,j=0,k;
	char ch;
	/*FILE *fp;
	fp=fopen(s,"r");*/
	while(1)
	{
		
		
		while(j<n)
		{
			ch=fgetc(fp);
			if(ch==EOF)
				break;
			while(ch!=','&& ch!='\n')
			{
				i++;
				ch=fgetc(fp);
			}
			if(i>t[j])
				t[j]=i;
			i=0;
			j++;
		}
		
		    while(ch!=EOF && ch!='\n')
			ch=fgetc(fp);
			j=0;
	    
			if(ch==EOF )
		    break;
    }
	
	
}
void firstLine(char *s)
{
	FILE *fp;
	fp=fopen(s,"r");
	char ch;
	int i=0,j=0;
	
	while(1)
	{
		
	    ch=fgetc(fp);	
		
		while(ch!=',' && ch!=EOF && ch!='\n')
		{
			j++;
			ch=fgetc(fp);
		}
		t[i]=j;
		j=0;
		i++;
		if(ch=='\n'|| ch==EOF)
			break;
	}
	if(ch!=EOF)
		tocount(fp,i,s);
	
	toprint(s,i);
}


int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int i;
	s=(char *)malloc(100*sizeof(char));
	t=(int *)malloc(100*sizeof(int));
	str=(char **)malloc(100*sizeof(char *));
	/*for(i=0;i<100;i++)
		str[i]=(char *)malloc(720*sizeof(char));*/
	printf("give the path of csv file  ");
	scanf("%s",s);
	firstLine(s);
	//tocount(s);
	return 0;
}

