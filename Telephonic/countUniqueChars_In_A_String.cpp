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



class myQueue
{
 stack<int> s1;
 stack<int> s2;
 public:
 void push(int);
 int pop(); 
 //int top();
 bool isEmpty();
 int size();
};



void myQueue::push(int element)
{
 s1.push(element);   //   Always Add Node to s1 stack..
}



 int myQueue::pop()
{
  int x;
  if(s2.empty()==true)
  {
   if(s1.empty()==true)
   {
    cout<<"Queue Empty...nothing To pop \n";
    return -1;
   }
   else
   {
    while(s1.size()!=1)
    {
     x=s1.top();
     s1.pop();
     s2.push(x);
    }
    x=s1.top();
    s1.pop();
    return x;
   }
  }
  else
  {
   x=s2.top();
   s2.pop();
   return x;
  } 


}

/*
int myQueue::top()
{



}
*/

 int myQueue::size()
 {
  return s1.size()+s2.size(); 
 }


bool myQueue::isEmpty()
{
 if(s1.empty()==true  &&  s2.empty()==true)
  return true;
 else
  return false; 
}


void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}




int  countUniqueChars(char a[])
{
 int i,j;
 int len;
 int count=0;
 int myMap[256]; 
 len=strlen(a);
 
 
 
 for(i=0;i<256;i++)
   myMap[i]=0;
 
 for(i=0;i<len;i++)
 {
  if(myMap[a[i]]==0)
   {
    myMap[a[i]]=1;
    count++;
   }
 }
  

 return count;
}



int main()
{
   int t;
   int i,n;
   int ans;
   char a[1000];
   myQueue mq;
   
   cin>>t;
   while(t--)
   {
    cout<<"Enter Number of Elements..\n";         
    cin>>n;
    for(i=0;i<n;i++)
    {
     cin>>ans;
     mq.push(ans); 
    } 
    
    for(i=0;i<n;i++)
    {
     ans=mq.pop();
     cout<<ans<<endl;
    } 

    
   } 
   
    getchar();
    return 0;


 return 0;
}

