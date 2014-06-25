/******************************************
*
* single source shortest path problem
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Finds the shortest path from a given 
* source vertex to all other vertices
*
******************************************/

#include<stdio.h>

int main()
{
  int cost[10][10];
 
  int n;
  int i, j, k;
  printf("enter the num of edges: ");
  scanf("%d", &n);
  int dist[n];
  int taken[n];
  
  for (i = 0 ; i < n; i++)
  {
    for (j = 0 ; j < n; j++)
    {
      scanf("%d", &cost[i][j]);
       
    }
  }
  int source;
  printf("enter the source: ");
  scanf("%d", &source);
  
  for (i = 1 ; i < n; i++)
  {
    dist[i] = cost[source][i];
    taken[i] = 0;
  }
  taken[source] = 1;
  
  for(i = 1; i < n; i++)
  {
    int min = 999999;
    int minvertex;
    //find the min
    for (j = 0 ; j < n; j++)
    {
      if (taken[j] != 1 && dist[j] < min)
      {
        minvertex = j;
        min = dist[j];
      }
    }
    taken[minvertex] = 1;
    
    //updations
    for (j = 0 ; j < n; j++)
    {
      if (taken[j] != 1 && cost[i][minvertex] + cost[minvertex][j] < dist[j])
      {
         dist[j] = cost[i][minvertex] + cost[minvertex][j];
      }
    }
  }
  for (i = 0 ; i < n; i++)
    printf("%d ", dist[i]);
  printf("\n");  
  return 0;
}  
