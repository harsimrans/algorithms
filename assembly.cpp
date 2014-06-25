/******************************************
*
* Assembly line scheduling problem
*
* Harsimran Singh
* harsimran_hs4@yahoo.co.in
*
* Finds the order of assembly lines for 
* best output
******************************************/


#include<iostream>

#define NUM 4
using namespace std;

int main()
{
  int a1[NUM], a2[NUM];
  int f1[NUM], f2[NUM];
  int t[2][NUM] = {};
  int taken[NUM];
  int e1, e2, x1, x2;
  
  for(int i = 0; i < NUM; i++)
  {
    cin>>a1[i];
    cin>>a2[i];
    
  }
  for (int i = 0; i < NUM-1; i++)
  {
    cin>>t[0][i];
    cin>>t[1][i];
  }
  
  e1 = 4; e2 = 5; x1 = 6; x2 = 7;
  
  f1[0] = e1 + a1[0];
  f2[0] = e2 + a2[0];
  
  if (f1[0] < f2[0])
    taken[0] = 1;
  else
    taken[0] = 2;
      
  for (int i = 1 ; i < NUM; i++)
  {
     if(f1[i-1] + a1[i] < f2[i-1] + t[1][i-1] + a1[i])
     {
        f1[i] = f1[i-1] + a1[i];
     }
     else
        f1[i] = f2[i-1] + t[1][i-1] + a1[i];
    
     if (f2[i-1] + a2[i] < f1[i-1] + t[0][i-1] + a2[i])
        f2[i] = f2[i-1] + a2[i];
     else
        f2[i] = f1[i-1] + t[0][i-1] + a2[i];
      
     if (f1[i] < f2[i])
       taken[i] = 1;
     else
       taken[i] = 2;
                       
  }
  if (f1[NUM - 1] + x1 < f2[NUM - 1] + x2)
    cout<<"Ans : "<<f1[NUM - 1] + x1;
  else
    cout<<"Ans : "<<f2[NUM - 1] + x2;
  
  cout<<"Begin --> ";
  for (int i = 0 ; i < NUM; i++)
  {
    cout<<taken[i]<<endl;
  }
  cout<<" End"<<endl;
 
  return 0;
  
}
