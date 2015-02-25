// Find common Elements in Two sorted
//  time complexity   0(n2)...
//  space complexity   0(1)....



#include<iostream>
//#include<cwindows>
#include<cstdio>
#include<ctime>
#include<unistd.h>

using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}



void printArray(int arr[],int size)
{
 if(size<1)
 {
  cout<<"Wrong Array size "<<endl;
  return ;
 }     
 int i;
 
 for(i=0;i<size;i++)
  cout<<arr[i]<<" ";

 cout<<endl;

}


void printCommanElements(int a[],int b[],int size)
{
 int buffer[size+1];
 int i,j;
 int k=0;
 
  i=0;
  j=0;
  while(i<size && j<size )
  {
   if(a[i]>b[j])
    j++;
   else if(a[i]<b[j])
    i++;
   else
   {
    buffer[k]=a[i];
    i++;
    j++;
    k++;
   } 
  }
    

  cout<<"K is "<<k<<endl;
  for(i=0;i<k;i++)
   cout<<buffer[i]<<" "; 


  return ;
}




int main()
{
int a[100];
int b[100];
int t,size,i;

cin>>t;
while(t--)
{
 cin>>size;
 
 for(i=0;i<size;i++)
  cin>>a[i];
  
 for(i=0;i<size;i++)
  cin>>b[i];
  
  
  //printArray(a,size);  
  //printArray(b,size);
  
  cout<<"Inplace Merge \n";
  //sleep(1000);
/*
  for(i=0;i<900000000;i++);
   cout<<" ..";
  for(i=0;i<900000000;i++);//sleep(1000);
   cout<<" ..";
  for(i=0;i<900000000;i++);//sleep(1000);
   cout<<" ..";
  for(i=0;i<900000000;i++);//sleep(1000);
   cout<<" ..";
*/  
  
 // cout<<endl;
  printCommanElements(a,b,size);

  //printArray(a,size);
  //printArray(b,size);

}


 return 0;
}
