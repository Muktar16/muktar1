#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) ((x)*(x)*(x)-4*(x)-8.95)
#define fp(x) (3*(x)*(x)-4)
#define EPS 1.0e-9

int main()
{
    int n=0;
    double x0=2,x1;

    while(1)
    {
        x1=x0-f(x0)/fp(x0);
        x0=x1;
        n++;

        if(fabs(f(x1))<=EPS)
        {
            printf("\nRoot = %lf",x0);
            printf("\nItr = %d ",n);
            exit(0);
        }
    }

}

