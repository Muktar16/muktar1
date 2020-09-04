#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int max=a[0],min=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max) max=a[i];
        else if(min>a[i]) min=a[i];
    }


    int maxi=0;int c=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==max)
        {
            maxi=i;
            break;
        }
    }
    for(int i=maxi;i>0;i--)
    {
        int temp=a[i];
        a[i]=a[i-1];
        a[i-1]=temp;
        c++;
    }


    int mini=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==min)
        {
            mini=i;
            break;
        }
    }
    for(int i=mini;i<n;i++)
    {
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
        c++;
    }
    cout<<c;
}
