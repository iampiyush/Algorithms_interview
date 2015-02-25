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
 
 
 
 int max(int a,int b)
 {
  if(a>b)
   return a;
  return b; 
 }
 
 

void stockBuy(int a[],int size)
{
 if(size<2)
  return ;

 int i,j;
 int maxProfit;
 int start,end;
 
 maxProfit=INT_MIN;
 start=end=0;
 
 for(i=1;i<size;i++)
 {
  if(a[i]<a[i-1])
  {
   end=i-1;
   
   if(a[end]-a[start]> maxProfit)
     maxProfit=a[end]-a[start];
   
   start=i;      
  }
 
 }   //
 //   else do nothing...we have incrreasing sequence now..
 
 if(start != (size-1))
 {
   end=size-1;
   if(a[end]-a[start]> maxProfit)
     maxProfit=a[end]-a[start];
 }

  cout<<"Max Profit Earned Can be "<<maxProfit<<endl;

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
  
  stockBuy(a,n);
  
 }
 
 
  getchar();
  return 0;
}


