#include<stdio.h>
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    node *prev,*next;
};

node *head, *tail;


void creatLinkList()
{
    head =NULL;
    tail =NULL;
}


node * creatNode(int data)
{
    node *newNode = new node;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;


}

void deleteFirstNode()
{

}


void insertAtBeginning(node *newNode)

{

    if(head==NULL&&tail==NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

}

void insertAtEnding(node *newNode)

{

    if(head==NULL&&tail==NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

}

insertAfterNode(node* previous,node *newNode)
{
    newNode->next=previous->next;
    newNode->prev=previous;
    previous->next->prev=newNode;
    previous->next=newNode;

}


void  traverseForward()
{


    for(node * current = head ; current != NULL; current= current->next)
    {

        printf("%d->",current->data);
    }
    printf("\n\n");

}

void traverseBackward()
{
    for(node * current = tail ; current != NULL; current= current->prev)
    {
        printf("%d->",current->data);
    }
    printf("\n\n");

}

node *searchNode(int value)
{
    for(node* current=head;current!=NULL;current=current->next)
    {
        if(current->data==value) return current;
    }
    return NULL;
}

void menu()
{
    printf("\nEnter your choice\n");
    printf("1.Insert at Beginning\n2.Insert at Ending\n");
    printf("3.Traverse from forward\n4.Traverse from backward\n");
    printf("5.Search an element\n");
    printf("6.Delete First element\n7.Delete an element from Middle\n");
    printf("")

}


int main()
{

    creatLinkList();

    menu;

    return 0;

}


