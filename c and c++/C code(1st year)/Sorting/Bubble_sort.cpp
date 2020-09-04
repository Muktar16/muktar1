#include<iostream>
using namespace std;

int *arr;
int n;

void bubble_sort(int *arr);

int main()
{
    cout<<"Enter number of elements ";
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    bubble_sort(arr);

    return 0;
}


void bubble_sort(int *arr)
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        int b=n-i-1;
        for(j=0;j<b;j++)
        {
             if(arr[j+1]<arr[j])
             {
                 int temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
             }
        }

        cout<<endl<<"The array after sorting proccess "<<i+1<<":  ";
        for(k=0;k<n;k++) cout<<arr[k]<<" ";
    }
    cout<<"\n\n";

}
