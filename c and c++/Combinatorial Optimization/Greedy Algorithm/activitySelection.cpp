#include<stdio.h>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int actNum,sTime[MAX],fTime[MAX],actCounter=1;

void activitySelection()
{
    cout<<"Selected activities are: \n";
    cout<<"Start\tFinish\n";
    cout<<"  "<<sTime[0]<<"\t"<<fTime[0]<<"\n";

    int k=0;
    for(int i=k+1;i<actNum;i++)
    {
        if(sTime[i]>=fTime[k])
        {
            cout<<"  "<<sTime[i]<<"\t"<<fTime[i]<<"\n";
            actCounter++;
            k=i;
            continue;
        }
    }
}

void Sort()
{
    for(int i=0;i<actNum;i++)
    {
        for(int j=0;j<actNum-i-1;j++)
        {
            if(fTime[j+1]<fTime[j])
            {
                int temp=fTime[j+1];
                fTime[j+1]=fTime[j];
                fTime[j]=temp;

                int temp2=sTime[j+1];
                sTime[j+1]=sTime[j];
                sTime[j]=temp2;
            }
        }
    }
}

int main()
{
    cout<<"Enter number of activities: ";
    cin>>actNum;

    for(int i=0;i<actNum;i++)
    {
        printf("Starting and Ending Time of activity %d: ",i+1);
        cin>>sTime[i]>>fTime[i];
        printf("\n");
    }

    Sort();
//    for(int i=0;i<actNum;i++)
//    {
//        printf("\n%d   %d",fTime[i],sTime[i]);
//    }

    activitySelection();
    printf("\nTotal selected activities %d\n",actCounter);

}
