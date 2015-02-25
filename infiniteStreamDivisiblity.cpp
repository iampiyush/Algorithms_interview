// Find MISSING eLEMENTS  using Sorting...
//  time complexity   0(n)...
//  space complexity   0(1)....



#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>


using namespace std;




int main()
{
    
int t,size,i;
int bit,oddCount,evenCount,ans;

cin>>t;
while(t--)
{
 cin>>size;
 
 oddCount=evenCount=0;
 for(i=1;i<=size;i++)
 { 
  cin>>bit;
  if(bit==1)
  {
  if(i%2)
   oddCount+=1;
  else
   evenCount+=1;
  }
 } 

 ans=abs(oddCount-evenCount);
 if(ans%3==0)
  cout<<"Divisible by 3.\n";
 else
  cout<<"Not Divisible by 3.\n"; 
 
  
}


 return 0;
}
