/*
 Grid Search Problem...
*/


#include<iostream>
#include<cstring>
#include<string>
#include<cstring>
using namespace std;



void printNormally(int m[][100],int r,int c)
{
 int i,j;
 
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   cout<<m[i][j]<<" ";
  cout<<endl;
 }

 return ;
}  



bool isSafe(int x,int y,int R,int C)
{
 if(x<0   ||  x>=R   ||   y<0  ||  y>=C)
  return false;
  
 return true; 
}


void SearchWordHepler(char grid[][100],char visited[][100],char key[],int row,int col,int x,int y,int index,int length,bool &ans)
{
 if(index==length)
 {
  ans=true;
  return ;
 }

 
 if(grid[x][y]==key[index]   &&   visited[x][y]==false)
 {
 //   explore all possiblity...All moves..
 
  visited[x][y]=true;
  if(isSafe(x,y+1,row,col)   && ans==false)
  {
   SearchWordHepler(grid,visited,key,row,col,x,y+1,index+1,length,ans);
  }
 
  if(isSafe(x+1,y,row,col) &&  ans==false)
  {
     SearchWordHepler(grid,visited,key,row,col,x+1,y,index+1,length,ans);
  }
 
  if(isSafe(x,y-1,row,col)  && ans==false)
  {
   SearchWordHepler(grid,visited,key,row,col,x,y-1,index+1,length,ans);
  }
 
 
  if(isSafe(x-1,y,row,col)   &&  ans==false)
  {
   SearchWordHepler(grid,visited,key,row,col,x-1,y,index+1,length,ans);
  }
   
  visited[x][y]=false;
  
 }       //   If mismatch....then   return
 
 
 return ; 
 


}


//   Wrapper Function Around  The Main Recursive Function for Finding The Word...
bool SearchWord(char mat[][100],int r,int c,char key[])
{
//  test for base cases...

bool ans=false;
bool visited[100][100];
int i,j;
int len;

len=strlen(key);

for(i=0;i<=r;i++)
 for(j=0;j<=c;j++)
  visited[i][j]=false;

// mat[i][j]==key[0] 

for(i=0;i<r;i++)
{
 for(j=0;j<c;j++)
 {
  if(ans==false )
   SearchWordHepler(mat,visited,key,r,c,i,j,0,len,ans);
  else
   return ans; 
 }
}


 return ans; 
}


int main()
{
 char mat[100][100];
 char key[100];
 int i,j;
 int r,c;



int t;
cin>>t;

while(t--)
{
cout<<"Enter number of rows And cols in  matrix "<<endl;          
cin>>r;
cin>>c;

cout<<"Enter The Grid..\n "<<endl;

for(i=0;i<r;i++)
 for(j=0;j<c;j++)
  cin>>mat[i][j];
  
 
cout<<"Enter word to be Searched..\n";
cin>>key; 
 
if(SearchWord(mat,r,c,key))
 cout<<"Word exist in the Grid..\n";
else  
cout<<"Words Is Not Present in the Grid..\n";
printDiagonalWise(mat,r,c);  


 
}



 return 0;

}
