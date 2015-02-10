/******************************************
*
* Longest Common substring
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Finds the longest common substring
* of the given two strings
*
******************************************/

#include<iostream>
#include<string>
#include<cmath>


using namespace std;

int values[20][20];
int path[20][20] = {0};

string s1, s2;

int LCS(int a, int b);
void pathprint(int a, int b);

int main()
{
  
  cout << "Enter string s1 : ";
  cin >> s1; 
  cout << "Enter string s2 : ";
  cin >> s2;
  
  int len1 = s1.size();
  int len2 = s2.size();
  
  
  for (int i = 0; i <= len1; i++)
  {
    for (int j = 0; j <= len2; j++)
    {
      values[i][j] = LCS(i , j);
      //cout<<i<<", "<<j << " : "<<values[i][j]<<endl;
    }
  } 
  
  cout<<"Longest sub string length: " <<values[len1][len2]<<endl; 
  cout<<"The longest substring is : ";
  pathprint(len1, len2);
  cout<<endl;
  return 0;
}

int LCS(int a, int b)
{
  if (a == 0 || b == 0)
    return 0;
        
  else if (s1[a-1] == s2[b-1]) //string indexes start from zero
  {
    path[a][b] = s1[a-1];
    return 1 + values[a-1][b-1];
  }  
  else
  {
    if (values[a-1][b] > values[a][b-1])
    {
      path[a][b] = 1; //left movement
      
    }
    else
      path[a][b] = 2;
    return max(values[a-1][b], values[a][b-1]);       
  }
}

/*
  helps to print the substring 
  1 : moves to the left
  2 : moves up the column
  else : there was a char match
         move diagonally 
*/         

void pathprint(int a, int b)
{
  
  if (a == 0 || b == 0)
    return ;
    
  if (path[a][b] != 2 && path[a][b] != 1)
  {
     pathprint(a-1, b-1);
     cout<<(char)path[a][b];
  }  
  else
  {
    if (path[a][b] == 1)
      pathprint(a-1, b);
    else
      pathprint(a, b-1);  
  }  
}

