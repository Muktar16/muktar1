#include<stdio.h>

typedef struct node{
    int vertexNum;
    node *next;
};

node **Graph;
/*typedef struct Graph{
    node *adjList;
};*/

node* createNode(int vertexNum)
{
    node *newNode = new node;

    newNode->vertexNum = vertexNum;
    newNode->next = NULL;
    return newNode;
}

void createEdge(int u, int v)
{
    node *newNode = createNode(v);
    Graph->next->= newNode;
}

int main()
{
    int numNode;
    int numEdge;
    int u,v;

    printf("Enter number of Nodes: ");
    scanf("%d",&numNode);

    for(int i=0; i<numNode; i++)
    {
        Graph[i]->vertexNum =
    }

    printf("\nEnter number of Edges: ");
    scanf("%d",&numEdge);

    for(int i=0; i<numEdge; i++)
    {
        printf("Edge no %d: ",i+1);
        scanf("%d %d ",&u,&v);
        createEdge(graph,u,v);
    }
}
