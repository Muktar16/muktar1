#include<stdio.h>

double w[100],p[100],pbyw[100];
int n;

double fractional_knapsack(double maxw)
{
    double maxp=0.0;
    double sumw=0.0,rw;

    for(int i=0;i<n;i++)
    {
        sumw=sumw+w[i];
        //printf("%lf",w[i]);
        if(sumw<maxw)
        {
            maxp=maxp+p[i];
            //printf("\n%lf",p[i]);
            //continue;
        }
        else
        {
            rw=maxw-(sumw-w[i]);
            printf("\n%lf",rw);
            maxp=maxp+pbyw[i]*rw;
            break;
        }
    }
    return maxp;
}

void Sort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(pbyw[j+1]>pbyw[j])
            {
                double temp1=pbyw[j+1];
                pbyw[j+1]=pbyw[j];
                pbyw[j]=temp1;

                double temp2 = p[j+1];
                p[j+1]=p[j];
                p[j]=temp2;

                double temp3=w[j+1];
                w[j+1]=w[j];
                w[j]=temp3;
            }
        }
    }
}

int main()
{
    double maxw,maxp=1;

    printf("\nEnter number of objects: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter profit and weight for object %d: ",i+1);
        scanf("%lf %lf",&p[i],&w[i]);
        pbyw[i] = p[i]/w[i];
    }

    printf("\nEnter maximum weight: ");
    scanf("%lf",&maxw);

    Sort();
    maxp = fractional_knapsack(maxw);

    printf("\nMaximum possible profit: %.2f",maxp);
}
