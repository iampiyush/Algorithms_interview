//   Ceil and Floor Of BST

#include<iostream>
#include<stack>
#include<queue>
using namespace std;



typedef struct tnode
{
 int data;
 struct tnode *left;
 struct tnode *right;
};


tnode* createNode(int num)
{
 tnode *temp;
 temp=(tnode*)malloc(sizeof(tnode));
 temp->data=num;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}


void inorder(tnode *root)
{
 if(root==NULL)
  return ;
 inorder(root->left);
 cout<<root->data<<endl;
 inorder(root->right); 
}



void preorder(tnode *root)
{
 if(root==NULL)
  return ;
 cout<<root->data<<endl; 
 preorder(root->left);
 preorder(root->right); 
}



void postorder(tnode *root)
{
 if(root==NULL)
  return ;
 postorder(root->left);
 postorder(root->right); 
 cout<<root->data<<endl;
}


int height(tnode *root)
{
 if(root==NULL)
  return 0;
  
int lheight,rheight;
lheight=height(root->left);  
rheight=height(root->right); 

if(lheight>rheight)
 return (lheight+1);
else
 return (rheight+1);
 }



int max(int a,int b,int c)
{
 if(a>=b && a>=c)
  return a;
 if(b>=c && b>=a)
  return b;
if(c>=a && c>=b)
 return c;
}



//    
tnode  *floor(tnode *root,int k)
{
 if(root==NULL)
  return NULL;
 
 if(root->data==k)
  return root;
  
 if(root->data>k)
  return ( floor(root->left,k) || root );
 else
  return ( floor(root->right,k) || root );

}


int main()
{
 int wait;   
 tnode *root=NULL;
 tnode *temp=NULL;
 bool state;
 int k;
 root=createNode(5);
 root->left=createNode(3);
 root->right=createNode(8);
 root->left->left=createNode(2);
 root->left->right=createNode(4);
 root->right->left=createNode(6);
 root->right->right=createNode(10);

 tnode *p=NULL,*q=NULL;
 
 cout<<"Enter The Value Of k..\n";
 cin>>k;
 temp=floor(root,k);
 if(temp)
 cout<<"LCA is "<<temp->data<<endl; 
 else
 cout<<"Nodes are Not present in tree..\n";  
 cin>>wait;
 return 0;
}


