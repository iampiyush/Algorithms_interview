

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;





void constructFailFunction(char pat[],int fail[])
{
 int i,j;
 int len;
 int n;
 
 n=strlen(pat);
 

 len=0;
 fail[0]=0;
 i=1;
 while(i<n)
 {
  if(pat[i]==pat[len])
  {
   len++;
   fail[i]=len;
   i++;
  }
  else  //  if  not equal..
  {
   if(len!=0)
   {
    len=fail[len-1];
   }
   else
   {
    fail[i]=0;
    i++; 
   }
  }
  
}  //  end of while..
  
  
  
 // cout<<"Fail Function Output...\n";
 // for(i=0;i<n;i++)
  // cout<<fail[i]<<" ";
   
  cout<<endl; 
  return ;

}

int Search(char text[],char pat[])
{
 int i,j;
 int textLen,patLen;
 int result=-1;
  
 
   textLen=strlen(text);
   patLen=strlen(pat);
   
   cout<<textLen<<" "<<patLen<<endl;
  
  int fail[patLen+1];
 
  int textIndex;
  int patIndex;
  
  
  constructFailFunction(pat,fail);
  
  patIndex=0;
  for(textIndex=0;textIndex<textLen;)  
  {
   if(text[textIndex]==pat[patIndex])
   {
    textIndex++;
    patIndex++;
   }
   
   if(patIndex==patLen)
   {
    if(result==-1)
    {
     result=textIndex-patIndex;
    }
    cout<<" pattern found "<<textIndex-patIndex<<endl;
    patIndex=fail[patIndex-1];
   }
  
   else if(pat[patIndex]!=text[textIndex])
   {
    if(patIndex!=0)
     patIndex=fail[patIndex-1];
    else
     textIndex=textIndex+1; 
   }
  
  }   //  end of for loop..
 

 return result;

}










int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
int iter,k;
char text[100],pat[100];

cin>>t;

while(t--)
{
  cin>>text;
  cin>>pat;
 
 ans=Search(text,pat);
 //cout<<buf<<endl;
 cout<<"Answer Is "<<ans<<endl;
}


 return 0;
}
