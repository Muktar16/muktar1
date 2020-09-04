#include<iostream>
#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int G[100][100],RG[100][100];
int prev[100],q[100];
int color[100];


int BFS(int n,int s, int t)
{
    int u,front=0,rear=0;
    for(int i=0;i<n;i++)
    {
        color[i]=WHITE;
        //d[i]=-1;
        prev[i]=-1;
    }
    color[s]=GRAY;
    //d[s]=0;
    prev[s]=0;
    q[rear++]=s;
    while(front!=rear)
    {
        u= q[front++];
        for(int v=0;v<n;v++)
        {
            if(RG[u][v]>0)
               {
                if(color[v]==WHITE)
                    {
                        color[v]=GRAY;
                        //d[v]=d[u]+1;
                        prev[v]=u;
                        q[rear++]=v;
                    }
               }
        }
        color[u]=BLACK;
    }
    if(color[t]==BLACK) return 1;
    else return 0;
}


int ford_fulkerson(int n,int s,int t)
{
    int u,v,f=0;

    while(BFS(n,s,t)==1)
    {
        int cf=1000000;
        for(v=t;v!=s;v=prev[v])
        {
            u=prev[v];
            if(RG[u][v]<cf) cf=RG[u][v];
        }

        for(int v=t;v!=s;v=prev[v])
        {
            u=prev[v];
            RG[u][v]=RG[u][v]-cf;
            RG[v][u]=RG[v][u]+cf;
        }
        f=f+cf;
    }
    return f;
}

int main()
{
    int n,e,c,u,v;
    //cout<<"Enter number of nodes: ";
    cin>>n;
    //cout<<"Enter number of edges: ";
    cin>>e;

    for(int i=0;i<e;i++)
    {
        //cout<<"edges "<<i+1<<"and capacity: ";
        scanf("%d %d %d",&u,&v,&c);
        G[u][v]=RG[u][v]=c;
    }

    cout<<"Maximum flow: "<<ford_fulkerson(n,0,n-1);
}


/*6 10
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4*/
