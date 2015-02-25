//  program Anagrams Together...

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<string>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>


using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}


bool isalphas(char c)
{
 if((c>= 'a'   &&  c<= 'z')    || (c>= 'A'   &&  c<= 'Z') )
   return true;
 return false;     
}


void reverse(char *start,char *end)
{
 char c;
 while(start<end)
 {
  c=*start;
  *start=*end;
  *end=c;
  start++;
  end--;
 }


 return ;
}


void printAnagramincString(char buf[][100],int size)
{
 int i,j;
 
 map<string,vector<int> > myMap;
 
 for(i=0;i<size;i++)
 {
  string temp(buf[i]);              
  sort(temp.begin(), temp.end());
  myMap[temp].push_back(i);    //   push all the 
 }


//  time to print...


 int index;    
cout<<"Non  Anagramic Strings are..\n\n\n";
for(i=0;i<size;i++)
{
              
  string temp(buf[i]); 
  sort(temp.begin(), temp.end());
  
//  cout<<"Anagrams are ..\n";
  while(myMap[temp].size()!=0)
  { 
   index=myMap[temp].back();
   cout<<buf[index]<<"    ";
   myMap[temp].pop_back();
  }
 cout<<endl;

}




 return ;
}

int main()
{
int a[100];
int b[100];
int t,size,i,n;
int ans;
char buf[100][100];

cin>>t;
fflush(stdin);
while(t--)
{
 //cin>>buf;
 cin>>n;
 for(i=0;i<n;i++)
  cin>>buf[i];
 
 printAnagramincString(buf,n);

}


 return 0;
}
