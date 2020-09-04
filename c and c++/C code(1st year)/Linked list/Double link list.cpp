#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int ch,n,linksize=0;

void insert_menu();
void traverse_menu();
void search_menu();
void delete_menu();
void traverseForward();
void main_menu();

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

Node* creatNode(int data)
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


void insertByLocation(int loc,Node* newNode)
{
    Node *current=head;

    for(int i=1;i<=loc;i++)
    {
        if(i==loc)
        {
            newNode->prev=current->prev;
            newNode->next=current;
            current->prev->next=newNode;
            current->prev=newNode;

        }
        current=current->next;
    }
}


void  traverseForward()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\tList is empty\n");
        return;
    }

    printf("\n\t\t\t");
    for(Node * current = head ; current != NULL; current= current->next)
    {
        printf("%d->",current->data);
    }
    printf("\n");

}



void traverseBackward()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\tList is emty\n");
        return;
    }

    printf("\n\t\t\t");
    for(Node * current = tail ; current != NULL; current= current->prev)
    {
        printf("%d->",current->data);
    }

    printf("\n");
}



void searchByValue(int value)
{

    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\tList is Emty  \n");
        return;
    }


    else if(head==tail)
    {
        printf("\n\t\t\tList has only one element\n");
        if(value==head->data)
        {
            printf("\n\t\t\t%d is found in location 1 \n",value);
        }

        else
        {
            printf("\n\t\t\t%d is not in the list\n",value);
        }
        return;
    }



    int loc=1;
    int count=0;

    for(Node* current=head;current!=NULL;current=current->next)
    {
        if(current->data==value)
        {
             printf("\n\t\t\t%d is found in Location %d\n",value,loc);
             count=1;
             break;
        }
        loc++;
    }

    if(count==0)
    {
        printf("\n\t\t\t%d is not found in the list\n",value);
        return;
    }
}


void searchByLocation(int loc)
{

    if(head==NULL && tail==NULL)
    {
        printf("\nList is Emty  \n");
        return;
    }

    else if(head==tail)
    {
        printf("\n\t\t\tList has only one element\n");
        if(loc==1)
        {
            printf("\n\t\t\t%d is found in location 1 \n",head->data);
        }

        else
        {
            printf("\n\t\t\tThis Location is not in the list\n");
        }
        return;
    }

    Node* current=head ;
    int count=0;

     for(int i=1;current!=NULL;i++)
     {
        if(i==loc)
        {
            printf("\n\t\t\t%d is found in location %d\n",current->data,loc);
            count=1;
            break;
        }
        current=current->next;
     }

     if(count==0)
     {
        printf("\n\t\t\tThis location is not in the list\n");
     }
}



void deleteFirstNode()
{

    if(head==tail)
    {
        head=NULL;
        tail=NULL;
        linksize=linksize-1;
        printf("\n\t\t\tSUCCEED\n");
        return;
    }

    Node *nodeToDelete=head;

    head->next->prev=NULL;
    head=head->next;
    free(nodeToDelete);
    linksize=linksize-1;
    printf("\n\t\t\tSUCCEED\n");
}



void deleteLastNode()
{

    if(head==tail)
    {
        head=NULL;
        tail=NULL;
        linksize=linksize-1;
        printf("\n\t\t\tSuccesfully deleted\n");
        return;
    }

    Node* nodeToDelete=tail;

    tail->prev->next=NULL;
    tail=tail->prev;

    free(nodeToDelete);
    linksize=linksize-1;
    printf("\n\t\t\tSUCCEED\n");

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
                printf("\n\t\t\tSUCCEED\n");
                return;
            }
        }
    }
    printf("\n\t\t\t%d is not in the list\n",value);
    return;

}


void deleteByLocation(int loc)
{
    Node *current=head;
    for(int i=1;current!=NULL;i++)
    {
        if(loc==i)
        {
            Node* nodeToDelete=current;

            current->prev=current->next;
            current->next=current->prev;

            free(nodeToDelete);
            linksize=linksize-1;
            printf("\n\t\t\tSUCCEED\n");
            return;
        }
        current=current->next;
    }

    printf("\n\t\t\tThis Location is Not in the list\n");
}

void ascending_sort()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\tList is emty\n");
        main_menu();
        return;
    }

    else if(head==tail)
    {
        printf("\n\t\t\tThe list has only one element. Already sorted \n");
        main_menu();
        return;
    }



    for(Node* current=head;current!=NULL;current=current->next)
    {
        for(Node* current2=current->next;current2!=NULL;current2=current2->next)
        {
            if(current->data>current2->data)
            {
                int temp=current->data;
                current->data=current2->data;
                current2->data=temp;
            }
        }
    }
    printf("\n\t\t\tSucceed\n\n");
}



void main_menu()
{


    printf("\n\n\t\t\tENTER YOUR CHOICE\n\n");
    printf("\n\t\t\t1.Insert\n\t\t\t2.Traverse\n\t\t\t3.Search\n\t\t\t4.Delete\n\t\t\t5.Sort Link List\n\t\t\t6.Exit\n\t\t\t");
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
        ascending_sort();
        break;

        case 6:
        exit(1);

        default:
        printf("\n\t\t\tInvalid input\n");
        main_menu();
    }

}




void insert_menu()
{
    int data;
    printf("\n\n\t\t\t1.Insert At Beginning\n\t\t\t2.Insert at Ending\n\t\t\t3.Insert at middle by previous value\n\t\t\t4.Insert at middle by location\n\t\t\t5.Back   ");
    cin>>ch;

    switch(ch)
    {

        case 1:

            printf("\n\t\t\tHow many data you want to insert???  ");
            scanf("%d",&n);
            linksize=linksize+n;
            for(int i=1;i<=n;i++)
            {
                printf("\n\t\t\tEnter data %d  ",i);
                scanf("%d",&data);

                insertAtBeginning(creatNode(data));

            }
            break;

        case 2:

            printf("\n\t\t\tHow many data you want to insert???  ");
            scanf("%d",&n);
            linksize=linksize+n;
            for(int i=1;i<=n;i++)
            {
                printf("\n\t\t\tEnter data  %d  ",i);
                scanf("%d",&data);

                insertAtEnding(creatNode(data));
            }
            break;

        case 3:
        {

            if(head==NULL && tail==NULL)
            {
                printf("\n\t\t\tList is Empty\n\t\t\tYou have to insert some elements at Begining or Ending\n");
                insert_menu();
                break;
            }

            else if(head==tail)
            {
                printf("\nList has only one element\nYou have to insert some element at Beginning or Ending\n");
                insert_menu();
                break;
            }


            int prevData,data;

            printf("\n\t\t\tEnter previous data : (from the list : ");
            Node* current=head;
            while(current!=NULL)
            {
                printf("%d  ",current->data);
                current=current->next;
            }
            printf(")");
            scanf("%d",&prevData);

            printf("\n\t\t\tEnter data to be insert  ");
            scanf("%d",&data);
            linksize=linksize+1;

            for(Node* current=head;current!=NULL;current=current->next)
            {
                if(current->data==prevData)
                {
                    insertAtMiddle(current, creatNode(data));
                }

            }
            break;
        }

        case 4:

            if(head==NULL && tail==NULL)
            {
                printf("\n\t\t\tList is emty. You have to insert some elements first\n");
                insert_menu();
                return;
            }

            else if(head==tail)
            {
                printf("\n\t\t\tList has only one element. You have to insert some elements at Beginning or Ending\n");
                insert_menu();
                return;
            }

            int loc;

            printf("\n\t\t\tEnter a valid (2-%d) Location to insert data\n ",linksize);
            scanf("%d",&loc);

            if(loc<2 || loc>linksize)
            {
                printf("\n\t\t\tInvalid Location.\n");
                break;
            }
            printf("\n\t\t\tEnter data to insert\n");
            scanf("%d",&data);

            insertByLocation(loc,creatNode(data));
            linksize=linksize+1;
            break;

        case 5:
            main_menu();
            break;

        default:
            printf("\n\t\t\tWrong input. Please Enter a valid number   ");
            insert_menu();
            break;
    }

     main_menu();
}




void traverse_menu()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\tList is empty\n");
        main_menu();
        return;
    }

    printf("\n\t\t\t1.Traverse From Forward\n\t\t\t2.Traverse From Backward\n\t\t\t3.Back ");
    cin>>ch;

    switch(ch)
    {
        case 1:
        {
            traverseForward();
            main_menu();
            break;

        }

        case 2:
        {
            traverseBackward();
            main_menu();
            break;
        }

        case 3:
        {
            main_menu();
            break;
        }

        default:
        {
            printf("\n\t\t\tWrong Input. Please enter a valid number\n");
            traverse_menu();
            break;
        }
    }
}



void search_menu()
{

    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\tList is Empty.\n");
        main_menu();
        return;
    }

    else if(head==tail)
    {
        printf("\n\t\t\tList has only one element : %d\n",head->data);
        main_menu();
        return;
    }


    printf("\n\n\t\t\t1.Search by value\n\t\t\t2.Search by Location\n\t\t\t3.Back");
    cin>>ch;

    switch(ch)
    {
        case 1:
        {
            int value;
            printf("\n\t\t\tEnter the value to search: ");
            scanf("%d",&value);
            searchByValue(value);
            break;
        }
        case 2:

            int loc;
            printf("\n\t\t\tEnter a valid (1-%d) Location to search   ",linksize);
            scanf("%d",&loc);
            searchByLocation(loc);
            break;

        case 3:

            main_menu();
            break;

        default:
            printf("\n\t\t\tWrong Input. Please Enter a valid number.\n\n");
            search_menu();
            break;
    }
    main_menu();
}





void delete_menu()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\tList is Empty\n");
        main_menu();
        return;
    }

    printf("\n\n\t\t\t1.Delete First element\n\t\t\t2.Delete last element\n\t\t\t3.Delete an element from middle by value\n\t\t\t4.Delete an element by Location\n\t\t\t5.Back      ");
    scanf("%d",&ch);

    switch(ch)
    {

        case 1:
            deleteFirstNode();
            break;

        case 2:
            deleteLastNode();
            break;

        case 3:
            int value;

            if(head==tail)
            {
                printf("\n\t\t\tThe list has only one element.\n\t\t\tYou can delete it by selecting other delete option\n\n");
                delete_menu();
                return;
            }

            printf("\n\t\t\tEnter the value to delete  ");
            scanf("%d",&value);
            deleteFromMiddle(value);
            break;

        case 4:

            if(head==tail)
            {
                printf("\n\t\t\tThe list has only one element.\n\t\t\tYou can delete it by selecting other delete option\n\n");
                main_menu();
                return;
            }

            int loc;

            printf("\n\t\t\tEnter a valid (1-%d) Location to delete   ",linksize);
            scanf("%d",&loc);
            deleteByLocation(loc);
            break;

        case 5:
                main_menu();
                break;
        default:
            printf("\n\t\t\tInvalid Input\n\n");
            delete_menu();
            break;
   }
   main_menu();
}

int main()
{
    printf("\n\n\t\t\t\tWELCOME TO LINKED LIST OPERATIONS\n\n\n");
    creatLinkList();
    main_menu();
    return 0;
}
