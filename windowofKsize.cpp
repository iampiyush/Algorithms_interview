

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>



using namespace std;




int iterSum(int a[],int size,int iter)
{
 int i,j;
 int sum=0;
 
 if(iter>size-1)
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



void maxWindow(int a[],int b[],int size,int w)
{
 int i,j;
 deque<int> mq;
 int wait;
 int cur;
 
 
 //  initial set up...

 
 for(i=0;i<w;i++)
 {
  cur=a[i];
  while(mq.empty()==false)
  {
   if(mq.back()>cur)
     break;
   //cout<<"break..\n";
   mq.pop_back();
  }
  
  //cout<<"Wo\n";
  mq.push_back(cur) ;   //      push current element in the queue.... it can be maximum value
 }

  //cout<<"Bug\n";


 b[0]=mq.front();
 //cout<<b[0]<<endl;
 
 j=1;
for(i=w;i<size;i++)
 {
  cur=a[i];
  while(mq.size()!=0)
  {
   if(mq.back()>cur)
     break;
   mq.pop_back();
  }
  
  
  if(mq.size()==0 || mq.size()!=w)
   mq.push_back(cur) ;   //      push current element in the queue.... it can be maximum value
   else
   {
   mq.pop_front();
   mq.push_back(cur);
   }
   
   b[j]=mq.front();   //    assign max value to the j th window....
   j++;
 }

 b[j]=-1;
 return ; 

}





//  0(n*k)...
void makeMaxWindow(int a[],int b[],int size,int w)
{
 if(w>size ||  size<1)
 {
  cout<<"Illegal Window Size or Array Size....\n";
  b[0]=-1;
  return ;
 }
 
 int i,j;
 int k=0;
 int max;
 
 for(i=0; i<(size-w+1)  ;i++)
 {
  max=INT_MIN;           
  for(j=i;j<i+w;j++)
  {
   if(a[j]>max)
    max=a[j];
  }
  
 // update maximum....
  b[k]=max;
  k++;
 }
 
 b[k]=-1;
 
 return ;
  
}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
int iter,k;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 cin>>size;
 for(i=0;i<size;i++)
  cin>>a[i];
 
 cout<<"Enter Window Size..\n\n";
 cin>>k;
  
 
 maxWindow(a,b,size,k); 
 
 for(i=0;b[i]!=-1;i++)
  cout<<b[i]<<" ";
  
  cout<<endl;
 
 //cout<<buf<<endl;
}


 return 0;
}
