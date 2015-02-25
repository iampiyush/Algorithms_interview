/*
 There are 2 sorted arrays A and B of size n each. Write an algorithm to 
 find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n).
*/

#include<iostream>
//#include<cwindows>
#include<cstdio>
#include<ctime>
#include<unistd.h>

using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}



void printArray(int arr[],int size)
{
 if(size<1)
 {
  cout<<"Wrong Array size "<<endl;
  return ;
 }     
 int i;
 
 for(i=0;i<size;i++)
  cout<<arr[i]<<" ";

 cout<<endl;

}



//  finding median in 0(n)  time...just for implementation purspose...
int findMedian(int a[],int b[],int size)
{
 int i,j,k;
 int median;
 int sum=0;
 
 
 i=j=k=0;
 while(k<size-1)
 {
  
  if(a[i]<b[j])
   i++;
  else
  j++; 
  
  k++;
 }
 
 

// find next 2 mins...
 if(a[i]>b[j])
  sum=b[j++];
 else
   sum=a[i++];
 

 if(i==size)
 {
  sum+=b[j];
 }
 else if(j==size)
 {
  sum+=a[i];
 }
 else
 {
  if(a[i]>b[j])
   sum+=b[j++];
  else
   sum+=a[i++];
 }
 
 median=sum/2;
 
 return median;
}




int main()
{
int a[100];
int b[100];
int t,size,i;

cin>>t;

while(t--)
{
 cin>>size;
 
 for(i=0;i<size;i++)
  cin>>a[i];
  
 for(i=0;i<size;i++)
  cin>>b[i];
  
 int median=findMedian(a,b,size);

 
  cout<<median<<endl;

}


 return 0;
}
