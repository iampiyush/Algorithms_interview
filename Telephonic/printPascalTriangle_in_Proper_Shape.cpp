//  Write a code to remove duplicate entries in array of size N having elements only from 1 to N.

//   Find common elements in two unique sorted arrays...


#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
 
 
 int mat[510][510];
 
 
 int max(int a,int b)
 {
  if(a>b)
   return a;
  return b; 
 }
 
 



void preprocess()
{

int i,j;

//  initialise the matrix...
for(i=0;i<500;i++)
 for(j=0;j<=500;j++)
  mat[i][j]=0;
 
 mat[1][1]=1; 
 
 
 for(i=2;i<=500;i++)
{
 for(j=1;j<=i;j++)
  mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
} 

//  Done...

 return ;
}



void  printPascalTriangle(int line)
{
 int i,j;
 
 for(i=1;i<=line;i++)
 {
  //  printing Appropriate Space..
  for(j=1;(j<=line-i); j++)
   cout<<" ";
 //  Print elements..
  for(j=1;j<=i;j++)
 //  printf("%4d ",mat[i][j]);
   cout<<mat[i][j]<<" ";
   
   cout<<endl;
 }


}
 
int main()
{
 int i;
 int t;
 int n,m;   
 int a[1000],b[1000]; 
  
 //  Enter T values//
  cout<<"Enter Value of t..\n";  
  cin>>t;  
  
  preprocess();   //   calculate pascal triangle for value 500...
  while(t--)
 {
  cout<<"Enter Number of Lines You Want to Print \n";          
  cin>>n;
  
  printPascalTriangle(n);
  cout<<"\n\n\n";
 }
 
 
  getchar();
  return 0;
}


