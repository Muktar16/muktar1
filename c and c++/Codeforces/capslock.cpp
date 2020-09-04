#include<iostream>
#include<ctype.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int c=0,c2=0,c3=0;
    if(s[0]>='a' && s[0]<='z')
    {
        for(int i=1;s[i]!='\0';i++)
        {
            if(s[i]>='a' && s[i]<='z') c=1;
        }
        if(c==1)
        {
            cout<<s;
            return 0;
        }
        else
        {
            s[0]=toupper(s[0]);
            for(int i=1;s[i]!='\0';i++)
            {
                s[i]=tolower(s[i]);
            }
            cout<<s;
            return 0;
        }
    }
    else if(s[0]>='A' && s[0]<='Z')
    {
        for(int i=1;s[i]!='\0';i++)
        {
            if(s[i]>='a' && s[i]<='z') c2=1;
        }
        if(c2==1)
        {
            cout<<s;
            return 0;
        }
        else
        {
            //s[0]=toupper(s[0])
            for(int i=0;s[i]!='\0';i++)
            {
                s[i]=tolower(s[i]);
            }
            cout<<s;
            return 0;
        }
    }
    else cout<<s;
}
