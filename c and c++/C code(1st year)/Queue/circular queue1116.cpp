#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int queue_size, Front, Rear, *Queue;

void EnQueue();
int  DeQueue();
void display();
void menu();

void EnQueue()
{
    int item;
    printf("\nEnter item to Enqueue  ");
    scanf("%d",&item);

    if(Front == -1)
    {
        Front=0;
        Rear=0;
        Queue[Rear]=item;
    }

    else if((Rear==queue_size-1 && Front==0) || Rear==Front-1)
    {
        printf("\nQueue is Overflow");
        return;
    }

    else if(Rear == queue_size-1 && Front!= 0)
    {
        Rear = 0;
        Queue[Rear] = item;
    }
    else
    {
        Rear++;
        Queue[Rear] = item;
    }

    printf("\nSuccessful\n");
}

int DeQueue()
{
    int item;

    if(Front==-1)
    {
        return -5;
    }

    item=Queue[Front];

    if(Front==Rear)
    {
        Front = Rear = -1;
    }
    else if(Front == queue_size-1)
    {
        Front = 0;
    }
    else
    {
        Front++;
    }
    return item;
}

void menu()
{
    int ch,item;
    printf("\n1.EnQueue\n2.DeQueue\n3.Display Queue\n4.Exit    ");
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
            printf("\nQueue is underflow\n");
            break;
        }
        printf("\n%d is deleted\n",item);
        break;

        case 3:
        display();
        break;

        case 4:
        exit(1);

        default:
        printf("\nWrong Input. Enter a valid number\n");
    }
    menu();
}


int main(void)
{
    printf("\nEnter the size of queue   ");
    scanf("%d",&queue_size);

    Front=-1;
    Rear= -1;

    Queue = new int [queue_size];
    menu();
    return 0;
}


void display()
{
    int i;
    if(Front==-1)
    {
        printf("\nNo elements \n");
        return;
    }

    printf("\nthe list is : ");
    if(Rear >= Front)
    {
        for(i=Front;  i<=Rear;  i++)
        {
            printf("%d     ",Queue[i]);
        }
        printf("\n\n");
    }

    else
    {
        for(i=Front; i<queue_size; i++)
        {
            printf("%d     ",Queue[i]);
        }

        for(i=0;  i<=Rear;  i++)
        {
            printf("%d    ",Queue[i]);
        }
        printf("\n\n");
    }
}
