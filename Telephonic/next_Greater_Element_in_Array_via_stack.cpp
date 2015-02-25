

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;


void printGreater(int a[],int size)
{
 if(size<1)
 {
  cout<<"Invalid Array Size..\n";
  return ;
 }
 
 int i;
 int cur,prev;
 
 stack<int> s;
 
 s.push(a[0]);
 for(i=1;i<size;i++)
 {
  cur=a[i];
  while(s.empty()==false)
  {
    prev=s.top();
    if(prev>cur)
    {
     break;
    }
    else
    {
     cout<<"Greater Element for the element "<<prev<<" "<<cur<<endl;
     s.pop();
    }
  }  //   end of while loop..
  
  s.push(cur);
 }


   while(s.empty()==false)
   {
    cout<<"Greater Element for the element "<<s.top()<<" "<<-1<<endl;
    s.pop();
   }



 cout<<"Done..\n";

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

cin>>t;

while(t--)
{
 //cin>>buf;
 cout<<"Enter Number of Elements.....\n";
 cin>>n;

 for(i=0;i<n;i++)
  cin>>a[i];
  
  printGreater(a,n);

}


 return 0;
}


