#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char str[1005];
    gets(str);
    int n=strlen(str);
    int ch[26]={0};
    for(int i=1;i<n-1;i=i+3)
    {
        ch[str[i]-'a']=1;
    }
    int c=0;
    for(int i=0;i<26;i++)
    {
        if(ch[i]==1) c++;
    }
    cout<<c;
}
