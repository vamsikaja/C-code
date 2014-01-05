// csvfile.cpp : Defines the entry point for the console application.
//printing of csv file that contains exactly 4 columns with variable row size

#include "stdafx.h"
#include<malloc.h>
void toprint(char *s,int t1,int t2,int t3,int t4)
{
	FILE *fp;
	char *s1,*s2,*s3,*s4,ch;
	s1=(char *)malloc(t1*sizeof(char));
	s2=(char *)malloc(t2*sizeof(char));
	s3=(char *)malloc(t3*sizeof(char));
	s4=(char *)malloc(t4*sizeof(char));
	int i,j=1;
	
	fp=fopen(s,"r");
	
	s1[t1]='\0';
	s2[t2]='\0';
	s3[t3]='\0';
	s4[t4]='\0';
	while(1)
	{
		for(i=0;i<t1;i++)
		   s1[i]=' ';
	    for(i=0;i<t2;i++)
		   s2[i]=' ';
	    for(i=0;i<t3;i++)
		   s3[i]=' ';
	    for(i=0;i<t4;i++)
		   s4[i]=' ';
		i=0;
		while(j<5)
		{
			ch=fgetc(fp);
		    if(ch==','||ch=='\n'||ch==EOF)
		    {
			 if(j==4)
			 {
				s4[t4]='\0';
				printf("%s%s%s%s\n",s1,s2,s3,s4);
			 }
			j++;
			i=-1;
		 }
		  if(ch==EOF)
			break;
		  if(j==1)
			  s1[i]=ch;
		  else if(j==2)
			  s2[i]=ch;
		  else if(j==3)
			  s3[i]=ch;
		  else if(j==4)
			  s4[i]=ch;
		  i++;
		  
		}
		j=1;
		if(ch==EOF)
			break;
	}
}
void tocount(char *s)
{
	int t1=0,t2=0,t3=0,t4=0;
	int i=0,j=1;
	char ch;
	FILE *fp;
	fp=fopen(s,"r");
	while(1)
	{
		
		
		while(j<5)
		{
			ch=fgetc(fp);
			if(ch==','||ch=='\n')
			{
				if(j==1)
				{
					if(t1<i)
						t1=i;
				}
				else if(j==2)
				{
					if(t2<i)
						t2=i;
				}
				else if(j==3)
				{
					if(t3<i)
						t3=i;
				}
				else if(j==4)
				{
					if(t4<i)
						t4=i;
				}
				j++;
				i=-1;
			}
			if(ch==EOF)
		    break;
			i++;

			
		}
		j=1;
		if(ch==EOF)
		break;

			

    }
	toprint(s,t1+1,t2+1,t3+1,t4+1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	s=(char *)malloc(100*sizeof(char));
	printf("give the path of csv file  ");
	scanf("%s",s);
	tocount(s);
	return 0;
}

