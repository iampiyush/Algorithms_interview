#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
 
 
void printArray(int a[],int size)
{
 int i;

 for(i=0;i<size;i++)
  cout<<a[i]<<" ";
 
 cout<<endl;


 return ;
}
 
 
void move2(int a[],int size)
{
 int i,j;
 
 
 i=0;
 j=size-1;
 while(i<j)
 {
  if(a[i]==0  && a[j]!=0)
  {
   swap(a[i],a[j]);
   i++;j--;
  }         
  else if(a[i]!=0)
   i++;
  else if(a[j]==0)
   j--;
  // else  do nothing  ...
   
 }


 return ;
}

 
 
 
void move(int a[],int size)
{
 int i,j;
 
 j=-1;
 i=0;
 
 while(i<size)
 {
  if(a[i]!=0)
   a[++j]=a[i];
  i++;
 }
 
 for(i=j+1;i<size;i++)
  a[i]=0; 


  return ;
}

 
int main()
{
  int arr[] = {3,2,10,5,4,4,8,10};
  int size = sizeof(arr)/sizeof(arr[0]);
   move2(arr,size);
   printArray(arr,size);
 
  getchar();
  return 0;
}


