#include<iostream>
#include<bits/stdc++.h>
#define N 100
#define s 20
using namespace std;
double rsltM[N];
char str[s];
int p=0;

void gauss_jordan_method(double matA[N][N],int n,FILE *out_file)
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

    if(p==0) fprintf(out_file,"<Gauss-Jordan method>\n");
    for(int m=0;m<n;m++)
    {
        if(n!=m && m!=0) fprintf(out_file,", ");
       fprintf(out_file,"%.2lf",matA[m][n]);
    }
    fprintf(out_file,"\n");
    p++;
}

void print_output_file()
{
    char c;
    FILE *fp;
    if( (fp=fopen("Gauss-Jordan Elimination output file.txt","r"))==NULL) cout<<"Error opening file";

    while((c=fgetc(fp))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
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
    if((output_file=fopen("Gauss-Jordan Elimination output file.txt","w"))==NULL) cout<<"Error Creating file";

    int n;
    fscanf(file,"%d",&n);
    while(!feof(file))
    {
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
        gauss_jordan_method(matA,n,output_file);
        fscanf(file,"%d",&n);
    }
    fclose(file);
    fclose(output_file);
    print_output_file();
}
