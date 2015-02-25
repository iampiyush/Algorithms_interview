#include<iostream>
#include<cstring>
#include<string>
using namespace std;



int main()
{
char a[20],b[20];
string x,y;

int t;

cin>>t;

while(t--)
{
cin>>x;
cin>>y;


 
 if(x.compare(y)==0)
  cout<<x<<" Is equal to "<<y<<endl;
 else if(x.compare(y)>0)
 cout<<x<<" Is greater than  "<<y<<endl;
 else
 cout<<y<<" Is greater than  "<<x<<endl;

}


}
