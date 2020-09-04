#include<iostream>
using namespace std;

void merge_sort(int *arr,int left,int right);
void merge(int* arr,int left,int mid,int right);

int main()
{
    int n;
    cout<<"Array size ";
    cin>>n;

    int *arr=new int[n];

    cout<<"\nEnter "<<n<<" elements  ";
    for(int i=0;i<n;i++) cin<<arr[i];

    merge_sort(arr,n-1,0);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}

void merge_sort(int *arr,int left,int right)
{
    if(left>=right) return;

    int mid=(left+right)/2;

    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);

    merge(arr,)
}

void merge(int *arr,int left,int mid,int right)
{
	int left_size,right_size,i,j,k;

	left_size=mid-left+1;
	right_left=right-mid;

	int L[left_size],R[right_size];

	for(i=0;i<left_size;i++)  L[i]=arr[i];

	for(i=left_size;i<right_size;i++) R[i]=arr[i];

	i=0;
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
