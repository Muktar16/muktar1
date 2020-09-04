#include<iostream>
using namespace std;

int queue_size,Rear,Mypos,Front=-1,time=0;


int main()
{
    int test,i;
    cout<<"\nEnter number of test case: ";
    cin>>test;

    while(test--)
    {
        int time=0,queue_size,Front=0,Rear=0;

        cout<<"\nEnter Queue size and your position: ";
        cin>>queue_size>>Mypos;

        int arr[queue_size*3];

        for(i=0;i<queue_size;i++)
        {
            cin>>arr[i];
        }

        Front=0;
        Rear=queue_size-1;

        if(Front==Rear)
        {
            cout<<(++time);
            continue;
        }

        while(1)
        {
            int breaker=0;
            for(i=Front+1;i<=Rear;i++)
            {
                if(arr[i]<=arr[Front])
                {
                    breaker=1;
                    continue;
                }
                else if(arr[i]>arr[Front])
                {
                    if(Front==Mypos)
                    {
                        Mypos=Rear+1;
                    }
                    arr[++Rear]=arr[Front];
                    Front++;
                    breaker=0;
                    break;
                }

            }
            if(breaker==1)
            {
                time++;
                if(Mypos==Front)
                {
                    cout<<time;
                    break;
                }
                Front++;
            }
        }
    }
}
