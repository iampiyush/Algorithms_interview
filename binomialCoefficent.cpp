//  program to calculate the binomial coeffiecent   of n to k objects......
/*
  binomial(n,k)=binomial()+binomial();
 
   

*/



#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<string>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<map>
#define size 1000


using namespace std;


int M[8000][8000];


int maximum(int a,int b)
{
 if(a>b)
  return a;
 else 
 return b; 
}


// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
 
 return ;
}




void binomialCoeffiecntDP()
{
 int i,j;
 for(i=0;i<size;i++)
 {
  for(j=0;j<size;j++)
  {
   if(i<j)                  
    M[i][j]=0;
   else
    M[i][j]=1;
  } 
  // cout<<endl; 
 }
 
 
 for(i=1;i<size;i++)
 {
  for(j=1;j<size;j++)
   if(i>=j)
   M[i][j]=M[i-1][j]+M[i-1][j-1];    
 }
 
 
  return ;
}




int binomialCoeffiecnt(int n,int k)
{
 if(n<k)
  return 0;
     
 if(k==0  ||  n==k )
   return 1;
 else
  return binomialCoeffiecnt(n-1,k)+binomialCoeffiecnt(n-1,k-1);  
}





int main()
{
int t,n,k;
int ans,i;



binomialCoeffiecntDP();
cin>>t;
while(t--)
{
 
 cout<<"Enter The Value of n \n";
 cin>>n;
 cout<<"Enter The value of k\n";
 cin>>k;

 //cout<<"Ans is \n"<<binomialCoeffiecnt(n,k)<<endl;
 cout<<"Ans is \n"<<M[n][k]<<endl;
 
}


 return 0;
}





