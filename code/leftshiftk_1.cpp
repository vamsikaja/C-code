// leftshift_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void leftone(int *a,int n)
{
int k,i=0;
k=a[i];
while(i<n-1)
{
a[i]=a[i+1];
i++;
}
a[i]=k;
}

void leftk1(int *a,int k,int n)
{
int i;
while(k>0)
{
leftone(a,n);
k--;
}
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,k,i,*a;
printf(" \n enter the length of array");
scanf("%d",&n);
a=(int *)malloc(n*sizeof(int));
printf("\n enter elements of array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the value of k");
scanf("%d",&k);
leftk1(a,k,n);
	return 0;
}

