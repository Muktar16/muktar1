#include<stdio.h>

int Graph[100][100];
int indegree[100];
int Queue[100];
int front=0,rare = 0;
int count = 0;
int rslt[100];
int rCount = 0;

void inQueue(int item)
{
    Queue[rare]= item;
    rare++;
}

int deQueue()
{
    int item = Queue[front];
    front++;
    return item;
}



int main()
{
    int numNode,numEdge,u,v;

    printf("\nEnter number of nodes: ");
    scanf("%d",&numNode);

    printf("\nEnter number of edges: ");
    scanf("%d",&numEdge);

    for(int i=0; i<numNode; i++){
            indegree[i]=0;
        for(int j=0; j<numNode; j++){
            Graph[i][j] = 0;
        }
    }

    for(int i=0; i<numEdge; i++)
        {
            printf("\nEnter edge no. %d: ",i+1);
            scanf("%d %d",&u,&v);
            Graph[u][v] = 1;
            indegree[v]++;
        }

        for(int i=0; i<numNode; i++)
        {
            if(indegree[i] == 0)
            {
                inQueue(i);

            }
        }

        while(rare >= front)
        {
            rslt[rCount] = deQueue();

                for(int j = 0; j<numNode; j++)
                {
                    if(Graph[rslt[rCount]][j] == 1)
                    {
                        indegree[j]--;
                        if(indegree[j]==0) inQueue(j);
                    }
                }
                rCount++;
        }

        for(int i=0; i<numNode; i++)
        {
            printf("%d->",rslt[i]);
        }
}
