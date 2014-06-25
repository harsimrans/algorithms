/******************************************
*
* Kruskals algorithm
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Finds the cost of min. spanning tree
******************************************/


#include<stdio.h>

//graph (only supporting 10 set of nodes)
int cost[10][10], parent[10]; //depict the set node belongs to 
int minCost = 0;

int main()
{
  
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

  //seting each node as it`s parent
  for (i = 0; i < n; i++)
  {
    parent[i] = i;
  }
  
  int tmp = n-1;
  while(tmp--)
  {
  
  //traking the minimum edge
  
  int minEdge = 999999999; //arbitrary high value, garuntee to be max
  int source, dest;
  for (i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if (cost[i][j] < minEdge)
      {
        minEdge = cost[i][j];
        source = i;
        dest = j;
      }  
    }
  }
  
  //can we add a edge??
  //yes if no cycle occurs :)
  
  //check for cycle i.e belong to same parent
  int s = parent[source];
  int d = parent[dest];
  if (s != d) //there is already a path? NO
  {
    if (s != source)
    {
      parent[dest] = s;
    }
    else if (d != dest)
    {
      parent[source] = d;
    }
  }
  //added the edges
  minCost += cost[source][dest];
  printf("adding : %d, %d -> %d\n", cost[source][dest], source,dest);
  cost[source][dest] = 99999999; //make it so high cannot be covered again
  cost[dest][source] = 99999999;
  }    
  
  printf("min cost: %d\n", minCost);
    
  return 0;
}

