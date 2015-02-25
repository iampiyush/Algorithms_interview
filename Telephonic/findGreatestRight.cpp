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
void findGreatestRight2(int a[],int size)
{
 int i,j;
 int max,cur;
  
 for(i=0;i<size;i++)
 {
  cur=a[i];
  max=-1;
  for(j=i+1;j<size;j++)
  {
   if(max<a[j])
    max=a[j];
  }
  
  cout<<" Element And It's maximum "<<cur<<" "<<max<<endl;
 }
 

 cout<<"Done "<<endl;
 return ;
}


void findGreatestRight(int a[],int size)
{
 if(size<1)
  return ;
 
 int i,max;
 
 
 max=-1;
 for(i=size-1;i>-1;i--)
 {
  cout<<a[i]<<" "<<max<<endl;
  if(a[i]>max)
   max=a[i];
 } 

 return ;
}



 
int main()
{
  int arr[] = {3,2,5,4,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  findGreatestRight(arr,size);
 
  getchar();
  return 0;
}


