#include<iostream>
using namespace std;

#define size 8000

int M[8000][8000];



int space_optimised_ways(int a[],int n,int sum)
{
 int i,j;
 int ways[10000];
 int tempSum;
 
 ways[0]=1;
 
 for(i=1;i<=sum;i++)
 {
  ways[i]=0;                  
  for(j=0;j<n;j++)
  {
    if(a[j]>i)
    tempSum=0;
    //else if(a[j]==i)
    //tempSum=1;
    else
    tempSum=ways[i-a[j]];
    
    ways[i]=ways[i]+tempSum;   
  }
 }

   return ways[sum];

}

int memoised_ways(int a[],int n,int sum)
{
 if(sum==0)
  return 1;
 
 if(sum<0)
  return 0;
 
 if(n==0 && sum>0)
  return 0;

 if(M[n][sum]==-1)
 {
  M[n][sum]=memoised_ways(a,n,sum-a[n-1])+memoised_ways(a,n-1,sum);
 }

  return M[n][sum];
}




int f(int a[],int n,int sum)
{
 int i,j;
 
 for(i=0;i<=n;i++)
 {
  for(j=0;j<=sum;j++)
   M[i][j]=-1;
 }
 
 //return memoised_ways(a,n,sum);

  return space_optimised_ways(a,n,sum);
}




int f2(int a[],int n,int sum)
{
 int ways;
 int i,j;
 int index;
 int with,without;
 
 for(i=0;i<size;i++)
  M[i][0]=!(M[0][i]=0);     //tricky...


 for(i=1;i<=n;i++)
 {
  //    j is individual sum values from 1 to sum...
  for(j=1;j<=sum;j++)
  {
    index=j-a[i-1];
    if(index<0)
     with=0;
    else
     with=M[i][index]; 
  
    without=M[i-1][j];
   
    M[i][j]=with+without;
  }
 
 }


  ways=M[i-1][sum];
  
 return ways;
}




//      

int main()
{
 int i;
 int t,n;
 int a[10000];
 int sum;
 
 cin>>t;
 while(t--)
 {
  cin>>n;
  
  for(i=0;i<n;i++)
   cin>>a[i];
  
  cin>>sum;
  
  cout<<f(a,n,sum)<<endl;
 
 }

 return 0;
 
}
