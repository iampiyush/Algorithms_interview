

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;



int findPivot(int arr[], int low, int high)
{
   // base cases
   if (high < low)  return -1;
   if (high == low) return low;
 
   int mid = (low + high)/2;   /*low + (high - low)/2;*/
   if (mid < high && arr[mid] > arr[mid + 1])
     return mid;
   if (mid > low && arr[mid] < arr[mid - 1])
     return (mid-1);
   if (arr[low] >= arr[mid])
     return findPivot(arr, low, mid-1);
   else
     return findPivot(arr, mid + 1, high);
}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
int iter,k;
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
  
 ans=findPivot(a,0,n-1); 
 
 if(ans!=-1)
 cout<<"pivot  and maximum are "<<ans<<" "<<a[ans]<<endl;
 else
 cout<<"-1 "<<endl;
 

}


 return 0;
}


