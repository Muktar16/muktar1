#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct person{
    char name[50];
    int priority;
    person *next;
};

person *Front=NULL;

void insert_queue(char name[50],int priority)
{
    person *NewNode;

    NewNode=new person;
    strcpy(NewNode->name,name);
    NewNode->priority=priority;
    NewNode->next=NULL;

    if(Front==NULL || priority<Front->priority)
    {
        NewNode->next=Front;
        Front=NewNode;
    }
    else
    {
        person *current=Front;
        for(;  current->next!=NULL && current->next->priority <= priority; current = current->next);

        NewNode->next=current->next;
        current->next=NewNode;
    }
}

void delete_queue()
{
    if(Front==NULL)
    {
        printf("\nQueue is empty. No element to delete\n");
        return;
    }
    person *NodeToDelete = Front;
    Front=Front->next;
    free(NodeToDelete);
    printf("\nSuccessfully deleted\n");
}

void display()
{
    if(Front==NULL)
    {
        printf("\nQueue is empty  ");
        return;
    }

    printf("\n\nPriority\t   Name");
    for(person *current=Front;  current!=NULL;  current=current->next)
    {
        printf("\n   %d\t     %s",current->priority, current->name);
    }
    printf("\n\n");
}

void menu()
{
    int ch,priority;
    char name[50];
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice :   ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter your name  :  ");
                scanf("%s",name);
                printf("\nEnter priority :  ");
                scanf("%d",&priority);
                insert_queue(name,priority);
                break;
            case 2:
                delete_queue();
                break;
            case 3:
                display();
                break;

        }
    }while(ch!=4);
}

int main()
{
    menu();
}
