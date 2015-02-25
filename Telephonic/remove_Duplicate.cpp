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
 
 
 
 
//  o(n*n)  complexity...


void removeDuplicate(int a[],int n)
{
 int i,j;
 int index; 

 j=0;
 for(i=0;i<n;i++)
 {
  index=abs(a[i])-1;
  if(a[index]>0)
  {
   a[index]=-a[index];
   a[j]=a[i];
   j++;
  }
  else
  {
   cout<<index+1<<" ";
  } 
  
 }

  a[j]=-(n+1);

  for(i=0;i<j;i++)
  {
   a[i]=a[i]>0?a[i]:-a[i];
   cout<<a[i]<<" ";
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
  
  removeDuplicate(a,n);
  
 }
 
 
  getchar();
  return 0;
}


