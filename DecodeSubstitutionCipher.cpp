//  program Anagrams Together...

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<string>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>


using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}


bool isalphas(char c)
{
 if((c>= 'a'   &&  c<= 'z')    || (c>= 'A'   &&  c<= 'Z') )
   return true;
 return false;     
}


void reverse(char *start,char *end)
{
 char c;
 while(start<end)
 {
  c=*start;
  *start=*end;
  *end=c;
  start++;
  end--;
 }


 return ;
}


void decode(char buf[],int dis)
{
 int i;
 int len;
 
 len=strlen(buf);
 for(i=0;i<len;i++)
 {
  buf[i]=buf[i]-dis;
  if(buf[i]<'a')
   buf[i]=buf[i]+26;
 }


 return ;
}


int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
char buf[100];
int dis;


cin>>t;
fflush(stdin);
while(t--)
{
 //cin>>buf;
 cin>>buf;
 cin>>dis;
 decode(buf,dis);
 cout<<"Decoded Message "<<buf<<endl;
}


 return 0;
}
