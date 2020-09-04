#include<stdio.h>
#define MAX 100
#define WHITE 0
#define GREY 1
#define BLACK 2

void initialize_Graph();


int Graph[MAX][MAX],dTime[MAX],fTime[MAX],color[MAX],prev[MAX],time;

void print_path(int src, int des)
{
    if(src==des)
    {
        printf("%d->",src);
    }
    else if(prev[des]==-1)
    {
        printf("There is no any path");
    }

    else{
        print_path(src,prev[des]);
        printf("%d->",des);
    }
}

void BFS_visit(int u,int numNode)
{
    time++;
    dTime[u]=time;
    color[u]=GREY;

    int v;
    for(int v=0;v<numNode;v++)
    {
        if(Graph[u][v] && color[v]==WHITE)
        {
            prev[v]=u;
            BFS_visit(v,numNode);
        }
    }
    time++;
    fTime[u]=time;
    color[u]=BLACK;
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
            BFS_visit(u,numNode);
        }
    }
}

void printGraph(int numNode)
{
    for(int i=0; i<numNode; i++)
    {
        for(int j=0; j<numNode; j++)
        {
            printf("%d  ",Graph[i][j]);
        }
        printf("\n");
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
        Graph[v][u] = 1;
    }

    printGraph(numNode);

    DFS(numNode);

    printf("\n\nColor\n");
    for(int i=0;i<numNode;i++)
    {
        printf("%d ",color[i]);
    }

    printf("\n\n\ndTimes\n");
    for(int i=0;i<numNode;i++)
    {
        printf("%d ",dTime[i]);
    }

    printf("\n\n\nfTimes\n");
    for(int i=0;i<numNode;i++)
    {
        printf("%d ",fTime[i]);
    }

    printf("\n\n\nprev\n");

    for(int i=0;i<numNode;i++)
    {
        printf("%d ",prev[i]);
    }

    printf("\n\n\n");

    int src,des;

    printf("\nEnter source to Destination: ");
    scanf("%d %d",&src,&des);
    print_path(src,des);



}
