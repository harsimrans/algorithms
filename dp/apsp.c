/******************************************
*
* All pairs shortest path problem
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Finds the shortest path length between 
* all pairs of vertices
******************************************/



#include<stdio.h>

void printPath(int i ,int j);

int path[10][10];

int main()
{
  int cost[10][10];
  

  int n;
  int i, j, k;
  printf("enter the num of edges: ");
  scanf("%d", &n);
  
  for (i = 0 ; i < n; i++)
  {
    for (j = 0 ; j < n; j++)
    {
      scanf("%d", &cost[i][j]);
      path[i][j] = -1;
      
    }
  }
  
  for (k = 0 ; k < n ; k++)
  {
    for (i = 0 ; i < n; i++)
    {
      for (j = 0 ; j < n; j++)
      {
        if (i != j)
        {
          if (cost[i][k] + cost[k][j] < cost[i][j])
          {
            cost[i][j] = cost[i][k] + cost[k][j];
            path[i][j] = k;
          }
        }
      }
    }
  }
  
  //exaple cheching 
  printPath(0,2);
  return 0;
}  

void printPath(int i , int j)
{
  if (path[i][j] == -1) // direct is the shortest
  {
    return ;
  }
  else
  {  
    printf("%d --> ", i);
    printPath(i, path[i][j]);
    printf("%d --> ", path[i][j]);
    printPath(path[i][j], j);
    printf("%d\n", j);
  } 
}
