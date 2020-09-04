#include<iostream>
#include<bits/stdc++.h>
#define N 100
using namespace std;
double rsltM[N];

void solve_equation(double matA[N][N],int n)
{
    for(int k=0;k<n;k++)
    {
        for(int l=k+1;l<n+1;l++) matA[k][l] = matA[k][l] / matA[k][k];

        matA[k][k]=1;

        for(int i=0;i<n;i++)
        {
            if(i!=k)
            {
                for(int j=k+1;j<n+1;j++)    matA[i][j] = matA[i][j] - (matA[k][j] * matA[i][k]);
            }
        }
    }

    for(int m=0;m<n;m++)
    {
        rsltM[m]=matA[m][n];
        printf("%.2f  ",rsltM[m]);
    }
}

void printMattrix(double matA[N][N],int n)
{
    cout<<"\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<matA[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    double matA[N][N];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>matA[i][j];
        }
    }
    printMattrix(matA,n);
    solve_equation(matA,n);
}
