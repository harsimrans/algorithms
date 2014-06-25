/******************************************
*
* N Queens Problem
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Prints the board arrangement which are
* solutions to N queens problem
*
******************************************/

#include<stdio.h>

//100 x 100 boards max as of now
int x[100] = {0, 3, 5, 2, -1, -1};

void NQ(int k, int n);
int diagonal(int i, int j, int n);
int place(int i, int j, int n);
void display(int n);

int numSol = 0;

int main()
{
  int n, i;
  printf("Enter the dimension of board : ");
  scanf("%d", &n);
  
  for (i = 0 ; i < n; i++)
    x[i] = -1;
    
  numSol = 0;  
  NQ(0, n);
  printf("sols : %d\n", numSol);
  return 0;
}

void NQ(int k, int n)
{
  //printf("NQ called\n");
  int i; 
  
  for (i = 0 ; i < n; i++)
  {
    if (place(k, i, n) == 1)
    {      
      x[k] = i;
      
      if(k == n-1)
      {
        //int j;
        printf("SOLUTION\n");
        numSol++;
        display(n);
        printf("\n");          
      }
      else
        NQ(k+1, n);  
    }
  }
  /*  
  if(x[k] == -1)
  {
    x[k-1] = -1;
  }
  */
  
}

int place(int i, int j, int n)
{
  //printf("called for : %d %d\n",i , j );
  
  //check for the column
  int m;
  for (m = 0; m < i; m++)
  {
    if (x[m] == j)
    {
  //    printf("Column violation\n");
      return -1;
    }  
  }
  
  //printf("Checked for column\n");
  
  //check diagonal 
  int b = diagonal(i, j, n);
  if (b == -1)
    return -1;
  
  return 1;    

}

int diagonal(int i, int j, int n)
{
  int z, y;
  z = i;
  y = j;
  
  //check up-left
  
  while (--z >= 0 && --y >= 0)
  {
    if (x[z] == y)
    {
      return -1;
    }  
  }
  
  //check up-right
  
  z = i;
  y = j;
  while (--z >= 0 && ++y < n)
  {
    if (x[z] == y)
    {
      return -1;
    }  
  }
  
  return 1;
}


void display(int n)
{
  int i, j;
  for (i=0; i < n; i++)
  {
    for(j = 0 ; j < n; j++)
    {
      if (x[i] == j)
        printf("Q ");
      else
        printf("# ");  
    }
    printf("\n");
  }
}
