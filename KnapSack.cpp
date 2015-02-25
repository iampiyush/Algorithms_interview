//  program to find Number of ways to make a sum from given denomination...
/*
 f(n,sum)=f(n,sum-a[i])+f(n-1,sum);

*/



#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<string>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<map>
#define size 8000


using namespace std;


int M[8000][8000];


int maximum(int a,int b)
{
 if(a>b)
  return a;
 else 
 return b; 
}


// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
 
 return ;
}




int knapsackDP(int weight[],int value[],int W,int n)
{
 int i,j;
 int v;
 
 for(i=0;i<=n || i<=W ;i++)
  {
   M[0][i]=M[i][0]=0;    //  intialise matrix...
  }
  
  
//   i is the Weight u r trying to make....ranges from 1 to W...   
 for(i=1;i<=W;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(weight[j-1]>i)
    v=0;
   else
    v=value[j-1]+M[i-weight[j-1]][j-1];
   
   M[i][j]=maximum(M[i][j-1],v);   
  }
 }
 
 return M[W][n];   //   return answer....
 
}




int knapsack(int weight[],int value[],int W,int n)
{
 if(n==-1 || W==0)
  return 0;
 
 if(weight[n]>W)
 return knapsack(weight,value,W,n-1);
 else
 return maximum(value[n]+knapsack(weight,value,W-weight[n],n-1),knapsack(weight,value,W,n-1));
}





int main()
{
int a[100];
int b[100];
int t,n,W;
int ans,i;


cin>>t;

while(t--)
{
 
 cout<<"Enter number of Different Weights\n";
 cin>>n;
 cout<<"Now Enter Different Weights and Their Value....\n";
 for(i=0;i<n;i++)
{
  cin>>a[i];
  cin>>b[i]; 
}
  

 cout<<"Ans is \n"<<knapsackDP(a,b,W,n)<<endl;
 
 
}


 return 0;
}


/*

http://www.geeksforgeeks.org/amazon-interview-experience-set-171/

http://www.geeksforgeeks.org/komli-media-interview-experience/

http://www.geeksforgeeks.org/browserstack-interview-experience-set-5-fresher/

http://www.geeksforgeeks.org/toptalent-interview-naveen-got-bloomreach/

http://www.geeksforgeeks.org/intuit-interview-experience-set-7-3-5-years-experienced/

http://www.geeksforgeeks.org/rockstand-interview-experience/

http://www.tutorialspoint.com/design_pattern/builder_pattern.htm

http://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/

http://www.geeksforgeeks.org/rockstand-interview-experience/ 

http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/

http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/

http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

http://www.geeksforgeeks.org/bipartite-graph/

http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/

http://www.geeksforgeeks.org/fill-two-instances-numbers-1-n-specific-way/

http://www.geeksforgeeks.org/optimal-read-list-given-number-days/

http://www.geeksforgeeks.org/find-paths-given-source-destination/

http://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/

http://en.wikipedia.org/wiki/15_puzzle

http://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/

http://www.geeksforgeeks.org/sort-array-wave-form-2/

*/




