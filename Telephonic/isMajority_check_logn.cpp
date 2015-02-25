//   Divide And Conquer

//   check Majority Element check..using  first occurence and last occurences logrithmic functions..

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;




int firstOccurence(int a[],int start,int end,int key)
{
 if(end>=start)
 {
  int mid;
  mid=start+(end-start)/2;
  
  if( ( mid==0 || a[mid-1]<key ) && a[mid]==key)
   return mid;
  else if(a[mid]<key)
   return firstOccurence(a,mid+1,end,key); 
  else
   return firstOccurence(a,start,mid-1,key);
 }
 else
  return -1;
}



int lastOccurence(int a[],int start,int end,int key,int size)
{
 if(end>=start)
 {
  int mid;
  mid=start+(end-start)/2;
  
  if((mid==(size-1)  ||  a[mid+1]>key  ) &&   a[mid]==key)
   return mid;
  else if(a[mid]>key)
   return lastOccurence(a,start,mid-1,key,size); 
  else
   return lastOccurence(a,mid+1,end,key,size); 

 }
 else
  return -1;
}



bool isMajority(int a[],int size,int key)
{
 // if(a[size/2]!=key)
  // return false;

 int startIndex,endIndex;
 
 startIndex=firstOccurence(a,0,size-1,key);
 if(startIndex==-1)
  return false;
 int numberofElements;
 endIndex=lastOccurence(a,0,size-1,key,size); 


 cout<<startIndex<<" And "<<endIndex<<endl;
 numberofElements=(endIndex-startIndex)+1;
 
 cout<<numberofElements<<" And "<<(size/2+1)<<endl;
 
 if(numberofElements>=(size/2+1))
  return true;
 else 
 return false; 

}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
int iter,k;
int key;
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
 
 cout<<"Enter key..\n";
 cin>>key; 
  
 if(isMajority(a,n,key)==true)
 {
  cout<<"key is Majority Element"<<endl;
 }
 else
 {
  cout<<"key is not the Majority Element"<<endl;
 }

}


 return 0;
}


