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



void findElementsSorting(int a[],int size)
{
 int i;
 int printCount=0;
 
 
 if(size%2 && size<1)
 { 
  cout<<"Invalid input...\n";
  return ;
 }
 
 
 // sort the array..
 sort(a,a+size);
 
 for(i=0;i<size-1;)
 {
  if(a[i]==a[i+1])
  {
   i=i+2;
  }
  else 
  {
   cout<<a[i]<<" ";
   printCount++;
   i++;
  }
 }

 if(printCount==1)
  cout<<a[size-1]<<" ";

 cout<<endl;
 return ;

}




void findElements(int a[],int size)
{
 int i;
 int x1=0,x2=0,x3;
 int temp;
 int pos=1;
 
 for(i=0;i<size;i++)
  x1=x1^a[i];
  
  temp=x1;
 
  cout<<"Powers of two..\n";
  while(temp)
  {
   cout<<pos<<endl;          
   if(pos&temp)
    break;
   pos=pos<<1;
  }
   
 
  x2=0;x3=0;
  for(i=0;i<size;i++)
  {
   if(pos&a[i])
    x2=x2^a[i];
   else
    x3=x3^a[i];
  }


 cout<<x2<<" "<<x3<<endl;

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
  //printArray(b,size);
  
 // findElements(a,size);
  findElementsSorting(a,size);
  //printArray(a,size);
  //printArray(b,size);

}


 return 0;
}
