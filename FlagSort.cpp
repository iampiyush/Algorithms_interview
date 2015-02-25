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
 return ;
}




void printElements(int arr[],int size)
{
  int i,j;

  i=0;
  j=size-1;
  
  while(i<j)
  {
  
   if(arr[i]==1  &&  arr[j]==0)
   {
    swap(arr[i],arr[j]);
    i++;
    j--;
   }
   else if(arr[i]==0  &&  arr[j]==1)
   {
   //  do nothing and move forward and backword....
    i++;
    j--;
   } 
  else if(arr[i]==0 && arr[j]==0)
  {
   i++;
  }
  else if(arr[i]==1 && arr[j]==1)
  {
   j--;
  }

}

//  cout<<endl;
  cout<<"Outside Loop..\n";
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
  
  //printArray(a,size);  

  
 // findElements(a,size);
   printElements(a,size);
   
    printArray(a,size);
  //printArray(b,size);

}


 return 0;
}
