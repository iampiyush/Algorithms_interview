#include<iostream>
using namespace std;

int mat[100][100];




int findRow(int r,int c)
{
 int i,j;
 int max;
 
 max=r;
 i=0;
 j=r-1;
 while(i<r  &&  j>-1)
 {
  if(mat[i][j]==1)
  {
   max=i;
   j--;
  }
  else
  {
  i++;
  }
 }

 return max;
 
}



int main()
{
 int i,j;
 int t;
 int r;
 int c;
 int ans;
 
 
 cin>>t;
 while(t--)
 {
  cin>>r;
  cin>>c;         
  for(i=0;i<r;i++)
   for(j=0;j<c;j++)
    cin>>mat[i][j];
  
 
  ans=findRow(r,c);
  cout<<"Row Number with maximum ones"<<ans<<endl;
  
  
 }



}
