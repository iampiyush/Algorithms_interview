#include<iostream>
using namespace std;




void printArray(int a[],int size)
{
 int i;
 
 for(i=0;i<size;i++)
  cout<<a[i]<<" ";
  
  cout<<endl;
  return ;
}



void printKCombinationUtill(int a[],int output[],int outputIndex,int arrIndex,int n,int k,int& count)
{
     
 if(outputIndex==k)
 {
  count++;                 
  printArray(output,k);
  return ;
 }
  
 //   include current element..
 
  int i;
  
  for(i=arrIndex;n-i>=k-outputIndex;i++)
  {
   output[outputIndex]=a[i];
   printKCombinationUtill(a,output,outputIndex+1,i+1,n,k,count);
  }  
  return ;
}



void printKCombinationFromSet(int a[],int n,int k)
{
 int len;
 
 if(k<1)
  return ;
/* 
 if(k>len)
 {
  cout<<"Invalid K....can't print anything...."<<endl;
  return ;
 }
 */
 
 int output[k+1];
 int count=0; 
 printKCombinationUtill(a,output,0,0,n,k,count);
 // cout<<"Count is "<<count<<endl;
 return ;
}


int main()
{
 int a[100];
 int k;
 int n;
 int t;
 int i;
 
 cin>>t;
 
 while(t--)
 {
  cout<<"Input Size..\n";
  cin>>n;
  
  for(i=0;i<n;i++)
   cin>>a[i];
  
  
  cout<<"Input K\n";
  cin>>k;
  
  printKCombinationFromSet(a,n,k);
  

 }
 
 
 return 0;

}
