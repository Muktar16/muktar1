#include<iostream>
#include<stdlib.h>

using namespace std;
int *arr,Max_size;
int Front=-1,rear=-1;

void EnQueue(int item)
{
    if(Front==-1)
    {
        Front=0;
    }

    else if(rear==Max_size-1)
    {
        cout<<"\nList is full";
        return;
    }

    rear++;
    arr[rear]=item;
    return;
}

void DeQueue()
{
    if(Front==-1)
    {
        cout<<"\nList is empty";
        return;
    }

    else if(rear==Front)
    {
        rear=Front=-1;
        cout<<"\nDeleted Successfully";
        return;
    }

    Front=Front+1;
    cout<<"\nDeleted Successfully\n";
    return;
}


void display()
{
    if(Front==-1)
    {
        cout<<"\nList is empty";
        return;
    }

    for(int i=Front;i<=rear;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return;
}

void menu()
{
    int ch,item;
    cout<<"\n1.EnQueue\n2.DeQueue\n3.display\n4.exit\n\nEnter your choice";
    cin>>ch;

    switch(ch)
    {
        case 1:
        cout<<"\nEnter item to enqueue : ";
        cin>>item;
        EnQueue(item);
        break;

        case 2:
        DeQueue();
        break;

        case 3:
        display();
        break;

        case 4:
        exit(1);

    }
    menu();
}

int main()
{
    cout<<"\nEnter size : ";
    cin>>Max_size;

    arr=new int[Max_size];

    menu();
}
