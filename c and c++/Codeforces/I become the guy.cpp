#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n,p,q;
    cin>>n;
    int arr[n];

    cin>>p;
    int pa[p];

    for(int i=0;i<p;i++)
    {
        cin>>pa[i];
        arr[pa[i]-1]=1;
    }

    cin>>q;
    int qa[q];
    for(int i=0;i<q;i++)
    {
        cin>>qa[i];
        arr[qa[i]-1]=1;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=1)
        {
            cout<<"I become the guy.";
            count=1;
            break;
        }
    }
    if(count!=1) cout<<"Oh, my keyboard!";


}
