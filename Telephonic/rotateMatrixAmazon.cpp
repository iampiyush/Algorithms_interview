#include<iostream>

using namespace std;


void rotateMatrix(int image[][100],int r,int c)
{
 int aux[c+1][r+1];   
 int newrow,newcol;
 int oldrow,oldcol;
 int i,j;
 
 oldcol=0;
 oldrow=r-1;
 newrow=0;
 newcol=0;

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
  cin>>r;
  cin>>c;
   
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
      cin>>image[i][j];
    }
  
 rotateMatrix(image,r,c);
 return 0;
}
