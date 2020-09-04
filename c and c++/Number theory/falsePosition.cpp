#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) ((x)*(x)*(x)-4*(x)-8.95)
#define EPS 1.0e-9

int main()
{
    int n=0;
    double a=2,b=3,x0;

    if(f(a)*f(b)>0)
    {
        printf("\nNo root.");
        exit(0);
    }

    while(1)
    {
        x0=((a*f(b)-b*f(a))/(f(b)-f(a)));
        n++;

        if(fabs(f(x0))<=EPS)
        {
            printf("\nRoot = %lf",x0);
            printf("\nItr = %d ",n);
            exit(0);
        }

        if(f(a)*f(x0)>0) a=x0;
        else b=x0;
    }

}


