// Find MISSING eLEMENTS  using Sorting...
//  time complexity   0(n)...
//  space complexity   0(1)....



#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>


using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}




void printArray(int a[],int size)
{
 int i;
 
 
 cout<<"Array is \n";
 for(i=0;i<size;i++)
  cout<<a[i]<<" ";
  
 cout<<endl; 
 return ;
}



void solve(int a[],int b[],int size)
{
 int i,j;
 int left[1000];
 int right;
 
 cout<<"New Solve Function..\n";
 // fill left array...
 left[0]=1;
 for(i=1;i<size;i++)
  left[i]=left[i-1]*a[i-1];

 right=1;
 for(i=size-1;i>-1;i--)
 {
  b[i]=left[i]*right;
  right=right*a[i];
 } 

 
 return ;
}




//  using 2 arrayss...
void solve2(int a[],int b[],int size)
{
 int i,j;
 int left[1000], right[1000];
 
 
 // fill left array...
 left[0]=1;
 for(i=1;i<size;i++)
  left[i]=left[i-1]*a[i-1];

//  fill right array..
 right[size-1]=1;
 for(i=size-2;i>-1;i--)
  right[i]=right[i+1]*a[i+1];

 for(i=0;i<size;i++)
  b[i]=left[i]*right[i];
 
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
  
  solve(a,b,n);
  printArray(b,n);
 
 }


 return 0;
}
