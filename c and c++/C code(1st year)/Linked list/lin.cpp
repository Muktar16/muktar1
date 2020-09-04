#include<iostream>
using namespace std;

int ifsorted(int *ara);
int n;
void linearSearch(int element,int *ara);
void binarySearch(int element,int *ara);

int main(void)
{
    int *ara,element=0;
    cout<<"How many element you want to input:";
    cin>>n;

    ara = new int [n];

    cout<<"Enter "<<n<<" element in the array: ";

    for(int i=0; i<n; i++)
        cin>>ara[i];

    int result=ifsorted(ara);

    if(result==0)
    cout<<"Unsorted"<<endl;
    else
        cout<<"Sorted"<<endl;

    cout<<"Enter the element do you want to search: ";
    cin>>element;

    if(result==0)
        linearSearch(element,ara);
    else
        binarySearch(element,ara);

        return 0;
}

int ifsorted(int *ara)
{
    int i=0;
    while(i<n-1)
    {
        if(ara[i]>ara[i+1])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void linearSearch(int element,int *ara)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        if(ara[i]==element)
        {
            cout<<element<<" is found in position no: "<<i+1<<endl;
            return;
        }
    }
    cout<<element<<" is not found in the array.";
}

void binarySearch(int element,int *ara)
{
    int low=0,high=n-1,mid=0;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(element==ara[mid])
        {
            cout<<element <<" is found in position no: "<<mid+1;
            return;
        }
        else if(element<ara[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<element<<" is not found in the array.";
}
