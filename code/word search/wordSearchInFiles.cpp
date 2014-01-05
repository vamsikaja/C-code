// seach a word in a large number of files



#include "stdafx.h"
#include<malloc.h>
#include<string.h>
int g=-1,temp=1000,o=0;
struct node * newword(char *word,char *s,struct node* a);
struct node * open(char *s,struct node *a);
struct node * tolink(char *word,char *s,struct node * a);
void look(char *search,struct node * a);
struct node
{
	int count;
	char filename[25];
	char w[200];
};
struct node * open(char *s,struct node *a)
{
	char ch,*word;
	int i=0;
	o=g+1;
	word=(char *)malloc(200*(sizeof(char)));
	FILE *fp;
	fp=fopen(s,"r");
	if(fp==NULL)
	{
		printf("cannot open file");
		return a;
	}
    while(1)
	{
		ch=fgetc(fp);
	    while(ch!=' '&&ch!='\n'&&ch!=EOF)
	    {
				word[i]=ch;
				
				ch=fgetc(fp);
				
				i++;
		}
		if(i>0)
		{
				word[i]='\0';
				//printf("%s \n",word);
				a=newword(word,s,a);
				i=0;
		}
		if(ch==EOF)
		{
			fclose(fp);
			break;
		}

		
	}
	
	return a;
}
struct node * newword(char *word,char *s,struct node* a)
{
	int j=0;
	/*if(g==-1)
	{
		a=tolink(word,s,a);
		return a;*/
	//}
	for(j=o;j<=g;j++)
	{
		if(strcmp(a[j].w,word)==0 && strcmp(a[j].filename,s)==0)
		{
			(a[j].count)++;
			return a;
		}
	}
		a=tolink(word,s,a);
	return a;
}
struct node * tolink(char *word,char *s,struct node * a)
{
	g=g+1;
	a[g].count=1;
	strcpy(a[g].filename,s);
	strcpy(a[g].w,word);
	temp--;
	if(temp==1)
	{
		a=(struct node *)realloc(a,(g+1000)*sizeof(struct node));
		temp=1000;
	}
	return a;
}
void look(char *search,struct node * a)
{
	int j;
	for(j=0;j<=g;j++)
	{
		if(strcmp(a[j].w,search)==0)
		{
			printf("%s   %d \n",a[j].filename,a[j].count);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	struct node *a;
	a=(struct node *)malloc(1000 * sizeof(struct node ));
	char *s,*search;
	s=(char *)malloc(20 * sizeof(char));
	search=(char *)malloc(100 * sizeof(char));
	int i=0;
	char ch;
	fp=fopen("list","r");
	while(1)
	{
		
		ch=fgetc(fp);
		
		
		/*if(ch=='\n'||ch==EOF)
		{
			
			s[i]='\0';
			i=0;
			a=open(s,a);
		}
		else
		{
			s[i]=ch;
			i++;
		}*/
		while(ch!='\n'&&ch!=EOF)
		{
			s[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		if(i>0)
		{
			s[i]='\0';
			printf("%s  ",s);
			a=open(s,a);
			i=0;
		}
		if(ch==EOF)
			break;
	}
	//for(i=0;i<g;i++)
	//{
		//printf("%s %s %d \n",a[i].w,a[i].filename,a[i].count);
	//}
	
	printf("enter the search word");
	scanf("%s",search);
	
	look(search,a);
	return 0;
}



