#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char str[n];
    cin>>str;
    int c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='x')
        {
            c1++;
        }
        else c1=0;
        if(c1>=3) c2++;
    }
    cout<<c2;
}
