#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) ((x)*(x)*(x)-4*(x)-8.95)
#define EPS 1.0e-9

int main()
{
    int n=0;
    double x0=2,x1=3,x2;

    while(1)
    {
        x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
        x0=x1;
        x1=x2;
        n++;

        if(fabs(f(x2))<=EPS)
        {
            printf("\nRoot = %lf",x0);
            printf("\nItr = %d ",n);
            exit(0);
        }

    }

}

