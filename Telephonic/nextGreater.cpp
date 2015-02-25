

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;



void  printMaxKElements(int a[],int n,int k)
{
 int i,j;
 int temp[k+10];
 int min;
 int minIndex;
 int cur;
 
 min=INT_MAX;
 minIndex=-1;
 for(i=0;i<k;i++)
 {
  temp[i]=a[i];
  if(min>temp[i])
  {
   min=temp[i];
   minIndex=i;
  }
 }


 for(;i<n;i++)
 {
  cur=a[i];
  if(cur>min)
  {
   temp[minIndex]=cur;
   min=cur;
   
   //   0(k)  Step...
   for(j=0;j<k;j++)
   {
    if(min>temp[j])
    {
     min=temp[j];
     minIndex=j;
    } 
   } 
  }
  //   else igonre....
 }
 
 
 cout<<"Max k Elements are..\n";
 for(j=0;j<k;j++)
  cout<<temp[j]<<" ";
 
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
  
  cin>>k;
  printMaxKElements(a,n,k);

}


 return 0;
}


