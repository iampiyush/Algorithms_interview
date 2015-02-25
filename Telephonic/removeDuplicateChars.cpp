//  Remove Duplicate Elements...

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




void removeDuplicateChars(char a[])
{
 int i,j;
 int len;
 int myMap[256]; 
 len=strlen(a);
 
 for(i=0;i<256;i++)
   myMap[i]=0;
 
 for(i=0;i<len;i++)
  myMap[a[i]]=myMap[a[i]]+1;
  
 
  j=0; 
 for(i=0;i<len;i++)
 {
   if(myMap[a[i]]==1)
     a[j++]=a[i];
 }
  
 //  terminate string..
 a[j]='\0'; 


 return ;
}



int main()
{
   int t;
   int i;
   char a[1000];
   
   cin>>t;
   while(t--)
   {
    cout<<"Enter the string "<<endl;
    cin>>a;
    cout<<" String Is "<<a<<endl; 
    removeDuplicateChars(a);
    cout<<" String After Removal Is "<<a<<endl; 
   } 
   
    getchar();
    return 0;


 return 0;
}

