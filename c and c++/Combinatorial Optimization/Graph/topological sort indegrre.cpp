#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int Graph[100][100];
int indegree[100];
int count = 0;
int rslt[100];
int rCount = 0;
queue<int>q;

void topoSort(int numNode)
{
    for(int u=0;u<numNode;u++)
    {
        if(indegree[u]==0) q.push(u);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        rslt[count++]=u;

        for(int v=0;v<numNode;v++)
        {
            if(Graph[u][v]==1)
            {
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
    }
}

void initialize_Graph(int numNode)
{
    for(int i=0; i<numNode; i++)
    {
        indegree[i]=0;
        for(int j=0; j<numNode; j++)
        {
            Graph[i][j] = 0;
        }
    }
}


int main()
{
    int numNode,numEdge,u,v;

    printf("\nEnter number of nodes: ");
    scanf("%d",&numNode);

    printf("\nEnter number of edges: ");
    scanf("%d",&numEdge);

    initialize_Graph(numNode);

    for(int i=0; i<numEdge; i++)
    {
        printf("\nEnter edge no. %d: ",i+1);
        scanf("%d %d",&u,&v);
        Graph[u][v] = 1;
        indegree[v]++;
    }

    topoSort(numNode);

    if(count!=numNode) {printf("Not possible"); return 0;}

    for(int i=0; i<numNode; i++)
    {
        printf("%d->",rslt[i]);
    }
}
