// toBinary.cpp : Defines the entry point for the console application.
//Take an integer input and print its binary equivalent and if the number is negative print its 2's complement
//binary number size is restricted to 8 digits only

#include "stdafx.h"
#include<malloc.h>
void toBinary(char *a,int n);
void toTwosComplement(char *a);

void toBinary(char * a,int n)
{
int i;
for(i=7;i>=0;i--)
{
if(n%2==1)
*(a+i)='1';
else
*(a+i)='0';
n=n/2;
if(n==0)
break;
}
}

int _tmain(int argc, _TCHAR* argv[])
{


char *a;
a=(char *)malloc(8*sizeof(char));
int n,i,temp=1;
for(i=0;i<8;i++)
a[i]='0';
printf("enter no that you want to find its binary value and no should be between -128   and 127 as we are restricting size of binary number to 8 digits only \n");
scanf("%d",&n);

if(n>=0)
toBinary(a,n);
else
{
toBinary(a,-n);
toTwosComplement(a);
}
*(a+8)='\0';
printf("\n%s",a);


return 0;
}
void toTwosComplement(char *a)
{
int i;
for(i=7;;i--)
{
if(*(a+i)=='1')
break;
}

for(i=i-1;i>=0;i--)
{

if(*(a+i)=='1')
*(a+i)='0';
else
*(a+i)='1';
}

}


