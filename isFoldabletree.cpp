//Foldable Binary Trees

//  Traversals...

#include<iostream>
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

int min(int a,int b,int c)
{
 if(a<=b && a<=c)
  return a;
 if(b<=c && b<=a)
  return b;
if(c<=a && c<=b)
 return c;
}

int minimum(tnode *root)
{
 if(root==NULL)
  return 0;
 
 else  min(root->data,minimum(root->left),minimum(root->right)); 
}


int maximum(tnode *root)
{
 if(root==NULL)
  return 0;
 
 else  max(root->data,maximum(root->left),maximum(root->right)); 
}



void mirror(tnode *root)
{
 if(root==NULL)
  return ;

 mirror(root->left);
 mirror(root->right);
 
 tnode *temp;
 
 temp=root->left;
 root->left=root->right;
 root->right=temp;  

 return ;
}


bool isSimilar(tnode *first,tnode *second)
{
 if(first==NULL  &&  second==NULL)
  return true;
 
 if(first  &&  second)
 {
  return isSimilar(first->left,second->left)  &&  isSimilar(first->right,second->right)  ;
 }
 
 return false; 

}



bool isFoldable(tnode *root)
{
 if(root==NULL)
  return true;
 
 if(root->left &&  root->right)
{
 bool x;
 mirror(root->left);  
 
 x=isSimilar(root->left,root->right);
 mirror(root->left);
 return x;
}
else if(root->left==NULL  &&  root->right==NULL)
 return true;

 return false;
}


int main()
{
 int wait;   
 tnode *root;
 root=createNode(3);
 root->left=createNode(1);
 root->right=createNode(5);
 root->left->right=createNode(2);
 root->left->left=createNode(10);
 root->right->left=createNode(4);
 root->right->right=createNode(7);
 
 if(isFoldable(root)==true)
  cout<<"Tree Is Foldable..\n";
 else
  cout<<"Tree is not Foldable..\n";
   
 cin>>wait;
 return 0;
}

