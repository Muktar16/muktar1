#include<iostream>

using namespace std;

void insert(int item);
void display();

int arr[100],heapsize;

int main()
{
    heapsize=0;
    int choice,item;

    while(1)
    {
        cout<<"\n1.Insert at heap\n2.Delete\n3.Display\n4.Heapify\n5.Heapsort\n\nEnter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"\nEnter an element to insert :  ";
            cin>>item;
            insert(item);
            break;
        case 3:
            display();
            break;
        }
    }
}


void insert(int item)
{
    int p,l,r,largest,temp;

    heapsize=heapsize+1;
    arr[heapsize]=item;

    for(p=heapsize/2;p>0;p=p/2)
    {
        l=p*2;
        r=p*2+1;

        if(l<=heapsize && arr[l]>arr[p]) largest = l;
        else largest = p;

        if(r<=heapsize && arr[r]>arr[largest]) largest = r;

        if(largest!=p)
        {
            temp = arr[largest];
            arr[largest]= arr[p];
            arr[p]=temp;
        }
    }
}

void display()
{
    if (heapsize == 0)
    {
        cout<<"\n\nHeap is empty \n";
        return;
    }
    for(int i=1;i<=heapsize;i++) cout<<arr[i]<<"  ";
    cout<<"\n";
}
