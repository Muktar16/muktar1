#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    long long n,n1,n2;
    cin>>n;
    if(n%2==0)
    {
        n1 = n/2;
        n2 = n/2;
    }
    else
    {
        n1 = n/2;
        n2 = (n/2)+1;
    }

    cout<<(n1*(n1+1))-(n2*n2);
}
