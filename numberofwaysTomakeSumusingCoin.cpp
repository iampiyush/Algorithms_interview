//  program to find Number of ways to make a sum from given denomination...
/*
 f(n,sum)=f(n,sum-a[i])+f(n-1,sum);

*/



#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<string>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<map>
#define size 8000


using namespace std;


int M[8000][8000];


// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
 
 return ;
}






int main()
{
int a[100];
int b[100];

int ans,i;
char buf[100][100];
int t,size,i,n;

cin>>t;
fflush(stdin);
while(t--)
{
 //cin>>buf;
 cin>>n;
 for(i=0;i<n;i++)
  cin>>buf[i];
 
 printNonAnagramincString(buf,n);

}


 return 0;
}




int f(int a[],int size)
{
 int i,j;
 //   i   for   number of elements....and   j  for   particular sum......
 
 for(i=0;i<size;i++) 
  {
  // M[i][0]=!(M[0][i])=0 ;                 
   M[0][i]=0;
   M[i][0]=1;
  }

  return 0;
}


