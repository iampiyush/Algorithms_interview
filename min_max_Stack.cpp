// Find MISSING eLEMENTS  using Sorting...
//  time complexity   0(n)...
//  space complexity   0(1)....

#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>
#include<stack>


using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}



void superStack(int a[],int size)
{
 int i,j;
 stack<int> normal;
 stack<int> minStack;
 stack<int> maxStack;
 
 
 for(i=0;i<size;i++)
 {
  normal.push(a[i]);   //  push in normal stack...
  //  maintain min stack..
  if(minStack.size()==0)
  {
   minStack.push(a[i]);
  }
  else
  {
   if(a[i]<=minStack.top())
     minStack.push(a[i]);
  }

  // maintain maxStack...
   if(maxStack.size()==0)
  {
   maxStack.push(a[i]);
  }
  else
  {
   if(a[i]>=maxStack.top())
    maxStack.push(a[i]);
  }
 }
 //   End of for Loop...
 
  int ele;
  for(i=0;i<size;i++)
  {
   ele=normal.top();
   
   if(minStack.top()==ele)
   {
    cout<<"Min Stack ..."<<ele<<endl;
    minStack.pop(); 
   }
   if(maxStack.top()==ele)
   {
    cout<<"Max Stack..."<<ele<<endl;
    maxStack.pop();
   }
   normal.pop();
   cout<<ele<<"\n";   
  
  }
  

 return ;
}



int main()
{
int a[100];
int b[100];
int t,size,i,n;
char buf[100];

cin>>t;

while(t--)
{
 //cin>>buf;
 cin>>n;
 for(i=0;i<n;i++)
  cin>>a[i];
  
  superStack(a,n); 

}


 return 0;
}
