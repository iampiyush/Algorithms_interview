//  program to reverse individual words from the given string....

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



void reverseOrderOfWords(char str[])
{
 int len;
 int state;
 len=strlen(str);
 int i,j;
 int wordCount=0;
 char *start,*end;
 
 
 reverse(str,str+len-1);
 
 
 state=1;
 for(i=0;i<len;i++)
 {
  if(isalphas(str[i]))
  {
   if(state==1)
   {
    start=str+i;
    state=0;
    //wordCount++;
   }
  }
  else
  {
   if(state==0)
   {
    state=1;
    end=str+i-1;
    reverse(start,end);
    //  reverse the words...
   }

  } 
}  //   end of for loop..
 
    //end=str+len-1;
   reverse(start,str+len-1);

  return ;

}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
char buf[100];

cin>>t;
fflush(stdin);
while(t--)
{
 //cin>>buf;
 gets(buf);
 reverseOrderOfWords(buf); 
 cout<<buf<<endl;
}


 return 0;
}
