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
 
 


void FindMaxSumSpaceOptimised(int a[],int size)
{
 if(size<4)
  return ;
 
 int ans[100];
 
 int i,j;
 
 int temp;
 int first;
 int second;
 int curMax,Max;
 
 //  initialise the shit out of it...
 first=a[0];
 second=a[1];
 
 //ans[2]=a[0]+a[2];  
 
 curMax=Max=INT_MIN;
 
 for(i=3;i<size;i++)
 {
  curMax=max(first,second)+a[i];
  if(curMax>Max)
   Max=curMax;
  temp=second;
  second=first+a[i-1];
  first=temp;
  
  
  /*
  temp=first;
  first=second;
  second=temp+a[i-1];
 */
 }

 cout<<"Will it Work..\n";
 cout<<"Max is "<<Max<<endl;
 return ;
}
 
 
 
void FindMaxSum(int a[],int size)
{
 if(size<4)
  return ;
 
 int ans[100];
 
 int i,j;
 
 int temp;
 int first;
 int second;
 
 //  initialise the shit out of it...
 ans[0]=a[0];
 ans[1]=a[1];
 ans[2]=a[0]+a[2];  
 
 for(i=3;i<size;i++)
 {
  ans[i]=max(ans[i-2],ans[i-3])+a[i];
 }

 cout<<"Will it Work..\n";
 cout<<max(ans[size-1],ans[size-2]);
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
  
 FindMaxSumSpaceOptimised(a,n);
  
 }
 
 
  getchar();
  return 0;
}


