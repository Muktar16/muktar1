#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n,m,c=0;
    scanf("%d %d",&n,&m);
    int p=n*m;

    for(int i=p;i>0;i=i-(m+n))
    {
        c++;
        n--;
        m--;
    }
    if(c%2!=0) cout<<"Malvika";
    else cout<<"Akshat";
}
