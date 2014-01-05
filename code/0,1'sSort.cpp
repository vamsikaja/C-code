// 0,1'sSort.cpp : Defines the entry point for the console application.
// Sort an array which has only 0's and 1's as values.
//input consists of only 0's and 1's

#include "stdafx.h"
#include<malloc.h>



void sort(int *a,int n)
{
int i,j;
for(i=0,j=n-1;;i++,j--)
{
	while(a[i]==0)
		i++;
	while(a[j]==1)
		j--;
    if(i>j)
		break;
    else
	{
		a[i]=0;
		a[j]=1;
    }
}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int *a;
	int i,n;
    printf("enter size of array \n");
    scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
    printf("enter elements of array that need to be sorted and which contains only 0's and 1's \n ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,n);
    for(i=0;i<n;i++)
    printf("%d    ",a[i]);

	return 0;
}

