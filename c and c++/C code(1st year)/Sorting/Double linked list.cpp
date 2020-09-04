#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int ch,n;

void insert_menu();
void traverse_menu();
void search_menu();
void delete_menu();
void traverseForward();


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



void insertAtMiddle(Node *previous, Node *newNode)
{

    newNode->prev=previous;
    newNode->next=previous->next;
    previous->next->prev=newNode;
    previous->next=newNode;
}




void  traverseForward()
{
    for(Node * current = head ; current != NULL; current= current->next)
    {

        cout<<current->data<<"->";
    }
    cout<<endl;

}



void traverseBackward()
{
    for(Node * current = tail ; current != NULL; current= current->prev)
    {

        cout<<current->data<<"->";
    }

   cout<<endl;

}



void searchByValue(int value)
{

    int loc=1;
    for(Node* current=head;current!=NULL;current=current->next)
    {
        if(current->data==value)
        {
             printf("\n\t\t\t%d is found in Location %d\n",value,loc);
             break;
        }
        loc++;
    }
}




void searchByLocation(int loc)
{
    Node* current=head ;

     for(int i=1;i<=loc;i++)
     {
        if(i==loc)
        {
            printf("\n\t\t\t%d is found in location %d\n",current->data,loc);
            break;
        }
        current=current->next;
     }
}



void deleteFirstNode()
{
    Node* NodeToDelete=head;
    head->next->prev=NULL;
    head=head->next;
    free(NodeToDelete);
}



void deleteLastNode()
{
    Node* NodeToDelete=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(NodeToDelete);
}


void deleteFromMiddle(int value)
{
    if(head->data==value) deleteFirstNode();
    else if(tail->data==value) deleteLastNode();

    else
    {
        for(Node* current=head->next;current!=NULL;current=current->next)
        {
            if(current->data==value)
            {
                current->prev->next=current->next;
                current->next->prev=current->prev;
                break;
            }
        }
    }
}


void main_menu()
{


    printf("\n\n\t\t\tENTER YOUR CHOICE\n\n");
    printf("\n\t\t\t1.Insert\n\t\t\t2.Traverse\n\t\t\t3.Search\n\t\t\t4.Delete\n\t\t\t5.Exit\n\t\t\t");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        insert_menu();
        break;

        case 2:
        traverse_menu();
        break;

        case 3:
        search_menu();
        break;

        case 4:
        delete_menu();
        break;

        case 5:
        exit(1);
        break;

        default:
            printf("\n\t\t\tWrong Input. Please Enter a write number   ");
            main_menu();
            break;
    }

}




void insert_menu()
{
     int data;

    printf("\n\n\t\t\t1.Insert At Beginning\n\t\t\t2.Insert at Ending\n\t\t\t3.Insert at middle\n\t\t\t4.Back    ");
    cin>>ch;

    switch(ch)
    {

        case 1:
        {
            printf("\n\t\t\tHow many data you want to insert???  ");
            scanf("%d",&n);

            for(int i=1;i<=n;i++)
            {
                printf("\n\t\t\tEnter data %d  ",i);
                scanf("%d",&data);

                insertAtBeginning(creatNode(data));

            }
            break;
        }


        case 2:
        {
            printf("\n\t\t\tHow many data you want to insert???  ");
            scanf("%d",&n);

            for(int i=1;i<=n;i++)
            {
                printf("\nEnter data  %d  ",i);
                scanf("%d",&data);

                insertAtEnding(creatNode(data));

            }
            break;
        }


        case 3:
        {
            if()

            int prevData,data;

            printf("\n\t\t\tEnter previous data  ");
            scanf("%d",&prevData);

            printf("\n\t\t\tEnter data to be insert  ");
            scanf("%d",&data);

            for(Node* current=head;current!=NULL;current=current->next)
            {
                if(current->data==prevData)
                {
                    insertAtMiddle(current, creatNode(data));
                }

            }
            break;
        }


    }

     main_menu();
}




void traverse_menu()
{

    printf("\t\t\t1.Traverse From Forward\n\t\t\t2.Traverse From Backward  ");
    cin>>ch;

    if(ch==1)
    {
        traverseForward();
        main_menu();

    }
    else if(ch==2)
    {
        traverseBackward();
        main_menu();
    }
}



void search_menu()
{
    printf("\t\t\t1.Search an element by value\n\t\t\t2.Search by Location   ");
    cin>>ch;

    if(ch==1)
    {
        int value;

        printf("\n\t\t\tEnter the value to search   ");
        scanf("%d",&value);

        searchByValue(value);
    }

    else if(ch==2)
    {
        int loc;

        printf("\n\t\t\tEnter the Location to search   ");
        scanf("%d",&loc);

        searchByLocation(loc);
    }

    main_menu();
}




void delete_menu()
{

    printf("\t\t\t1.Delete First element\n\t\t\t2.Delete last element\n\t\t\t3.Delete an element from middle   ");
    scanf("%d",&ch);

    if(ch==1)
    {
        deleteFirstNode();
        printf("\n\t\t\tSuccessfully deleted  \n");
    }

    else if(ch==2)
    {
        deleteLastNode();
        printf("\n\t\t\tSuccessfully deleted  \n");

    }

    else if(ch==3)
    {

        int value;

        printf("\n\t\t\tEnter the value to delete  ");
        scanf("%d",&value);

        deleteFromMiddle(value);
        printf("\n\t\t\tSuccessfully deleted  \n");
    }

    main_menu();

}


int main()
{

    printf("\n\n\t\t\t\tWELCOME TO LINKED LIST OPERATIONS\n");
    creatLinkList();

    main_menu();

    return 0;

}
