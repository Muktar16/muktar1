#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"I hate it";
        return 0;
    }
    if(n==2)
    {
        cout<<"I hate that I love it";
        return 0;
    }
    if(n%2==0)
    {
        for(int i=0;i<n/2-1;i++)
        {
            cout<<"I hate that I love that ";
        }
        cout<<"I hate that I love it";
    }
    else
    {
        for(int i=0;i<n/2;i++)
        {
            cout<<"I hate that I love that ";
        }
        cout<<"I hate it";
    }
}
