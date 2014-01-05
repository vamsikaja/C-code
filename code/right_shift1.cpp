// right_shift1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void shift(int *a,int n,int k)
{
	int *b,i;
	b=(int *)malloc(k*sizeof(int));
	for(i=0;i<k;i++)
		b[i]=a[n-1-i];
	for(i=k;i<n;i++)
		a[i]=a[i-k];
	for(i=k-1;i>=0;i--)
		a[k-1-i]=b[i];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,*a,i,k;
	printf("enter size of array");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter shift value");
	scanf("%d",&k);
	if(k>0)
	shift(a,n,k);
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
    return 0;
}

