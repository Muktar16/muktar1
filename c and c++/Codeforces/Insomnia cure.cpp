#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int k,l,m,n,d;
    scanf("%d %d %d %d %d",&k,&l,&m,&n,&d);

    int a[d]={0};
    for(int i=0;i<d;i++)
    {
        if((i+1)%k==0 || (i+1)%l==0 || (i+1)%m==0 || (i+1)%n==0)
        {
            a[i]=1;
        }
    }
    int c=0;
    for(int i=0;i<d;i++)
    {
        if(a[i]==1) c++;
    }
    printf("%d",c);
}
