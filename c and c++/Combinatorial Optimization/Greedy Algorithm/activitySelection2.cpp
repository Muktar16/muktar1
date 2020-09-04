#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    actNum;
    sTime;
    fTime;
}

node* creatNode(int actNum,int sTime,int fTime)
{
    node* newNode = new node;

    newNode->actNum = actNum;
    newNode->sTime = sTime;
    newNode->fTime = fTime;

    return newNode;
}

int main()
{
    int n,sTime,fTime;
    printf("\nEnter number of activities: ");
    scanf("%d",&n);

    node acts[n];

    for(int i=0;i<n;i++)
    {
        printf("\nActivity number %d: \nEnter Start and Finishing Time: ");
        scanf("%d %d",&sTime,&fTime);
        node *newNode = createNode(i+1,sTime,fTime);
        acts[i]->actNum = newNode->actNum;
        acts[i]->sTime = newNode->sTime;
        acts[i]->fTime = newNode->fTime;
    }
}
