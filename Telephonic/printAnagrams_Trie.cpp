

//  Print Anagrams Together....

//  Using A trie..


#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
#include<vector>
 
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
 Trie *childs[27];
 vector<int> mylist;
};



Trie* createTrieNode()
{
 Trie *temp;
 int i;
 
 temp=(Trie*)malloc(sizeof(Trie));
 
  temp->isLeaf=false;
 
 for(i=0;i<26;i++)
  temp->childs[i]=NULL;
 
 //(temp->mylist).resize(10);
 
 return temp;
}




int search(Trie *root,char key[])
{
 int i,len;
 int index;
 
 Trie *move;
 move=root;
 len=strlen(key);
 
 for(i=0;i<len;i++)
 {
  index=key[i]-'a';
  
  if(move->childs[index]==NULL)
   return 0;
 
  move=move->childs[index];
 }

 if(move->isLeaf==true)
 return 1;
 
 return 0;
 
}



void insert(Trie *root,char key[],int in)
{
 int i;
 int len;
 int index;
 
 len=strlen(key);

 Trie *move=root,*temp=NULL;
 

 for(i=0;i<len;i++)
 {
  index=key[i]-'a';    
 // cout<<"Index is "<<index<<endl;             
  if(move->childs[index]==NULL)
  {
   temp=createTrieNode();
   if(temp==NULL)
   {
   cout<<"No Memory..\n";
   return ; 
   }
   move->childs[index]=temp;
   //move=move->childs[index];
  }
   
   move=move->childs[index]; 
 
 }
 

  move->isLeaf=true;
 
 (move->mylist).push_front(in);
 // cout<<"Index is "<<in<<endl;
   // cout<<"Bug..\n";
    

 return ;
}



void dfsTrie(Trie *root,char* wordArr[])
{
 if(root==NULL)
  return ;
 
 int i;
 
 //  then print All Anagrams Together....
 if((root->isLeaf)==true)
 {
  int size;
  int index;
  size=(root->mylist).size();                       
  for(i=0;i<size;i++)
  {
   index=root->mylist[i];                  
   cout<<wordArr[index]<<" ";
  }  
  cout<<endl;
 } 
 
 //  continue DS..
 for(i=0;i<26;i++)
  dfsTrie(root->childs[i],wordArr);
  
  
  return ;

}



void printAnagramsTogether(char* wordArr[], int size)
{
 int i,j;
 int len;
 
 char buffer[100];
 Trie *root=NULL;
 
 root=createTrieNode();
 
 
 for(i=0;i<size;i++)
 {
  strcpy(buffer, wordArr[i]);
  len=strlen(buffer);
  
  sort(buffer,buffer+len);
// cout<<"sorted anagram is "<<buffer<<endl;
  insert(root,buffer,i);
 }
 
 
 //  now time for DFS....
 
   dfsTrie(root,wordArr);

}

 
int main()
{
int a[100];
int b[100];
int t,i,n;
int iter,k;
char buf[100];
int number;
int ans;

char* wordArr[] = {"cat", "dog", "tac", "god", "act","abc","xyz","avinash"}; 
int size = sizeof(wordArr) / sizeof(wordArr[0]);

//cout<<size<<endl;
printAnagramsTogether(wordArr, size);
   

 cin>>ans;

 return 0;
 }
 
