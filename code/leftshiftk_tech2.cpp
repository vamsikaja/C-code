// leftshift_tech2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void leftk2(int *a,int k,int n)
{
int *b,i;
b=(int *)malloc(k*sizeof(int));
for(i=0;i<k;i++)
b[i]=a[i];
while(i<n)
{
a[i-k]=a[i];
i++;
}
while(i-k<n)
{
a[i-k]=b[i-n];
i++;
}
for(i=0;i<n;i++)
printf("%d",a[i]);
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
leftk2(a,k,n);

	return 0;
}

