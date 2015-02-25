

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>


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


int reverseIndiviualWords(char str[])
{
 int len;
 int state;
 len=strlen(str);
 int i,j;
 int wordCount=0;
 
 state=1;
 for(i=0;i<len;i++)
 {
  if(isalphas(str[i]))
  {
   if(state==1)
   {
    state=0;
    wordCount++;
   }
  }
  else
  {
   state=1;
  } 
}
 

  return wordCount;

}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 gets(buf);
 cout<<reverseIndiviualWords(buf)<<endl; 
 //cout<<buf<<endl;
}


 return 0;
}
