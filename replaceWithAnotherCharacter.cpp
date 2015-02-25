
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



void replaceString(char str[],char a,char b)
{
 int i,j;
 int state;
 
 cout<<a<<" "<<b<<endl;
 
 state=0;
 j=0;
 for(i=0;str[i]!='\0';i++)
 {
   if(str[i]==a && state==0)
   {
   str[j]=b;
   state=1;
   j++;
   }
   else if(str[i]!=a)
   {
    str[j]=str[i];
    state=0;
    j++;
   }  
}

  str[j]='\0';
 

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
   
 
  //printArray(a,size);  
  //printArray(b,size);
   cout<<"Enter chars..\n";
   cin>>a;
   cin>>b;
 // findElements(a,size);
  //  compreesString(buf);
   replaceString(buf,a,b);
  //printArray(a,size);
  //printArray(b,size);
  cout<<buf<<endl<<endl;
}


 return 0;
}
