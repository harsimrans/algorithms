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
* Also print_path function has been 
* provided which  provides the shortest 
* path.
*
* 999999: Here signifies a very large
* value aka infinity.
******************************************/

#include<stdio.h>

int previous[10] = {-1}; // track down the path

void print_path(int vertex);

int main()
{
  int cost[10][10];

  int n;
  int i, j, k;
  printf("enter the num of nodes: ");
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

  for (i = 0 ; i < n; i++)
  {
    dist[i] = cost[source][i];
    taken[i] = 0;
  }
  taken[source] = 1;

  for(i = 0; i < n; i++)
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
         previous[j] = minvertex;
      }
    }
  }

  printf("The shortest distances of the vertex from source vertex is: \n");
  for (i = 0 ; i < n; i++)
    printf("%d ", dist[i]);
  printf("\n");

  return 0;
}

void print_path(int vertex)
{
    if (previous[vertex] != -1 && vertex != 0)
    {
        print_path(previous[vertex]);
    }
    else
    {
        printf(" %d ", vertex);
        return;
    }
    printf(" %d ", vertex);
}
