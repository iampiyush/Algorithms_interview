

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


char* getFirstLetterWord(char str[])
{
 int len;
 int state;
 len=strlen(str);
 int i,j,k;
 int wordCount=0;
 char *buf;
 buf=(char*)malloc(len+1);
 
 state=1;
 k=0;
 for(i=0;i<len;i++)
 {
  if(isalphas(str[i]))
  {
   if(state==1)
   {
    state=0;
    buf[k]=str[i];
    k++;
    wordCount++;
   }
  }
  else
  {
   state=1;
  } 
}
 
 buf[k]='\0';
  return buf;

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
 cout<<getFirstLetterWord(buf)<<endl; 
 //cout<<buf<<endl;
}


 return 0;
}
