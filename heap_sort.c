/*****************************************
*
* Heap Sort algorithm
*
* Mohit Goyal
* mohitgoyal707@gmail.com
*
* Takes an array input and outputs the
* sorted array using heap sort algo.
*
******************************************/

#include <stdio.h>

void heapsort(int*,int);
void createheap(int*,int);
void heapify(int*,int,int);

int main()
{
	int a[10],size = 10,i;//array a with size 10
	printf("\nEnter Elements :");
	for(i=0;i<size;i++)
	{
		scanf("%d",a+i); //input elements to the array
	}
	printf("\nBefore Sorting:\n");
	for(i=0;i<size;i++)
	{
		printf(" %d ",*(a+i));
	}
	heapsort(a,size);
	printf("\nAfter Sorting:\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",*(a+i));
	}
	return 0;
}

void heapsort(int *a,int n)
{
	int i;
	createheap(a,n);
	for(i = n-1;i>0;i--)
	{
		a[0] = a[0] + a[i] - (a[i] = a[0]);
		heapify(a,0,i);
	}
}

void createheap(int *a,int n)
{
	int i;
	for(i = (n-1)/2;i>=0;i--)
	{
		heapify(a,i,n);
	}
}

void heapify(int *a,int i,int n)
{
	int left,right,max = i;
	left = 2*i + 1;
	right = 2*i + 2;
	if(left < n && a[left] > a[i])
		max =left;
	if(right < n && a[right]> a[max])
		max = right;
	if(max != i)
	{
		a[i] = a[i] + a[max] - (a[max] = a[i]);
		heapify(a,max,n);
	}
}