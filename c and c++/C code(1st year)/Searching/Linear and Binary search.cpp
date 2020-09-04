#include<iostream>
using namespace std;

int n,*arr;

void linear_search(int *arr);
void binary_search(int *arr);
int ifsorted(int *arr);

int main()
{
    cout<<"\n\nEnter the number of elements  \n";
    cin>>n;

    int* arr=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    if(ifsorted(arr)==1)
    {
        cout<<"\n\nThe list is Sorted\n\n";
        binary_search(arr);
        return 0;
    }

    else
    {
        cout<<"\n\nThe list is Unsorted\n\n";
        linear_search(arr);
        return 0;
    }

}



int ifsorted(int *arr)
{
    int i;

    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            return 0;
        }
    }
    return 1;
}



void linear_search(int *arr)
{
    int item,i,count1=1;

    cout<<"\n\nEnter the element to search \n\n";
    cin>>item;

    for(i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            cout<<"\n\n"<<item<<" is Found in Location "<<i+1<<"\n\n";
            count1=0;
        }
    }

    if(count1){
    cout<<"\n\n"<<item<<" is not found\n\n";
    }
}



void binary_search(int *arr)
{
    int beg=0,fin=n-1,mid=(beg+fin)/2,item;

    cout<<"\n\nEnter the item to search \n\n";
    cin>>item;

    while(beg<=fin && arr[mid]!=item)
    {
        if(arr[mid]>item)
        {
            fin=mid-1;
            mid=(beg+fin)/2;
        }

        else
        {
            beg=mid+1;
            mid=(fin+beg)/2;
        }
    }

    if(arr[mid]==item)  cout<<"\n\n"<<item<<" is found in location "<<mid+1<<"\n\n";
    else cout<<"\n\n"<<item<<" is not found\n\n";
}
