/*
Sample:
Input:
3
3 4 5 26
4 3 6 28
9 4 5 32
output: 1 2 3

3
1 1 1 6
0 2 5 -4
2 5 -1 27
output: 5 3 -2
*/

#include <bits/stdc++.h>
using namespace std;
#define N 100

void printMattrix(int matA[N][N],int n);

int B[N],adjA[N][N],rsltM[N];

void mattrix_multiplier(int matA[N][N],int B[N],int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            rsltM[i]+=matA[i][j]*B[j];
        }
    }
}


void co_factor(int matA[N][N], int tempM[N][N], int a, int b, int n)
{
    int k=0,h=0;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            //tempM[i][j] = 0;
            if (i!=a && j!=b)
            {
                tempM[k][h++] = matA[i][j];

                if (h == n - 1)
                {
                    h = 0;
                    k++;
                }
            }
        }
    }
}

int determinant(int matA[N][N], int n)
{
    int detA = 0;
    if (n==1)  return matA[0][0];
    else if(n==2) return ((matA[0][0]*matA[1][1])-(matA[0][1]*matA[1][0]));

    int temp[N][N],sign = 1;
    for (int k = 0; k < n; k++)
    {
        co_factor(matA, temp, 0, k, n);
        detA+= sign * matA[0][k] * determinant(temp, n - 1);
        sign = -sign;
    }

    return detA;
}

void adjoint_mattrix(int matA[N][N],int n)
{
    int tempM[N][N],sign=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sign=pow(-1,i+j);
            co_factor(matA,tempM,i,j,n);
            adjA[j][i]=sign*determinant(tempM,n-1);

        }

    }
    cout<<"\nAdjoint Mattrix: ";
    printMattrix(adjA,n);
}



void solve_equation(int matA[N][N],int n)
{
    for(int i=0;i<n;i++) B[i]=matA[i][n];
    int detA=determinant(matA,n);
    if(detA==0) {cout<<"\nInverse Mattrix dosent exist"; return;}
    adjoint_mattrix(matA,n);
    mattrix_multiplier(adjA,B,n);
    cout<<"\nSolution:\n";
    for(int i=0;i<n;i++)
    {
        cout<<(double)rsltM[i]/(double)detA<<"  ";
    }

}

void printMattrix(int matA[N][N],int n)
{
    cout<<"\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matA[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int n;
    cin>>n;
    int matA[N][N];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>matA[i][j];
        }
        //cin>>B[i];
    }
    printMattrix(matA,n);
    solve_equation(matA,n);
}
