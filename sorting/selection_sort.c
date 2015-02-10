/*****************************************
*
* Selection Sort algorithm
*
* Mohit Goyal
* mohitgoyal707@gmail.com
*
* Takes an array input and outputs the
* sorted array using selection sort algo.
*
******************************************/

#include <stdio.h>

void selectionSort(int*,int);

int main()
{
	int a[10],n=10,i;
	printf("\nEnter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	selectionSort(a,n);
	printf("\nAfter Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

void selectionSort(int *a,int n)
{
	int i,j,m;
	for(j=0;j<n;j++)
	{	
		m = j;
		for(i=j+1;i<n;i++)
		{
			if(a[i] < a[m])
				m = i;
		}
		a[m] = a[m] + a[j] - (a[j] = a[m]);
	}

}