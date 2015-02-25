

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>


using namespace std;




int iterSum(int a[],int size,int iter)
{
 int i,j;
 int sum=0;
 
 if(iter>size-2)
 {
  cout<<"Invalid Input...\n";
  return 0;
 }
 int n;
 
 n=size-1;
 for(i=0;i<iter;i++)
 {
  for(j=0;j<n;j++)
  {
   a[j]=a[j+1]-a[j];
  }
   n--;
}


for(i=0;i<=n;i++)
 sum=sum+a[i];




 return sum;
}




int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
int iter;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 cin>>size;
 for(i=0;i<size;i++)
  cin>>a[i];
 
 cout<<"Enter Number Of iterations..\n";
 cin>>iter;
  
 cout<<"Sum is "<<iterSum(a,size,iter)<<endl; 
 //cout<<buf<<endl;
}


 return 0;
}
