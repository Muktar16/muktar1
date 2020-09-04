#include<stdio.h>

int Graph[100][100],n,m,cost[100],visited[100];

struct edge{
    int u;
    int v;
    int w;
} edges[100];

void SortEdge()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m-1-i;j++)
        {
            if(edges[j+1].w<edges[j].w)
            {
                int temp1 = edges[j+1].w;
                edges[j+1].w=edges[j].w;
                edges[j].w=temp1;

                int temp2 = edges[j+1].u;
                edges[j+1].u=edges[j].u;
                edges[j].u=temp2;

                int temp3 = edges[j+1].v;
                edges[j+1].v=edges[j].v;
                edges[j].v=temp3;

            }
        }
    }
}

int kruskals()
{
    int MST=0;
    SortEdge();

    for(int i=0;i<m;i++)
    {
        if( visited[edges[i].u]!=1 || visited[edges[i].v]!=1  )
        {
            visited[edges[i].u]=1;
            visited[edges[i].v]=1;
            MST=MST+edges[i].w;
        }
    }
    return MST;

}

int main()
{
    int u,v,w;
    scanf("%d %d",&n,&m);


    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        Graph[u][v]=w;
        Graph[v][u]=w;

        edges[i].u=u;
        edges[i].v=v;
        edges[i].w=w;

    }

    printf("\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",Graph[i][j]);
        }
        printf("\n\n");
    }

    printf("\nMST = %d\n\n",kruskals());

    return 0;
}

