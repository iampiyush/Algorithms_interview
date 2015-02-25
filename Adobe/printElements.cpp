#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




void printElementsinC(int a[],int b[],int l1,int l2,int k)
{
 
 int i,j;
 
 
 sort(a,a+l1);  //  sort array A
 sort(b,b+l2);  //  sort array B
 
 
 i=0;j=l2-1;
 while(i<l1  && j>-1)
 {
  if(a[i]+b[j]==k)
  {
   cout<<a[i]<<" "<<b[j]<<endl;
   return ;
  }
  else if(a[i]+b[j]<k)
    i++;
  else
    j--;
 
 }
 
 
 return ;

}








void printElements(vector<int> &a,vector<int> &b,int k)
{
 int l1,l2;
 int i,j;
 
 l1=a.size();
 l2=b.size();
 
 sort(a.begin(),a.end());  //  sort array A
 sort(b.begin(),b.end());  //  sort array B
 
 
 i=0;j=l2-1;
 while(i<l1  && j>-1)
 {
  if(a[i]+b[j]==k)
  {
   cout<<a[i]<<" "<<b[j]<<endl;
   return ;
  }
  else if(a[i]+b[j]<k)
    i++;
  else
    j--;
 
 }


 return ;

}


int main()
{
 int first[100],second[100];

 int size1;
 int size2;
 
 int t,i,x;
 int k;
 
 cin>>t;
 while(t--)
 {
  cin>>size1;
  
  for(i=0;i<size1;i++)
   cin>>first[i];                   
  
 
 cin>>size2;
  for(i=0;i<size2;i++)
   cin>>second[i];
   
  
 cout<<"Enter the Sum "<<endl;
 cin>>k;
// printElements(first,second,k);
 printElementsinC(first,second,size1,size2,k);
 
 
 }


 return 0;
}
