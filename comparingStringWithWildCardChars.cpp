
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




void comparingStringWithWildCardChars(char a[],char b[])
{
  int i,j;
  int len;
  
  len=strlen(a);
  if(len!=strlen(b))
  {
     cout<<"MisMatch..\n";
     return ;
  }
  
  for(i<0;i<len;)
  {
   if(a[i]!='?')
   {
    if(a[i]!=b[i])
    {
     cout<<"MisMatch..\n";
     return ; 
    }
 
   }
   i++;
   j++;
  }
  
  cout<<"Strings match..\n";
  return ;
}




int main()
{

int t,size,i;
char buf[100];
char a[100],b;

cin>>t;

while(t--)
{
 //cin>>buf;
   cout<<"Enter String..\n";
   //gets(buf);
   cin>>buf;
   
 
  //printArray(a,size);  
  //printArray(b,size);
   cout<<"Enter chars..\n";
   cin>>a;
  // cin>>b;
 // findElements(a,size);
  //  compreesString(buf);
   comparingStringWithWildCardChars(buf,a);
  //printArray(a,size);
  //printArray(b,size);
  cout<<buf<<endl<<endl;
}


 return 0;
}
