
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



bool findPattern(char text[],char pattern[])
{
 int len;
 int i;
 
 len=strlen(pattern);
 
 for(i=0;i<len;i++)
 {
  if(text[i]!=pattern[i])
  {
   return false;
  }
 }


 return true;
}


void replacePattern(char text[],char pattern[])
{
 int i,j;
 int state;
 int textLen,patternLen;
 bool isPresent;
 
 textLen=strlen(text);
 patternLen=strlen(pattern);
 
 
 
 
 state=0;
 j=0;
 for(i=0;i<(textLen-patternLen+1);)
 {
   if(text[i]==pattern[0])
   {
   //  pattern search here....
    isPresent=findPattern(text+i,pattern); 
    
    if(isPresent==true )
    {
      if(state==0)
      {                 
      text[j]='X'; 
      state=1;
      i=i+patternLen;
      j++;
      }
      else
      {
       i=i+patternLen;
      }
    }
    else
    {
     text[j]=text[i];
     state=0;
     i++;
     j++; 
    
    }   
   }
   else
   {
     text[j]=text[i];
     state=0;
     i++;
     j++;
   }   


}

  text[j]='\0';
 

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
   replacePattern(buf,a);
  //printArray(a,size);
  //printArray(b,size);
  cout<<buf<<endl<<endl;
}


 return 0;
}
