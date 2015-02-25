//   Divide And Conquer

//   Find A Fixed point in the given array...where  (a[index]==index)

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;



int fixedPoint(int a[],int start,int end)
{
 if(end>=start)
 {
  int mid;
  mid=start+(end-start)/2;
  
  if(a[mid]==mid)
   return mid;
  else if(a[mid]>mid)
   return fixedPoint(a,start,mid-1);
  else
   return fixedPoint(a,mid+1,end); 
 
 
 
 /*
   if(mid > a[mid])
    return fixedPoint(a, (mid + 1), end);
   else
   return fixedPoint(a, start, (mid -1));
 */
 
 }

 //   else  no such point exists...
  return -1;

}


int binarySearch(int arr[], int low, int high)
{
    if(high >= low)
    {
        int mid = (low + high)/2;  /*low + (high - low)/2;*/
        if(mid == arr[mid])
            return mid;
        if(mid > arr[mid])
            return binarySearch(arr, (mid + 1), high);
        else
            return binarySearch(arr, low, (mid -1));
    }
 
    /* Return -1 if there is no Fixed Point */
    return -1;
}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
int iter,k;
int key;
char buf[100];
int number;
int ans;

cin>>t;

while(t--)
{
 //cin>>buf;
 cout<<"Enter Number of Elements.....\n";
 cin>>n;

 for(i=0;i<n;i++)
  cin>>a[i];
 
  ans=fixedPoint(a,0,n-1); 
//  ans=binarySearch(a,0,n-1);
 cout<<"Fixed point in the array is "<<ans<<endl;
 
}


 return 0;
}


