
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;


//  0(n*k)...
int minDistance(int a[],int size,int x,int y)
{
 int i,j;
 int k=0;
 int max;
 int prev,cur;
 int min=INT_MAX;
 int prevIndex=-1;
 
 int flag;
 
 
 if(x==y)
  flag=1;
 else
 flag=0;
 
 
 for(i=0;i<size;i++)
 {
  if(a[i]==x   ||  a[i]==y)
  {
   prev=a[i];
   prevIndex=i;
   break;
  }
 }


  for(i=i+1;i<size;i++)
  {
   cur=a[i];               
   if(a[i]==x   ||  a[i]==y)
   {
    if(cur==prev)
    {
     if(flag==1)
     {
      if(min>(i-prevIndex))
      min=i-prevIndex;
      prev=cur;
      prevIndex=i;
     
     }
     else
    {
     prev=cur;   
     prevIndex=i;
     }
    }
    else
    {
     if(min>(i-prevIndex))
      min=i-prevIndex;
      prev=cur;
      prevIndex=i;
    }
   }
   
  }




 return min;
  
}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
int iter,k;
int x,y;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 cin>>size;
 for(i=0;i<size;i++)
  cin>>a[i];
 
 
  cout<<"Enter X and Y..\n";
  cin>>x;
  cin>>y;
  
 
 cout<<minDistance(a,size,x,y)<<endl; 
 

  
  cout<<endl;
 
 //cout<<buf<<endl;
}


 return 0;
}
