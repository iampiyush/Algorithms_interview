#include<iostream>
#include<list>
#include<algorithm>
#include<stdlib.h>
using namespace std;

typedef struct tree{
        int data;
        tree* left;
        tree* right;
}tree;

typedef struct dll
{
       int data;
       dll* prev;
       dll* next;
       list<int> list;
}dll;

tree* newnode(int d)
{
     tree* tmp=(tree*)malloc(sizeof(tree));
     tmp->data=d;
     tmp->left=tmp->right=NULL;
     return tmp;
}

void inorder(tree* root)
{
     if(!root)
     return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}

dll* createnode()
{
     dll* tmp=(dll*)malloc(sizeof(dll));
     tmp->data=0;
     tmp->next=tmp->prev=NULL;
     
     return tmp;
}

dll* vertical_util(tree* root,dll* tmp,int column)
{
     if(!root)
     return NULL;
     
     //tmp->data=tmp->data+root->data;
     
     if(column%2==0)
     {
         (tmp->list).push_back(root->data);
     }
     else
     {
         (tmp->list).push_front(root->data);   
     }
     
     if(root->left)
     {
       if(tmp->prev==NULL)
       {                 
        tmp->prev=createnode();
        tmp->prev->next=tmp;
       }
       vertical_util(root->left,tmp->prev,column-1);
     }
     
     if(root->right)
     {
       if(tmp->next==NULL)
       {
        tmp->next=createnode();
        tmp->next->prev=tmp;
       }
       vertical_util(root->right,tmp->next,column+1);
     }
     return tmp;
}

void verticalsum(tree* root)
{
     if(!root)
     return;
     
     dll* tmp=createnode();
     int column=0;
     dll* itr=vertical_util(root,tmp,column);
     
     while(itr->prev!=NULL)
     itr=itr->prev;
     /*
     while(itr!=NULL)
     {
      cout<<itr->data<<" ";
      
       for (std::list<int>::iterator it = (itr->list).begin() ; it != (itr->list).end(); ++it)
       cout << *it<<" ";
      cout<<endl;
      itr=itr->next;
     }
     */
     return;
}

main()
{
      tree* root=NULL;
      root=newnode(5);
      root->left=newnode(3);
      root->right=newnode(2);
      root->left->left=newnode(4);
      root->left->right=newnode(1);
      root->right->left=newnode(3);
      root->right->left->left=newnode(2);
      root->right->right=newnode(6);
//      inorder(root);
      
      verticalsum(root);
      
      getchar();
      return 0;
}
