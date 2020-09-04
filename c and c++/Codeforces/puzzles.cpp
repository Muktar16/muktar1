#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int f[m];
    for(int i=0;i<m;i++)
    {
        cin>>f[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m-i;j++)
        {
            if(f[j]>f[j+1])
            {
                int temp = f[j];
                f[j] = f[j+1];
                f[j+1] = temp;
            }
        }
    }

    //for(int i=0;i<m;i++) cout<<f[i]<<" ";

    int min = f[n-1]-f[0];
    for(int i=0;i<m-n+1;i++)
    {
        if(min>(f[n-1+i]-f[i])) min=f[n-1+i]-f[i];
    }
    cout<<min;
}
