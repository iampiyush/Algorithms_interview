#include<iostream>
using namespace std;



void printKCombinationUtill(char set[],char output[],int setIndex,int outputIndex,int n,int k,int& count)
{
     
 if(outputIndex==k)
 {
  count++;                 
  cout<<output<<endl; 
  return ;
 }
 if(setIndex==n)
  return ;
  
 //   include current element..
  output[outputIndex]=set[setIndex];
  printKCombinationUtill(set,output,setIndex+1,outputIndex+1,n,k,count);

//   exclude element..
  printKCombinationUtill(set,output,setIndex+1,outputIndex,n,k,count);
   
  return ;
}



void printKCombination(char a[],int k)
{
 int len;
 
 len=strlen(a);
 
 if(k>len)
 {
  cout<<"Invalid K....can't print anything...."<<endl;
  return ;
 }
 
 char buf[k+1];
 buf[k]='\0';
 int count=0; 
 printKCombinationUtill(a,buf,0,0,len,k,count);
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
  
  printKCombination(a,k);
  

 }
 
 


}
