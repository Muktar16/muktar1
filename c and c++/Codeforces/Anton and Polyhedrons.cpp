#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        if(str[0]=='T') sum=sum+4;
        else if(str[0]=='C') sum+=6;
        else if(str[0]=='O') sum+=8;
        else if(str[0]=='D') sum+=12;
        else sum+=20;
    }
    cout<<sum;
}
