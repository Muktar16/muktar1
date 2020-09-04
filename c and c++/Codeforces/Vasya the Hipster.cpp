#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a==b) cout<<a<<" "<<0;
    else if(a<b)
    {
        if((b-a)>1) cout<<a<<" "<<((b-a)/2);
        else cout<<a<<" "<<0;
    }
    else
    {
        if((a-b)>1) cout<<b<<" "<<((a-b)/2);
        else cout<<b<<" "<<0;
    }
}
