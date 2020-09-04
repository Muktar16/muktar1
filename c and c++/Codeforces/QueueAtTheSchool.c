#include<stdio.h>

int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    char q[n+1];
    for(int i=0;i<=n;i++)
    {
        scanf("%c",&q[i]);
    }

    for(int i=0;i<t;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(q[j]=='B' && q[j+1]=='G')
            {
                char temp = q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
                j++;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        printf("%c",q[i]);
    }
}
