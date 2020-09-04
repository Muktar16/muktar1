#include<stdio.h>

int graph[10][10]={0},n,cost[10],prev[10],visited[10],s;


void initializeSingleSource(int s)
{
    for(int i=0;i<n;i++)
    {
        cost[i]=10000;
        prev[i]=-1;
        visited[i]=0;
    }
    cost[s]=0;
}

int extractmin()
{
    int min=10000,u;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0&&cost[i]<min)
        {
            min=cost[i];
            u=i;
        }
    }
    return u;
}


void relax(int u,int v)
{
    if(cost[v]>graph[u][v]&&visited[v]==0)
    {
        cost[v]=graph[u][v];
        prev[v]=u;
    }
}


void prim(int s)
{
    int u;
    initializeSingleSource(s);
    while(1)
    {
        u=extractmin();
        visited[u]=1;
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]>0)
            {
                relax(u,v);
            }
        }
        int i=0;
        for(;i<n;i++)
        {
            if(visited[i]==0)
                break;
        }
        if(i==n)
        {
            break;
        }
    }
}

int main()
{
    int m,u,v,w;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;
    }

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n\n");
    }

    prim(0);

    int MST=0;

    for(int i=0;i<n;i++)
    {
        MST+=cost[i];
    }
    printf("%d\n",MST);

    return 0;
}
