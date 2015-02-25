// Inplace Merge
//  time complexity   0(n2)...
//  space complexity   0(1)....

#include<stdio.h>
#include<time.h>
#include<time.h>




// swap two variables...

void swap(int x,int y)
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
  //cout<<"Wrong Array size "<<endl;
  return ;
 }     
 int i;
 
 for(i=0;i<size;i++);
  //cout<<arr[i]<<" ";

// cout<<endl;

}


void mergeInplace(int a[],int b[],int size)
{
 int i,j;

 for(i=0;i<size;i++)
 {
  if(a[i]>b[0])
  {
   swap(a[i],b[0]);
   //   fix position of swapped element in array b...
   for(j=0;j<size-1;j++)
   {
    if(b[j]>b[j+1])
     swap(b[j],b[j+1]);
    else
     break;
   } 
  }
  
 }


  return ;
}




int main()
{
int a[100];
int b[100];
int t,size,i;

t=1;
//cin>>t;
while(t--)
{
 //cin>>size;
 
 for(i=0;i<size;i++)
  //cin>>a[i];
  
 for(i=0;i<size;i++)
 // cin>>b[i];
  
  
  printArray(a,size);  
  printArray(b,size);
  
  //cout<<"Inplace Merge \n";
  printf("..");
  sleep(1000);
   printf(" ..");
 // cout<<" ..";
  sleep(1000);
   printf(" ..");
 // cout<<" ..";
  sleep(1000);
   printf(" ..");
//  cout<<" ..";
  sleep(1000);
   printf(" ..");
//  cout<<" ..";
  
 // cout<<endl;
  mergeInplace(a,b,size);

  printArray(a,size);
  printArray(b,size);

}


 return 0;
}
