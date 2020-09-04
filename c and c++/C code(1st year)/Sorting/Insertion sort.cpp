#include<iostream>
using namespace std;

int main()
{
    int n,item,i,j;
    cout<<"Enter the number of elements ";
    cin>>n;

    int arr[n];

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=1;i<n;i++)
    {
        item=arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(item<arr[j]) arr[j+1]=arr[j];
        }
        arr[j]=item;//if use while loop then j will be replaced by j+1
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<"  ";
}
