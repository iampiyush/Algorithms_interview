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


int findMin(int a[],int start,int end)
{
 if(start>end)
  return -1;
     
 int middle;
 middle=(start+end)/2;
 
 if(middle==0  || a[middle]<a[middle-1])
   return a[middle];
 if(a[middle]>a[start])
  return findMin(a,middle+1,end);
 else
  return findMin(a,start,middle-1); 
}

//    2  3  4  5  1


int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 cin>>n;
 for(i=0;i<n;i++)
  cin>>a[i];
  
 ans=findMin(a,0,n-1); 
 cout<<ans<<endl;
}


 return 0;
}
