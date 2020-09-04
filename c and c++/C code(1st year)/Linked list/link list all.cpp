#include<stdio.h>
#include<iostream>

using namespace std;

struct Node
{
    int data;

    Node *prev,*next;
};

Node *head, *tail;


void creatLinkList()
{
    head =NULL;
    tail =NULL;
}


Node * creatNode(int data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


void insertAtBeginning(Node *newNode)

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


void insertAtEnding(Node *newNode)

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


void  traverseForward()
{
    for(Node * current = head ; current != NULL; current= current->next)
    {

        cout<<current->data<<" ";
    }
    cout<<endl;

}


void traverseBackward()
{
    for(Node * current = tail ; current != NULL; current= current->prev)
    {

        cout<<current->data<<" ";
    }

   cout<<endl;

}

void menu()
{
    printf("\n\nEnter Your Choice\n");
    printf("1.Insert At Beginning\n2.Insert at Ending\n");
    printf("3.Traverse From Forward\n4.Traverse From Backward\n");
    printf("5.Search an element by value\n6.Search by Location\n");
    printf("8.Delete First element\n9.Delete an element from middle\n10.Delete last element\n");
}


int main()
{

    menu();

    return 0;

}

