#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>

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


int main()
{

cout<<"======================================="<<endl;
cout<<"***************************************"<<endl;
cout<<"________Welcome to this program________"<<endl;
cout<<"***************************************"<<endl;
cout<<"======================================="<<endl;




    int n;


    int input;

    int i;
    creatLinkList();


   cout<<"Now start insert at beginning program........."<<endl<<endl;
   cout<<"How many numbers you want to "<<endl;
   cout<<"insert at beginning >>>>>>>";


    cin>>n;

    cout<<"Please put your input :";


    for(i=0; i<n; i++)
    {

        cin>>input;


        insertAtBeginning(creatNode(input));

    }

    cout<<"Traverse_ _ from_ _ Forward"<<endl;
    traverseForward();
  cout<<"Traverse_ _ from_ _ Backward"<<endl;
    traverseBackward();
    cout<<endl;

    cout<<"Now start insert at ending program........."<<endl<<endl;
   cout<<"How many numbers you want to "<<endl;
   cout<<"insert at ending >>>>>>>";


    cin>>n;

    cout<<"Please put your input :";

    for(i=0; i<n; i++)
    {

        cin>>input;


        insertAtEnding(creatNode(input));

    }

  cout<<"Traverse_ _ from_ _ Forward"<<endl;
    traverseForward();
   cout<<"Traverse_ _ from_ _ Backward"<<endl;
    cout<<endl;
    traverseBackward();




    return 0;

}
