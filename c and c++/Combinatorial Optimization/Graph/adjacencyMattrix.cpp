#include<stdio.h>
#define MAX 100

int Graph[MAX][MAX];

void printGraph(int numNode)
{
    for(int i=0; i<numNode; i++)
    {
        for(int j=0; j<numNode; j++)
        {
            printf("%d   ",Graph[i][j]);
        }
        printf("\n\n");
    }
}

void createEdge(int u, int v)
{
    Graph[u][v] = 1;
    Graph[v][u] = 1;
}

void initializer_Graph(int numNode)
{
    for(int i=0; i<numNode; i++)
    {
        for(int j=0; j<numNode; j++)
        {
            Graph[i][j] = 0;
        }
    }
}

int main()
{
    int numNode;
    int numEdge;
    int u,v;

    printf("\nEnter number of Nodes: ");
    scanf("%d",&numNode);

    initializer_Graph(numNode);

    printf("\nEnter number of Edge: ");
    scanf("%d",&numEdge);

    for(int i=0; i<numEdge; i++)
    {
        printf("\nEnter edge %d : ",i+1);
        scanf("%d %d",&u,&v);
        createEdge(u-1,v-1);
    }

    printf("\n\n");
    printGraph(numNode);
}
