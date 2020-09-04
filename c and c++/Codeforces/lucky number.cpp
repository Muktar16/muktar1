#include<iostream>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    int c = 0;
    int c2=0;

    while(n>0)
    {
        if(n%10==4 || n%10==7)
        {
            c =c + 1;
        }
        n=n/10;
    }

    if(c==4 || c==7) {cout<<"YES"; return 0;}
    if(c==0) {cout<<"NO"; return 0;}

    while(c>0)
    {
        if(c%10!=4 && c%10!=7)
        {
            c2=1;
            break;
        }
    }
    if(c2==0) cout<<"YES";
    else cout<<"NO";
}
