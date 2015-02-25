
/*
 Replace all occurrence of the given character to another character ‘X’.
 Note that multiple occurrences of character that are contiguous will be replaced with only one ‘X’.
*/

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


void interLeavingElegantCode(char str[],char a[],char b[])
{
 
 while(*str!='\0')
 {
  if(*str==*a)
   a++;
  else if(*str==*b)
  b++;
  else
  break;  
  
  str++;
 } 

 if(*a || *b )
 {
  cout<<"Not Interleaving...\n"; 
 }
 else
 {
 cout<<"Interlaving of 2 strings..."<<endl;
 }
 
 return ;
}


void interLeaving(char str[],char a[],char b[])
{
  int i,j,k;
  int len;
  char c;
  
  len=strlen(str);
  
  k=j=i=0;
  while(k<len && i<strlen(a)  && j<strlen(b))
  {
   //   check weather this character belongs to any string..
   c=str[k];
  
   if(c==a[i])
     i++;
   else if(c==b[j])  
    j++;
   else
    {
    cout<<"Wrong Answer..\n";
    return ;
    }  
  
   k++;
  }
  
  
  if(k==len)
  {
   // done..
   cout<<"Interlaving of 2 strings..."<<endl;
   return ;
  }
  else
  {
   if(j==strlen(b))
   {
    while(k<len)
    {
     if(a[i]!=str[k])
     {
      cout<<"Wrong Answer..\n";
      return ;
     }
     k++;
     i++;
    }
   }
   else
   {
     while(k<len)
    {
     if(b[j]!=str[k])
     {
      cout<<"Wrong Answer..\n";
      return ;
     }
     k++;
     j++;
    }
   }  
  
  }

 cout<<"Interlaving of 2 strings..."<<endl;
  return ;
}




int main()
{

int t,size,i;
char buf[100];
char a[100],b[100];

cin>>t;

   while(t--)
  {
   cout<<"Enter Test String..\n";
   cin>>buf;
   
   cout<<"Enter two strings..\n";
   cin>>a;
   cin>>b;
 // findElements(a,size);
  //  compreesString(buf);
   interLeavingElegantCode(buf,a,b);
  //printArray(a,size);
  //printArray(b,size);
  //cout<<buf<<endl<<endl;
}


 return 0;
}
