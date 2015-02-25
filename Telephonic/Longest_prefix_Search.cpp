
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
 Trie *childs[26];
};



Trie* createTrieNode()
{
 Trie *temp;
 int i;
 
 temp=(Trie*)malloc(sizeof(Trie));
 
  temp->isLeaf=false;
 
 for(i=0;i<26;i++)
  temp->childs[i]=NULL;
 
 
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



void LongestPrefix(Trie *root,char key[])
{
 int i,len;
 int index;
 int prefixLen=-1;
 
 Trie *move=NULL;
 move=root;
 len=strlen(key);
 
 
 for(i=0;i<len;i++)
 {
  index=key[i]-'a';
  
  if(move->childs[index]==NULL)
   break;
   else
   { 
    move=move->childs[index];
    if(move->isLeaf)
     prefixLen=i;
   }
 }

 key[prefixLen+1]='\0';

 
 return ;
 

}



void insert(Trie *root,char key[])
{
 int i;
 int len;
 int index;
 
 len=strlen(key);

 Trie *move=root;
 
 for(i=0;i<len;i++)
 {
  index=key[i]-'a';                 
  if(move->childs[index]==NULL)
  {
   move->childs[index]=createTrieNode();
   move=move->childs[index];
  }
  else
  {
   move=move->childs[index];
  }
 }
 
 move->isLeaf=true;
 
 
//  done..
 return ;
}




 
int main()
{
int a[100];
int b[100];
int t,size,i,n;
int iter,k;
char buf[100];
int number;
int ans;


Trie *root=NULL; 
cin>>t;
 
while(t--)
{
 root=createTrieNode();
 
 
 cout<<"Enter Number of Keys to be inserted.....\n";
 cin>>n;
 
 for(i=0;i<n;i++)
 {
  cin>>buf;
  insert(root,buf);
 } 
  //  now search some strings.. 

 cout<<"Enter Word for which you want to Search longest Prefix..\n";
 cin>>buf;
 
 LongestPrefix(root,buf);

 cout<<"Longest Prefix Present is "<<buf<<endl;
 
 }

 

 
 
 return 0;
 }
 
