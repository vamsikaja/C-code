// productArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int i,n,*a,*b;
    printf("enter the size of array \n");
    scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
    printf("enter elements of array \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    b[n-1]=a[n-1];
    for(i=n-2;i>=0;i--)
        b[i]=b[i+1]*a[i];
    for(i=1;i<n-1;i++)
        a[i]=a[i]*a[i-1];
    for(i=0;i<n;i++)
    {
        if(i==0)
            b[i]=b[i+1];
        else if(i==n-1)
            b[i]=a[i-1];
        else
            b[i]=a[i-1]*b[i+1];
     }
     for(i=0;i<n;i++)
     printf("%d	",b[i]);
	return 0;
}

