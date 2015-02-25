#include<iostream>
using namespace std;



void printKCombinationUtill(char set[],char output[],int outputIndex,int n,int k,int& count)
{
     
 if(outputIndex==k)
 {
  count++;                 
  cout<<output<<endl; 
  return ;
 }
  
 //   include current element..
 
  int i;
  
  for(i=0;i<n;i++)
  {
   output[outputIndex]=set[i];
   printKCombinationUtill(set,output,outputIndex+1,n,k,count);
  }  
  return ;
}



void printKCombinationFromSet(char a[],int k)
{
 int len;
 
 len=strlen(a);
/* 
 if(k>len)
 {
  cout<<"Invalid K....can't print anything...."<<endl;
  return ;
 }
 */
 
 char buf[k+1];
 buf[k]='\0';
 int count=0; 
 printKCombinationUtill(a,buf,0,len,k,count);
 // cout<<"Count is "<<count<<endl;
 return ;
}


int main()
{
 char a[100];
 int k;
 int t;
 
 
 cin>>t;
 
 while(t--)
 {
  cout<<"Input String..\n";
  cin>>a;
  
  cout<<"Input K\n";
  cin>>k;
  
  printKCombinationFromSet(a,k);
  

 }
 
 
 return 0;

}
