#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int ch,n,linksize=0,go=0;

void insert_menu();
void traverse_menu();
void search_menu();
void delete_menu();
void traverseForward();
void main_menu();
int main();

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
        printf("\n\t\t\t\t\tNO ELEMENTS TO TRAVERSE\n");
        return;
    }

    printf("\n\t\t\t\t\t");
    for(Node * current = head ; current != NULL; current= current->next)
    {
        printf("%d    ",current->data);
    }
    printf("\n");
}

void traverseBackward()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\t\t\tCANNOT TRVERSE AS LIST IS EMPTY\n");
        return;
    }

    printf("\n\t\t\t\t\t");
    for(Node * current = tail ; current != NULL; current= current->prev)
    {
        printf("%d    ",current->data);
    }

    printf("\n");
}



void searchByValue(int value)
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\t\t\tNO ELEMENTS TO SEARCH \n");
        return;
    }
    else if(head==tail)
    {
        printf("\n\t\t\t\t\tLIST HAS ONLY ONE ELEMENT\n");
        if(value==head->data)
        {
            printf("\n\t\t\t\t\t%d IS FOUND IN LOCATION 1 \n",value);
        }
        else
        {
            printf("\n\t\t\t\t\t%d IS NOT IN THE LIST\n",value);
        }
        return;
    }

    int loc=1;
    int count=0;
    for(Node* current=head;current!=NULL;current=current->next)
    {
        if(current->data==value)
        {
             printf("\n\t\t\t\t\t%d IS FOUND IN LOCATION %d\n",value,loc);
             count=1;
             break;
        }
        loc++;
    }

    if(count==0)
    {
        printf("\n\t\t\t\t\t%d IS NOT IN THE LIST\n",value);
        delete_menu();
        return;
    }
}

void searchByLocation(int loc)
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\t\t\tLIST HAS NO ELEMENT TO SEARCH\n");
        return;
    }
    else if(head==tail)
    {
        printf("\n\t\t\t\t\tLIST HAS ONLY ONE ELEMENT\n");
        if(loc==1)
        {
            printf("\n\t\t\t\t\t%d IS FOUND IN LOCATION 1 \n",head->data);
        }

        else
        {
            printf("\n\t\t\t\t\tTHIS LOCATION IS NOT IN THE LIST\n");
            delete_menu();
        }
        return;
    }

    Node* current=head ;
    int count=0;

     for(int i=1;current!=NULL;i++)
     {
        if(i==loc)
        {
            printf("\n\t\t\t\t\t%d IS FOUND IN LOCATION %d\n",current->data,loc);
            count=1;
            break;
        }
        current=current->next;
     }

     if(count==0)
     {
        printf("\n\t\t\t\t\tTHIS LOCATION IS NOT IN THE LIST\n");
     }
}



void deleteFirstNode()
{

    if(head==tail)
    {
        free(head);
        free(tail);
        head=NULL;
        tail=NULL;
        linksize=linksize-1;
        printf("\n\t\t\t\t\tSUCCEED\n");
        return;
    }

    Node *nodeToDelete=head;

    head->next->prev=NULL;
    head=head->next;
    free(nodeToDelete);
    linksize=linksize-1;
    printf("\n\t\t\t\t\tSUCCEED\n");
}

void deleteLastNode()
{

    if(head==tail)
    {
        free(head);
        free(tail);
        head=NULL;
        tail=NULL;
        linksize=linksize-1;
        printf("\n\t\t\t\t\tSUCCESSFULLY DELETED\n");
        return;
    }

    Node* nodeToDelete=tail;

    tail->prev->next=NULL;
    tail=tail->prev;

    free(nodeToDelete);
    linksize=linksize-1;
    printf("\n\t\t\t\t\tSUCCEED\n");

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
                Node *nodeToDelete=current;
                current->prev->next=current->next;
                current->next->prev=current->prev;
                free(nodeToDelete);
                linksize-=1;
                printf("\n\t\t\t\t\tSUCCEED\n");
                return;
            }
        }
    }
    printf("\n\t\t\t\t\t%d IS NOT IN THE LIST\n",value);
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

    printf("\n\t\t\t\t\tTHIS LOCATION IS NOT IN THE LIST\n");
}

void delete_linked_list()
{
    for(Node* current=head;current!=NULL;current=current->next)
    {
        free(current);
    }
    head=NULL;
    tail=NULL;
    linksize=0;
    go=1;
    printf("\n\t\t\t\t\tLINKED LIST HAS BEEN DELETED. NOW CREATE NEW LINKED LIST.\n\t\t\t\t\tENTER SIZE OF LINKED LIST  ");
    main();
}

void ascending_sort()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\t\t\tLIST IS EMPTY\n");
        main_menu();
        return;
    }

    else if(head==tail)
    {
        printf("\n\t\t\t\t\tTHE LIST HAS ONLY ONE ELEMENT WHICH IS ALREADY\n");
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
     printf("\n\t\t\t\t\tSUCCESSFULLY SORTED\n\n");
     main_menu();
}

void delete_menu()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\t\t\tDELETE COMMAND CANNOT BE PERFORMED AS THE LIST IS EMPTY\n");
        main_menu();
        return;
    }

    printf("\n\n\t\t\t\t\t1.DELETE FIRST NODE\n\t\t\t\t\t2.DELETE LAST NODE\n\t\t\t\t\t3.DELETE A NODE FROM MIDDLE BY VALUE\n\t\t\t\t\t4.DELETE A NODE BY LOCATION\n\t\t\t\t\t5.DELETE FULL LINKED LIST\n\t\t\t\t\t6.BACK      ");
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
                printf("\n\t\t\t\t\tTHE LIST HAS ONLY A SINGLE DATA. SELECT OTHER DELETE OPTION\n");
                delete_menu();
                return;
            }

            printf("\n\t\t\t\t\tENTER THE VALUE TO DELETE   ");
            scanf("%d",&value);
            deleteFromMiddle(value);
            break;

        case 4:

            if(head==tail)
            {
                printf("\n\t\t\t\t\tTHE LIST HAS ONLY A SINGLE DATA. SELECT OTHER DELETE OPTION\n");
                delete_menu();
                return;
            }

            int loc;

            printf("\n\t\t\t\t\tENTER A VALID (1-%d) LOCATION   ",linksize);
            scanf("%d",&loc);
            deleteByLocation(loc);
            break;
        case 5:
            delete_linked_list();
            break;

        case 6:
                main_menu();
                break;
        default:
            printf("\n\t\t\t\t\tINVALID INPUT. PLEASE ENTER A VALID NUMBER\n");
            delete_menu();
            break;
   }
   delete_menu();
}

void search_menu()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\t\t\tNO ANY ELEMENT TO SEARCH.\n");
        main_menu();
        return;
    }

    else if(head==tail)
    {
        printf("\n\n\t\t\t\t\tLIST HAS ONLY ONE ELEMENT : %d \n",head->data);
        main_menu();
        return;
    }
    printf("\n\n\t\t\t\t\t=> SEARCH MENU\n\n\t\t\t\t\t1.SEARCH LOCATION BY VALUE\n\t\t\t\t\t2.SEARCH VALUE BY LOCATION\n\t\t\t\t\t3.BACK     ");
    printf("%d",&ch);

    switch(ch)
    {
        case 1:
        {
            int value;
            printf("\n\t\t\t\t\tENTER THE VALUE TO SEARCH : ");
            scanf("%d",&value);
            searchByValue(value);
            break;
        }
        case 2:
            int loc;
            printf("\n\t\t\t\t\tENTER A VALID (1-%d) LOCATION TO SEARCH : ",linksize);
            scanf("%d",&loc);
            searchByLocation(loc);
            break;

        case 3:
            main_menu();
            break;
        default:
            printf("\n\t\t\t\t\tINVALID INPUT. PLEASE ENTER A VALID NUMBER ");
            search_menu();
            break;
    }
    main_menu();
}


void traverse_menu()
{
    if(head==NULL && tail==NULL)
    {
        printf("\n\t\t\t\t\tNO ELEMENTS TO TRAVERSE ");
        main_menu();
        return;
    }

    printf("\n\t\t\t\t\t=> TRAVERSE MENU\n\n\t\t\t\t\t1.TRAVERSE FROM FORWARD\n\t\t\t\t\t2.TRAVERSE FROM BACKWARD\n\t\t\t\t\t3.BACK     ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        {
            traverseForward();
            traverse_menu();
            break;
        }
        case 2:
        {
            traverseBackward();
            traverse_menu();
            break;
        }
        case 3:
        {
            main_menu();
            break;
        }
        default:
        {
            printf("\n\t\t\t\t\tINVALID INPUT. PLEASE ENTER A VALID NUMBER ");
            traverse_menu();
            break;
        }
    }
}


void insert_menu()
{
    int data;
    printf("\n\n\t\t\t\t\t=> INSERT MENU\n\n\t\t\t\t\t1.INSERT AT BEGINNING\n\t\t\t\t\t2.INSERT AT ENDING\n\t\t\t\t\t3.INSERT AT MIDDLE BY PREVIOUS VALUE\n\t\t\t\t\t4.INSERT AT MIDDLE BY LOCATION\n\t\t\t\t\t5.BACK   ");
    cin>>ch;

    switch(ch)
    {
        case 1:
            {
                printf("\n\t\t\t\t\tENTER NUMBER OF DATA YOU WANT TO INSERT :  ");
                scanf("%d",&n);
                linksize=linksize+n;
                printf("\n\t\t\t\t\tENTER %d ELEMENTS : ",n);
                for(int i=1;i<=n;i++)
                {
                    scanf("%d",&data);
                    insertAtBeginning(creatNode(data));
                }
                break;
            }
        case 2:
            {
                printf("\n\t\t\t\t\tENTER NUMBER OF DATA YOU WANT TO INSERT :  ");
                scanf("%d",&n);
                linksize=linksize+n;
                printf("\n\t\t\t\t\tENTER %d ELEMENTS : ",n);
                for(int i=1;i<=n;i++)
                {
                    scanf("%d",&data);
                    insertAtEnding(creatNode(data));
                }
                break;
            }

        case 3:
        {

            if(head==NULL && tail==NULL)
            {
                printf("\n\t\t\t\t\tLIST IS EMPTY.\n\t\t\t\t\tINSERT AT BEGINNING OR ENDING");
                insert_menu();
                break;
            }

            else if(head==tail)
            {
                printf("\n\t\t\t\t\tTHE LIST HAS ONLY ONE ELEMENT\n\t\t\t\t\tINSERT AT BEGINNING OR ENDING");
                insert_menu();
                break;
            }

            int prevData,data;
            printf("\n\t\t\t\t\tENTER THE DATA AFTER WHICH YOU WANT TO INSERT : ");
            scanf("%d",&prevData);
            printf("\n\t\t\t\t\tENTER THE DATA YOU WANT TO INSERT : ");
            scanf("%d",&data);
            linksize=linksize+1;

            for(Node* current=head;current!=NULL;current=current->next)
            {
                if(current->data==prevData)
                {
                    insertAtMiddle(current, creatNode(data));
                    insert_menu();
                    return;
                }
            }
            printf("\n\t\t\t\t\t%d IS NOT IN THE LIST\n\n",prevData);

            break;
        }

        case 4:

            if(head==NULL && tail==NULL)
            {
                printf("\n\t\t\t\t\tLIST IS EMPTY. INSERT AT BEGINNING OR ENDING");
                insert_menu();
                return;
            }

            else if(head==tail)
            {
                printf("\n\t\t\tLIST HAS ONLY ONE ELEMENT. INSERT AT BEGINNING OR ENDING");
                insert_menu();
                return;
            }

            int loc;

            printf("\n\t\t\t\t\tENTER A VALID (2-%d) LOCATION TO INSERT DATA :   ",linksize);
            scanf("%d",&loc);

            if(loc<2 || loc>linksize)
            {
                printf("\n\t\t\t\t\tIINVALID LOCATION.");
                insert_menu();
                break;
            }
            printf("\n\t\t\t\t\tENTER DATA TO INSERT :  ");
            scanf("%d",&data);

            insertByLocation(loc,creatNode(data));
            linksize=linksize+1;
            break;

        case 5:
            main_menu();
            break;

        default:
            printf("\n\t\t\t\t\tINVALID INPUT. PLEASE ENTER A VALID NUMBER ");
            insert_menu();
            break;
    }

     insert_menu();
}


void main_menu()
{
    printf("\n\n\t\t\t\t\t=> MAIN MENU\n");
    printf("\n\t\t\t\t\t1.INSERTION MENU\n\t\t\t\t\t2.TRAVERSING MENU\n\t\t\t\t\t3.SEARCHING MENU\n\t\t\t\t\t4.DELETING MENU\n\t\t\t\t\t5.SORT LINKED LIST\n\t\t\t\t\t6.EXIT   ");
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
        printf("\n\t\t\t\t\tINVALID INPUT. PLEASE ENTER A VALID NUMBER (1-6)");
        main_menu();
    }
}

int main()
{
    int item;
    creatLinkList();

    if(go==0)
    {
        printf("\n\t\t\t\t\t==================================");
        printf("\n\t\t\t\t\tWELCOME TO LINKED LIST OPERATIONS");
        printf("\n\t\t\t\t\t==================================");
        printf("\n\n\t\t\t\t\tCREATE LINKED LIST\n\t\t\t\t\tENTER THE SIZE OF LINKED LIST (1-100) : ");
    }

    scanf("%d",&linksize);

    if(linksize<1 || linksize>100)
    {
        printf("\n\t\t\t\t\tWRONG INPUT. PLEASE ENTER VALID SIZE (1-100) :  ");
        go=1;
        main();
    }

    printf("\n\t\t\t\t\tENTER %d ELEMENTS : ",linksize);
    for(int i=1;i<=linksize;i++)
    {
        scanf("%d",&item);
        insertAtEnding(creatNode(item));
    }

    main_menu();
    return 0;
}
