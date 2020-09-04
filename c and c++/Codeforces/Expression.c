#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    int arr[8],max=0;
    arr[0]=a+b*c;
    arr[1]=a*b+c;
    arr[2]=(a+b)*c;
    arr[3]=a+(b*c);
    arr[4]=(a*b)+c;
    arr[5]=a*(b+c);
    arr[6]=a*b*c;
    arr[7]=a+b+c;
    for(int i=0;i<8;i++)

    {
        if(arr[i]>max) max = arr[i];
    }
    printf("%d",max);
}
