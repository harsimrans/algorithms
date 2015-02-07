/*****************************************
*
* Radix Sort algorithm
*
* Mohit Goyal
* mohitgoyal707@gmail.com
*
* Takes an array input and outputs the
* sorted array using radix sort algo.
*
******************************************/

#include <stdio.h>

void radixsort(int*,int);

int main()
{
	int size=10,a[10],i; // array a of size 10
	printf("\nEnter Values\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nBefore Sorting Array is \n");
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	radixsort(a,size);
	printf("\nAfter Sorting Array is \n");
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

void radixsort(int *a,int size)
{
	int b[size],max,i,t=1,j,index=0;
	max = a[0];
	for(i=1;i<size;i++) // find the maximum number to counts the maximum digits to iterate on
	{
		if(max < a[i])
			max = a[i];
	}
	
	while(max/t > 0)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<size;j++)
			{
				if((a[j]/t)%10 == i)
					b[index++] = a[j];
			}
		}
		for(i=0;i<size;i++)
			a[i] = b[i];
		index = 0;
		t=t*10;
	}
}