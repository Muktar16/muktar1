#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int uc=0,lc=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z') lc++;
        else uc++;
    }
    for(int i=0;i<n;i++)
    {
        if(uc>lc && (s[i]>='a' && s[i]<='z'))
        {
            s[i]=s[i]-32;
        }
        else if(uc<=lc && (s[i]>='A' && s[i]<='Z'))
        {
            s[i]=s[i]+32;
        }
    }
    cout<<s;
}
