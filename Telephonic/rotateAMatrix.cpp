#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<deque>
using namespace std;





void printMatrix(int image[][100],int r,int c)
{
 int i,j;
 
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   cout<<image[i][j]<<" ";
  cout<<endl;
 }
}

void rotateMatrix(int image[][100],int r,int c)
{
 int aux[c+1][r+1];   
 int newrow,newcol;
 int oldrow,oldcol;
 //  rotate the matrix..
 int i,j;
 
 oldcol=0;
 oldrow=r-1;
 newrow=0;
 newcol=0;


/*
  for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   cout<<image[i][j]<<" ";
    cout<<endl;
 }
*/


//cout<<"\n\n now rotate  the matrix.. \n\n";

// rotate logic..
 for(i=0;i<c;i++)
 {
  newcol=0;
  oldrow=r-1;
  for(j=0;j<r;j++)
  {
   aux[newrow][newcol]=image[oldrow][oldcol];
   newcol++;
   oldrow--;
  }
 
  newrow++;
  oldcol++;
 }
 
 
  for(i=0;i<c;i++)
 {
  for(j=0;j<r;j++)
   cout<<aux[i][j]<<" ";
  cout<<endl;
 }

}


int main()
{
  int  wait;
  int image[100][100];
  int r,c,t;
  int i,j;
  //int image[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
 
   cin>>t;
   while(t--)
   {
   // cout<<"Enter Row and column..\n";
    cin>>r;
    cin>>c;
   
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
      cin>>image[i][j];
    }
  
   rotateMatrix(image,r,c);
  
   }
  
  
//  cin>>wait;
 return 0;
}
