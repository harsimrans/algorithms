/*****************************************
*
* Insertion Sort algorithm
*
* Mohit Goyal
* mohitgoyal707@gmail.com
*
* Takes an array input and outputs the
* sorted array using insertion sort algo.
*
******************************************/

#include <stdio.h>

void insertionSort(int*,int);

int main()
{
	int a[10],n = 10,i;//array a with size 10
	printf("\nEnter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]); //input to array 
	}
	printf("Before Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	insertionSort(a,n);
	printf("\nAfter Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

void insertionSort(int *a,int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		j=i;
		while(a[j] < a[j-1] && j>0)
		{
			a[j] = a[j] + a[j-1] - (a[j-1]=a[j]);
			j--;
		}
	}
}