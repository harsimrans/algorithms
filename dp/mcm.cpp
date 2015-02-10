/*****************************************
*
* Matrix Chain Multiplication
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Prints the best way (order) to multiply 
* two matrices
*
******************************************/

#include<iostream>

using namespace std;

void printOptimal(int s[10][10], int i, int j);


int main()
{
  int m[10][10]; //supporting only 10 matrices
  int s[10][10];
  int p[11];
  
  int num;
  cout<<"Enter the number of matrices : ";
  cin >> num;
  
  cout<<"Enter the order of the matrices : ";
  for (int i = 0; i < num + 1; i++)
    cin >> p[i];
  
  //filling the diagonal entries
  for (int i = 0; i < num; i++)
  {
    m[i][i] = 0; //no cost for a single matrix
  }
  
  
  
  //fill for remaining rows
  for (int i = 1; i < num; i++)
  {
    for (int j = 0; j < num - i; j++)  //no of columns along the diagonal
    {
      int k = j + i;
      m[j][k] = 999999; //high value
      
      for (int l = j; l < k; l++)
      {
         int q = m[j][l] + m[l+1][k] + p[j] * p[l+1] * p[k+1];
         
         if (q < m[j][k])
         {  
           m[j][k] = q;
           s[j][k] = l;
         }  
      }
    
    }
  }
  
  cout << m[0][num-1]<<endl;
  
  printOptimal(s, 0, num-1);
  return 0;
}

void printOptimal(int s[10][10], int i, int j)
{
  if (i == j)
    cout<< " "<< i << " "; 
  else
  {
    cout<<" ( ";
    printOptimal(s, i, s[i][j]);
    printOptimal(s, s[i][j]+1, j);
    cout<<" ) ";
  
  }  
}

