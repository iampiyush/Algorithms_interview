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


void printMaxAndSecondMax(int a[],int size)
{
     
 if(size<1)
 {
  cout<<"Invalid Input..\n";
  return ;
 }
 
 int i,j;
 int max,secondmax;
 
 max=secondmax=-1;
 for(i=0;i<size;i++)
 {
  if(a[i]>max)
  {
   secondmax=max;
   max=a[i];
  }
  else if(a[i]>secondmax)
   secondmax=a[i];
 }
 
 cout<<max<<" "<<secondmax<<endl;
 return ;
}


int main()
{
int a[100];
int b[100];
int t,size,i,n;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 cin>>n;
 for(i=0;i<n;i++)
  cin>>a[i];
  
  printMaxAndSecondMax(a,n); 

}


 return 0;
}
