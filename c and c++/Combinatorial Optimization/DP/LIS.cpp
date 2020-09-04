#include<iostream>

using namespace std;

int find_max(int *arr,int n)
{
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m) m=arr[i];
    }
    return m;
}

int lis(int *arr, int n)
{
    int lis[n];
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }

    return find_max(lis,n);
}

int main()
{
    int n;
    cin>>n;
    int item[n];

    for(int i=0;i<n;i++)
    {
        cin>>item[i];
    }

    cout<<lis(item,n);
}
