// leftShift_tech3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void reverse(int *a,int i,int j)
{
	int k,temp;
	for(k=0;k<=(j-i)/2;k++)
	{
		temp=a[k+i];
		a[k+i]=a[j-k];
		a[j-k]=temp;
	}
}
void shift(int *a,int n,int k)
{
	reverse(a,0,k-1);
	reverse(a,k,n-1);
	reverse(a,0,n-1);
}



int _tmain(int argc, _TCHAR* argv[])
{
	int *a,n,k,i;
	printf("enter size of array ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter elements into array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter the value of k");
	scanf("%d",&k);
	if(k>0)
	shift(a,n,k);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}

