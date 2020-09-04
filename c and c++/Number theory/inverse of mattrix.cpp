#include<bits/stdc++.h>
#include<iostream>
using namespace std;

double determinant(double [50][50], int n);
void find_inverse_mattrix(double num[50][50], int f);
void transpose(double num[50][50], double fac[50][50], int r);
double inverse[50][50],arr[50];

void mattrix_multiplier(double A[50][50],double B[50],int n)
{
    for(int i=0;i<n;i++) arr[i]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i]+=A[i][j]*B[j];
        }
    }

}

void inverse_method(double A[50][50],double B[50],int n)
{
    double d = determinant(A,n);
    if (d==0.0)   return;
    find_inverse_mattrix(A, n);
    mattrix_multiplier(inverse,B,n);
}

int main()
{
    double A[50][50],B[50];
    int n;

    FILE *fptr=fopen("input_for_linear_system_equation.txt","r");
    FILE *fp=fopen("output.txt","w");
    FILE *file=fopen("result.txt","w");
    fprintf(file,"<Mattrix Inversion method>\n");


    char ch;
    while((ch=getc(fptr))!=EOF)
    {

        if(ch!=',') fprintf(fp,"%c",ch);
    }
    fclose(fptr);
    fclose(fp);

    FILE *file2=fopen("output.txt","r");
    fscanf(file2,"%d", &n);
    while(!feof(file2))
    {
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<n+1;j++)
            {
                fscanf(file2,"%lf",&A[i][j]);
                if(j==n) B[i]=A[i][j];
            }

        }
        inverse_method(A,B,n);
        fscanf(file2,"%d", &n);
        for(int i=0;i<n;i++) fprintf(file,"%.2f,  ",arr[i]);
        fprintf(file,"\n");
    }
    fclose(file);
    fclose(file2);

    FILE *fprint=fopen("result.txt","r");
    char c;
    while((c=getc(fprint))!=EOF) printf("%c",c);
}


double determinant(double A[50][50], int n)
{
    double detA=0, M[50][50];
    int  sign=1;
    int i, j, m, k, c;
    if (n == 1)
    {
        return (A[0][0]);
    }
    else
    {
        detA = 0;
        for (c = 0; c < n; c++)
        {
            m = 0;
            k = 0;
            for (i = 0;i < n; i++)
            {
                for (j = 0 ;j < n; j++)
                {
                    M[i][j] = 0;
                    if (i != 0 && j != c)
                    {
                        M[m][k] = A[i][j];
                        if (k < (n - 2))
                        k++;
                        else
                        {
                            k = 0;
                            m++;
                        }
                    }
               }
             }
          detA = detA + sign * (A[0][c] * determinant(M, n - 1));
          sign = -1 * sign;
          }
    }

    return (detA);
}

void find_inverse_mattrix(double matA[50][50], int f)
{
    double b[50][50], fac[50][50];
    int p, q, m, n, i, j;
    for (q = 0;q < f; q++)
    {
        for (p = 0;p < f; p++)
        {
            m = 0;
            n = 0;
            for (i = 0;i < f; i++)
            {
                for (j = 0;j < f; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = matA[i][j];
                        if (n < (f - 2))
                        n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
        }
  }
  transpose(matA, fac, f);
}

void transpose(double num[50][50], double fac[50][50], int r)
{
    int i, j;
    double b[50][50], d;

    for (i = 0;i < r; i++)
    {
        for (j = 0;j < r; j++)
        {
            b[i][j] = fac[j][i];
        }
    }
    d = determinant(num, r);
    for (i = 0;i < r; i++)
    {
        for (j = 0;j < r; j++)
        {
            inverse[i][j] = b[i][j] / d;
        }
    }
}
