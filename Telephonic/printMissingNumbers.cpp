//Given an array of size N. It contains numbers in the range 1-N. 
//Find the numbers which are not present.


#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;



void printNonExistentElement(int a[],int n)
{
 int i;
 int index;
 
 
 for(i=0;i<n;i++)
 {
  index=abs(a[i])-1;
  if(a[index]>0)
   a[index]=-a[index]; 
 }



 for(i=0;i<n;i++)
  if(a[i]>0)
   cout<<i+1<<" ";
   
  
  cout<<endl;


 return ;
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
  
 printNonExistentElement(a,n);
 
 

}


 return 0;
}


