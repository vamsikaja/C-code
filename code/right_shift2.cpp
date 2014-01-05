// right_shift2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void shift_1(int *a,int n)
{
	int i,temp;
	temp=a[n-1];
	for(i=n-1;i>0;i--)
		a[i]=a[i-1];
	a[0]=temp;
}
void shift(int *a,int n,int k)
{
	int i;
	for(i=0;i<k;i++)
		shift_1(a,n);
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
	shift(a,n,(k-n)%n);
	for(i=0;i<n;i++)
		printf("%d \n",a[i]);
	return 0;
}

