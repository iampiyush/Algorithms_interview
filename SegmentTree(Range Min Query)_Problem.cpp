#include<iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
using namespace std;


 
// A utility function to get minimum of two numbers
int min(int x, int y) { return (x < y)? x: y; }
 
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 

//   Wrong Ans..
void updateMin(int st[],int start,int end,int in,int index,int val)
{
  if(in<start && in>end)  
    return ;
  
  if(start==end)
  {
   if(start==in)
    st[index]=val;
   return ; 
  }
  
   int mid;
   mid=(start+end)/2;  
   updateMin(st,start,mid,in,2*index+1,val);
   updateMin(st,mid+1,end,in,2*index+2,val);
  
   st[index]=min(st[index*2+1],st[index*2+2]);
   


   return ;

}



int getMin(int st[],int start,int end,int l,int r,int index)
{
 if(start>r || end<l)
  return INT_MAX;
  
 if(start>=l  && end<=r)
  return st[index]; 
//   if this conditions does not hold
  int mid;
  mid=(start+end)/2;

 return min(getMin(st,start,mid,l,r,2*index+1),getMin(st,mid+1,end,l,r,2*index+2));
}




// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int start, int end, int *st, int index)
{
  if(start==end)
  {
   st[index]=arr[start];
   return arr[start];
  }
  
  int mid;
  mid=(start+end)/2;

  st[index]=min(constructSTUtil(arr,start,mid,st,2*index+1),constructSTUtil(arr,mid+1,end,st,2*index+2));
  return st[index];
}
 
 
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}



int main()
{
    int arr[] = {1, 3, 2, 6, 9, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
 
    int l = 3;  // Starting index of query range
    int r = 5;  // Ending index of query range
    int in=3,index=0;
    int val=1;
    printf("Minimum of values in range [%d, %d] is = %d\n",l, r, getMin(st,0,n-1,l,r,0));
     
     cout<<"Now Update Value..."<<endl;
     arr[in]=val;
     updateMin(st,0,n-1,in,index,val); 
     
     
    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",l-1, r, getMin(st,0,n-1,l-1,r,0));
    cin>>l;
    return 0;
}
