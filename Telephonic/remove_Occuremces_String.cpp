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

void swap(char &x,char &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}




bool isPattern(char a[],char b[])
{
 int i,j;
 int len1,len2;
 
 len1=strlen(a);
 len2=strlen(b); 

 i=0;
 j=0;
 while(i<len1 &&  j<len2)
 {
  if(a[i]!=b[j])
   return false;
      
  i++;
  j++;
 }
 //  end of while loop..
 if(j==len2)
  return true;
 else
  return false; 
}

void  removeOccurences(char a[],char b[])
{
 int i,j;
 int len1=strlen(a);
 int len2=strlen(b);
 bool state;
 
 j=0;
 for(i=0;i<len1;)
 {
  if(a[i]==b[0])
  {
   state=isPattern(a+i,b);
   if(state)
   {
    i=i+len2;
   }
   else
   {
    a[j]=a[i];
    i++;
    j++; 
   }
  }  //  if not equal....
  
  else
  {
    a[j]=a[i];
    i++;
    j++; 
  }
 } 

 a[j]='\0';


 return ;
}


int main()
{
//int a[100];
//int b[100];
int t,size,i;
char a[100],b[100];

cin>>t;

while(t--)
{
 //cin>>buf;
  cout<<"Input Text String \n";
  cin>>a;
  
  cout<<"Input Pattern String..\n";
  cin>>b;
  
 
  removeOccurences(a,b);
 
  //printArray(a,size);
  //printArray(b,size);
  cout<<a<<endl;
}


 return 0;
}
