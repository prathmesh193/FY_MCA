#include<stdio.h>

void merge(int arr[],int left,int middle,int right)
{
	int i,j,k;
	int n1=middle-left+1;
	int n2=right-middle;
	
	//create  temporary arrays
	int L[n1],R[n2];
	
	//copy data to temperary arrays l[] and R[]
	for(i=0;i<n1;i++)
		L[i]=arr[left + i];
	for(j=0;j<n2;j++)
		R[j]=arr[middle + 1 + j];
	
	//merge the temporary arrays back into arr[left..right]
	i=0;
	j=0;
	k=left;
	while(i<n1 &&  j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	//copy the remaining elements of L[],if there are any
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	//copy the remaining elements of R[],if there are  any
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

//Function to perform merge sort on the arrray
void mergeSort(int arr[],int left,int right)
{
	if(left<right)
	{
		int middle=left + (right - left)/2;
		
		mergeSort(arr,left,middle);
		mergeSort(arr,middle+1,right);
		
		merge(arr,left,middle,right);
	}
}

void printArray(int A[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
int main()
{
	int i;
	int arr_size;
	printf("Enter the number of elements you want to enter :");
	scanf("%d",&arr_size);
	
	int arr[arr_size];
	
	printf("Enter the elments in array :\n");
	for(i=0;i<arr_size;i++)
	{
		printf("Element %d :",i+1);
		scanf("%d",&arr[i]);
	}
//	int arr[]={12,11,13,5,6,7};
//	int arr_size = sizeof(arr)/sizeof(arr[0]);
//	
	printf("Given array is :\n");
	printArray(arr,arr_size);
	
	mergeSort(arr,0,arr_size-1);
	
	printf("Sorted array is :\n");
	printArray(arr,arr_size);
	
	return 0;
}