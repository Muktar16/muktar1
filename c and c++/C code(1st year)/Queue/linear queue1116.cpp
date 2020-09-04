#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int queue_size,Front=-1,Rear=-1,*Queue;

void menu();
void EnQueue();
int DeQueue();
void display();

int main(void)
{

    printf("\nEnter the size of queue   ");
    scanf("%d",&queue_size);

    Queue=new int [queue_size];
    menu();
}


void menu()
{
    int ch,item;

    printf("\n\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit   ");
    scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            EnQueue();
            break;

            case 2:
            item=DeQueue();
            if(item==-5)
            {
                printf("\nQueue is Underflow\n\n");
                menu();
                break;
            }
            printf("\n%d is deleted\n",item);
            menu();
            break;

            case 3:
            display();
            break;

            case 0:
            exit(1);

            default:
            printf("\n Wrong input. Please enter a valid number  \n");
        }
        menu();
}

void EnQueue()
{
    int item;
    if(Rear==queue_size-1)
    {
        printf("\nQueue is Overflow  \n");
    }

    else
    {
        if(Front==-1)
        {
            Front=0;
        }

        printf("Enter item to EnQueue : ");
        scanf("%d",&item);

        Rear++;
        Queue[Rear]=item;
        printf("\nSuccessful\n\n");
    }
    menu();
}

int DeQueue()
{
    int item;

    if(Front==-1 || Front>Rear)
    {
        return -5;
    }

    item = Queue[Front];

    if(Front==Rear)
    {
        Front=-1;
        Rear=-1;
    }
    else
    {
        Front++;
    }

    return item;
}

void display()
{
    int iterator;

    if(Front==-1)
    {
        printf("\nNo Elements\n");
    }

    else
    {
        printf("\nThe list is : ");
        for(iterator=Front;iterator<=Rear;iterator++)
        {
            printf("%d    ",Queue[iterator]);
        }
        printf("\n\n");
    }
    menu();
}
