#include<stdio.h>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int value,coinNum;
int coin[MAX],result[MAX];
int coinCounter=0;

void sortCoins()
{
    for(int i=0;i<coinNum; i++)
    {
        for(int j=0;j<coinNum-1-i;j++)
        {
            if(coin[j+1]>coin[j])
            {
                int temp = coin[j];
                coin[j] = coin[j+1];
                coin[j+1] = temp;
            }
        }
    }
}

void coinChange()
{
    sortCoins();
    for(int i=0;i<coinNum;i++)
    {
        while(coin[i]<=value)
        {
            value=value-coin[i];
            result[coinCounter]=coin[i];
            coinCounter++;
        }
    }
}


int main()
{

    cout<<"Enter the value: ";
    cin>>value;
    cout<<"Enter number of coins: ";
    cin>>coinNum;

    cout<<"Enter values of coins: \n";
    for(int i=0;i<coinNum;i++)
    {
        cout<<"Coin "<<(i+1)<<": ";
        cin>>coin[i];
    }

    coinChange();
    printf("you need %d coins.",coinCounter);
    for(int i=0;i<coinCounter;i++)
    {
        printf("%d  ",result[i]);
    }

}
