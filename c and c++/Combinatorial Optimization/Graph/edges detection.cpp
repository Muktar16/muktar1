#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2


int Graph[100][100];
int Color[100], dTime[100],fTime[100], prev[100];
int front=0, rear=0, time=0;



int isPath(int s, int v)
{
    if(s==v) return 1;

    else if(prev[v]==-1) return 0;

    else isPath(s,prev[v]);
}

int treeEdgeDetector(int u,int v)
{
    if(prev[v] == u) return 1;
    else return 0;
}

int forwardEdgeDetector(int u,int v)
{
    if((dTime[u]<dTime[v]) && isPath(u,v))
    {
        return 1;
    }
        return 0;
}


int backEdgeDetector(int u,int v)
{
    if((dTime[u]>dTime[v]) && isPath(v,u))
    {
        return 1;
    }
        return 0;
}


DFS_visit(int u,int numNode)
{
    int v;

    time++;
    dTime[u]=time;
    Color[u]=GRAY;

    for(v=0;v<numNode;v++)
    {
        if(Graph[u][v]==1 && Color[v]==WHITE)
        {
            prev[v]=u;
            DFS_visit(v,numNode);
        }
    }
    time++;
    fTime[u]=time;
    Color[u]= BLACK;
}



void DFS(int numNode)
{
    for(int i=0; i<numNode; i++)
    {
        Color[i]=WHITE;
        prev[i]=-1;
    }

    for(int i=0; i<numNode; i++)
    {
        if(Color[i]==WHITE)
        {
            DFS_visit(i,numNode);
        }

    }
}

int main()
{
    int numNode,numEdge,u,v;

    printf("Enter the number of nodes: ");
    scanf("%d",&numNode);
    printf("Enter number of edges : ");
    scanf("%d",&numEdge);


    for(int i=0; i<numNode; i++)
    {
        for(int j=0; j<numNode; j++)
        {
            Graph[i][j]=0;
        }
    }

    for(int i=0; i<numEdge; i++)
    {
        printf("Enter edges-%d: ",i+1);
        scanf("%d %d",&u,&v);
        Graph[u][v]= 1;
    }

    DFS(numNode);

    int ch;
    printf("\n\n1.DETECT EDGE\n2.EXIT\n\nEnter your Choice: ");
    scanf("%d",&ch);

    while(ch!=2)
    {
        int s,f;
        printf("\nEnter the edge to Detect: ");
        scanf("%d %d",&s,&f);

        if(treeEdgeDetector(s,f) == 1)
        {
            printf("This is a \"TREE EDGE\"");
        }


        else if(forwardEdgeDetector(s,f) == 1)
        {
            printf("This is a \"FORWARD EDGE\"");
        }


        else if(backEdgeDetector(s,f) == 1){
            printf("\nThis is a \"BACK EDGE\"");
        }

        else printf("\nThis is a \"CROSS EDGE\"");
    }

    return 0;
}

