#include<iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main()
{
    int n;
    int count = 0;
    cin>>n;
    char str[n+1];
    cin>>str;
    if(n<26) cout<<"NO";
    else
    {
        int a[26]={0};
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                str[i]=tolower(str[i]);
            }
        }
        for(int i=0;str[i]!='\0';i++)
        {
            int j = str[i]-'a';
            if(a[j]!=1)
            {
                count++;
                a[j]=1;
            }
        }
        if(count==26) cout<<"YES";
        else cout<<"NO";
    }

}
