#include<iostream>
using namespace std;

struct tree
{
       int data;
       struct tree* left;
       struct tree* right;
};

struct tree* newnode(int d)
{
       struct tree* node=(struct tree*)malloc(sizeof(struct tree));
       if(!node)
       return NULL;
       node->data=d;
       node->left=NULL;
       node->right=NULL;
       return node;
}




struct tree* insert(struct tree* root,int d)
{
       if(!root)
       return newnode(d);
       else
       {
           if(root->data>d)
           {
            root->left=insert(root->left,d);
           }
           else
           root->right=insert(root->right,d);
       }
       return root;
}




void inorder(struct tree* root)
{
     if(!root)
     return;
     
     inorder(root->left);
     cout<<root->data<<endl;
     inorder(root->right);
}

struct tree* tree2dll(struct tree* root)
{
     if(!root)
     return NULL;
     
     struct tree* left=tree2dll(root->left);
     struct tree* right=tree2dll(root->right);     
     
     
     tree* tmp;
     
     tmp=left;     
     
     if(tmp)
     {
     while(tmp->right)
      tmp=tmp->right;
      
      tmp->right=root;
      root->left=tmp;
      tmp=tmp->right; 
     }
     else
     {
      tmp=root;
      left=root;
     }

     
     if(right)
    {
     right->left=tmp;
     tmp->right=right;
    }
    else
    {
     tmp->right=NULL;
    }
    
     
   //while(root->left!=NULL)
     //root=root->left;
     return left;
}



void printdll(struct tree* root)
{
     if(root==NULL)
     {
      cout<<"Empty DLL \n";
      return ;
     }
     
     struct tree* tmp=root;
     while(tmp)
     {
     cout<<tmp->data<<" ";
     tmp=tmp->right;
     }
}



main()
{
       //              7
      //           5      10
      //         4  6   9    12
      //       3       8
      struct tree* root=NULL;
      root=insert(root,7);
      root=insert(root,5);
      root=insert(root,4);
      root=insert(root,6);
      root=insert(root,3);
      root=insert(root,10);
      root=insert(root,12);
      root=insert(root,9);                        
      root=insert(root,8);
      
      inorder(root);
      root=tree2dll(root);
      cout<<"Done..\n";
      printdll(root);
      
      getchar();
      return 0;      
}
