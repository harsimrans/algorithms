/******************************************
*
* Graph coloring problem
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Finds if the graph can be colored in 
* given no. of colors and if possible  
* outputs the solution.
*
******************************************/


#include<stdio.h>
#define ORDER 3

int graph[10][10];
int x[10];

int main()
{
  int numColor, i, j;
  printf("Enter the number of colors : ");
  scanf("%d", &numColor);

  printf("Enter the edges : ");
  for (i = 0 ; i < ORDER; i++)
  {
    for (j = 0; j < ORDER; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }
 /* 
  printf("Current graph reading is : ");
  for (i = 0 ; i < ORDER; i++)
  {
    for(j = 0 ; j < ORDER; j++)
      printf("%d ", graph[i][j]);
    printf("\n");
  }
  */ 
  nextColor(0, numColor, ORDER);
  return 0;
}

int checkColorPossible(int k, int curColor, int numColor)
{
  int i;
  for (i = 0 ; i < k; i++)
  {
    if ((graph[k][i] != 0) && (x[i] == curColor))
    {
       return 0;
    }
  }
  return 1;  
}

//maybe a little bugy
void nextColor(int k, int numColor, int totNodes)
{
  int i;
  if (k == totNodes)
  {
   //print the values of x
   for(i = 0 ; i < totNodes; i++)
   {
     printf("%d ", x[i]);
   }
   printf("\n");
   return ;  //signifying reached end and so successful
  }

  for (i = 0; i < numColor; i++)
  {
    if (checkColorPossible(k, i, numColor))
    {
      x[k] = i;
      nextColor(k+1, numColor, totNodes);
    }
  }
}
