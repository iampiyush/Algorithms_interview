
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;



void swap(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
 return ;
}

void printArray(int a[],int size)
{
 int i;

 for(i=0;i<size;i++)
  cout<<a[i]<<" ";
 
 cout<<endl;


 return ;
}



void reverse(int a[],int start,int end)
{
 while(start<end)
 {
  swap(a[start],a[end]);
  start++;
  end--;
 }
 return ;
}
 
 
void rotate(int a[],int size,int k)
{
  //  rotate array bi reversal...
  int i,j;
  
  k=k%size;  
  
  reverse(a,0,size-1);   ///  reverse Whole Array...
  
  //  now reverse only first k elements..
  reverse(a,0,k-1);
  
  // now reverse n-k elements..
  
  reverse(a,k,size-1);
  
  return ;
}
 
 
 
void rotateWithExtraSpace(int a[],int size,int k) 
{
 int i,j;
 int b[1000];
 int index;
 
 k=k%size;
 for(i=0;i<size;i++)
 {
  index=(i+k)%size;
  b[index]=a[i];
 }

  for(i=0;i<size;i++)
   a[i]=b[i];
 
 return ;
}
 
int main()
{
  int arr[] = {1,2,3,4,5,6,7};
  int k;
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printArray(arr,arr_size);
  cout<<"Enter The Value Of K..\n";
  cin>>k;
  rotateWithExtraSpace(arr,arr_size,k);
  printArray(arr,arr_size);
  
  cin>>k; 
  getchar();
  return 0;
}


