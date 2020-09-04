#include <bits/stdc++.h>
using namespace std;
#define N 100
#define s 20

double B[N],adjA[N][N],rsltM[N];
char str[s];
int p=0;

void mattrix_multiplier(double matA[N][N],int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            rsltM[i]+=matA[i][j]*B[j];
        }
    }
}


void co_factor(double matA[N][N], double tempM[N][N], int a, int b, int n)
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

double determinant(double matA[N][N], int n)
{
    double detA = 0.0;
    if (n==1)  return matA[0][0];
    else if(n==2) return ((matA[0][0]*matA[1][1])-(matA[0][1]*matA[1][0]));

    double temp[N][N],sign = 1.0;
    for (int k = 0; k < n; k++)
    {
        co_factor(matA, temp, 0, k, n);
        detA+= sign * matA[0][k] * determinant(temp, n - 1);
        sign = -sign;
    }

    return detA;
}

void adjoint_mattrix(double matA[N][N],int n)
{
    double tempM[N][N],sign=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sign=pow(-1,i+j);
            co_factor(matA,tempM,i,j,n);
            adjA[j][i]=sign*determinant(tempM,n-1);

        }

    }
}


void matrix_inversion_method(double matA[N][N],int n,FILE *out_file)
{
    for(int i=0;i<n;i++) B[i]=matA[i][n];
    double detA=determinant(matA,n);
    if(detA==0.0) {cout<<"\nInverse Mattrix dosent exist"; return;}
    adjoint_mattrix(matA,n);
    mattrix_multiplier(adjA,n);

    if(p==0) fprintf(out_file,"<Mattrix inversion method>\n");
    for(int m=0;m<n;m++)
    {
        if(n!=m && m!=0) fprintf(out_file,", ");
       fprintf(out_file,"%.2lf",rsltM[m]/detA);
    }
    fprintf(out_file,"\n");
    p++;

}

void print_output_file()
{
    char c;
    FILE *fp;
    if( (fp=fopen("matrix_inverse_output_file2.txt","r"))==NULL) cout<<"Error opening file";

    while((c=fgetc(fp))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
}

void initialize(int n)
{
    for(int i=0;i<n;i++) rsltM[i]=0;
}

void initialize_string(char str[s])
{
    for(int i=0;str[i]!='\0';i++) str[i]='\0';
}

int main()
{
    FILE *file;
    if( (file=fopen("input_for_linear_system_equation.txt","r"))==NULL) cout<<"Error opening file";

    FILE *output_file;
    if((output_file=fopen("matrix_inverse_output_file2.txt","w"))==NULL) cout<<"Error Creating file";

    int n;
    fscanf(file,"%d",&n);
    while(!feof(file))
    {
        initialize(n);
        double matA[N][N];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                initialize_string(str);
                fscanf(file,"%s",str);
                for(int i=0;str[i]!='\0';i++)
                {
                    if(str[i]==',')
                    {
                        str[i]='\0';
                        break;
                    }
                }
                matA[i][j]=atof(str);
            }
        }
        matrix_inversion_method(matA,n,output_file);
        fscanf(file,"%d",&n);
    }
    fclose(file);
    fclose(output_file);

    print_output_file();
}
