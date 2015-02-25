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






bool isBSTUtill(tnode *root,int min,int max)
{
 if(root==NULL)
 {
   return true;
 }

 if(root->data>min  &&  root->data<max)
 {
  return isBSTUtill(root->left,min,root->data)  && isBSTUtill(root->left,root->data,max)  ;  
 }
 else
  return false;

  
}



bool isBST(tnode* root)
{
 if(root==NULL)
  return true;
  
 return isBSTUtill(root,INT_MIN,INT_MAX);
}

int maximum(tnode *root)
{
 if(root==NULL)
  return 0;
 
 else  max(root->data,maximum(root->left),maximum(root->right)); 

}


int minimum(tnode *root)
{
 if(root==NULL)
  return 0;
 
 else  min(root->data,minimum(root->left),minimum(root->right)); 

}

bool isBST2(tnode* root)
{
 if(root==NULL)
  return true;

 int max,min;
 
  max=maximum(root->left);
  min=minimum(root->right);


 
 return ( (max<=root->data && min>=root->data)  &&  isBST2(root->left)  &&  isBST2(root->right) );


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
 
 
 if(isBST(root)==true)
  cout<<"Tree Is BST..\n";
 else
  cout<<"Tree is not BST..\n";
   
 cin>>wait;
 return 0;
}

