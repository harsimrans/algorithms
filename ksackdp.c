/******************************************
*
* 0/1 Knapsack problem
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Solves 0/1 knapsack using DP
*
******************************************/

#include<stdio.h>

int vals[100][100];

int main()
{
  int i, j;
  
  int w[] = {0,  2,  3,  4, 2, 1};
  int p[] = {0, 10, 30, 25, 7, 4};
  int W = 10;
  int numItems = 5;
  
  for (i = 0 ; i <= numItems; i++)
  {
    vals[i][0] = 0;
  }
  
  for (i = 0; i <= W; i++)
  {
    vals[0][i] = 0;
  }
  
  for (i = 0 ; i <= numItems; i++)
  {
    for(j = 0; j <= W; j++)
      vals[i][j] = 0;
  }
  for (i = 1 ; i <= numItems; i++)
  {
    for (j = 0; j <= W; j++)
    {
      if (w[i] <= j)
      {
        printf("Considering item : %d\n", i);
        //taking the item
        if (vals[i-1][j] < p[i] + vals[i-1][j - w[i]])
          vals[i][j] = p[i] + vals[i-1][j - w[i]];
        else
          vals[i][j] = vals[i-1][j];
      }
      else
        vals[i][j] = vals[i-1][j];
      
      printf("Value of %d , %d is : %d\n", i, j, vals[i][j]);  
    }
  }
  printf("Vals : %d\n", vals[numItems][W]);
  return 0;
}
