
//  max heap...


//  find K smallest Element   in any array...

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


class heap
{
 int *a;
 int s;
 int capacity;
 public: 
 heap(int);
 heap(int*,int,int);
 int size();
 void push(int);
 int pop();    
 int top();
 void buildHeap();
 void bubble_up(int);
 void bubble_down(int);
}; 
 
 
 heap::heap(int n)
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




 heap::heap(int *p,int n,int c)
 {
  a=p;  //  assign array's base pointer to a pointer.. 
  s=n;
  capacity=c;
  buildHeap();
  //  done..
 }





 int heap::size() 
 {
  return s;
 } 
 
 void heap::push(int x)
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
 
 
 int heap::pop()
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
 
 
  
 int heap::top()
 {
  if(s>0)
   return a[0];
  else
  {
   cout<<"Exception in the code...no element present in the code..\n";
   exit(0);    
   }
 }
 
 
 
 
 
 void heap::bubble_down(int index)
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
 
 
  void heap::bubble_up(int index)
  {
   int parent;
    
   parent=(index-1)/2;
   if(index==0  || a[index] < a[parent])
     return ;
   
   swap(a[index],a[parent]);
    this->bubble_up(parent);
    
   return ;        
  }
 
 
 void heap::buildHeap()
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
 
 
heap myheap(1000); 
 cin>>t;
 
while(t--)
{
 //cin>>buf;
 cout<<"Enter Number of Elements.....\n";
 cin>>n;
 cin>>k;
 
 
 for(i=0;i<n;i++)
 {
  cin>>a[i];
  if(i<k)
   myheap.push(a[i]);
 }
  
  
 // cout<<"Control..\n";
  
 for(i=k;i<n;i++)
 {
  if(myheap.top()>a[i])
  {
   myheap.pop();
   myheap.push(a[i]);
  }
 } 
  
  for(i=0;i<k;i++)
    b[i]=myheap.pop();
 
  for(i=0;i<k;i++)
   cout<<b[i]<<" ";
 
  cout<<endl;
  cout<<"MyHeap size is "<<myheap.size()<<endl;
}
 
 
 return 0;
 }
 
