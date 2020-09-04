#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string str1,str2;
    cin>>str1;
    cin>>str2;
    for(int i=0;str1[i]!='\0';i++)
    {
        if(str1[i]==str2[i]) cout<<0;
        else cout<<1;
    }

}
