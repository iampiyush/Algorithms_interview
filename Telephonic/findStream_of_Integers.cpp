
//  max heap...


#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
 
using namespace std;
 

void swap(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
 return ;
}


class maxHeap
{
 int *a;
 int s;
 int capacity;
 public: 
 maxHeap(int);
 maxHeap(int*,int,int);
 int size();
 void push(int);
 int pop();    
 int top();
 void buildHeap();
 void bubble_up(int);
 void bubble_down(int);
}; 
 

class minHeap
{
 int *a;
 int s;
 int capacity;
 public: 
 minHeap(int);
 minHeap(int*,int,int);
 int size();
 void push(int);
 int pop();    
 int top();
 void buildHeap();
 void bubble_up(int);
 void bubble_down(int);
}; 



 
 maxHeap::maxHeap(int n)
  {
  int *ptr=NULL;
  ptr=(int*)malloc(sizeof(int)*n);
  
  if(ptr==NULL)
  {
   cout<<"Not enough memory to continue..\n"<<endl;
   exit(0);
  }
  
  a=ptr;
  s=0;
  capacity=n;
  //  done..
 }




 maxHeap::maxHeap(int *p,int n,int c)
 {
  a=p;  //  assign array's base pointer to a pointer.. 
  s=n;
  capacity=c;
  buildHeap();
  //  done..
 }





 int maxHeap::size() 
 {
  return s;
 } 
 
 void maxHeap::push(int x)
 {
  if(s<capacity)
  { 
  a[s]=x; 
  bubble_up(s);
  s++;
  }
  else
   cout<<"Heap FULL..Element can not be added to heap "<<endl;
    return ;
 }
 
 
 int maxHeap::pop()
 {
  //  pop element from the heap...
  //  extracting min element..  
   
   int ele=-1;
   if(s>0)
   {
    ele=a[0];    
    a[0]=a[s-1];
     s--;
    bubble_down(0);
   } 
   else
   {
    cout<<"Heap Empty can not pop anything from it...."<<endl;
   }
 
  return ele;
 }
 
 
  
 int maxHeap::top()
 {
  if(s>0)
   return a[0];
  else
  {
   cout<<"Exception in the code...no element present in the code..\n";
   exit(0);    
   }
 }
 
 
 
 
 
 void maxHeap::bubble_down(int index)
  {
  int left;
  int right;
  int max;
  
  left=2*index+1;
  right=2*index+2;
  max=index;
  if(left<s && a[left] > a[max])
   max=left;
  
  if(right<s  && a[right]> a[max])
    max=right; 
   
  if(max!=index)
  {
   swap(a[index],a[max]);
   this->bubble_down(max);
  }
  else
   return ;
  //  done... 
 
 }
 
 
  void maxHeap::bubble_up(int index)
  {
   int parent;
    
   parent=(index-1)/2;
   if(index==0  || a[index] < a[parent])
     return ;
   
   swap(a[index],a[parent]);
    this->bubble_up(parent);
    
   return ;        
  }
 
 
 
 void maxHeap::buildHeap()
 {
  int i;
   
  
  for(i=(s/2)+1;i>=0;i--)
   bubble_down(i);
  
   return ;
 }
 
 
 
 
  minHeap::minHeap(int n)
  {
  int *ptr=NULL;
  ptr=(int*)malloc(sizeof(int)*n);
  
  if(ptr==NULL)
  {
   cout<<"Not enough memory to continue..\n"<<endl;
   exit(0);
  }
  
  a=ptr;
  s=0;
  capacity=n;
  //  done..
 }




  minHeap::minHeap(int *p,int n,int c)
 {
  a=p;  //  assign array's base pointer to a pointer.. 
  s=n;
  capacity=c;
  buildHeap();
  //  done..
 }





 int  minHeap::size() 
 {
  return s;
 } 
 
 void  minHeap::push(int x)
 {
  if(s<capacity)
  { 
  a[s]=x; 
  bubble_up(s);
  s++;
  }
  else
   cout<<"Heap FULL..Element can not be added to heap "<<endl;
    return ;
 }
 
 
 int  minHeap::pop()
 {
  //  pop element from the heap...
  //  extracting min element..  
   
   int ele=-1;
   if(s>0)
   {
    ele=a[0];    
    a[0]=a[s-1];
     s--;
    bubble_down(0);
   } 
   else
   {
    cout<<"Heap Empty can not pop anything from it...."<<endl;
   }
 
  return ele;
 }
 
 
  
 int  minHeap::top()
 {
  if(s>0)
   return a[0];
  else
  {
   cout<<"Exception in the code...no element present in the code..\n";
   exit(0);    
   }
 }
 
 
 
 
 
 void  minHeap::bubble_down(int index)
  {
  int left;
  int right;
  int max;
  
  left=2*index+1;
  right=2*index+2;
  max=index;
  if(left<s && a[left] < a[max])
   max=left;
  
  if(right<s  && a[right] < a[max])
    max=right; 
   
  if(max!=index)
  {
   swap(a[index],a[max]);
   this->bubble_down(max);
  }
  else
   return ;
  //  done... 
 
 }
 
 
  void  minHeap::bubble_up(int index)
  {
   int parent;
    
   parent=(index-1)/2;
   if(index==0  || a[index] > a[parent])
     return ;
   
   swap(a[index],a[parent]);
    this->bubble_up(parent);
    
   return ;        
  }
 
 
 void minHeap::buildHeap()
 {
  int i;
   
  
  for(i=(s/2)+1;i>=0;i--)
   bubble_down(i);
  
   return ;
 }
 
 
 
 
 
int main()
{
int a[100];
int b[100];
int t,size,i,n;
int iter,k;
char buf[100];
int number;
int ans;
int leftSize,rightSize;
int median;
 
cin>>t;

maxHeap mymaxHeap(100);
minHeap myminHeap(100);
 
while(t--)
{
 //cin>>buf;
 //cout<<"Enter Number of Elements.....\n";
 n=1;
 
 leftSize=0;
 rightSize=0;
 median=0;
 cout<<"Start of stream..\n";
 
 while(n!=-1)
 {
  cin>>n;
  
  leftSize=mymaxHeap.size();
  rightSize=myminHeap.size();
  
  if(leftSize==rightSize)   //  both  
  {
   if(n<median)
   {
    mymaxHeap.push(n);
    median=mymaxHeap.top();
   }
   else
   {
    myminHeap.push(n);
    median=myminHeap.top();
   }
  }
 
  else if(leftSize > rightSize)
  {
   if(median>n)    //   Element belongs to smaller side...
   {
    mymaxHeap.push(n);
    myminHeap.push(mymaxHeap.pop());
    
    median=( myminHeap.top() + mymaxHeap.top() )/2 ;
   }
   else   //  Element belongs to larger side...
   {
    myminHeap.push(n);
    median=( myminHeap.top() + mymaxHeap.top() )/2 ;
   }
  }
  
  else   //   rightSize  >  leftSize...
  {
  
    if(median>n)    //   Element belongs to smaller side...
   {
    mymaxHeap.push(n);
   }
   else   //  Element belongs to larger side...
   {
    myminHeap.push(n);
    mymaxHeap.push(myminHeap.pop());   
   } 
   
   median=( myminHeap.top() + mymaxHeap.top() )/2 ;
 
  }    
  
  
  cout<<"Median is "<<median<<endl;

 
 }   //   while...


}   ////   end of test cases...

 
 
 return 0;
 }
 
