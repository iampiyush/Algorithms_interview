//   Print unique rows in a given boolean matrix


// Longest  Prefix Search Using Trie...


#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
 
using namespace std;
 

void swap(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
 return ;
}



typedef struct Trie
{
 bool isLeaf;
 Trie *left;
 Trie *right;
};



Trie* createTrieNode()
{
 Trie *temp;
 
 temp=(Trie*)malloc(sizeof(Trie));
 
 temp->isLeaf=false;
 temp->left=NULL;
 temp->right=NULL;
 
 return temp;
}




int search(Trie *root,int mat[][100],int rowIndex,int numberOfCol)
{
 int i,len;
 int index;

 Trie *crawl=NULL;
 
 crawl=root;

 for(i=0;i<numberOfCol;i++)
 {
  index=mat[rowIndex][i];
  if(index==0)
  {
   if(crawl->left)
    crawl=crawl->left; 
   else
    return 0;
  }
  
  if(index==1)
  {
   if(crawl->right)
    crawl=crawl->right; 
   else
    return 0;
  }
 
 }//  end of for loop....


 return 1;

}





void insert(Trie *root,int mat[][100],int rowIndex,int numberOfCol)
{
 int i,len;
 int index;

 Trie *crawl=NULL;
 
 crawl=root;
 
 for(i=0;i<numberOfCol;i++)
 {
   index=mat[rowIndex][i];
   
   if(index==0)
   {
    if(crawl->left==NULL)
    crawl->left=createTrieNode();
    crawl=crawl->left;
   }
   else
   {
    if(crawl->right==NULL)
     crawl->right=createTrieNode();
     crawl=crawl->right; 
   }
 
 }  //   end of for loop..
 
 crawl->isLeaf=true;
 
 
//  done..
 return ;
}




 
int main()
{
int a[100];
int b[100];
int t,size,i,j,n;
int iter,k;
char buf[100];
int number;
int ans;
int mat[100][100];
int r,c;


Trie *root=NULL; 
cin>>t;
 
while(t--)
{
 root=createTrieNode();
 
 
 cout<<"Enter Number of rows and cols...\n";
 cin>>r;
 cin>>c;
 
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   cin>>mat[i][j];
 } 
 
  //  now search some strings.. 


cout<<"Unique Rows are..\n";

 for(i=0;i<r;i++)
 {
  ans=search(root,mat,i,c);
  if(ans==0)
  {
   for(j=0;j<c;j++)
    cout<<mat[i][j]<<" ";
   cout<<endl;
   insert(root,mat,i,c); 
  }
 
 } 




 
 }  //  end of test cases..

 

 
 
 return 0;
 }
 
