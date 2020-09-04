#include<iostream>
using namespace std;

int main()
{
    int n;
    int count=0;
    scanf("%d",&n);

    String mag[n];
    for(int i=0;i<n;i++)
    {
        cin>>mag[i];
    }
    String a;
    strcpy(a,mag[0]);
    for(int i=1;i<=n;i++)
    {
        if(strcmp(a,mag[i]))
        {
            count++;
            strcpy(a,arr[i]);
        }
    }
    printf("%d",count);
}
