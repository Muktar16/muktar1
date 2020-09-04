#include<iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==b && a==c && a==d) cout<<3;
    else if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d) cout<<0;
    else if((a==b && a==c && a!=d) || (a==b && a==d && a!=c) || (a==c && a==d && a!=b) || (b==c && b==d && a!=b)) cout<<2;
    else if((a==b && c==d && a!=c) || (a==c && b==d &&a!=b) || (a==d && b==c && a!=b)) cout<<2;
    else cout<<1;

    //else if((a==b && c!=d && a!=c) || (a==c && b!=d && a!=b) || (a==d && b!=c && a!=b) || (b==c && a!=d && b!=a) || (b==d && a!=c && b!=a) || (c==d && a!=b && ))


}
