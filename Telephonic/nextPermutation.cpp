#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
 
 
 



void nextPermutation(char a[],char next[])
{
 int i,j,len;
 char ch;
 int min,minIndex;
 len=strlen(a);
 
 
 next[len]='\0';
 for(j=len-1;j>0;j--)
 {
  if(a[j]>a[j-1])
  {
   break;
  } 
 }

 if(j==0)
 {
  cout<<"No bigger permutation Possible..."<<endl;
  next[0]='\0';
  return ;
 }


 ch=a[j-1];
 min=150;
 for(i=j;i<len;i++)
 {
   if(a[i]>ch  &&  a[i]<min)
   {
    minIndex=i;
    min=a[i];
   }
 }
 
  swap(a[j-1],a[minIndex]);
  
   for(i=0;i<len;i++)
   next[i]=a[i];
  
  swap(a[j-1],a[minIndex]);
  
 // sort(next+j,next+len);   //  fix sort now...
  
  
  i=j;
  j=len-1;
  while(i<j)
  {
   ch=next[i];
   next[i]=next[j];
   next[j]=ch;
   i++;
   j--;
  }

  
  return ;
}

 
int main()
{
 int t;
 int i;
 int len;
 char str[100];
 char next[100];
 
 cin>>t;
 
 while(t--)
 {
  cin>>str;
  nextPermutation(str,next);
  cout<<"Next permutation for string "<<str<<" is "<<next<<endl;
 }
 
  getchar();
  return 0;
}


