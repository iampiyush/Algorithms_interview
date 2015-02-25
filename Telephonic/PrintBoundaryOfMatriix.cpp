#include<iostream>
#include<cstdio>
using namespace std;



void printBoundary(int mat[][2],int m,int n,int k)
{
   
 //   Handle Base Cases here...
 if(m<=0  ||  n<=0)
  return ;
 
 int i,j;
  
 // cout<<m<<" "<<n<<endl;
 //   case where only 1 row exists..  
 if(m==1)
 {
  for(i=0;i<n;i++)
   cout<<mat[k][k+i]<<" ";
  return ;
 }
 
 //   case where only one column exists...
 if(n==1)
 {
  for(i=0;i<m;i++)
   cout<<mat[k+i][k]<<" ";
  return ;
 }
  
 //  Print Upper Row..    
 for(i=k;i<k+n;i++)
  cout<<mat[k][i]<<" ";
 //cout<<endl;
 
 //  print Right Column..
 for(i=k+1;i<k+m;i++)
  cout<<mat[i][k+n-1]<<" ";
// cout<<endl;
 
 
 //  print Lower Row...
 for(i=k+n-2;i>=k;i--)
  cout<<mat[k+m-1][i]<<" ";
  //cout<<endl;
 //  print Left Column...
 for(i=k+m-2;i>k;i--)
  cout<<mat[i][k]<<" ";  
//  cout<<endl;
  

  cout<<"Layer "<<k+1<<endl;
  printBoundary(mat,m-2,n-2,k+1);

 // cout<<"\nDone..\n";
  return ;

}


 
// driver program to test above function
int main()
{
  int mat[1][2] = { {10, 20}
                  };
  printBoundary(mat,1,2,0);
  getchar();
  return 0;
}
