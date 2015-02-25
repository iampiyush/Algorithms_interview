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
 


int findMin(int a[],int size)
{
 int left,right;
 int middle;
 
 left=0;
 right=size-1;
 
 while(a[left]>a[right])
 {
  middle=left+(right-left)/2;
  if(a[middle]>a[right])
   left=middle+1;
  else
   right=middle; 
 }

 return left;
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
  
  cout<<findMin(a,n)<<endl;
  
 }
 
 
  getchar();
  return 0;
}


