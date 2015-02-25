
/*
 Replace all occurrence of the given character to another character ‘X’.
 Note that multiple occurrences of character that are contiguous will be replaced with only one ‘X’.
*/

#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>
#include<cstdlib>

using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}



void  compreesString(char str[])
{
 int i,j,k,l,m;
 int state;
 int len;
 int dig;
 int count;
 
 len=strlen(str);
 char *buf;
 char x[1000];
 
 buf=(char*)malloc(len*2+1);
 if(buf==NULL)
 {
 cout<<"Less memory Avaialvle..buy a new hard disk..\n";
 return ;
 } 
 

 char ch;
 
 j=0;
 k=0;
 i=0;
 while(i<len)
 {
  ch=str[i];
  j=i+1;
  count=1;
  
  //count chars here....
  while(j<len && ch==str[j])
  {
     j++;
    count++;
  }
 //   fill in output buffer...
  buf[k++]=ch;
  
  itoa(count,x,10);
   m=0;
   dig=strlen(x);
  // cout<<x<<endl;
   while(m<dig)
   {
    buf[k++]=x[m];           
    m++;
   }
 
  i=j;  // updating i...
 }
  
 // cout<<"k 's value is  "<<k<<endl; 
 buf[k]='\0';
  
  // cout<<"Compressed output is..\n";
   cout<<buf<<endl;
  return ;
}




int main()
{

int t,size,i;
char buf[100];
char a,b;

cin>>t;

while(t--)
{
 //cin>>buf;
   cout<<"Enter String..\n";
   //gets(buf);
   cin>>buf;
   //cout<<buf<<endl;  
 
 compreesString(buf);
  // replaceString(buf,a,b);
  //printArray(a,size);
  //printArray(b,size);
 
}


 return 0;
}
