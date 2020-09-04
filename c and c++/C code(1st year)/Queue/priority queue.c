#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct person {
    char name[50];
    int priority;
    struct person* next;

} Node;

Node* createNode(char string[50], int priority)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    strcpy(string,NewNode->name);
    NewNode->priority = priority;
    NewNode->next = NULL;

    return NewNode;
}


void pop(Node** head)
{
    Node* NewNode = *head;
    (*head) = (*head)->next;
    free(NewNode);
}


void enQueue(Node** head, char name[50], int priority)
{
    Node* start = (*head);
    Node* NewNode = createNode(name, priority);

    if ((*head)->priority > priority)
        {
            NewNode->next = *head;
            (*head) = NewNode;
        }
    else {

        while (start->next != NULL &&
               start->next->priority < priority) {
            start = start->next;
        }

        NewNode->next = start->next;
        start->next = NewNode;
    }
}

int isEmpty(Node** head)
{
    return (*head) == NULL;
}

int main()
{
    Node* pq = createNode("Muktar", 3);
    enQueue(&pq, "Jubaer", 2);
    enQueue(&pq, "hgdf", 3);
    enQueue(&pq, "fsdds", 0);

    return 0;
}
