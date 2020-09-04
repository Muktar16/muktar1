#include<iostream>
using namespace std;

int main()
{
    int n,l;
    cin>>n>>l;
    float a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                float t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    double d;
    if(a[0]>(l-a[n-1])) d=a[0];
    else d=(double)l-a[n-1];

    for(int i=0;i<n-1;i++)
    {
        double k = (a[i+1]-a[i])/2.0;
        if(k>d) d=k;
    }
    cout<<d;
}
