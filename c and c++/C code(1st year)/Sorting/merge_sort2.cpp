#include<stdio.h>

int n;
void merge_sort(int *arr,int left,int right);
void merge(int *arr,int left,int mid,int right);

int main()
{
	int i;
	printf("\nEnter the number of element ");
	scanf("%d",&n);

	int arr[n];
	printf("\nEnter %d elements  ",n);
	for(i=0;i<n;i++) scanf("%d",&arr[i]);

	merge_sort(arr,0,n-1);

	printf("\nAfter sorting the array is:  ");
	for(i=0;i<n;i++) printf("%d  ",arr[i]);

}

void merge_sort(int *arr,int left,int right)
{
	int mid;
	if(left>=right) return;

	mid=(left+right)/2;

	merge_sort(arr,left,mid);
	merge_sort(arr,mid+1,right);

	merge(arr,left,mid,right);
}

void merge(int *arr,int left,int mid,int right)
{
	int left_size,right_size,i,j,k;

	left_size=mid-left+1;
	right_size=right-mid;

	int L[left_size],R[right_size];

	for(i=0;i<left_size;i++)  L[i]=arr[i];

    for(i=0;i<right_size;i++)  R[i]=arr[mid+1+i];
	j=0;
	k=0;

	for(i=0;i<n;i++)
	{
		if(L[j]<R[k])
		{
			arr[i]=L[j];
			j++;
		}
		else
		{
			arr[i]=R[k];
			k++;
		}
	}
}
