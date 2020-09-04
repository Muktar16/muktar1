#include<iostream>

using namespace std;
int n;

void selection_sort(int* arr);

int main()
{

    cout<<"Enter the number of elements  ";
    cin>>n;

    int* arr=new int[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    selection_sort(arr);
    return 0;
}

void selection_sort(int* arr)
{
    int i,j,index_min;

    for(i=0;i<n;i++)
    {
        index_min=i;

        for(j=i;j<n;j++)
        {
            if(arr[j]<arr[i]) index_min=j;
        }

        if(index_min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[index_min];
            arr[index_min]=temp;
        }
        cout<<"\nAfter sort "<<i+1<<" the array is: ";
        for(int k=0;k<n;k++) cout<<arr[k]<<" ";
    }
}

