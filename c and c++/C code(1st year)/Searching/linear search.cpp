#include<iostream>
using namespace std;

int arr[10];
int n,i,item;

int ifsorted(int* arr);
void binary_Search(int *arr,int item);
void linear_Search(int *arr,int item);

int main()
{

    cout<<"How many items you want to input?   ";
    cin>>n;

    int* arr=new int[n];

    cout<<"\n\nEnter elements  ";
    for(i=0;i<n;i++)
    {
         cin>>arr[i];
    }



    if(ifsorted(arr))
    {

        cout<<"\n\nEnter the number you want to search\n";
        cin>>item;

        binary_Search(arr,item);
        return 0;
    }
    else
    {

        cout<<"\n\nEnter the number you want to search\n";
        cin>>item;

        linear_Search(arr,item);
        return 0;
    }


}



int ifsorted(int *arr)
{
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<"\n\nThe list is Unsorted\n";
            return 0;
        }
    }
    cout<<"\n\nThe list is Sorted ";
    return 1;
}




void linear_Search(int* arr, int item)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            cout<<endl<<item<<" is found in Location: "<<i+1;
            exit(1);
        }

    }
    cout<<endl<<item<<" is not found ";
}



void binary_Search(int *arr,int item)
{
    int first=0,last=n-1,mid=(first+last)/2;

    while(first<last)
    {
        if(arr[mid]==item)
        {
            cout<<endl<<item<<" is found in Location: "<<mid+1;
            exit(1);
        }
        else if(arr[mid]>item)
        {
            last=mid;
            mid=(first+last)/2;
        }

        else
        {
            first=mid;
            mid=(first+last)/2;

        }
    }
    cout<<endl<<item<<" is not found\n";

    }

