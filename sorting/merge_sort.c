/*****************************************
*
* Merge Sort algorithm
*
* Mohit Goyal
* mohitgoyal707@gmail.com
*
* Takes an array input and outputs the
* sorted array using merge sort algo.
*
******************************************/

#include <stdio.h>

void mergelist(int*,int,int,int,int);
void splitlist(int*,int,int,int);
void mergesort(int*,int);

int main()
{
	int size=10,a[10],i; // array a of size 10
	printf("\nEnter the values: \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",a+i); // input the elements to array
	}
	printf("\n\nBefore Sorting\n");
	for(i=0;i<size;i++)
	{
		printf(" %d",a[i]);
	}
	mergesort(a,10);
	printf("\n\nAfter Sorting\n");
	for(i=0;i<size;i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}

void mergesort(int *a,int size)
{
	splitlist(a,0,size-1,size);
}
void splitlist(int *a,int start,int end,int size)
{
	int mid,i;
	if(start == end)
		return;
	mid = (start + end)/2;
	splitlist(a,start,mid,size);
	splitlist(a,mid+1,end,size);
	mergelist(a,start,mid,end,size);
}

void mergelist(int *a,int start,int mid,int end,int size)
{
	int i = start,begin = start,m = mid + 1,k,b[size];
	while(start <= mid && m <= end)
	{
		if(a[start] < a[m])
		{
			b[i] = a[start];
			start++;
			i++;
		}
		else
		{
			b[i] = a[m];
			m++;
			i++;
		}
	}
	if(m > end)
	{
		for(k=start;k<=mid;k++)
			b[i++] = a[k];
	}
	else
	{
		for(k = m;k<=end;k++)
			b[i++] = a[k];
	}

	for(i=begin;i<=end;i++)
	{
		a[i] = b[i];
	}
}
