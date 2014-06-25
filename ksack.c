/******************************************
*
* Knapsack Problem (fractional)
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
*
******************************************/


#include<stdio.h>

int main()
{
  int n, i, j;
  float  weight[100], price[100]; //supporting only 100 items
  printf("enter the number of items: ");
  scanf("%d", &n);

  for (i = 0 ; i < n; i++)
  {
    scanf("%f %f", &weight[i], &price[i]);
  }
  float maxweight;
  printf("Enter the maximum weight to carry: ");
  scanf("%f", &maxweight);

  //sorting the list by price to weight
  for (i = 0; i < n; i++)
  {
    for (j = i+1 ; j < n; j++)
    {
      if(price[i]/weight[i] < price[j]/weight[j])
      {
        int temp_p = price[i];
        int temp_w = weight[i];
        price[i] = price[j];
        weight[i] = weight[j];
        price[j] = temp_p;
        weight[j] = temp_w;
      }
    }
  }
  
  printf("sorted the list\n");
  
  float weightPicked = 0, totalPrice = 0;
  int currentItem = 0;
  
  //pick up the items till bag not full
  
  while(weight[currentItem] <= (maxweight - weightPicked) && currentItem < n)
  {
      weightPicked += weight[currentItem];
      totalPrice += price[currentItem];
      currentItem++;
  }
  
  //pick the remaining weight
  if (weightPicked != maxweight && currentItem < n)
  {
    float percentPick = (maxweight - weightPicked)/ weight[currentItem];
    totalPrice += price[currentItem] * percentPick; 
  }

  printf("The total price is : %f\n", totalPrice);

  return 0;
}
