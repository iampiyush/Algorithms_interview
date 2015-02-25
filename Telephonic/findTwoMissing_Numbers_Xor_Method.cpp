
//   only 2 Missing Number
//Find out non repeating numbers Given an array having numbers from 1 to N in 
//random order such that all numbers except two are repeating, find out the two numbers...

//  Simulate A queue Using Stack....


#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;



// swap two variables...




void findMissingNumber_Xor(int a[],int n)
{
 int i,j;
 int xorn=0;
 int xora=0;
 int one;
 int x,y;

 for(i=0;i<n;i++)
 {
 // xorn=xorn^(i+1);
  xora=xora^a[i];
 }
 
 //   xora would be now xor of the two Missing Number...
 //  now find RightMost Set Bit of this Number
 
 one=1;
 i=0;
 while( i<((sizeof(int)*8)-1) && (xora&one)==0)
 {
  one=one<<1;
  i++;
 }
 
 
 x=0;y=0;
 for(i=0;i<n;i++)
 {
  if(one&a[i])
   x=x^a[i];
  else
   y=y^a[i]; 
 } 


 cout<<"Missing Numbers are  "<<x<<" "<<y<<endl;
 
 return ;
}



int main()
{
   int t;
   int i,n;
   int ans;
   int a[1000],b[1000];
   
   
   cin>>t;
   while(t--)
   {   
     cout<<"Enter value of n \n";     
     cin>>n;   
     
     cout<<"Enter n Elements..\n";
     for(i=0;i<n;i++)
      cin>>a[i];
      
     //findMissingNumber(a,n);
     findMissingNumber_Xor(a,n);
   } 
   
 return 0;

}

