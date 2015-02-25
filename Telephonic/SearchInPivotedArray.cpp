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
 


int SearchInPivotedArray(int a[],int size,int key)
{
 int left,right;
 int middle;
 
 left=0;
 right=size-1;
 
 while(left<=right)
 {
  middle=left+(right-left)/2;
  
  
  if(a[middle]==key)
   return middle;
  
  if(a[left]<=a[middle])    //   We have A sorted range 
  {
   if(a[left]<=key  &&  a[middle]>=key)
    right=middle-1;
   else
    left=middle+1;                       
  } 
  else    //  Right Half is Sorted Range
  {
   if(a[middle]<=key   &&  a[right]>=key)
    left=middle+1;
   else
    right=middle-1; 
  }
  
 }

 return -1;
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
 // cout<<"Enter First Array's size..\n";          
  
  cin>>n;
  for(i=0;i<n;i++)
   cin>>a[i];
  
   cout<<"Enter key to be searched..\n";
   cin>>m;
  cout<<SearchInPivotedArray(a,n,m)<<endl;
  
 }
 
 
  getchar();
  return 0;
}


