#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int r[n]={0};
    int p,q;
    cin>>p;
    int a[p];
    for(int i=0;i<p;i++)
    {
        cin>>a[i];
        r[a[i]-1]=1;
    }

    cin>>q;
    int b[q];
    for(int i=0;i<q;i++)
    {
        cin>>b[i];
        r[b[i]-1]=1;
    }

    for(int i=0;i<n;i++)
    {
        if(r[i]==0)
        {
            cout<<"Oh, my keyboard!";
            return 0;
        }
    }
    cout<<"I become the guy.";
}
