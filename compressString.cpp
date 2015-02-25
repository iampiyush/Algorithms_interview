// Find MISSING eLEMENTS  using Sorting...
//  time complexity   0(n)...
//  space complexity   0(1)....



#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>


using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}



void compreesString(char str[])
{
 int len,i,j;
 int state; 
 len=strlen(str);
 
 
 i=0;
 j=0;
 state=0;
 while(i<len)
 {
  if(str[i]==' '  &&  state==1)
  {
    //  do nothing...
  }
  else
  {
   if(str[i]==' ')
   {
    str[j]=str[i];
    state=1;
   }
   else
   {
    str[j]=str[i];
    state=0;
   }  
   j++;
  }  
  
  i++;  
 }
 
 str[j]='\0'; 

  return ;
}




int main()
{
int a[100];
int b[100];
int t,size,i;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 gets(buf);
 
  //printArray(a,size);  
  //printArray(b,size);
  
 // findElements(a,size);
  compreesString(buf);
  //printArray(a,size);
  //printArray(b,size);
  cout<<buf<<endl;
}


 return 0;
}
