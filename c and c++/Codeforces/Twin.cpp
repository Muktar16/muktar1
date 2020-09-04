#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int c[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(c[j]<c[j+1])
            {
                int temp = c[j];
                c[j] = c[j+1];
                c[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++) sum = sum+c[i];

    int temp2=(sum/2);
    int sum2 =0;
    int count=0;

    while(sum2<=temp2)
    {
        sum2 = sum2+c[count++];
    }

    cout<<count;
}
