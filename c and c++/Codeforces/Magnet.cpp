#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int n;
    int count=1;
    cin>>n;

    string mag[n];
    for(int i=0;i<n;i++)
    {
        cin>>mag[i];
    }
    string a;
    a=mag[0];
    for(int i=1;i<n;i++)
    {
        if(!(a==mag[i]))
        {
            count++;
            a=mag[i];
        }
    }
    cout<<count;
}

