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
 
 
 
 
//  o(n*n)  complexity...


void printCommonElements(int a[],int n,int b[],int m)
{
 int i,j;

 i=0;
 j=0;
 while(i<n  &&  j<m)
 {
  if(a[i]>b[j])
  {
   j++;
  }
  else if(b[j]>a[i])
  {
   i++;
  }
  else
  {
   cout<<a[i]<<" ";
   i++;
   j++;
  }
 }
 
 

 cout<<endl;
 return ;
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
  while(t--)
 {
  cout<<"Enter First Array's size..\n";          
  
  cin>>n;
  for(i=0;i<n;i++)
   cin>>a[i];
  
  cout<<"Enter Second  Array's size..\n";  
  cin>>m; 
  for(i=0;i<m;i++)
   cin>>b[i];
   printCommonElements(a,n,b,m);
 }
 
 
  getchar();
  return 0;
}


