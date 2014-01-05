// game1.cpp : Defines the entry point for the console application.
//takes strings as inputs that contain only 0's and 1's
//clears if there is a path between (0,0) and (m-1,n-1)
//i had taken a string that contais the path how we travelled
//l-we moved left ,r-right,d-down,t-top
//t array is initialized to 0
//and corresponding elements are made 1 if we traversed the node (i,j)

#include "stdafx.h"
#include<malloc.h>


int g=0;
void del(char **b,int m,char *s)//delete the characters in the path
{
	int i=1,j=2;
	int k=0;
	while(*(s+k)!='\0')
	{
		if(*(s+k)=='d')
		{
			b[i][j]=' ';
			b[i+1][j-1]=' ';
			b[i+1][j]=' ';
			b[i+1][j+1]=' ';
			i=i+2;
		}
		if(*(s+k)=='r')
		{
			b[i][j]=' ';
			b[i][j+2]=' ';
			j=j+4;
		}
		if(*(s+k)=='l')
		{
			b[i][j]=' ';
			b[i][j-2]=' ';
			j=j-4;
		}
		if(*(s+k)=='t')
		{
			b[i][j]=' ';
			b[i-1][j-1]=' ';
			b[i-1][j]=' ';
			b[i-1][j+1]=' ';
			i=i-2;
		}
		k=k+1;
	}
	b[i][j]=' ';
	for(i=0;i<2*m+1;i++)
	{
			printf("%s \n",b[i]);
	}
	
}
//find the path between (0,0) and (m,n)
char ** game(char **a,int i,int j,int m,int n,char **t,char *s)
{
	
	if( i+1<=m-1 && t[i+1][j]=='0'&& a[i+1][j]=='1')
	{
		*(s+g)='d';
		g++;
		i=i+1;
		t[i][j]='1';
		if(i==m-1 && j==n-1)
			return t;
		
				
		return game(a,i,j,m,n,t,s);
	}
	if(  i-1>=0 && t[i-1][j]=='0' && a[i-1][j]=='1')
	{
		*(s+g)='t';
		g++;
		i=i-1;
		t[i][j]='1';
		if(i==m-1 && j==n-1)
			return t;
		
		
		return game(a,i,j,m,n,t,s);
	}
	if(   j-1>=0 && t[i][j-1]=='0' && a[i][j-1]=='1')
	{
		*(s+g)='l';
		g++;
		j=j-1;
		t[i][j]='1';
		if(i==m-1 && j==n-1)
			return t;
		
		
		return game(a,i,j,m,n,t,s);
	}
	if(  j+1<=n-1 && t[i][j+1]=='0' && a[i][j+1]=='1')
	{
		*(s+g)='r';
		g++;
		j=j+1;
		t[i][j]='1';
		if(i==m-1 && j==n-1)
			return t;
		
		
		return game(a,i,j,m,n,t,s);
	}
	else
	{
		g--;
		if(*(s+g)=='d')
		{
			
			return game(a,i-1,j,m,n,t,s);
		}
		else if(*(s+g)=='t')
			{
				
				return game(a,i+1,j,m,n,t,s);
		}
		else if(*(s+g)=='r')
			
				return game(a,i,j-1,m,n,t,s);
		else if(*(s+g)=='l')
			return game(a,i,j+1,m,n,t,s);
		else 
		{
			printf("no path");
			return t;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	char *s=(char *)malloc(100*sizeof(char));
	int m,n,i,j=0,k=0;
	char **a,**b;
	char **t;
	int p;
	
	printf("enter row size ");
	scanf("%d",&m);
	printf("column size   ");
	scanf("%d",&n);
	a=(char **)malloc(m*sizeof(char*));
	for(i=0;i<m;i++)
		a[i]=(char *)malloc(n*sizeof(char));
	t=(char **)malloc(m*sizeof(char*));
	for(i=0;i<m;i++)
		t[i]=(char *)malloc(n*sizeof(char));
	for(i=0;i<m;i++)
	{
		printf("enter %dth row :",i+1);
		scanf("%s",a[i]);
	}
	b=(char **)malloc((2*m+1)*sizeof(char*));
	for(i=0;i<2*m+1;i++)
		b[i]=(char *)malloc((4*n+1)*sizeof(char));
	p=-1;
	for(i=0;i<2*m+1;)
	{
		if(j==4*n+1)
		{
			b[i][j]='\0';
			i++;
			j=0;
			if(i%2==1)
			{
				k=0;
				p++;
			}
		}
		if(i==2*m+1)
			break;
		if(i%2==0)
		{
			b[i][j++]='-';
		}
		else
		{
			if((j%4)==0)
				b[i][j++]='|';
			else if((j%4)==2)
				b[i][j++]=a[p][k++];
			else
				b[i][j++]=' ';
		}
	}
	for(i=0;i<2*m+1;i++)
		printf("%s \n",b[i]);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			t[i][j]='0';
		}
	}
	t[0][0]='1';
	
	t=game(a,0,0,m,n,t,s);
	if(g>0)
	{
		*(s+g)='\0';
	//printf("%s \n",s);
	del(b,m,s);
	
	}

	return 0;
}

