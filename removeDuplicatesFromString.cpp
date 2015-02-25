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


void removeDuplicateBitVector(char str[])
{
 int i,j;
 int len,index;
 unsigned char mymap[26];
 len=strlen(str);

 for(i=0;i<26;i++)
  mymap[i]=0;
  
 j=0;
 for(i=0;i<len;i++)
 {
  if(str[i]>='a'  &&  str[i]<='z')
  {
  index=str[i]-'a';                 
   if(mymap[index]==0)
   {
    str[j]=str[i];
    mymap[index]=1;
    j++;
   }
  }
  else
  {
  //assert(0); 
   cout<<"Wrong Input\n";
   break;
  }
 } 

  str[j]='\0';

 return ;
}


//   method considering '\0' as special token
void removeDuplicate2(char str[])
{
 int len,i,j,k;
 int countUnique;
 int state; 
 len=strlen(str);
 
 
 
 //countUnique=0;
 i=0;
 j=0;
 while(i<len)
 {
  if(str[i]!='\0')
   {
    str[j]=str[i];
    
    for(k=j+1;k<len;k++)
     { 
      if(str[k]==str[j])
       str[k]='\0';    
     }
   
   j++;
  }
  i++;  
 }
 
 str[j]='\0'; 

  return ;
}





void removeDuplicate(char str[])
{
 int len,i,j,k;
 int state; 
 len=strlen(str);
 
 
 i=0;
 j=0;
 while(i<len)
 {
  if(str[i]!='$')
   {
    str[j]=str[i];
    
    for(k=j+1;k<len;k++)
     { 
      if(str[k]==str[j])
       str[k]='$';    
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
 removeDuplicateBitVector(buf);
 cout<<buf<<endl;
}


 return 0;
}
