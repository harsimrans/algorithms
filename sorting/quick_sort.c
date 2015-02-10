/*****************************************
*
* Quick Sort algorithm
*
* Mohit Goyal
* mohitgoyal707@gmail.com
*
* Takes an array input and outputs the
* sorted array using quick sort algo.
*
******************************************/

#include <stdio.h>

void quicksort(int*,int,int);
int partition(int*,int,int);

int main()
{	
	int arr[10],size = 10,i; //array arr of size 10
	printf("\nEnter values : \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",arr+i);
	}
	printf("\nBefore Sorting List is\n");
	for(i=0;i<size;i++)
	{
		printf(" %d",*(arr+i));
	}
	quicksort(arr,0,size-1);
	printf("\nAfter Sorting List is\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",*(arr + i));
	}
	return 0;
}

void quicksort(int *a,int start,int end)
{
	int pos;
	if(start < end)
	{
		pos = partition(a,start,end);
		quicksort(a,start,pos-1);
		quicksort(a,pos+1,end);
	}
}

int partition(int* a,int start,int end)
{
	int pivot = start,select = start+1,i = start;
	while(i<=end)
	{
		if(a[i] < a[pivot])
		{
			a[i] = a[select] + a[i] - (a[select] = a[i]);
			select++;
		}
		i++;
	}
	a[pivot] = a[pivot] + a[select-1] - (a[select - 1] = a[pivot]);	 
	return (select - 1);
}
