// Find MISSING eLEMENTS  using Sorting...
//  time complexity   0(n)...
//  space complexity   0(1)....
//   Merge K Sorted Array....

#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>
#define inf -10000

using namespace std;


typedef struct pa
{
 int value;
 int index;
 int nextIndex;
};

// swap two variables...

void swap(pa &x,pa &y)
{
 pa temp;
 temp=x;
 x=y;
 y=temp;
 return ;
}


class heap
{
 pa *a;
 int s;
 int capacity;
 public: 
 heap(int);
 heap(pa*,int,int);
 int size();
 void push(int,int,int);
 pa pop();    
 int top();
 void buildHeap();
 void bubble_up(int);
 void bubble_down(int);
}; 
 
 
 heap::heap(int n)
  {
   pa *ptr=NULL;
  ptr=(pa*)malloc(sizeof(pa)*n);
  
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




 heap::heap(pa *p,int n,int c)
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
 
 void heap::push(int x,int i,int next)
 {
  if(s<capacity)
  { 
  a[s].value=x; 
  a[s].index=i;
  a[s].nextIndex=next;
  bubble_up(s);
  s++;
  }
  else
   cout<<"Heap FULL..Element can not be added to heap "<<endl;
   
   return ;
 }
 
 
  pa heap::pop()
 {
  //  pop element from the heap...
  //  extracting min element..  
   pa ele;
   if(s>0)
   {
    ele=a[0];    
    a[0].value=a[s-1].value;
    a[0].index=a[s-1].index;
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
   return a[0].value;
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
  if(left<s && a[left].value > a[max].value)
   max=left;
  
  if(right<s  && a[right].value> a[max].value)
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
   if(index==0  || a[index].value < a[parent].value)
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
 





void printArray(int a[],int size)
{
 int i;
 cout<<"Array is \n";
 for(i=0;i<size;i++)
  cout<<a[i]<<" ";
  
 cout<<endl; 
 return ;
}



void solve(int a[],int b[],int size)
{
 int i,j;
 int left[1000];
 int right;
 
 cout<<"New Solve Function..\n";
 // fill left array...
 left[0]=1;
 for(i=1;i<size;i++)
  left[i]=left[i-1]*a[i-1];

 right=1;
 for(i=size-1;i>-1;i--)
 {
  b[i]=left[i]*right;
  right=right*a[i];
 } 

 
 return ;
}




//  using 2 arrayss...
void solve2(int a[],int b[],int size)
{
 int i,j;
 int left[1000], right[1000];
 
 
 // fill left array...
 left[0]=1;
 for(i=1;i<size;i++)
  left[i]=left[i-1]*a[i-1];

//  fill right array..
 right[size-1]=1;
 for(i=size-2;i>-1;i--)
  right[i]=right[i+1]*a[i+1];

 for(i=0;i<size;i++)
  b[i]=left[i]*right[i];
 
 return ;
}



//  Merge K Sorted Array Using Heap....
void mergeKSorted(int a[][100],int res[], int k,int n)
{
 int i,j;
  heap myheap(k+30);
  
 int size;
 int outIndex; 
 pa tmp; 
  
  for(i=0;i<k;i++)
   myheap.push(a[i][0],i,1);
  
  outIndex=0;
  size=n*k;
  
  while(outIndex<size)
  { 
   tmp=myheap.pop();
   if(tmp.nextIndex == n)
   {
    myheap.push(inf,i,n);
   }
   else
   {
    myheap.push(a[tmp.index][tmp.nextIndex],tmp.index,(tmp.nextIndex)+1);
   }
   
   if(tmp.value!=inf)
   {
   res[outIndex]=tmp.value;
   outIndex++; 
   }
  }
 

}



int main()
{
int a[100][100];
int b[100];
int c[100];
int d[100];

int res[1000];
int t,size,i,j,n,k;
char buf[100];

cin>>t;

while(t--)
{
                    
cin>>k;
cin>>n;

for(i=0;i<k;i++)
{
 for(j=0;j<n;j++)
  cin>>a[i][j];
}


 mergeKSorted(a,res,k,n);

 for(i=0;i<n*k;i++)
  cout<<res[i]<<" ";
 
 }


 return 0;
}
