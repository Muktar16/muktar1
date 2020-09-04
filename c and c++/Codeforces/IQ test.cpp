#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0) c1++;
        else c2++;
    }
    if(c1>c2)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]%2!=0)
            {
                cout<<(i+1);
                return 0;
            }
        }
    }

    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0)
            {
                cout<<(i+1);
                return 0;
            }
        }
    }
}
