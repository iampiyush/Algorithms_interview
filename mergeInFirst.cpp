/*
 
 Given sorted arrays of length n and 2n with n elements each, merge first array into
  second arrayGiven sorted arrays of length n and 
 2n with n elements each, merge first array into second array.

*/


// Find MISSING eLEMENTS  using Sorting...
//  time complexity   0(n)...
//  space complexity   0(1)....

#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>
#include<stack>


using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}


void printArray(int a[],int size)
{
 int i;
 
 
 cout<<"Array is \n";
 for(i=0;i<size;i++)
  cout<<a[i]<<" ";
  
 cout<<endl; 
 return ;
}



void mergeInFirst(int a[],int b[],int n)
{
 int i,j,k;

 k=(2*n)-1;
 for(i=n-1,j=n-1;  i>-1  &&  j>-1    ; k--)
 {
  if(a[i]>b[j])
  {
   a[k]=a[i];
   i--;
  }
  else
  {
   a[k]=b[j];
   j--;
  }
 } 
 
 //   Remaining Elements...
 if(j==-1)
 {
  cout<<"j is equal to -1\n";        
  for(;i>-1;i--)
   a[k--]=a[i];
 }
 else 
 {
  cout<<"i is equal to -1\n";    
  for(;j>-1;j--)
   a[k--]=b[j];
 }

 return ;
}


void mergeInFirst2(int a[],int b[],int n)
{
 int i,j,k;
 
 //  shift array n...
 for(i=0;i<n;i++)
   a[i+n]=a[i];
  
  k=0;
 for(j=0;j<n &&  i<(2*n);)
 {
  if(a[i]<=b[j])
  {
   a[k]=a[i];
   i++;
  }
  else
  {
  a[k]=b[j];
   j++; 
  }
  k++;
 } 
  
  
  if(j==n)
  {
   for(;i<(2*n);i++)
    a[k++]=a[i];
  }
  else
  {
   for(;j<n;j++)
    a[k++]=b[j];
  }
   
//  end of function..
  return ;
}

int main()
{
int a[200];
int b[100];
int t,size,i,n;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;

 cout<<"Enter the value of n..\n";
 cin>>n;
 
 cout<<"Enter First Array..\n";
 for(i=0;i<n;i++)
  cin>>a[i];
  
 cout<<"Enter Second Array..\n";
 for(i=0;i<n;i++)
  cin>>b[i];
 
 
 mergeInFirst(a,b,n); 
 printArray(a,2*n);
 
}


 return 0;
}
