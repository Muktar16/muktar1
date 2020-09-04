#include<stdio.h>
#define MAX 100
#define WHITE 0
#define GREY 1
#define BLACK 2

int Graph[MAX][MAX],fTime[MAX],color[MAX],prev[MAX],time=0,count=0,arr[MAX];

void DFS_visit(int u,int numNode)
{
    time++;
    color[u]=GREY;

    for(int v=0;v<numNode;v++)
    {
        if(Graph[u][v] && color[v]==WHITE)
        {
            prev[v]=u;
            DFS_visit(v,numNode);
        }
    }
    time++;
    fTime[u]=time;
    color[u]=BLACK;
    arr[count++]=u;
}

void DFS(int numNode)
{
    for(int u=0;u<numNode;u++)
    {
        color[u] = WHITE;
        prev[u] = -1;
    }

    for(int u=0;u<numNode;u++)
    {
        if(color[u]==WHITE)
        {
            DFS_visit(u,numNode);
        }
    }
}


void initialize_Graph(int numNode)
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
    int numNode,numEdge,u,v;

    printf("Enter number of nodes: ");
    scanf("%d",&numNode);

    printf("\nEnter number of Edges: ");
    scanf("%d",&numEdge);

    initialize_Graph(numNode);

    for(int i=0;i<numEdge; i++)
    {
        printf("\nEnter edge %d: ",i+1);
        scanf("%d %d",&u,&v);
        Graph[u][v] = 1;
    }

    DFS(numNode);

    for(int i=count-1;i>=0;i--)
    {
        printf("%d->",arr[i]);
    }

}

