#include<iostream>
using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    int a[n],c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>h) c=c+2;
        else c=c+1;
    }
    cout<<c;
}
