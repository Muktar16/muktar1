#include<stdio.h>
#define MAX 100
#define WHITE 0
#define GREY 1
#define BLACK 2


int Graph[MAX][MAX],Graph2[MAX][MAX],dTime[MAX],fTime[MAX],color[MAX],prev[MAX],time=0;
int count=1,sccNum[MAX];


void printSCCs(int numNode)
{
    printf("\n\nThere are %d elements\n",count);
    for(int k=1;k<count;k++)
    {
        printf("\nSCC %d: ",k);
        for(int i=0;i<numNode;i++)
        {
            if(sccNum[i]==k)
                printf("%d  ",i);
        }
    }
}

int maxfTime(int numNode)
{
    int max=-1,maxNode;
    for(int v=0;v<numNode;v++)
    {
        if(fTime[v]>max)
        {
            max=fTime[v];
            maxNode=v;
        }
    }

    fTime[maxNode] = -1;
    return maxNode;
}

void sccDFS_visit(int u,int numNode)
{
    //time++;
    //dTime[u]=time;
    color[u]=GREY;
    for(int v=0;v<numNode;v++)
    {
        if(Graph[u][v] && color[v]==WHITE)
        {
            prev[v]=u;
            sccDFS_visit(v,numNode);
        }
    }
    //time++;
    //fTime[u]=time;
    color[u]=BLACK;
    sccNum[u]=count;
}

void sccDFS(int numNode)
{
    for(int u=0;u<numNode;u++)
    {
        color[u] = WHITE;
        prev[u] = -1;
    }

    for(int i=0;i<numNode;i++)
    {
        int max = maxfTime(numNode);
        if(color[max]==WHITE)
        {
            sccDFS_visit(max,numNode);
            count++;
        }
    }
}

void DFS_visit(int u,int numNode)
{
    time++;
    dTime[u]=time;
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
        Graph2[v][u] = 1;
    }

    DFS(numNode);
    sccDFS(numNode);
    printSCCs(numNode);
}
