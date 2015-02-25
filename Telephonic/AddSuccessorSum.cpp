//  Traversals...

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


int max(int a,int b,int c)
{
 if(a>=b && a>=c)
  return a;
 if(b>=c && b>=a)
  return b;
if(c>=a && c>=b)
 return c;
}



int min(int a,int b,int c)
{
 if(a<=b && a<=c)
  return a;
 if(b<=c && b<=a)
  return b;
if(c<=a && c<=b)
 return c;
}




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



void AddSumUtill(tnode *root,int &sum)
{
 if(root==NULL)
  return ;
  
  AddSumUtill(root->right,sum);
  root->data=root->data+sum;
  sum=root->data;
  AddSumUtill(root->left,sum);
  
  return ;
}



void AddSum(tnode *root)
{
 if(root==NULL)
  return ;
  
 int sum=0; 

 AddSumUtill(root,sum);

 return ;
}


int main()
{
 int wait;   
 tnode *root;
 root=createNode(5);
 root->left=createNode(3);
// root->right=createNode(8);
 root->left->left=createNode(2);
 root->left->right=createNode(4);
// root->right->left=createNode(6);
 //root->right->right=createNode(10);


 preorder(root);  
 cout<<"\nFunction Called\n"; 
 AddSum(root);
 preorder(root);
    
 cin>>wait;
 return 0;
}


