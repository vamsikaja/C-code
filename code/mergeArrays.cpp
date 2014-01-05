// mergeArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
void merge(int *a,int *b,int alen,int blen)
{
	int i=alen,j=blen,k=alen+blen+1;
	while(i>=0 && j>=0)
	{
		if(a[i]>b[j])
		{
			a[k]=a[i];
			i--;
		}
		else
		{
			a[k]=b[j];
			j--;
		}
		k--;
	}
	if(i>=0)
	{
		a[k]=a[i];
		i--;
		k--;
	}
	else if(j>=0)
	{
		a[k]=b[j];
		j--;
		k--;
	}
}
	
				





int _tmain(int argc, _TCHAR* argv[])
{
	int *a,*b,alen,blen,i;
	printf("enter a-length\n");
	scanf("%d",&alen);
	printf("enter b-length\n");
	scanf("%d",&blen);
	a=(int *)malloc((alen+blen)*sizeof(int));
	b=(int *)malloc(alen*sizeof(int));
	printf("enter elements into a in increasing order");
	for(i=0;i<alen;i++)
		scanf("%d",&a[i]);
	printf("enter elements into b in increasing order");
	for(i=0;i<blen;i++)
		scanf("%d",&b[i]);
	merge(a,b,alen-1,blen-1);
	for(i=0;i<alen+blen;i++)
	    printf("%d  ",a[i]);
	return 0;
}

