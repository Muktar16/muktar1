#include<iostream>
using namespace std;
#define MAX 99999
int G[100][100];
int d[100],prev[100];

int bellman_ford(int n,int s)
{
    int u,v;
    //initilize_single source Graph
    for( v=0;v<n;v++)
    {
        d[v]=MAX;
        prev[v]=-1;
    }
    d[s]=0;

    for(int i=0;i<n-1;i++)
    {
        //relaxation
        for(u=0;u<n;u++)
        {
            for(v=0;v<n;v++)
            {
                if(G[u][v]!=0 && d[u]!=MAX && d[v]>d[u]+G[u][v])
                {
                    d[v]=d[u]+G[u][v];
                    prev[v]=u;
                }
            }
        }
    }

    int k=-1;
    for(u=0;u<n;u++)
        {
            for(v=0;v<n;v++)
            {
                if(d[v]>d[u]+G[u][v])
                {
                    k=v;
                    break;
                }

            }
        }
        int counter=0;

        if(k!=-1)
        {
            for(int j=0;j<n;j++)
            k=prev[k];

            for(int v=k;;v=prev[v])
            {
                counter++;
                cout<<v<<"->";
                if(v==k && counter>1) break;
            }
        }
}

int main()
{
    int u,v,n,e,w;
    cin>>n;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u;
        cin>>v;
        cin>>w;
        G[u][v]=w;
    }
    bellman_ford(n,0);
}

/*8 11
0 1 3
0 2 5
0 3 2
1 4 -4
2 5 6
3 6 3
4 7 4
5 7 8
5 2 -3
6 3 -6
6 7 7
ans:False*/

/*False
5
5
0 1 1
1 2 2
2 3 3
3 4 -3
4 0 -3*/

