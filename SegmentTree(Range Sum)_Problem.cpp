#include<iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
using namespace std;


 
// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x < y)? x: y; }
 
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}


 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()


void updateSum(int st[],int start,int end,int in,int index,int val)
{
  if(in<start && in>end)  
    return ;
  st[index]=st[index]+val;    
  
  if(start!=end)
  {
  int mid;
  mid=(start+end)/2;
  updateSum(st,start,mid,in,2*index+1,val);
  updateSum(st,mid+1,end,in,2*index+2,val);
  } 
  
  return ;
}



int getSum(int st[],int start,int end,int l,int r,int index)
{
 if(start>r || end<l)
  return 0;
  
 if(start>=l  && end<=r)
  return st[index]; 
//   if this conditions does not hold

  int mid;
  mid=(start+end)/2;
 return getSum(st,start,mid,l,r,2*index+1)+getSum(st,mid+1,end,l,r,2*index+2);
  
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

  st[index]=constructSTUtil(arr,start,mid,st,2*index+1)+constructSTUtil(arr,mid+1,end,st,2*index+2);
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
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
 
    int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range
 
    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQ(st, n, qs, qe));
 
    return 0;
}
