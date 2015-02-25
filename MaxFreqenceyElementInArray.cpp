

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
#include<map>



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

void printMaxFreqNum(int a[],int size)
{
 int min,max;
 int index;
 int i;
 map<int,int> mymap;
   
   
 max=INT_MIN;
 for(i=0;i<size;i++)
 {
  index=a[i];                  
  mymap[index]=mymap[index]+1;
  if(max<mymap[index])
    max=mymap[index];
 }


for(i=0;i<size;i++)
{
 index=a[i];
 if(mymap[index]==max)
 {
  cout<<index<<" ";
  mymap[index]=-1;
 }
}


cout<<endl;

return ;
}







void printMaxFreqNum2(int a[],int size)
{
 int min,max;
 int index;
 int i;
 int mymap[10000];

 
 
 
 for(i=0;i<10000;i++)
  mymap[i]=0;
   
   
 max=INT_MIN;
 for(i=0;i<size;i++)
 {
  index=a[i];                  
  mymap[index]=mymap[index]+1;
  if(max<mymap[index])
    max=mymap[index];
 }


for(i=0;i<size;i++)
{
 index=a[i];
 if(mymap[index]==max)
 {
  cout<<index<<" ";
  mymap[index]=-1;
 }
}


cout<<endl;

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
 
 printMaxFreqNum(a,size); 
 

  
  cout<<endl;
 
 //cout<<buf<<endl;
}


 return 0;
}
