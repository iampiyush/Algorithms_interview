
//   only 1 Missing Number
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


 for(i=0;i<n;i++)
 {
  xorn=xorn^(i+1);
  xora=xora^a[i];
 }
 
 cout<<"Missing Number is "<<(xorn^xora)<<endl;
 
 return ;
}




void findMissingNumber(int a[],int n)
{
 int i,j;
 int sum=0;
 int arr_sum=0;
 
 /*
 for(i=1;i<=n;i++)
  sum=sum+i;
 */
 
  sum=(n*(n+1))/2;

 for(i=0;i<n;i++)
  arr_sum=arr_sum+a[i];



 
 cout<<"Missing number Is "<<(sum)-(arr_sum)<<endl;
 
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

