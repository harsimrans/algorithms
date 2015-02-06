/******************************************
*
* Prims algorithm
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* finds the cost of min. spanning tree
* using prims algorithm
*
******************************************/

#include<stdio.h>

int main()
{
  int cost[10][10];

  int n;
  int i, j;
  printf("enter the num of edges: ");
  scanf("%d", &n);
  
  for (i = 0 ; i < n; i++)
  {
    for (j = 0 ; j < n; j++)
    {
      scanf("%d", &cost[i][j]);
      
    }
  }
  
  int near[1000];
  
  int u = 0, v = 0, min = 9999999;
  
  
  //find the minimum edges
  for (i = 0; i < n; i++)
  {
    for (j = 0 ; j < n; j++)
    {
      if (cost[i][j] < min)
      {
        min = cost[i][j];
        u = i;
        v = j;
      }
    }
  }
  printf("found min edge : %d %d and weight : %d\n", u, v, min);
  
  int weight = min;
  
  
  //initializing the near of other elements
  
  for (i = 0; i < n; i++)
  {
    if (cost[i][u] < cost[i][v])
    {
      near[i] = u;
    }
    else
    {
      near[i] = v;
    }
  }
  
  near[u] = -1; near[v] = -1;
  //printf("");
  for (j = 1; j < n-1; j++)
  {
  //picking the minimum
  int min = 99999999, minvertex;
  for (i = 0 ; i < n; i++)
  {
    if (near[i] != -1)
    {
      if (cost[i][near[i]] < min)
      {
        min = cost[i][near[i]];
        minvertex = i;
      }
    }
  }
  printf("min vertex: %d from %d  and edge : %d\n", minvertex,near[minvertex], min);
  
  near[minvertex] = -1;
  weight += min;
  
  //check if adding the vertex causes any change
  for (i = 0; i < n; i++)
  {
    if (near[i] != -1)
    {
    
      if (cost[i][minvertex] < cost[i][near[i]])
      {
        near[i] = minvertex;
      }  
    }
    
  
  }
  }
  printf("%d\n", weight);
   
  return 0;
}
