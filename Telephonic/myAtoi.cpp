

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;



bool isIntegar(char ch)
{
 if(ch>='0' &&  ch<='9')
  return true;
 return false;
}



int myAsceeToIntegar(char str[])
{
 int i,j;
 int len;
 int sum;
 int dig;
 char curChar;
 
 len=strlen(str);

 if(len<=0)
  return 0;

  int sign=1;
  
  i=0;
  if(str[i]=='-')
 {
   sign=-1;
   i++;
 }
 else if(str[i]=='+') 
 {
  sign=1;
  i++;
 } 
   
 
  sum=0;
 for(;i<len;i++)
 {
  curChar=str[i];
  if(isIntegar(curChar))
  {
   dig=curChar-'0';
   cout<<dig<<endl;
   sum=(sum*10)+dig;
  }
  else
   break;
 
 } 


 sum=sign*sum;
 return sum;

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
  cin>>buf;
 
 ans=myAsceeToIntegar(buf);
 //cout<<buf<<endl;
 cout<<"Answer Is "<<ans<<endl;
}


 return 0;
}
