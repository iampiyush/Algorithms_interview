
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




/*
int f(int arr[],int size)
{
 if(size<1)
 {
  cout<<"Invalid Input..";
  return 0;
 }

 int i,j;
 int n;
 
 n=size-1;
 
 for(i=0;i<size-1;i++)
 {
  for(j=0;j<n;j++)
   arr[j]=arr[j+1]-arr[j];
  n--;
 }

 return arr[0];

}
*/




int main()
{
int a[100];
int b[100];
int t,n,W;
int ans,i;


cin>>t;

while(t--)
{
 
 cout<<"Enter number of Elements\n";
 cin>>n;
 cout<<"Enter Different Numbers....\n";
 for(i=0;i<n;i++)
  cin>>a[i];


  //cout<<"Final Element is "<<f(a,n)<<endl;

   
}


 return 0;
}





