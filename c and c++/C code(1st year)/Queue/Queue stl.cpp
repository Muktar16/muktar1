#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    int item;
    queue<int>MyQueue;

    for(int i=10;i<=15;i++)
    {
        scanf("%d",&item);
        MyQueue.push(item);
    }
    MyQueue.push(100);
    MyQueue.push(9);

    while(!MyQueue.empty())
    {
        cout<<endl<<MyQueue.front() <<endl;
        MyQueue.pop();
    }
    return 0;
}
